class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int, int> count;
        for (auto num:nums)
        {
            if (count.find(num) == count.end())
            {
                count[num] = 1;
            }
            else
            {
                count[num]+= 1;
            }
        }

        for (auto i = count.begin(); i != count.end(); i++)
        {
            if (i->second == 1)
            {
                return i->first;
            }
        }
        return -1;
    }
};

// amazing xor solution
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    for (const int  num : nums) {
        ones ^= (num & ~twos);
        twos ^= (num & ~ones);
    }
    return ones;
  }
};
