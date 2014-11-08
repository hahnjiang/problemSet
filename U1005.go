package main

import (
	"fmt"
)

var res int
var w [20]int

func solve(idx int, l int, r int) {
	if idx == 0 {
		tmp := l - r
		if tmp < 0 {
			tmp = -tmp
		}
		if tmp < res {
			res = tmp
		}
		return
	}
	solve(idx-1, l+w[idx-1], r)
	solve(idx-1, l, r+w[idx-1])
}

func main() {
	var x int
	fmt.Scan(&x)
	sum := 0
	for i := 0; i < x; i++ {
		fmt.Scan(&w[i])
		sum += w[i]
	}
	res = sum
	solve(x, 0, 0)
	fmt.Printf("%d\n", res)
}
