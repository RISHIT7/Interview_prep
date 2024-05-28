// O(1) Space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

// O(n) Space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums.size() - k;
            while (temp < 0)
            {
                temp += nums.size();
            }
            result.push_back(nums[(i + temp)%nums.size()]);
        }
        nums = result;
    }
};
