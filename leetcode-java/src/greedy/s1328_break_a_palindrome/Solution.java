package greedy.s1328_break_a_palindrome;

class Solution {
    public String breakPalindrome(String palindrome) {
        int l = 0, r = palindrome.length() - 1;
        if (r == 0) {
            return "";
        }
        StringBuilder stringBuilder = new StringBuilder(palindrome);
        while (l < r) {
            if (palindrome.charAt(l) != 'a') {
                stringBuilder.setCharAt(l, 'a');
                break;
            }
            ++l;
            --r;
        }
        if (l >= r) {
            stringBuilder.setCharAt(palindrome.length() - 1, 'b');
        }

        return stringBuilder.toString();
    }
}