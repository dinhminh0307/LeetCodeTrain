func max(arr []int) int {
    max_val := arr[0];
    for i:=0; i < len(arr); i++ {
        if arr[i] >= max_val {
            max_val = arr[i];
        }
    }
    return max_val
}

func kidsWithCandies(candies []int, extraCandies int) []bool {
    curr_max := max(candies);
    res := make([] bool, 0); // create a slice base on the array, and init with 0 element
    for i := 0; i < len(candies); i++ {
        if  candies[i] + extraCandies >= curr_max {
            res = append(res, true);
        } else {
            res = append(res, false);
        }
    }
    return res;
}