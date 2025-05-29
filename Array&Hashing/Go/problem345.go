func reverseVowels(s string) string {
    
    set := map[byte]bool {
        'a': true,
        'e': true,
        'i': true,
        'o': true,
        'u': true,
    }
    res := make([] byte, 0);
    for i := len(s) - 1; i >= 0; i-- {
        if set[s[i]] || set[s[i] + 'a' - 'A'] {
            res = append(res, s[i]);
        }
    }

    tmp := []byte(s) // convert string to slice of rune
    // now iterate from beginning to replace each character to the element in the list
    for i := 0; i < len(tmp); i++ {
        if set[tmp[i]] || set[tmp[i] + 'a' - 'A'] {
            tmp[i] = res[0];
            // deque
            res = res[1:]
        }
    }
    // fmt.Println(res)
    s = string(tmp) // convert back to string
    return s
}