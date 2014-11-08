package main

import (
	"fmt"
)

func main() {
	var x, n int
	var a [10]int
	fmt.Scan(&n)
	x = n
	for i := 9; i > 1; i-- {
		for n > 1 && n%i == 0 {
			n = n / i
			a[i]++
		}
	}
	if x == 0 {
		fmt.Printf("10\n")
	} else if n == 1 {
		if x == 1 {
			a[1] = 1
		}
		for i := 1; i <= 9; i++ {
			for j := 0; j < a[i]; j++ {
				fmt.Printf("%d", i)
			}
		}
		fmt.Printf("\n")
	} else {
		fmt.Printf("-1\n")
	}
}
