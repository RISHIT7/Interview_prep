#include <vector>
#include <iostream>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size();
    int mid = (start + end) / 2;
    if (nums.size() == 0)
    {
        vector<int> res = {-1, -1};
        return res;
    }
    while (start + 1 != end)
    {
        if (nums[mid] == target)
        {
            int first{mid}, second{mid};
            while (first > 0 && nums[first-1] == target)
            {
                first--;
            }
            while (second < nums.size() - 1 && nums[second+1] == target)
            {
                second++;
            }
            vector<int> res = {first, second};
            // if (!(first == 0 && second == nums.size()))
            // {
            //     res = {first + 1, second - 1};
            // }
            // else
            // {
            //     res = {first, second};
            // }
            return res;
        }
        else if (target < nums[mid])
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
        mid = (start + end) / 2;
    }
    if (nums[start] == target)
    {
        vector<int> res = {start, start};
        return res;
    }
    vector<int> res = {-1, -1};
    return res;
}

int main()
{
    vector<int> nums = {2, 2};
    int target = 2;
    vector<int> res = searchRange(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}