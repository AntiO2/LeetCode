//
// Created by Anti on 2023/9/28.
//
#include <list>

#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <bitset>
using board_t = std::vector<std::vector<char>>;


class Solution {

private:
    //用于判断在3*3方块内是否已有该数字，used[i][j]表示第i个3*3方块中是否已经有数字j+1
    // bool block_used[9][9]{};
    std::bitset<9> block_used[9];
    //  row_used[i][j] 第i行是否存在数字j+1
    // bool row_used[9][9]{};
    std::bitset<9> row_used[9];
    // col_used[i][j] 第i列是否存在数字j+1
    // bool col_used[9][9]{};
    std::bitset<9> col_used[9];
    //统计有多少个待填充的位置
    int num = 0;
    //已经填充了多少个位置
    int count = 0;

public:
    void solveSudoku(board_t &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') num++;
                else {
                    block_used[3 * (i / 3) + j / 3][ch - '1'] = true;
                    row_used[i][ch - '1'] = true;
                    col_used[j][ch - '1'] = true;
                }
            }
        }
        backtracking(board, 0, 0);
    }

    // 判断是否合法
private:
    inline bool isValid(const board_t &board, char ch, int row, int col) {

        // 判断九宫格，行列是否使用过
        if (block_used[3 * (row / 3) + col / 3][ch - '1'] ||
            row_used[row][ch - '1'] ||
            col_used[col][ch - '1']) {
            return false;
        }
        return true;
    }

    bool backtracking(board_t &board, int row, int col) {
        if (count == num) {
            return true;
        }
        if (row == 9 || col == 9) {
            return false;
        }
        int j = col;
        for (int i = row; i < 9; ++i) {
            for (; j < 9; ++j) {
                //如果已经填充，跳过
                if (board[i][j] != '.') continue;
                //1-9逐个尝试
                for (char k = '1'; k <= '9'; ++k) {
                    //如果合法，尝试填充
                    if (isValid(board, k, i, j)) {
                        //填充
                        board[i][j] = k;
                        //在对应的3*3方块中标记该数字
                        block_used[3 * (i / 3) + j / 3][k - '1'] = true;
                        row_used[i][k - '1'] = true;
                        col_used[j][k - '1'] = true;
                        //增加计数
                        ++count;
                        // printBoard(board);
                        if (backtracking(board, i, j)) {
                            return true;
                        }
                        //回溯
                        --count;
                        block_used[3 * (i / 3) + j / 3][k - '1'] = false;
                        row_used[i][k - '1'] = false;
                        col_used[j][k - '1'] = false;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
            j = 0;
        }
        return true;
    }
};

TEST(test37, SAMPLE1) {
    Solution s;
    auto b = board_t{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    s.solveSudoku(b);
    auto ans = board_t{
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    EXPECT_EQ(b, ans);
}
TEST(test37, SAMPLE2) {
    Solution s;
    auto b = board_t{
            {'.', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '.', '5', '6', '7'},
            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    s.solveSudoku(b);
    auto ans = board_t{
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    EXPECT_EQ(b, ans);
}
auto boardToString(const board_t &b) -> std::string {
    std::string s = "\n";
    for (auto &row: b) {
        for (auto &c: row) {
            s += c;
            s += " ";
        }
        s += "\n";
    }
    return s;
}
auto printBoard(const board_t &b) {
    LOG_INFO("%s", boardToString(b).c_str());
}