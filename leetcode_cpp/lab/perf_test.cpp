/**
 * @author Anti
 * @date 2023-12-16
 */

#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"
void C(int depth,int max) {
  if(depth>=max) {
    return ;
  }
  for(int i = 0; i < 100;i++) {
    int n = std::rand()%50+10;
    for(int i = 0 ; i< n;i++) {
      int fileDescriptor = open("example.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
      if (fileDescriptor == -1) {
        std::cerr << "无法打开文件！" << std::endl;
        return;
      }
      const char *message = "Perf Lab";
      ssize_t bytesWritten = write(fileDescriptor, message, strlen(message));
      if (bytesWritten == -1) {
        std::cerr << "写入文件时出错！" << std::endl;
        return;
      }

      fsync(fileDescriptor);

      // 关闭文件
      int closeResult = close(fileDescriptor);
      if (closeResult == -1) {
        std::cerr << "关闭文件时出错！" << std::endl;
        return;
      }
    }
  }
  C(depth+1,max);
}
void B() {
  int n = std::rand()%100+50;
  std::cout<<"Thread "<<std::this_thread::get_id()<< "Launch "<<n <<"Workers"<<std::endl;
  for(int i = 0; i < n;i++) {
    C(0,i);
  }
  }
class Runner {
 private:

  void A() {
    const int n = 10;
    std::vector<std::thread> tl;
    LOG_INFO("Launch %d thread",n);
    for(int i = 0; i < n; i++) {
      tl.emplace_back(B);
    }
    for(auto &t :tl) {
      t.join();
    }
  }
 public:
  void run() {
    A();
  }
};
TEST(PERF,T1) {
  Runner r;
  r.run();
}