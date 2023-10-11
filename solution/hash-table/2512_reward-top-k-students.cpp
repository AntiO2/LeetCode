//
// Created by Anti
//
#include "fmt/core.h"
#include "logger.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k) {
        unordered_set pos(positive_feedback.begin(), positive_feedback.end()), neg(negative_feedback.begin(), negative_feedback.end());
        vector score(student_id.size(), 0ll);
        ranges::transform(
                report, student_id, score.begin(), [](long long sc, unsigned id) { return -(sc << 32 | id); }, [&](auto &&s) { istringstream ss(s);
                return accumulate(istream_iterator<string>(ss), {}, 0l
                            , [&](auto a, auto&& s) { return a + pos.count(s) * 3 - neg.count(s); }); }, negate{});
        ranges::partial_sort(score, score.begin() + k);
        return {score.begin(), score.begin() + k};
    }
};
TEST(test2512, SAMPLE1) {
    Solution s;
    vector<string> positive_feedback{"smart", "brilliant", "studious"};
    vector<string> negative_feedback{"not"};
    vector<string> report{"this student is studious", "the student is smart"};
    vector student_id{1, 2};
    int k = 2;
    vector ans{1, 2};
    EXPECT_EQ(s.topStudents(positive_feedback, negative_feedback, report, student_id, k), ans);
}

TEST(test2512, SAMPLE3) {
    string s = "this student is studious";
    istringstream ss(s);
    std::for_each(istream_iterator<string>(ss), {}, [](auto &s) {
        cout << s << endl;
    });
}
