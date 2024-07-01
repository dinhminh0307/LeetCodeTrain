#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long cnt = 0;

        if(divisor == 0) return NULL;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        {
            if(dividend < 0 && divisor < 0)
            {
                dividend = -dividend;
                divisor = -divisor;
            }
            long long old_divisor = divisor;
            while(divisor <= dividend)
            {
                cnt++;
                divisor = divisor + old_divisor;
            }
        }
        else if(dividend > 0 && divisor < 0)
        {
            long long abs_divisor = -divisor; // get the abs_divisor
            long long old_divisor = abs_divisor;
            while(abs_divisor <= dividend)
            {
                cnt++;
                abs_divisor = abs_divisor + old_divisor;
            }
            cnt = - cnt;
        } else if(dividend < 0 && divisor > 0)
        {
            long long abs_dividend = -dividend; // get the abs_divisor
            long long old_divisor = divisor;
            while(divisor <= abs_dividend)
            {
                cnt++;
                divisor = divisor + old_divisor;
            }
            cnt = - cnt;
        }
        return cnt;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.divide(1, 10);
}