package reverse_c_style_string

import "testing"

func equal(a, b []byte, size int) bool {
	for i := 0; i < size; i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func TestReverse(t *testing.T) {
	empty := []byte("")
	empty = append(empty, byte(0)) // this makes it cstyle
	one := []byte("1")
	one = append(one, byte(0))
	even := []byte("even")
	even = append(even, byte(0))
	odd := []byte("odd")
	odd = append(odd, byte(0))
	extraNulls := []byte("extra")
	extraNulls = append(extraNulls, byte(0))
	extraNulls = append(extraNulls, byte(0))

	if !equal(Reverse(empty), []byte(""), 0) {
		t.Error()
	}
	if !equal(Reverse(one), []byte("1"), 1) {
		t.Error()
	}
	if !equal(Reverse(even), []byte("neve"), 4) {
		t.Error()
	}
	if !equal(Reverse(odd), []byte("ddo"), 3) {
		t.Error()
	}
	if !equal(Reverse(extraNulls), []byte("artxe"), 5) {
		t.Error()
	}
}
