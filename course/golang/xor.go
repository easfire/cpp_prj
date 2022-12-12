package main

import "fmt"

func main() {
	x, y := 19, 21
	fmt.Printf("x: %b\n", x)
	fmt.Printf("y: %b\n", y)
	fmt.Println(x ^ y)
	fmt.Printf("xy: %b\n", x^y)
}
