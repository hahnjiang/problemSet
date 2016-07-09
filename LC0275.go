package main

import "fmt"

func hIndex(citations []int) int {
	start := 0
	end := len(citations) - 1
	for start <= end {
		mid := (start + end) >> 1
		if citations[mid] == len(citations)-mid {
			return len(citations) - mid
		} else if citations[mid] < len(citations)-mid {
			start = mid + 1
		} else {
			end = mid - 1
		}
	}
	return len(citations) - start
}

func main() {
	data := [5]int{0, 1, 3, 5, 6}
	fmt.Println(hIndex(data[:]))
}
