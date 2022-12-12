package main

import "fmt"

func main() {

	slice := []int{1, 2, 3, 4, 5}
	//slice := []int{3}
	fmt.Println(sortList(slice, false))
}

// 顺序 sort = true
func sortList(list []int, turn bool) bool {
	if len(list) <= 1 {
		return true
	}
	for _, v := range list[1:] {
		if (turn && list[0] > v) || (!turn && list[0] < v) {
			return false
		}
		list = list[1:]
	}
	return true
}
