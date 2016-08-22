package binarytree

import (
	"testing"
)

// run with `go test --coverage`

func Comp(a interface{}, b interface{}) bool {
	int_a, ok_a := a.(int)
	int_b, ok_b := b.(int)
	return ok_a && ok_b && int_a < int_b
}

func TestTree(t *testing.T) {
	binT := NewBinaryTree(Comp)

	if err := binT.Delete(30); err == nil {
		t.Error("didn't return delete error")
	}

	binT.Add(10)
	binT.Add(3)
	binT.Add(12)
	binT.Add(2)
	binT.Add(1)
	binT.PrintInOrder()

	if !binT.Exists(1) || binT.Exists(4) {
		t.Error("found 4 or didn't find 1")
	}

	binT.Delete(1)
	binT.PrintInOrder()

	binT.Delete(10)

	binT.PrintInOrder()

	if binT.Exists(1) || binT.Exists(10) {
		t.Error("found 10 or 1")
	}
}
