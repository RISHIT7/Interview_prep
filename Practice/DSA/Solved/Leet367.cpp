class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l = 0, r = num, s;
        while(l <= r){
            long long int s = l + (r - l)/2;
            if(s*s == num){
                return true;
            }
            else if(s*s > num){
                r = s - 1;
            }       
            else if(s*s < num){
                l = s + 1;
            }
            else {
                return false;
            }
        } return 0;
    }
};