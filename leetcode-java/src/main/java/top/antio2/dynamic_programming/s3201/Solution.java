package top.antio2.dynamic_programming.s3201;

class Solution {
    public int maximumLength(int[] nums) {
        int cntOdd = 0;
        int cntEven = 0;
        int len = nums.length;
        int[][] dp = new int[len][2];
        
        if(nums[0] % 2 == 1) {
            dp[0][1] = 1;
            ++cntOdd;
        } else {
            dp[0][0] = 1;
            ++cntEven;
        }

        for(int i = 1 ; i < len; i++) {
            if(nums[i] % 2 == 1) {
                ++cntOdd;
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + 1);
            } else {
                ++cntEven;
                dp[i][1] = dp[i - 1][1];
                dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + 1);
            }
        }
        return Math.max(Math.max(cntEven, cntOdd), Math.max(dp[len - 1][0], dp[len - 1][1]));
    }
}
