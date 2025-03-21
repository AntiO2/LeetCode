package greedy.s2680_maximum_or;

class Solution {
    public long maximumOr(int[] nums, int k) {
        long ans = 0;
        long pre = 0;
        long fixed = 0;
        for(int num:nums) {
            fixed |= (pre & num);
            pre |= num;
        }

        for(int num: nums) {
            long withoutNum = (pre ^ num) | fixed;
            ans = Math.max(ans, withoutNum | ((long) num << k));
        }

        return ans;
    }
}