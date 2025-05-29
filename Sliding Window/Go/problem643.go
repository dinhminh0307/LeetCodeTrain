// using sliding window for prefix sum

func avr(arr []int, k int) float64 {
    var sum float64 = 0;

    for i := 0; i < len(arr); i++ {
        sum += float64(arr[i]);
    }
    return sum;
}

func findMaxAverage(nums []int, k int) float64 {
    // Initialize the prefix slice with the first k elements
    if k > len(nums) {
        return 0;
    }
    prefix := make([]int, k)
    copy(prefix, nums[:k])

    res := avr(prefix, k);
    

    max_res := res
    for i := 1; i <= len(nums); i++ {
        if i + k > len(nums) {
            break;
        }
        
        res = res - float64(nums[i - 1]) + float64(nums[i + k - 1]);
        if res >= max_res {
            max_res = res;
        }
    }
    return max_res / float64(k);
}