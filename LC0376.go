package main

import "fmt"

func sig(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	} else {
		return 0
	}
}

func wiggleMaxLength(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	var diff = make([]int, len(nums))
	for i := 1; i < len(nums); i++ {
		diff[i] = nums[i] - nums[i-1]
	}
	if diff[1] < 0 {
		for i := 1; i < len(diff); i++ {
			diff[i] = -diff[i]
		}
	}
	p := 0
	n := 0

	for i := 1; i < len(diff); i++ {
		if diff[i] > 0 && n >= p {
			p++
		} else if diff[i] < 0 && p > n {
			n++
		}
	}
	return p + n + 1
}

func main() {
	// data := [10]int{1, 17, 5, 10, 13, 15, 10, 5, 16, 8}
	// data := [6]int{1, 7, 4, 9, 2, 5}
	// data := [9]int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	data := [4]int{2, 1, 1, 3}
	fmt.Println(wiggleMaxLength(data[:]))
}
