/**
 * @author Anti
 * @date 2023-12-30
 * @see https://codeforces.com/contest/1916/problem/B
 */

#include <iostream>
#include <vector>
#include <cstdio>
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int main() {
  int t;
  std::cin>>t;
  while(t--) {
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long ans;
    if(b%a==0) {
          printf("%lld\n",b/a*b);
    } else {
      printf("%lld\n",a/gcd(a,b)*b);
    }
  }
}