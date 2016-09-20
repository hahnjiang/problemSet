package main

import "fmt"

func cal(x int) int {
	s := 0
	for ; x > 0; x = x >> 1 {
		s = s + (x & 1)
	}
	return s
}
func readBinaryWatch(num int) []string {
	var result []string
	for hour := 0; hour < 12; hour++ {
		for minute := 0; minute < 60; minute++ {
			if cal(hour)+cal(minute) == num {
				result = append(result, fmt.Sprintf("%d:%02d", hour, minute))
			}
		}
	}
	return result
}
func main() {
	fmt.Println(readBinaryWatch(1))
	fmt.Println(readBinaryWatch(2))
	fmt.Println(readBinaryWatch(3))
	fmt.Println(readBinaryWatch(4))
	fmt.Println(readBinaryWatch(5))
	fmt.Println(readBinaryWatch(6))
	fmt.Println(readBinaryWatch(7))
	fmt.Println(readBinaryWatch(8))
	fmt.Println(readBinaryWatch(9))
	fmt.Println(readBinaryWatch(10))
}
