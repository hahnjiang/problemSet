package main

import "fmt"

func majorityElement(nums []int) []int {
	var m = make(map[int]int)
	for i := 0; i < len(nums); i++ {
		val, ok := m[nums[i]]
		if ok {
			m[nums[i]] = val + 1
		} else {
			m[nums[i]] = 1
			if len(m) == 3 {
				var tmp = make(map[int]int)
				for k, v := range m {
					if v-1 > 0 {
						tmp[k] = v - 1
					}
				}
				m = tmp
			}
		}
	}
	var result []int
	for k, _ := range m {
		s := 0
		for i := 0; i < len(nums); i++ {
			if nums[i] == k {
				s++
			}
		}
		if s > len(nums)/3 {
			result = append(result, k)
		}
	}
	return result
}

func main() {
	fmt.Println(majorityElement([]int{3, 4, 5, 3}))
	fmt.Println(majorityElement([]int{3, 2, 3}))
}
