#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return nullptr;
        }

        TreeNode* res = root;
        while(true) {
            if(val == res->val) {
                return res;
            }

            if(val < res->val && res->left == nullptr) {
                break;
            } else if(val > res->val && res->right == nullptr) {
                break;
            }
            if(val < res->val) {
                res = res->left;
            } else if(val > res->val) {
                res = res->right;
            }
        }
        return nullptr;
    }
};