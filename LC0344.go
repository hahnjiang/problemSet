package main

import (
	"bytes"
	"fmt"
)

func reverseString(s string) string {
	var buf bytes.Buffer
	for i := 0; i < len(s); i++ {
		buf.WriteString(string(s[len(s)-i-1]))
	}
	return buf.String()
}

func main() {
	fmt.Println(reverseString("Hello"))
}
