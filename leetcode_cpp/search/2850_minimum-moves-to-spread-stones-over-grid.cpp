#include <iostream>
#include <vector>
#include <queue>
class Solution {
public:
    int minimumMoves(std::vector<std::vector<int>>& grid) {
      auto n = grid.size();
      auto m = grid[0].size();
      using pos = std::pair<int, int>;
      using dist = int;
      int ans = 0;
      std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto& num = grid[i][j];
            if(num != 0) {
                continue;
            }
            std::queue<std::pair<pos, dist>> search;
            std::vector<std::vector<bool>> book(n, std::vector<bool>(m, false));
            book[i][j] = 1;
            search.emplace(std::make_pair(i, j), 0);
            while(!search.empty()) {
              auto now_i = search.front().first.first;
              auto now_j = search.front().first.second;
              auto dis = search.front().second;
              auto& dest = grid[now_i][now_j];
              std::cerr << now_i << "\t" << now_j << "\t" << dis << "\t" << dest << std::endl;
              search.pop();

              if(dest > 1) {
                dest--;
                grid[i][j] = 1;
                ans += dis;
                break;
              }
              for (auto& direction : directions) {
                auto next_i = now_i + direction.first;
                auto next_j = now_j + direction.second;
                if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m ||
                    book[next_i][next_j]) {
                  continue;
                }
                std::cout << next_i << "\t" << next_j << std::endl;
                book[next_i][next_j] = true;
                search.emplace(
                std::make_pair(std::make_pair(next_i, next_j), dis + 1));
              }
            }
        }
      }
      return ans;
    }
};

int main() {
  Solution s;
     std::vector<std::vector<int>> vec = {  
        {3, 2, 0},  
        {0, 1, 0},  
        {0, 3, 0}  
    };
     std::cout << s.minimumMoves(vec) << std::endl;
}