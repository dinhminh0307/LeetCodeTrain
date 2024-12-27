class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptr1 = 0; 
        int ptr2 = 0;
        string res = "";
        while(true) {
            if(ptr1 < word1.length()) {
                res += word1[ptr1];
                ptr1++;
            }
            if(ptr2 < word2.length()) {
                res += word2[ptr2];
                ptr2++;
            }
            if(ptr1 >= word1.length() && ptr2 >= word2.length()) {
                break;
            }
            
        }
        return res;
    }
};