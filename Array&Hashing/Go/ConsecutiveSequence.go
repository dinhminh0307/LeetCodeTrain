package main

import (
	"fmt"
)

type Solution struct{}

func (s Solution) longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	// Create a set by using a map with unique keys
	numSet := make(map[int]struct{})
	for _, num := range nums {
		numSet[num] = struct{}{}
	}

	longestStreak := 0

	for num := range numSet {
		// Only check for the start of a sequence
		if _, exists := numSet[num-1]; !exists {
			currentNum := num
			currentStreak := 1

			// Find consecutive numbers
			for {
				_, exists := numSet[currentNum+1]
				if !exists {
					break
				}
				currentNum++
				currentStreak++
			}

			// Update the longest streak found
			if currentStreak > longestStreak {
				longestStreak = currentStreak
			}
		}
	}

	return longestStreak
}

func main() {
	sol := Solution{}
	test := []int{0, 3, 2, 5, 4, 6, 1, 1}
	result := sol.longestConsecutive(test)
	fmt.Println(result)
}
