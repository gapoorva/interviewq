package rm_duplicates

import "testing"

func TestRemoveDuplicates(t *testing.T) {
	empty := []byte("")
	one := []byte("1")
	eleven := []byte("11")
	spec := []byte("aaadaccaddde")
	all := []byte("aaaaaaaaaaaa")
	unique := []byte("abcdefghijklmnop")

	if string(RemoveDuplicates(empty)[:]) != "" {
		t.Error()
	}
	if string(RemoveDuplicates(one)[:]) != "1" {
		t.Error()
	}
	if string(RemoveDuplicates(eleven)[:]) != "1" {
		t.Error()
	}
	if string(RemoveDuplicates(spec)[:]) != "adce" {
		t.Error()
	}
	if string(RemoveDuplicates(all)[:]) != "a" {
		t.Error()
	}
	if string(RemoveDuplicates(unique)[:]) != "abcdefghijklmnop" {
		t.Error()
	}
}
