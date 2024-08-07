#include <iostream>
#include <bits/stdc++.h>

/*
Solution: use hash map <k,v> key: the character of string; value: is the frequency of that char.
          First we need to insert one string to that hash map; start by empty map then we increase the counter
          of value if we met that key again.
          Secondly, we compare with the second string and then decrease the value of each char if we finish comparing 1 char
*/

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> v;
        int counter = 0;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length();i++)
        {   
            int val = 1;
            auto it = v.find(s[i]);
            if(it != v.end())
            {

                it->second++;
            }
            else
            {
                v.insert({s[i], val});
            } 
        }


        for(int i = 0; i < t.length(); i++)
        {
            auto it = v.find(t[i]);
            // how to 
            if(it != v.end() && it->second > 0)
            {
                it->second--;
                counter++;
            }
        }

        if(counter == t.length())
        {
            return true;
        } 

        return false;
    }
};

int main(void)
{
    Solution sol;
    bool result = sol.isAnagram("aacc", "ccac");
    if(result)
    {
        cout << "True";
    } else 
    {
        cout << "False";
    }
}