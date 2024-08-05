#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int maxlen = 0;
        int c = 0;
        while (j < nums.size())
        {
            if (nums[j] == 0)
            {
                c++;
            }
            if (c <= k)
            {
                int len = j - i + 1;
                maxlen = max(len, maxlen);
            }
            else
            {
                c = 0;
                i++;
                j = i;
                j--;
            }
            j++;
        }
        return maxlen;
    }
};