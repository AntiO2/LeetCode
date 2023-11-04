/**
 * @author Anti
 * @date 2023/11/4
 * @see https://leetcode.cn/problems/word-search
 */

#include "fmt/core.h"
#include "gtest/gtest.h"
#include "logger.h"

class Solution {
 public:
  const int dx[4]{-1, 1, 0, 0}, dy[4]{0, 0, -1, 1};

 private:
  /**
   *
   * @param k 当前在寻找第k个字母
   * @param row
   * @param col
   * @param board
   * @param word
   * @return
   */
  bool search(int k, int row, int col,
              const std::vector<std::vector<char>>& board,
              const std::string& word, std::vector<std::vector<bool>>& book) {

    if (book[row][col]) {
      return false;
    }
    if (board[row][col] == word[k]) {
      if (k == word.length() - 1) {
        return true;
      }
      auto flag = false;
      book[row][col] = true;
      for (int d = 0; d < 4; ++d) {
        auto next_row = row + dx[d], next_col = col + dy[d];
        if (next_row < 0 || next_col < 0 || next_row >= board.size() ||
            next_col >= board[0].size()) {
          continue;
        }
        if (search(k + 1, next_row, next_col, board, word, book)) {
          flag = true;
          break;
        }
      }
      book[row][col] = false;
      return flag;
    } else {
      return false;
    }
  }

 public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    auto m = board.size();
    if (m == 0) {
      return false;
    }

    auto n = board.at(0).size();
    std::vector<std::vector<bool>> book(m, std::vector<bool>(n, false));
    for (auto i = 0; i < m; i++) {
      for (auto j = 0; j < n; j++) {
        if (search(0, i, j, board, word, book)) {
          return true;
        }
      }
    }
    return false;
  }
};

class Solution_Test {
 public:
  const int dx[4]{-1, 1, 0, 0}, dy[4]{0, 0, -1, 1};

 private:
  /**
   *
   * @param k 当前在寻找第k个字母
   * @param row
   * @param col
   * @param board
   * @param word
   * @return
   */
  bool search(int k, int row, int col, const std::vector<std::string>& board,
              const std::string& word, std::vector<std::vector<bool>>& book) {
    LOG_INFO("K:%d [%d][%d] = %c", k, row, col, board[row][col]);
    if (book[row][col]) {
      return false;
    }
    if (board[row][col] == word[k]) {
      if (k == word.length() - 1) {
        return true;
      }
      auto flag = false;
      book[row][col] = true;
      for (int d = 0; d < 4; ++d) {
        auto next_row = row + dx[d], next_col = col + dy[d];
        if (next_row < 0 || next_col < 0 || next_row >= board.size() ||
            next_col >= board[0].size()) {
          continue;
        }
        if (search(k + 1, next_row, next_col, board, word, book)) {
          flag = true;
          break;
        }
      }
      book[row][col] = false;
      return flag;
    } else {
      return false;
    }
  }

 public:
  bool exist(std::vector<std::string>& board, std::string word) {
    auto m = board.size();
    if (m == 0) {
      return false;
    }

    auto n = board.at(0).size();
    std::vector<std::vector<bool>> book(m, std::vector<bool>(n, false));
    for (auto i = 0; i < m; i++) {
      for (auto j = 0; j < n; j++) {
        if (search(0, i, j, board, word, book)) {
          return true;
        }
      }
    }
    return false;
  }
};

TEST(test79, SAMPLE1) {
  Solution_Test sol;
  std::vector<std::string> board{{"ABCE"}, {"SFCS"}, {"ADEE"}};
  std::string word = "ABCB";
  EXPECT_EQ(sol.exist(board, word), false);
}

TEST(test79, SAMPLE2) {
  Solution_Test sol;
  std::vector<std::string> board{{"ABCE"}, {"SFCS"}, {"ADEE"}};
  std::string word = "ABCCED";
  EXPECT_EQ(sol.exist(board, word), true);
}
TEST(test79, SAMPLE3) {
  Solution_Test sol;
  std::vector<std::string> board{{"ABCE"}, {"SFCS"}, {"ADEE"}};
  std::string word = "SEE";
  EXPECT_EQ(sol.exist(board, word), true);
}
TEST(test79, SAMPLE4) {
  Solution_Test sol;
  std::vector<std::string> board{"a"};
  std::string word = "a";
  EXPECT_EQ(sol.exist(board, word), true);
}
