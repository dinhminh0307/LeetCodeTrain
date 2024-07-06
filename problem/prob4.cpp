#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:

    string changeElement(string s, int idx_ptr, int char_idx)
    {
        s[idx_ptr] = 'A' + char_idx - 1;
        return s;
    }
    
    string convertToTitle(int columnNumber) {
        //ab, get the a number:
        string result = "AA";
        string old_result = result;
        
        int tmp = columnNumber;
        int ctr = 1;
        int index = 1;
        int i = 1;
        if(tmp == 0) return NULL;
        if(tmp <= 26) return result = ('A' + columnNumber - 1);

        while(tmp > 26)
        {
            tmp--;
            if(ctr >= 26)
            {
                ctr = 1;
                i++;
                if(i >= index)
                {
                    // add one more character to the end
                    result = old_result + "A";
                    old_result = result;
                    index++;
                    i = 1;
                }
            }
            // change every element inside the result
            result = changeElement(result, i, ctr);
            ctr++;
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    cout<<sol.convertToTitle(701);
}