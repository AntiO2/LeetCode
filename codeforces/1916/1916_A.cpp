/**
 * @author Anti
 * @date 2023-12-30
 * @see https://codeforces.com/contest/1916/problem/A
 */


#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin>>t;
  // auto p = generatePrimes(2023);
  while(t--) {
    int n, k;
    std::cin>>n>>k;
    std::vector<int> b(n);
    for(int i = 0 ; i < n; i++) {
      std::cin>>b[i];
    }
    bool flag = true;
    std::vector<int> ans(k);
    int a  = 2023;
    for(auto&bi:b) {
      if(a%bi) {
        std::cout<<"NO"<<std::endl;
        flag = false;
      }
      if(!flag) {
        break ;
      }
      a/=bi;
    }
    if(!flag) {
      continue ;
    }
    std::cout<<"Yes"<<std::endl;
    std::cout<<a<<" ";
    for(int i = 1; i < k; i++) {
      std::cout<<"1 ";
    }
    std::cout<<std::endl;
  }
}