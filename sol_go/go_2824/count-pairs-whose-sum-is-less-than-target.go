package go_2824

func countPairs(nums []int, target int) int {
	l := len(nums)
	ans := 0
	for i, num := range nums {
		for j := i + 1; j < l; j++ {
			if num+nums[j] < target {
				ans++
			}
		}
	}
	return ans
}
