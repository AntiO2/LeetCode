package go_2824

import "testing"

func Test1(t *testing.T) {
	nums := []int{-1, 1, 2, 3, 1}
	target := 2
	ans := 3
	if a := countPairs(nums, target); a != ans {
		t.Errorf("get %d", a)
		return
	}
}

func Test2(t *testing.T) {

}
