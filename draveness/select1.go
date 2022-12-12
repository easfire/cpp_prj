package main

import "fmt"

func main() {
	ch := make(chan int, 1)
	ch <- 1

	select {
	case i := <-ch:
		fmt.Println(i)
		return
	default:
		fmt.Println("default")
	}
}
