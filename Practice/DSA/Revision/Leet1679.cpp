#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int ans = 0;

        for (int num : nums) {
            int complement = k - num;
            if (count[complement] > 0) {
                ans++;
                count[complement]--;
            } else {
                count[num]++;
            }
        }

        return ans;
    }
};
