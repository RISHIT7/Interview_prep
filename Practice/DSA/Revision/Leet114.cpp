#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {};
 };

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* last = nullptr;
        flt(root, last);
    }
private:
    void flt(TreeNode* root, TreeNode* &last){
        if(!root)return;
        last = root;
        flt(root->left, last);
        last->right = root->right;
        last->left = nullptr;
        flt(root->right, last);
        if(root->left)
            root->right = root->left;
        root->left = nullptr;
    }
};