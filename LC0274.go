package main

import "fmt"

func hIndex(citations []int) int {
	max := 0
	for i := 0; i < len(citations); i++ {
		if citations[i] > max {
			max = citations[i]
		}
	}
	var s = make([]int, max+1)
	for i := 0; i < len(citations); i++ {
		s[citations[i]]++
	}
	sum := 0
	for i := len(s) - 1; i >= 0; i-- {
		sum += s[i]
		if sum >= i {
			return i
		}
	}
	return 0
}

func main() {
	data := [5]int{3, 0, 6, 1, 5}
	fmt.Println(hIndex(data[:]))
}
