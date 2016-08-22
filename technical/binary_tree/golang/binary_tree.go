// binarytree implements a binary tree data structure in golang that supports the Add, Delete, Exists, and Print
// functionality of a binary tree of arbitrary type.

// DELETES ARE A WORK IN PROGRESS
package binarytree

import (
	"errors"
	"fmt"
)

type Node struct {
	Left  *Node
	Right *Node
	Data  interface{}
}

// helper functionality on node
func (n *Node) add(v interface{}, comp func(interface{}, interface{}) bool) {
	if n.Data == nil {
		// if this node has nil data, allocate a node to it
		*n = Node{Data: v}
	} else if comp(n.Data, v) { // decide on where to insert.
		if n.Right == nil {
			n.Right = &Node{}
		}
		n.Right.add(v, comp)
	} else if comp(v, n.Data) {
		if n.Left == nil {
			n.Left = &Node{}
		}
		n.Left.add(v, comp)
	}
}

// helper functionality on node
func (n *Node) find(v interface{}, comp func(interface{}, interface{}) bool) *Node {
	// check current node first (root)
	if n != nil && (!comp(n.Data, v) && !comp(v, n.Data)) {
		return n
	}
	parent, me := n.findParent(v, comp)
	if parent == nil {
		return parent
	}
	return me
}

// helper functionality on node
// findParent returns nil if the node doesn't exist
// or is the root of the tree and has no parent
func (n *Node) findParent(v interface{}, comp func(interface{}, interface{}) bool) (*Node, *Node) {
	if n == nil || (n.Right == nil && n.Left == nil) { // nil pointer or no children
		return nil, nil
	}
	// compare against the current node to find which child the node is
	if n.Right != nil && (!comp(n.Right.Data, v) && !comp(v, n.Right.Data)) {
		return n, n.Right
	} else if n.Left != nil && (!comp(n.Left.Data, v) && !comp(v, n.Left.Data)) {
		return n, n.Left
	} else {
		// n is not the parent of node v, continue searching
		if comp(n.Data, v) {
			return n.Right.findParent(v, comp)
		} else {
			return n.Left.findParent(v, comp)
		}
	}
}

//helper functionality on node 
func (n *Node) findMax() *Node {
	if n.Right == nil {
		return n
	} else {
		return n.Right.findMax()
	}
}

//helper functionality on node
func (n *Node) findMin() *Node {
	if n.Left == nil {
		return n
	} else {
		return n.Left.findMin()
	}
}


//helper functionality on node
func (n *Node) inOrder() {
	if n != nil {
		n.Left.inOrder()
		fmt.Printf("%v ", n.Data)
		n.Right.inOrder()
	}
}

func (n *Node) deleteNode(v interface{}, comp func(interface{}, interface{}) bool, root *Node) error {
	if n == nil {
		return errors.New("trying to delete nil node")
	}
	if comp(n.Data, v) {
		return n.Right.deleteNode(v, comp)
	} else if comp(v, n.Data) {
		return n.Left.deleteNode( v, comp)
	} else { // delete the node here
		parent := 
		if n.Left == nil && n.Right == nil {

		}
	}
}

// helper functionality on node
func (n *Node) deleteChild(child *Node) error {
	if n != nil {
		if n.Left == child {
			n.Left = nil
		} else if n.Right == child {
			n.Right = nil
		} else {
			return errors.New("tried to delete with non child!")
		}
	}
}

// helper functionality on node
func (n *Node) replaceChild(child *Node, replace *Node) error {
	if n != nil {
		if n.Left == child {
			n.Left = replace
		} else if n.Right == child {
			n.Right = replace
		} else {
			return errors.New("tried to replace a non child!")
		}
	}
}

// helper functionality on node
func (n *Node) inOrderPredecesor() *Node {
	return n.Left.findMax()
}

// helper functionality on node
func (n *Node) inOrderSucessor() *Node {
	return n.Right.findMax()
}

type BinaryTree struct {
	Root *Node
	Size int64
	Comp func(interface{}, interface{}) bool
}

func NewBinaryTree(Comp func(interface{}, interface{}) bool) *BinaryTree {
	return &BinaryTree{
		Root: nil,
		Comp: Comp, //custom comparator - no operator overloading in golang
	}
}

// Add a value to the tree
func (b *BinaryTree) Add(v interface{}) {
	if b.Root == nil {
		b.Root = &Node{Data: v}
	} else {
		b.Root.add(v, b.Comp)
	}
	b.Size++
}

// Follows the binary tree property of the tree to check for the existence of
// a value in Log(N) time. Returns true if the item exists
func (b *BinaryTree) Exists(v interface{}) bool {
	if b.Root == nil {
		return false
	} else {
		return b.Root.find(v, b.Comp) != nil
	}
}

// Print an in-order Traversal of the tree
func (b *BinaryTree) PrintInOrder() {
	fmt.Print("[")
	b.Root.inOrder()
	fmt.Printf("] size: %d\n", b.Size)
}

// Delete a value from the tree, deleting a value that doesn't exist is valid.
// Deleting from an empty tree should cause an error.
func (b *BinaryTree) Delete(v interface{}) error {
	if b == nil || b.Size == 0 {
		return errors.New("attempted to delete from empty tree")
	}
	var toDelete *Node
	// check root
	if !b.Comp(b.Root.Data, v) && !b.Comp(v, b.Root.Data) {
		// root is the node to delete
		
		if b.Root.Left == nil && b.Root.Right == nil {
			b.Root = nil
			return nil
		} else if b.Root.Left == nil && b.Root.Right != nil {
			b.Root = b.Root.Right
			return nil
		} else if b.Root.Right == nil && b.Root.Left != nil {
			b.Root = b.Root.Left
			return nil
		} 
		// last case is both are null and delete is more complex
		toDelete = b.Root

	} else if parent, victim := b.Root.findParent(v, b.Comp); parent != nil {
		if victim.Left == nil && victim.Right == nil {
			if err := parent.deleteChild(victim); err != nil{
				return err
			}
		} else if victim.Left == nil && victim.Right != nil {
			if err := parent.replaceChild(victim, victim.Right); err != nil {
				return err
			}
		} else if victim.Right == nil && victim.Left != nil {
			if err := parent.replaceChild(victim, victim.Left); err != nil {
				return err
			}
		}
		// last case is both are null and delete is more complex
		toDelete = victim

	}

	for toDelete != nil {
		if toDelete.Left == nil && toDelete.Right == nil
	}

	if successor := toDelete.inOrderSucessor(); successor != nil {
		toDelete.Data = successor.Data // copy over data

	}



	b.Size--
	return nil
}
