package main

import "fmt"

func gcd(a int, b int) int {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func canMeasureWater(x int, y int, z int) bool {
	if z > x+y {
		return false
	}
	switch {
	case x == 0 && y == 0 && z == 0:
		return true
	case x == 0 && y == 0 && z != 0:
		return false
	case x == 0 && y != 0:
		return z%y == 0
	case x != 0 && y == 0:
		return z%x == 0
	}
	if z == 0 {
		return true
	}
	return z%gcd(x, y) == 0
}

func main() {
	fmt.Println(canMeasureWater(1, 1, 12))
	fmt.Println(canMeasureWater(0, 0, 1))
	fmt.Println(canMeasureWater(0, 0, 0))
	fmt.Println(canMeasureWater(3, 5, 4))
	fmt.Println(canMeasureWater(2, 6, 5))
}
