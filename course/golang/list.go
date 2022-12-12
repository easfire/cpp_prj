package main

import "fmt"

// 双向环形链表
// 为了方便向链表头尾增删节点
type Element struct {
	pre, next *Element

	list  *List
	value interface{}
}

type List struct {
	root Element
	len  int
}

func New() *List {
	return new(List).Init()
}

func (l *List) Len() int { return l.len }

func (l *List) Init() *List {
	l.root.next = &l.root
	l.root.pre = &l.root
	l.len = 0
	return l
}

func (l *List) lazyInit() {
	if l.root.next == nil {
		l.Init()
	}
}

// insert e after at
func (l *List) insert(e, at *Element) *Element {
	e.pre = at
	e.next = at.next
	e.pre.next = e
	e.next.pre = e

	e.list = l
	l.len++
	return e
}

// insert value after at
func (l *List) insertValue(v interface{}, at *Element) *Element {
	return l.insert(&Element{value: v}, at)
}

// push back
func (l *List) PushBack(v interface{}) *Element {
	l.lazyInit()
	// root.pre 为链表尾部
	return l.insertValue(v, l.root.pre)
}

// push front
func (l *List) PushFront(v interface{}) *Element {
	l.lazyInit()
	// root.next 为链表首位节点
	return l.insertValue(v, &l.root)
}

func (l *List) InsertAfter(v interface{}, mark *Element) *Element {
	if mark.list != l {
		return nil
	}
	return l.insertValue(v, mark)
}

func (l *List) InsertBefore(v interface{}, mark *Element) *Element {
	if mark.list != l {
		return nil
	}

	return l.insertValue(v, mark.pre)
}

func (l *List) Front() *Element {
	if l.len == 0 {
		return nil
	}
	return l.root.next
}

func (e *Element) Next() *Element {
	if p := e.next; e.list != nil && p != &e.list.root {
		return p
	}
	return nil
}

func (e *Element) Prev() *Element {
	if p := e.pre; e.list != nil && p != &e.list.root {
		return p
	}
	return nil
}

func main() {
	l := New()
	e1 := l.PushFront(1)
	e5 := l.PushBack(5)
	e2 := l.InsertAfter(2, e1)
	l.InsertBefore(4, e5)
	l.InsertAfter(3, e2)
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Println(e.value)
	}
}
