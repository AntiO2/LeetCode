package array.s2642_row_with_maximum_ones;

class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int maxRow = 0, maxNum = 0;
        for(int i = 0; i < mat.length; ++i) {
            int cnt = 0;
            for(int a: mat[i]) {
                cnt+= a;
            }
            if(cnt > maxNum) {
                maxNum = cnt;
                maxRow = i;
            }
        }
        int[] ans = new int[2];
        ans[0] = maxRow;
        ans[1] = maxNum ;
        return ans;
    }
}