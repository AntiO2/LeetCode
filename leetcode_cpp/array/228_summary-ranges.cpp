#include <bits/stdc++.h>
class Solution {
 public:
  std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    std::vector<std::string> ans;
    if (nums.empty()) {
      return ans;
    }
    auto start_idx = 0;
    auto start_num = nums[0];
    auto last_num = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != last_num + 1) {
        auto end_idx = i - 1;
        if (start_idx == end_idx) {
          ans.emplace_back(std::to_string(start_num));
        } else {
          std::ostringstream os;
          os << start_num << "->" << last_num;
          ans.emplace_back(os.str());
        }
        start_idx = i;
        start_num = nums[i];
      }
      last_num = nums[i];
    }
    if (start_idx + 1 == nums.size()) {
      ans.emplace_back(std::to_string(*nums.rbegin()));
    } else {
      std::ostringstream os;
      os << start_num << "->" << last_num;
      ans.emplace_back(os.str());
    }
    return ans;
  }
};