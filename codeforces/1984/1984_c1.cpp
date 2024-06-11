#include <iostream>
#include <algorithm>
void solve();

int main() {
    int t;
    std::cin>>t;
    while(t--) {
        solve();
    }
}


void solve() {
    int n = 0;
    std::cin >> n;
    long long max{0}, min{0};
    for(int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        max = std::max(std::abs(max + a), std::abs(min + a));
        min = min + a;
    }
    std::cout << std::max(max, std::abs(min)) << std::endl;
}