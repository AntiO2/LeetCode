package go_2304

import "math"

func minPathCost(grid [][]int, moveCost [][]int) int {
	m := len(grid)
	n := len(grid[0])
	dp := make([]int, 0, n)
	dp = append(dp, grid[0]...) // 第一行的值
	for i := 0; i < m-1; i++ {
		tmp := make([]int, n)
		for j := 0; j < n; j++ {
			tmp[j] = math.MaxInt
		}
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				tmp[k] = min(tmp[k], dp[j]+grid[i+1][k]+moveCost[grid[i][j]][k])
			}
		}
		dp = tmp
	}
	ans := dp[0]
	for i := 1; i < n; i++ {
		ans = min(ans, dp[i])
	}
	return ans
}
