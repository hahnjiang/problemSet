package main

import (
	"container/list"
	"fmt"
	"math"
)

func main() {
	items := list.New()
	for {
		var x int64
		k, _ := fmt.Scan(&x)
		if k != 1 {
			break
		}
		items.PushFront(x)
	}
	for elem := items.Front(); elem != nil; elem = elem.Next() {
		fmt.Printf("%.4f\n", math.Sqrt(float64(elem.Value.(int64))))
	}
}
