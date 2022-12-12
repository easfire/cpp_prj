package main

import "fmt"

func main() {
	c := make(chan int, 1)
	quit := make(chan int, 1)
	fibonacci(c, quit)
}

func fibonacci(c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case c <- x:
			x, y = y, x+y
		case quit <- y:
			x, y = x+y, y
		case <-quit:
			fmt.Println("quit", x, y)
			return
		case <-c:
			fmt.Println("c", x, y)
			return
		default:
			fmt.Println("default")
			return
		}
	}
}
