/**
 * https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> student_line;
        queue<int> sandwich_line;
        stack<int> res;

        for(int i = 0; i < students.size(); i++) {
            student_line.push(students[i]);
        }

        for(int i = 0; i < sandwiches.size(); i++) {
            sandwich_line.push(sandwiches[i]);
        }

        int atempt = 0;
        while(student_line.size() > 0 && atempt < student_line.size()) { // if attemp == student size it means that all the studebt
        //are given chance to re allignment the stack but not match to avoid looop

            if(student_line.front() == sandwich_line.front()) {
                student_line.pop();
                sandwich_line.pop();
                atempt = 0; // reset the attemp if match
            } else  {
                student_line.push(student_line.front());
                student_line.pop();
                atempt++; // every student is given a chance to go back to stack    
            }
        }


        return student_line.size();
    }
};

int main(void) {
    Solution sol;
    vector<int> student = {0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,1};
    vector<int> food = {1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0};
    sol.countStudents(student, food);
}