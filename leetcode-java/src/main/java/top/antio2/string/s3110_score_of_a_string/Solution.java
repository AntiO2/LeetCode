package top.antio2.string.s3110_score_of_a_string;

class Solution {
    public int scoreOfString(String s) {
        int ans = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            char now = s.charAt(i);
            char next = s.charAt(i + 1);
            ans+=Math.abs(now-next);
        }
        return ans;
    }
}