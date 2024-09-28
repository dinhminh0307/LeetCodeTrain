package main

import "fmt"
func searchInsert(nums []int, target int) int {
	count := 0;
	expected := 0
	is_expected := false;
    for index, num := range nums {
		// fmt.Println(index);
		if target ==  num{
			fmt.Println("hit equal");
			break;
		}
		
		if target <= num && !is_expected{
			expected = index;
			fmt.Printf("hit smaller %v %v\n", expected, num);
			is_expected = true;
		}

		if target > nums[len(nums) - 1] { // if the target is greater than the greatest
			expected = len(nums);
			return expected;
		}
		if count == len(nums) - 1 { // if can not find the target, return the excpeted 
			// insert
			return expected;
		}
		count++;
	}
	return count;
}

func main() {
	nums := []int{3};
	fmt.Println(searchInsert(nums, 1));
}