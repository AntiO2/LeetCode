/**
 * @author Anti
 * @date 2023-12-31
 * @see https://codeforces.com/contest/1916/problem/D
 */

#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

void solve();
int main() {
    int t;
    std::cin>>t;
    while(t--) {
        solve();
    }
    
}

void solve() {
    int n;
    std::cin>>n;
    if(n==1) {
      printf("1\n");
      return;
    }
    // 1  6  9    13
    // 1 6 9 0 0  130
    // 1 0 6 0 9  103
    for(int i = 0; i < n/2; i++) {
      std::stringstream s;
      s<<'1';
      for(int j = 0; j <i;j++) {
        s<<'0';
      }
      s<<'6';
      for(int j = 0; j <i;j++) {
        s<<'0';
      }
      s<<'9';
      for(int j = 0; j < n - 3 - i * 2;j++) {
        s<<'0';
      }
      std::string ans;
      s>>ans;
      std::cout<<ans<<std::endl;
    }
    // 9 6 1 31 ^2
    // 9 0 6 0 1     301
    for(int i = 0; i < n/2; i++) {
      std::stringstream s;
      s<<'9';
      for(int j = 0; j <i;j++) {
        s<<'0';
      }
      s<<'6';
      for(int j = 0; j <i;j++) {
        s<<'0';
      }
      s<<'1';
      for(int j = 0; j < n - 3 - i * 2;j++) {
        s<<'0';
      }
      std::string ans;
      s>>ans;
      std::cout<<ans<<std::endl;
    }

    // 1 9 6
    std::stringstream  s;
    s<<"196";
    for(int i = 0; i < n -3;i++) {
      s<<'0';
    }
    std::string ans;
    s>>ans;
    std::cout<<ans<<std::endl;
}