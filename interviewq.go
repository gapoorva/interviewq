package interviewq

import "fmt"

type Node struct {
	Left  *Node
	Right *Node
	Data  interface{}
}

func (n *Node) add(v interface{}, comp func(interface{}, interface{}) bool) {
	if n.Data == nil {
		*n = Node{Data: v}
	} else if comp(n.Data, v) {
		if n.Right == nil {
			n.Right = &Node{}
		}
		n.Right.add(v, comp)
	} else {
		if n.Left == nil {
			n.Left = &Node{}
		}
		n.Left.add(v, comp)
	}
}

func (n *Node) find(v interface{}, comp func(interface{}, interface{}) bool) *Node {
	if n == nil {
		return nil
	} else if !comp(n.Data, v) && !comp(v, n.Data) {
		return n
	} else if comp(n.Data, v) {
		return n.Right.find(v, comp)
	} else {
		return n.Left.find(v, comp)
	}

}

func (n *Node) inOrder() {
	if n != nil {
		n.Left.inOrder()
		fmt.Printf("%v ", n.Data)
		n.Right.inOrder()
	}
}

type BinaryTree struct {
	Root *Node
	Size int64
	Comp func(interface{}, interface{}) bool
}

func NewBinaryTree(Comp func(interface{}, interface{}) bool) *BinaryTree {
	return &BinaryTree{
		Root: nil,
		Comp: Comp,
	}
}

func (b *BinaryTree) Add(v interface{}) {
	if b.Root == nil {
		b.Root = &Node{Data: v}
	} else {
		b.Root.add(v, b.Comp)
	}
	b.Size++
}

func (b *BinaryTree) Exists(v interface{}) bool {
	if b.Root == nil {
		return false
	} else {
		return b.Root.find(v, b.Comp) != nil
	}
}

func (b *BinaryTree) PrintInOrder() {
	fmt.Print("[")
	b.Root.inOrder()
	fmt.Printf("] size: %d\n", b.Size)
}
