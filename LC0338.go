package main

import "fmt"

func countBits(num int) []int {
	var count []int
	count = append(count, 0)
	if num == 0 {
		return count
	}
	count = append(count, 1)
	for idx := 2; idx <= num; idx++ {
		var s = idx
		for ; idx < (s<<1) && idx <= num; idx++ {
			count = append(count, count[idx-s]+1)
		}
		idx--
	}
	return count
}

func main() {
	var res = countBits(5)
	for i := 0; i < len(res); i++ {
		fmt.Println(res[i])
	}
}
