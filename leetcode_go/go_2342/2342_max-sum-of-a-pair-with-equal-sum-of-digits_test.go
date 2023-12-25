package go_2342

import (
	"sort"
	"testing"
)

func getNumSum(x int) int {
	sum := 0
	for x > 0 {
		sum += x % 10
		x /= 10
	}
	return sum
}

func maximumSum(nums []int) int {
	count := make(map[int][]int)
	for _, num := range nums {
		sum := getNumSum(num)
		_, ok := count[sum]
		if !ok {
			count[sum] = make([]int, 0)
		}
		count[sum] = append(count[sum], num)
	}
	ans := -1
	for _, list := range count {
		if len(list) <= 1 {
			continue
		}
		sort.Slice(list, func(i, j int) bool {
			return list[i] > list[j]
		})
		ans = max(ans, list[0]+list[1])
	}
	return ans
}

func Test_maximumSum(t *testing.T) {
	nums := []int{18, 43, 36, 13, 7}
	ans := 54
	if tmp := maximumSum(nums); tmp != ans {
		t.Errorf("%v %d!=%d", nums, tmp, ans)
	}
	nums = []int{229, 398, 269, 317, 420, 464, 491, 218, 439, 153, 482, 169, 411, 93, 147, 50, 347, 210, 251, 366, 401}
	ans = 973
	if tmp := maximumSum(nums); tmp != ans {
		t.Errorf("%v %d!=%d", nums, tmp, ans)
	}
}
