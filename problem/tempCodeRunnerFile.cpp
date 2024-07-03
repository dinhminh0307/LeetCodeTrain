string changeElement(string s, int idx_ptr, int char_idx)
    {
        s[idx_ptr] = 'A' + char_idx - 1;
        return s;
    }