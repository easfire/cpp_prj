package main

import "fmt"

func main() {
	fmt.Println("vim-go")
	ch := make(chan int, 1)
	ch <- 1
	a := <-ch
	fmt.Println(a)
}
