func find_max(nums[] int) int {
    max_num := nums[0]
    for _, val := range(nums) {
        if val >= max_num {
            max_num = val;
        }
    }
    return max_num
}

func kidsWithCandies(candies []int, extraCandies int) []bool {
    largest := find_max(candies);
    var res []bool;
    for _, val := range(candies) {
        if(val + extraCandies) >= largest {
            res = append(res, true);
        } else {
            res = append(res, false);
        }
    }
    return res;
}