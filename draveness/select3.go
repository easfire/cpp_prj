package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan int)
	go func() {
		time.Sleep(10 * time.Second)
		for range time.Tick(1 * time.Second) {
			ch <- 0
		}
	}()

	fmt.Println("start select")
	for {
		select {
		case <-ch:
			fmt.Println("case1")
		case <-ch:
			fmt.Println("case2")
		case <-ch:
			fmt.Println("case3")
		}
	}
	return
}
