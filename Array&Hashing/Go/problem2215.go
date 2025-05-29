func findDifference(nums1 []int, nums2 []int) [][]int {
    m1 := map[int]int{};
    m2 := map[int]int{};

    new_nums1 := []int{};
    new_nums2 := []int{};
    res := make([][]int, 0)
    // update map to check nums1
    for i := 0; i < len(nums1); i++ {
        // check if a key-val exist in the map
        if _, exist := m1[nums1[i]]; !exist{
            m1[nums1[i]] = 1
            new_nums1 = append(new_nums1, nums1[i]); // remove duplicate
        }
    }
    // update map to check nums2
    for i := 0; i < len(nums2); i++ {
        // check if a key-val exist in the map
        if _, exist := m2[nums2[i]]; !exist{
            m2[nums2[i]] = 1
            new_nums2 = append(new_nums2, nums2[i]); // remove duplicate
        }
    }
    tmp1 := make([]int, 0);
    // now iterate each nums to check 
    for i := 0; i < len(new_nums1); i++ {
        if _, exist := m2[new_nums1[i]]; !exist {
            // ignore _ because we check the 
            tmp1 = append(tmp1, new_nums1[i]);
            // delete key val in map
            delete(m2, new_nums1[i]);
        }
        
    }

    tmp2 := make([]int, 0);
    // now iterate each nums to check 
    for i := 0; i < len(new_nums2); i++ {
        if _, exist := m1[new_nums2[i]]; !exist {
            tmp2 = append(tmp2, new_nums2[i]);
            delete(m1, new_nums2[i]);
        }
        
    }

    res = append(res, tmp1);
    res = append(res, tmp2);
    return res;
}