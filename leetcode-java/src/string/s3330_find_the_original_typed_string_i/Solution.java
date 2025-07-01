package string.s3330_find_the_original_typed_string_i;

class Solution {
    public int possibleStringCount(String word) {
        int ans = 1;
        int cnt = 1;
        char prev = word.charAt(0);
        int idx= 1;
        for(; idx < word.length(); ++idx) {
            if(word.charAt(idx) == prev) {
                ++cnt;
            } else {
                ans += (cnt - 1);
                cnt = 1;
                prev = word.charAt(idx);
            }
        }
        ans+= (cnt - 1);
        return ans;
    }
}