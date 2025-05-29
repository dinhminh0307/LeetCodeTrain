func uniqueOccurrences(arr []int) bool {
    m := map[int]int {};
    set := make(map[int]struct{});
    for i := 0; i < len(arr); i++ {
        if val, exist := m[arr[i]]; exist {
            occ := val;
            occ += 1;
            m[arr[i]] = occ;
        } else {
            m[arr[i]] = 1;
        }
    }

    // now iterate thru the map and put the occurence to the set, if find once, return false
    for _, v := range m {
        if _, exist := set[v]; exist {
            return false;
        } else {
            set[v] = struct{}{};
        }
    }
    return true;
}