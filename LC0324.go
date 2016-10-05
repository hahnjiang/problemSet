package main

import "fmt"

func A(i int, n int) int {
	return (1 + 2*i) % (n | 1)
}
func findMedian(nums []int) int {
	var l = len(nums)
	if l%2 == 0 {
		return (find(nums, l/2, 0, l-1) + find(nums, l/2-1, 0, l-1)) / 2
	} else {
		return find(nums, l/2, 0, l-1)
	}
}
func find(nums []int, k int, s int, e int) int {
	if s >= e {
		return nums[s]
	}
	m := partition(nums, s, e)
	if m == k {
		return nums[m]
	} else if m < k {
		return find(nums, k, m+1, e)
	} else {
		return find(nums, k, s, m-1)
	}
}
func partition(nums []int, i int, j int) int {
	var pivot = nums[i]
	var m = i
	var n = i + 1
	for n <= j {
		if nums[n] < pivot {
			m += 1
			nums[m], nums[n] = nums[n], nums[m]
		}
		n += 1
	}
	nums[i], nums[m] = nums[m], nums[i]
	return m
}
func wiggleSort(nums []int) {
	n := len(nums)
	i := 0
	j := 0
	k := n - 1
	mid := findMedian(nums)
	for j <= k {
		if nums[A(j, n)] > mid {
			nums[A(i, n)], nums[A(j, n)] = nums[A(j, n)], nums[A(i, n)]
			i += 1
			j += 1
		} else if nums[A(j, n)] < mid {
			nums[A(j, n)], nums[A(k, n)] = nums[A(k, n)], nums[A(j, n)]
			k -= 1
		} else {
			j += 1
		}
	}
}

func main() {
	var list = []int{1, 1, 1, 1, 2, 2, 2}
	wiggleSort(list)
	fmt.Println(list)
}
