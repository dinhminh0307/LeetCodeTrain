#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/**
 * Method: compare from the middle to chec the even substring. if s[i-1] == s[i+1], continue to expand until they not equal
 * then restore the right to current i and compare from i to i+1 to check the odd substring. for example: "cbbbbbc"
 * 
 * in the example above, the substring is bbbbb is check first, then at i = 2, it is bbb, i = 3, it is bbbbbb and then find 
 * until there is no longer substring palindrome
 */
class Solution {
public:
    string longestPalindrome(string s) {
        //cbaaabd
        int left = 0;
        int right = 0;
        int next = 0; 
        bool isEvenInLoop = false;
        bool isOddLoop = false;
        string max_string = string(1, s[0]);
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {

            if(i > 0  && i < s.length())
            {
                left = i - 1;
                if(i == s.length() - 1)
                {
                    break;
                }
                right = i + 1;
                next = right + 1;
                
            }

            string str = string(1, s[i]);
            // for "bab"
            while(s[left] == s[right] && left >= 0 && right < s.length())
            {
                if(i == 0){
                    break;
                }
                str = s[left] + str + s[right];

                isEvenInLoop = true; 
                left--;
                right++;
                if(right > s.length() - 1 || left < 0)
                {
                    break;
                }  
            }

            //for abba case
            //return the left and right value
            right = i;
            next = right + 1;
            string str2 = "";
            while(s[right] == s[next] && next <= s.length() - 1 && right >= 0)
            {
                str2 = string(1, s[right]) + str2 + string(1, s[next]);
                isOddLoop = true;
                if(right == 0 ||next == s.length() - 1)
                {
                    break;
                }
                right--;
                next++;
                // cout << right<< " " << next << endl;
            }

            if(isEvenInLoop || isOddLoop)
            {
                if(str.length() > max_string.length())
                {
                    max_string = str;
                }
                if(str2.length() >= max_string.length())
                {
                    max_string = str2;
                }
                isEvenInLoop = false;
                isOddLoop = false;
            }
        }


        return max_string;
    }
};

int main(void)
{
    Solution sol;
    string c = "accccccccccccccccccccccccccccccccccc";
    cout << sol.longestPalindrome(c);
}