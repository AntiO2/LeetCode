package sliding_window.s1456_maximum_number_of_vowels_in_a_substring_of_given_length;

class Solution {
    private boolean isVowel(char c) {
        return  c == 'a' || c== 'e' || c=='i' || c=='o' || c=='u';
    }
    public int maxVowels(String s, int k) {
        int ans = 0;
        int l = 0;
        int r = 0;
        for(; r < k; r++) {
            if(isVowel(s.charAt(r))) {
                ++ans;
            }
        }
        int now = ans;
        for(; r < s.length(); r++) {
            if(isVowel(s.charAt(l++))) {
                --now;
            }
            if(isVowel(s.charAt(r))) {
                ++now;
            }
            ans = Math.max(ans, now);
        }
        return ans;
    }
}