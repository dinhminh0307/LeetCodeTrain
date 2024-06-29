/*https://leetcode.com/problems/string-to-integer-atoi/*/
#include <iostream>
#include <string.h>
#include <math.h>
#define UPPER_LIMIT (pow(2, 31) - 1)
#define DOWN_LIMIT -(pow(2, 31))

using namespace std;

class Solution 
{

public:

    int myAtoi(string s) 
    {
        //loop thr the string , skip blank
        bool isNumFound = false;
        bool isNegSignFound = false;
        bool isPlusSignFound = false;
        bool isSpaceFound = false;
        bool isFirstPlus = false;
        bool isFirstMinus = false;
        long long tmp = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if((isNegSignFound && s[i] == '-') || (isPlusSignFound && s[i] == '+')) return 0;

            if(s[i] == '+' && !isNumFound)
            {
                if(!isFirstPlus) isFirstPlus = true;
                isPlusSignFound = true;
                isSpaceFound = false;
            }
            if(s[i] == '-' && !isNumFound)
            {
                if(!isFirstMinus) isFirstMinus = true;
                isNegSignFound = true;
                isSpaceFound = false;
            }
            if(isNegSignFound && isPlusSignFound) return 0;
            if((isNegSignFound || isPlusSignFound) && s[i] == ' ') break; 
            // first non digit is skipped
            if(s[i] >= '0' && s[i] <= '9')
            {
                
                long num = s[i] - '0';
                if(tmp * 10 > INT_MAX) tmp = UPPER_LIMIT;
                tmp = tmp * 10 + num;
                isNumFound = true;
                isSpaceFound = false;
                isNegSignFound = false;
                isPlusSignFound = false;
            }
            else
            {
                if(!isNumFound && (s[i] != '-' && s[i] != ' ' && s[i] != '+'))
                {
                    return 0;
                }
                if(isNumFound)
                {
                    break;
                }
                isSpaceFound = true;
            }
        }
        if(isFirstMinus)
        {
            tmp = - tmp;
        }
        if(tmp > UPPER_LIMIT) tmp = UPPER_LIMIT;
        else if(tmp < DOWN_LIMIT) tmp = DOWN_LIMIT;
        
        return tmp;
    }
};

int main(void)
{
    Solution prob;
    cout << prob.myAtoi("-5-");
}