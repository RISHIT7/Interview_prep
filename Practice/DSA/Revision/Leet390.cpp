class Solution {
    int ans = 0;
    void left(int si, int ei, int jump)
    {
        if (si == ei){
            ans = si;
            return;
        }

        int n = (si-ei)/jump;
        if (n % 2 == 0){
            si+=jump;
            ei-=jump;
        }
        else{
            si+=jump;
        }
        jump*=2;
        right(si, ei, jump);
    }

    void right(int si, int ei, int jump)
    {
        if (si == ei){
            ans = si;
            return;
        }

        int n = (si-ei)/jump;
        if (n % 2 == 0){
            si+=jump;
            ei-=jump;
        }
        else{
            ei-=jump;
        }
        jump*=2;
        left(si, ei, jump);
    }



public:
    int lastRemaining(int n) {
        left(1,n,1);
        return ans;
    }
};