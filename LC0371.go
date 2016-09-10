package main

import "fmt"

func getSum(a int, b int) int {
	carry := 0
	for b != 0 {
		carry = a & b
		a = a ^ b
		b = carry << 1
	}
	return a
}

func main() {
	fmt.Println(getSum(1, 2))
	fmt.Println(getSum(123, 987))
}
