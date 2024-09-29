#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = {-1, -2, 3, -4, 5};
    ostringstream oss;

    sort(nums.begin(), nums.end());

    for(auto& it : nums)
    {
        cout << it << " ";
    }
    return 0;
}
