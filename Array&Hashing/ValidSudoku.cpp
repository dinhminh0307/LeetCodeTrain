#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> tmp;
        // compare in row by row first
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                
                auto it = tmp.find(board[i][j]);
                if(it != tmp.end() && board[i][j] != '.')
                {
                    return false;
                } else {
                    tmp.insert(board[i][j]);
                }
            }
            tmp.clear();
        }

        // compare column by col
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                auto it = tmp.find(board[j][i]);
                if(it != tmp.end() && board[j][i] != '.')
                {
                    return false;
                } else {
                    tmp.insert(board[j][i]);
                }
            }
            tmp.clear();
        }


        unordered_map<int, unordered_set<char>> map;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;

                if(map[(i /3) * 3 + j/3].count(board[i][j]))
                {
                    return false;
                } else {
                    map[(i /3) * 3 + j/3].insert(board[i][j]);
                }

            }
        }

        return true;
    }
};

int main(void)
{
      vector<vector<char>> board = {
        {'.','.','.','.','.','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','1','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','.','4'},
        {'.','.','.','6','.','.','2','.','5'},
        {'7','.','.','.','.','4','.','.','6'},
        {'.','.','.','.','4','.','.','.','.'},
        {'.','.','.','.','.','9','.','.','.'},
        {'.','.','.','.','.','.','.','7','9'}
    };

    // vector<vector<char>> board = {
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','.','.','.','.'}
    // };
    Solution sol;
    if(sol.isValidSudoku(board))
    {
        cout << "valid";
    }
}
