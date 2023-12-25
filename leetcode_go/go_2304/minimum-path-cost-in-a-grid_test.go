package go_2304

import "testing"

func Test1(t *testing.T) {
	grid := [][]int{{5, 3}, {4, 0}, {2, 1}}
	moveCost := [][]int{{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}}
	expectedResult := 17
	result := minPathCost(grid, moveCost)
	if result != expectedResult {
		t.Errorf("Expected %d, but got %d", expectedResult, result)
	}
}

func Test2(t *testing.T) {

}
