package main

import "fmt"

func main() {
	a := []int{1, 6, 3, 5, 4}
	fmt.Println(bubbleSort(a))
}

func bubbleSort(a []int) []int {
	if len(a) <= 1 {
		return a
	}
	for i := 0; i < len(a); i++ {
		flag := false
		for j := 0; j < len(a)-i-1; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
				flag = true
			}
		}
		if !flag {
			break
		}
	}
	return a
}
