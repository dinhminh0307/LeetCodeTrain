func mergeAlternately(word1 string, word2 string) string {
    str := "";
    // convert string to rune for indexing
    rune1 := []rune(word1);
    rune2 := []rune(word2);
    ptr1, ptr2 := 0,0; // assign multiple var
    for (ptr1 < len(rune1) && (ptr2 < len(rune2))) {
        str += string(rune1[ptr1]) + string(rune2[ptr2]);
        ptr1++;
        ptr2++;
    }
    for ptr1 < len(rune1) {
        str += string(rune1[ptr1]);
        ptr1++;
    }

    for ptr2 < len(rune2) {
        str += string(rune2[ptr2]);
        ptr2++;
    }
    return str
}