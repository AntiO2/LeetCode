//
// Created by Anti on 2023/9/1.
//
#include "gtest/gtest.h"

class Solution {
private:
    using word_list_t = std::vector<std::string>;
    std::unordered_map<std::string, word_list_t>words_map;
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {

        std::vector<word_list_t> ans;
        for (auto const &word: strs) {
            auto tmp_word = word;
            std::sort(tmp_word.begin(),tmp_word.end());
            words_map[tmp_word].emplace_back(word);
        }

        for(auto &aggregated_word:words_map) {
            ans.emplace_back(std::move(aggregated_word.second));
        }
        return ans;
    }
};