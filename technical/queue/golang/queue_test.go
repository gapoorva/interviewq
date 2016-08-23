package queue

import "testing"

func TestEmpty(t *testing.T) {
	q := &Queue{}
	if !q.Empty() {
		t.Fail()
	}
	_, front := q.PopFront()
	if front == nil {
		t.Fail()
	}
	_, back := q.PopBack()
	if back == nil {
		t.Fail()
	}
}

func TestFronts(t *testing.T) {
	q := &Queue{}
	if !q.Empty() {
		t.Fail()
	}
	q.PushFront(0)
	q.PushFront(1)
	q.PushFront(2)
	q.PushFront(3)
	three, _ := q.PopFront()
	if v, ok := three.(int); !ok || v != 3 {
		t.Fail()
	}
	two, _ := q.PopFront()
	if v, ok := two.(int); !ok || v != 2 {
		t.Fail()
	}
	one, _ := q.PopFront()
	if v, ok := one.(int); !ok || v != 1 {
		t.Fail()
	}
	zero, _ := q.PopFront()
	if v, ok := zero.(int); !ok || v != 0 {
		t.Fail()
	}
	if !q.Empty() {
		t.Fail()
	}
}

func TestBacks(t *testing.T) {
	q := &Queue{}
	if !q.Empty() {
		t.Fail()
	}
	q.PushBack(0)
	q.PushBack(1)
	q.PushBack(2)
	q.PushBack(3)
	three, _ := q.PopBack()
	if v, ok := three.(int); !ok || v != 3 {
		t.Fail()
	}
	two, _ := q.PopBack()
	if v, ok := two.(int); !ok || v != 2 {
		t.Fail()
	}
	one, _ := q.PopBack()
	if v, ok := one.(int); !ok || v != 1 {
		t.Fail()
	}
	zero, _ := q.PopBack()
	if v, ok := zero.(int); !ok || v != 0 {
		t.Fail()
	}
	if !q.Empty() {
		t.Fail()
	}
}

func TestFIFOFront(t *testing.T) {
	q := &Queue{}
	if !q.Empty() {
		t.Fail()
	}
	q.PushBack(0)
	q.PushBack(1)
	q.PushBack(2)
	q.PushBack(3)
	three, _ := q.PopFront()
	if v, ok := three.(int); !ok || v != 0 {
		t.Fail()
	}
	two, _ := q.PopFront()
	if v, ok := two.(int); !ok || v != 1 {
		t.Fail()
	}
	one, _ := q.PopFront()
	if v, ok := one.(int); !ok || v != 2 {
		t.Fail()
	}
	zero, _ := q.PopFront()
	if v, ok := zero.(int); !ok || v != 3 {
		t.Fail()
	}
	if !q.Empty() {
		t.Fail()
	}
}

func TestFIFOBack(t *testing.T) {
	q := &Queue{}
	if !q.Empty() {
		t.Fail()
	}
	q.PushFront(0)
	q.PushFront(1)
	q.PushFront(2)
	q.PushFront(3)
	three, _ := q.PopBack()
	if v, ok := three.(int); !ok || v != 0 {
		t.Fail()
	}
	two, _ := q.PopBack()
	if v, ok := two.(int); !ok || v != 1 {
		t.Fail()
	}
	one, _ := q.PopBack()
	if v, ok := one.(int); !ok || v != 2 {
		t.Fail()
	}
	zero, _ := q.PopBack()
	if v, ok := zero.(int); !ok || v != 3 {
		t.Fail()
	}
	if !q.Empty() {
		t.Fail()
	}
}
