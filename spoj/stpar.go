package main

import "fmt"

var stack [1005]int
var top int

func main() {
	var n int
	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		var a [1005]int
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &a[i])
		}
		stack[0], top = 0, 1
		var goal, idx int
	JLoop:
		for goal, idx = 1, 0; goal <= n; {
			switch {
			case a[idx] == goal:
				idx++
				goal++
			case stack[top-1] == goal:
				goal++
				top--
			default:
				if idx == n {
					break JLoop
				}
				stack[top] = a[idx]
				top++
				idx++
			}
		}
		if goal == n+1 {
			fmt.Printf("yes\n")
		} else {
			fmt.Printf("no\n")
		}
	}
}
