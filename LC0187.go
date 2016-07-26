package main

import "fmt"

func t(c byte) int64 {
	switch c {
	case 'A':
		return 0
	case 'C':
		return 1
	case 'G':
		return 2
	case 'T':
		return 3
	}
	return 0
}
func findRepeatedDnaSequences(s string) []string {
	var result []string
	if len(s) < 10 {
		return result
	}
	m := make(map[string]int)
	m[s[0:10]] = 0
	for i := 10; i < len(s); i++ {
		tmp := s[i-9 : i+1]
		v, ok := m[tmp]
		if ok {
			if v == 0 {
				result = append(result, tmp)
			}
			m[tmp] = v + 1
		} else {
			m[tmp] = 0
		}
	}
	return result
}

func main() {
	fmt.Println(findRepeatedDnaSequences("AAAAAAAAAAAAAAAAAAAA"))
	fmt.Println(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
	fmt.Println(findRepeatedDnaSequences("CAAAAAAAAAC"))
}
