package main

import "fmt"

func remove(slice []int, s int) []int {
    return append(slice[:s], slice[s+1:]...)
}

func removeDuplicates(nums []int) int {
	left := 0
	right := len(nums) - 1
    for left < right {
		// left_idx := left
		// right_idx := right
		length := len(nums)
		for left < length &&  nums[left] == nums[left + 1]  {
			
			nums = remove(nums, left + 1)
			length = len(nums)
			
			for nums[left] == nums[left +1] && left < length {
				nums = remove(nums, left + 1)
				length = len(nums)
			}
			right--
			left++
			if left == length - 1 {
				break;
			}
			// if right == 0 {
			// 	break;
			// }

		}
		fmt.Printf("Size: %v Index: %v\n", length, right)
		// for nums[right] == nums[right - 1] && right > 0 {
		// 	fmt.Println(nums)
		// 	fmt.Printf("%v %v Old Value: %v %v\n", left, left + 1, nums[left], nums[left + 1])
		// 	nums = remove(nums, right - 1)
		// 	length = len(nums)
		// 	fmt.Printf("%v %v Value: %v %v\n\n", left, left + 1, nums[left], nums[left + 1])
		// 	right--
		// 	// if right == 0 {
		// 	// 	break;
		// 	// }
		// }
		left++
		right--
	}
	return len(nums)
}

func main()  {
	test := []int{1,1}

	fmt.Println(removeDuplicates(test))
}