package dynamic_programming.s132_palindrome_partitioning_ii;

import java.lang.reflect.Array;
import java.util.Arrays;

class Solution {
    public int minCut(String S) {
        char[] s = S.toCharArray();
        int n = s.length;

        int[][] palMemo = new int[n][n];
        for(int[] row: palMemo) {
            Arrays.fill(row, -1);
        }

        int[] f = new int[n];
        Arrays.fill(f, -1);
        return dfs(n  - 1, s, palMemo, f);
    }

    private int dfs(int r, char[] s, int[][] palMemo, int[] f) {
        if(isPalindrome(0,r, s, palMemo)) {
            return 0;
        }
        if(f[r] != -1) {
            return f[r];
        }
        int res = Integer.MAX_VALUE;
        for(int  l = 1; l <= r; l++) {
            if(isPalindrome(l, r, s, palMemo)) {
                res = Math.min(res, dfs(l - 1, s, palMemo, f) + 1);
            }
        }
        return f[r] = res;
    }

    private boolean isPalindrome(int l, int r, char[] s, int[][]palMemo) {
        if(l >= r) {
            return true ;
        }
        if(palMemo[l][r]!=-1) {
            return palMemo[l][r] == 1;
        }

        boolean res = s[l] == s[r] && isPalindrome(l + 1, r - 1, s, palMemo);
        palMemo[l][r] = res ? 1 : 0;
        return res;
    }
}
