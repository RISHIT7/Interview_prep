#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        vector<int> temp_res;
        queue<TreeNode*> Q;
        Q.push(root);
        res.push_back(vector<int>{root->val});
        Q.push(NULL);

        while (!Q.empty())
        {
            TreeNode* temp = Q.front();
            Q.pop();
            if (temp!= NULL) {
                if (temp->left) {
                    temp_res.push_back(temp->left->val);
                    Q.push(temp->left);
                }
                if (temp->right) {
                    temp_res.push_back(temp->right->val);
                    Q.push(temp->right);
                }
            }
            else if (!Q.empty()){
                res.push_back(temp_res);
                temp_res.clear();
                Q.push(NULL);
            }
        }
        return res;
    }
};