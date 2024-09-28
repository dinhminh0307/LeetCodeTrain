package main

import (
	"fmt"
)

// Solution struct
type Solution struct{}

// isAnagram function that checks if two strings are anagrams
func (s Solution) isAnagram(str1, str2 string) bool {
	// If lengths are not the same, they can't be anagrams
	if len(str1) != len(str2) {
		return false
	}

	// Create a frequency map
	freqMap := make(map[rune]int)

	// Increment the frequency for characters in str1
	for _, char := range str1 {
		freqMap[char]++
	}

	// Decrement the frequency for characters in str2
	for _, char := range str2 {
		if freqMap[char] > 0 {
			freqMap[char]--
		} else {
			return false
		}
	}

	// Check if all values in the frequency map are zero
	for _, count := range freqMap {
		if count != 0 {
			return false
		}
	}

	return true
}

func main() {
	sol := Solution{}
	result := sol.isAnagram("aacc", "ccac")
	if result {
		fmt.Println("True")
	} else {
		fmt.Println("False")
	}
}
