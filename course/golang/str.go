package main

import "fmt"

type ListNode struct {
	Next *ListNode
	Val  int
}

func main() {
	var head *ListNode
	curr := &ListNode{}

	fmt.Printf("head: %x\n", &head)
	fmt.Printf("curr: %x\n", &curr)

	s := "hello"
	fmt.Printf("s: %s, %x %p\n", s, s, &s)
	// 深拷贝
	t := s[2:3]
	fmt.Printf("t: %s, %x %p\n", t, t, &t)
	s = "abc"
	fmt.Printf("s: %s, %x %p\n", s, s, &s)
	fmt.Printf("t: %s, %x %p\n", t, t, &t)

	x := []int{2, 3, 4, 5, 6}
	y := x[1:3]

	fmt.Printf("x: %v, %p\n", x, &x)
	fmt.Printf("y: %v, %p\n", y, &y)
}
