#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        if(nums.size() == 1) return false;
        unordered_set<int> s; // using unoredered_set we can store key without concerning about the order
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]) != s.end()) // if has found nums[i], the find will equal to end
            {
                return true;
            }

            s.insert(nums[i]); // insert the not equal element to the unordered set
        }

        return false;
    }
};

int main(void)
{
    Solution sol;
    vector<int> v = {1,2,3,4, 1};
    if(sol.hasDuplicate(v))
    {
        cout <<"Has duplicate";
    } 
}

// CPP program to illustrate the 
// unordered_set::begin() function 

// #include <iostream> 
// #include <bits/stdc++.h>

// using namespace std; 

// int main() 
// { 

// 	unordered_set<int> sampleSet; 

// 	// Inserting elements in the std 
// 	sampleSet.insert(5); 
// 	sampleSet.insert(10); 
// 	sampleSet.insert(15); 
// 	sampleSet.insert(20); 
// 	sampleSet.insert(25); 

// 	auto itr1 = sampleSet.begin(); 
// 	auto itr2 = sampleSet.begin(1); 

// 	cout << "First element in the container is: " << *itr1; 
// 	cout << "\nFirst element in the bucket 4 is: " << *itr2; 

// 	return 0; 
// } 

