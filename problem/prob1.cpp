#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution 
{
    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        bool isFound = false;
        int index = 0;
        int j = 1;
        int i = 0;
        int cnt = 0;
        string result = "";

        if(strs.size() == 0) return result;
        if(strs.size() == 1 && strs[i] != "") return strs[i];

        while(!isFound)
        {
            if(j == strs.size() + 1) break;

            if(index == strs[i].length()) break; // if the character out of bounds

            if(strs[i] == "" || strs[j] == "") return ""; // if the string is empty, return false

            if(strs[i][index] == strs[j][index])
            {
                j++; // compare each character from one elemen to other
            }
            else
            {
                break;
            }

            if(j == strs.size())
            {
                result += strs[i][index];
                j = 1;
                index++;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution prob;
    vector<string> g1 = {"flower","flower","flower","flower"};
    cout << prob.longestCommonPrefix(g1);
}