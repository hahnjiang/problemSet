package main

import "fmt"

func singleNumber(nums []int) int {
	x := 0
	for i := 0; i < len(nums); i++ {
		x = x ^ nums[i]
	}
	return x
}

func main() {
	fmt.Println(singleNumber([]int{1, 1, 2, 2, 3}))
	fmt.Println(singleNumber([]int{4, 5, 6, 5, 4}))
}
