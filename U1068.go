package main

import (
	"fmt"
)

func main() {
	var x int
	sum := 0
	fmt.Scan(&x)
	if x >= 1 {
		for i := 1; i <= x; i++ {
			sum += i
		}
	} else {
		for i := x; i <= 1; i++ {
			sum += i
		}
	}

	fmt.Printf("%d\n", sum)
}
