package main

import (
	"fmt"
)

func lengthLongestPath(input string) int {
	result := 0
	dirNum := 0
	var dir []int
	isDir := true
	cur := 0
	input = input + "\n"
	for i := 0; i < len(input); i++ {
		switch input[i] {
		case 10:
			// fmt.Printf("%v\t%v\t%v\t%v\n", dirNum, isDir, cur, dir)
			tmp := cur
			if dirNum > 0 {
				tmp += dir[dirNum-1]
			}
			if isDir {
				if dirNum < len(dir) {
					dir[dirNum] = tmp + 1
				} else {
					dir = append(dir, tmp+1)
				}
			} else {
				if tmp > result {
					result = tmp
				}
			}
			isDir = true
			cur = 0
			dirNum = 0
		case 9:
			dirNum += 1
		case 46:
			isDir = false
			cur += 1
		default:
			cur += 1
		}
	}
	return result
}

func main() {
	fmt.Println(lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"))
	fmt.Println(lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"))
}
