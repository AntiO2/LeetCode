package go_1410

import "testing"

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
