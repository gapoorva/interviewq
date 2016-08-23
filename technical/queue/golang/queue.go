// package queue is a simple linked-list implementation of a queue. It doesn't garuntee thread safety
package queue

import (
	"errors"
	"fmt"
)

type Node struct {
	Data interface{}
	Next *Node
	Prev *Node
}

type Queue struct {
	Head *Node
	Tail *Node
}

func assert(b bool, info string) {
	if !b {
		fmt.Println("Assertion failed:", info)
	}
}

func (q *Queue) Empty() bool {
	return q.Head == nil && q.Head == q.Tail
}

func (q *Queue) PushFront(v interface{}) {
	if q.Empty() {
		q.Head = &Node{v, nil, nil}
		q.Tail = q.Head
	} else {
		q.Head = &Node{v, q.Head, nil}
		q.Head.Next.Prev = q.Head
	}
}

func (q *Queue) PushBack(v interface{}) {
	if q.Empty() {
		q.Head = &Node{v, nil, nil}
		q.Tail = q.Head
	} else {
		q.Tail = &Node{v, nil, q.Tail}
		q.Tail.Prev.Next = q.Tail
	}

}

func (q *Queue) PopFront() (interface{}, error) {
	if q.Empty() {
		return nil, errors.New("popped from empty queue")
	} else {
		data := q.Head.Data
		q.Head = q.Head.Next
		if q.Head != nil {
			q.Head.Prev = nil
		} else {
			q.Tail = q.Head
		}
		return data, nil
	}
}

func (q *Queue) PopBack() (interface{}, error) {
	if q.Empty() {
		return nil, errors.New("popped from empty queue")
	} else {
		data := q.Tail.Data
		q.Tail = q.Tail.Prev
		if q.Tail != nil {
			q.Tail.Next = nil
		} else {
			q.Head = q.Tail
		}
		return data, nil
	}
}
