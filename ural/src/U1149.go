package main

import (
	"fmt"
)

func A(n int) {
	for i := 1; i <= n; i++ {
		if i > 1 && i%2 == 1 {
			fmt.Print("+")
		} else if i > 1 && i%2 == 0 {
			fmt.Print("-")
		}
		fmt.Printf("sin(%d", i)
	}
	for i := 1; i <= n; i++ {
		fmt.Printf(")")
	}
}

func S(n, i int) {
	if i == 1 {
		A(i)
	} else {
		fmt.Printf("(")
		S(n, i-1)
		fmt.Printf(")")
		A(i)
	}
	fmt.Printf("+%d", n-i+1)
}

func main() {
	var x int
	fmt.Scan(&x)
	S(x, x)
	fmt.Printf("\n")
}
