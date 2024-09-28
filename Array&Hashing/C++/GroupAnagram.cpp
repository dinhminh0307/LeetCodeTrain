#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/*
The statement vector<int> count(12, 4); is written in C++ and is used to create and initialize a vector of integers. Here's a detailed explanation of what this statement does:

Components of the Statement
vector<int>:

This specifies that we are creating a vector (a dynamic array) that will hold elements of type int.
count:

This is the name of the vector being declared. In this context, count is the identifier for the vector object.
(12, 4):

This is the constructor for the vector that takes two arguments:
The first argument, 12, specifies the number of elements the vector should initially contain.
The second argument, 4, specifies the value to which each of these elements should be initialized.
*/


/*
Algorithm: to find the group of anagram we must following each step:
step1: count every character inside the string and store the count into a string distinguish by #  from a-z
for example, bddddddddddd, we have 1(b) and 10(d) so the string is #0#1#0#10#0#0...#0
step2: store that string as a key and the string that contain that sub string as value into a map
step3: find group of anagram in the map and group them into a vector then push to a vector
step 4: return this vector;
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> final_result;
        vector<string> char_freq_ctn;
        unordered_multimap<string, string> string_map;
        
        for(auto &my_string : strs)
        {
            vector<int> char_freq(26, 0); // 26 element, each element initalized value 0
            string ctn = "";
            for(char &c : my_string)
            {
                char_freq[c - 'a']++; //incerase the value of the char freq when count every character inside a string
            }

            for(auto it : char_freq)
            {
                ctn += "#" + to_string(it); // add "#" to distinguish 
            }
            char_freq_ctn.push_back(ctn);
            string_map.insert({ctn, my_string});
        }

        for(int i = 0; i < char_freq_ctn.size(); i++)
        {
            auto it = string_map.find(char_freq_ctn[i]);
            vector<string> temp_result;
            bool anagramFound = false;
            while(it != string_map.end()) // if find the anagram
            {
                anagramFound = true;
                temp_result.push_back(it->second); // group them and delete the anagram found
                string_map.erase(it);
                it = string_map.find(char_freq_ctn[i]);
            }
            if(anagramFound)
            {
                final_result.push_back(temp_result);
            }
        }
        return final_result;
    }
};

int main(void)
{
    Solution sol;
    vector<string> str = {"bdddddddddd","bbbbbbbbbbc"};
    vector<vector<string>> printV = sol.groupAnagrams(str);
    for(int i = 0; i < printV.size();i++)
    {
        cout << "vector " << to_string(i) << " : ";
        for(int j = 0; j < printV[i].size(); j++)
        {
            cout << printV[i][j] << " ";
        }
        cout << endl;
    }
}