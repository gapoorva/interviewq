package interviewq

import (
	"testing"
)

func Comp(a interface{}, b interface{}) bool {
	int_a, ok_a := a.(int)
	int_b, ok_b := b.(int)
	return ok_a && ok_b && int_a < int_b
}

func TestTree(t *testing.T) {
	binT := NewBinaryTree(Comp)
	binT.Add(10)
	binT.Add(3)
	binT.Add(12)
	binT.Add(2)
	binT.Add(1)
	binT.PrintInOrder()

	if !binT.Exists(1) || binT.Exists(4) {
		t.Fail()
	}
}
