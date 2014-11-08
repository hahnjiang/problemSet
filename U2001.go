package main

import (
	"fmt"
)

func main() {
	var a1, a2, a3, b1, b2, b3 int
	fmt.Scan(&a1, &b1)
	fmt.Scan(&a2, &b2)
	fmt.Scan(&a3, &b3)
	fmt.Printf("%d %d\n", a1-a3, b1-b2)
}
