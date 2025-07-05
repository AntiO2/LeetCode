package top.antio2.string.s3340_check_balanced_string;

class Solution {
    public boolean isBalanced(String num) {
        int diff = 0, sign = 1;
        for(int i = 0; i < num.length(); ++i) {
            int d = num.charAt(i) - '0';
            diff += d* sign;
            sign *= -1;
        }
        return diff == 0;
    }
}