/**
 * @author Anti
 * @date 2023-12-30
 * @see https://codeforces.com/contest/1916/problem/C
 */

#include <cstdio>
#include <iostream>
#include <vector>
constexpr int max_num = 1e5+5;
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    scanf("%d",&n);

    int odd = 0;
    long long prev = 0;
    for(int i = 0; i < n;i++) {
      int d;
      scanf("%d",&d);
      if(d%2) {
        odd++;
        prev += (d-1);
      } else {
        prev += d;
      }
      int even = i + 1 - odd; // 0
      int d_odd = odd;
      int ex = 0;
      // M : odd -=2 ex + 1
      // Olya: odd -=1 (even>=1)

      // All : even -=2
      if(odd>=3) {
        // 1 1 1
        // 2 1
        // 2
        ex = odd/3;
        d_odd%=3;
        even+=ex;
      }
      // 0 1 2
      // 0 1
      long long ans = prev + ex*2;
      if(d_odd==2) {
        // 1 1
        ans+=2;
      }
      if(d_odd==1&&even==0) {
        ans+=1;
      }
      printf("%lld ",ans);
    }
    printf("\n");
  }
}