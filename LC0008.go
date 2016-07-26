package main

import "fmt"

func myAtoi(str string) int {
	const INT_MAX = 2147483647
	const INT_MIN = -2147483648
	x := 0
	i := 0
	flag := 1
	for ; i < len(str) && str[i] == ' '; i++ {
	}
	if i == len(str) {
		return 0
	}
	if str[i] == '+' || str[i] == '-' {
		if str[i] == '-' {
			flag = -1
		}
		i++
	}
	for ; i < len(str) && '0' <= str[i] && str[i] <= '9'; i++ {
		x = x*10 + int(str[i]) - 48
		if x > INT_MAX {
			if flag > 0 {
				return INT_MAX
			} else {
				return INT_MIN
			}
		}
	}
	return x * flag
}

func main() {
	fmt.Println(myAtoi("1234"))
	fmt.Println(myAtoi("+-2"))
	fmt.Println(myAtoi(" -0012a42"))
	fmt.Println(myAtoi("2147483648"))
}
