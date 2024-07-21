#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_prod(nums.size(), 1);
        vector<int> suffix_prod(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            prefix_prod[i] = nums[i-1] * prefix_prod[i-1];
        }
        for (int i = nums.size()-2; i > -1; i--)
        {
            suffix_prod[i] = nums[i+1] * suffix_prod[i+1];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(prefix_prod[i] * suffix_prod[i]);
        }
        return ans;
    }
};