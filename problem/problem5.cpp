#include <iostream>
#include <string.h>
#include <map>
#include <vector>

using namespace std;



class Solution {
public:
    map<string, string> my_map;

    map<string, string> addToMap(map<string, string> mp)
    {
        mp["2"] = "abc";
        mp["3"] = "def";
        mp["4"] = "ghi";
        mp["5"] = "jkl";
        mp["6"] = "mno";
        mp["7"] = "pqrs";
        mp["8"] = "tuv";
        mp["9"] = "wxyz";
        return mp;
    }

    /**
     * @brief function to find the value of the corresponding key
     */
    string find_val(map<string, string> mp, string c)
    {
        map<string, string>::iterator it = mp.begin();
        while (it != mp.end()) 
        {
            if(it->first == c) return it->second;
            ++it;
        }
    }

    vector<string> compareString(string str1, vector<string> temp)
    {
        string res = "";
        int index = 0;
        vector<string> final_result;
        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = 0; j < str1.length(); j++)
            {
                res = res + temp[i] + str1[j];
                
                final_result.insert(final_result.begin() + index, res);
                res = ""; // reset res
                index++;
            }
        }
        return final_result;
    } 

    vector<string> letterCombinations(string digits) 
    {
        map<string, string> mp;
        vector<string> temp_result;
        vector<string> result;
        my_map = addToMap(mp);
        string char_to_string = "";

        // extract every element inside the string
        
        //assign the first value to match with other first
        int idx = 0;
        string first_element = find_val(my_map, char_to_string + digits[0]);
        // add to the temp_result
        for(int i = 0; i < first_element.length(); i++)
        {
            string val_to_pass = first_element[i] + char_to_string;
            temp_result.insert(temp_result.begin() + i, val_to_pass);
        }

        // the loop from the rest to the end, add  element by element and the store to result loop by loop
        while(idx < digits.length())
        {
            idx++;
            // find the sequence string match with that digits
            string next_tmp_val = find_val(my_map, char_to_string + digits[idx]);
            temp_result = compareString(next_tmp_val, temp_result);
            for(int i = 0; i < temp_result.size(); i++)
            {
                cout << temp_result[i] << endl;
            }
        }
        return temp_result;
    }
};

int main(void)
{
    Solution sol;
    // sol.letterCombinations("hello");

    // Get an iterator pointing to the first element in the
    // map
    // map<string, string> ctn;
    // // map<string, string> temp = sol.addToMap(ctn);

    // string a = "2";
    // cout << sol.find_val(temp, a);
    vector<string> test =  sol.letterCombinations("234");
    // for(int i = 0; i < test.size() - 1; i++)
    // {
    //     cout<< test[i] << endl;
    // }
}