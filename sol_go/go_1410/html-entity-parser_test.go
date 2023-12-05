package go_1410

import (
	"fmt"
	"testing"
)

func Test1(t *testing.T) {
	text := "&amp; is an HTML entity but &ambassador; is not."
	ans := "& is an HTML entity but &ambassador; is not."
	if a := entityParser(text); a != ans {
		t.Error(a)
	}
}

func Test2(t *testing.T) {
	text := "and I quote: &quot;...&quot;"
	ans := "and I quote: \"...\""
	if a := entityParser(text); a != ans {
		t.Error(a)
	}
}

func Test3(t *testing.T) {
	a := make([]int, 5)
	for i, _ := range a {
		a[i] = i
	}
	b := a[0:3]
	b[2] = 5
	fmt.Printf("%v\n%v", a, b)
}
