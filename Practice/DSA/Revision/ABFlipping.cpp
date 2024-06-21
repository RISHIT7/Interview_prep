#include <bits/stdc++.h>
using namespace std;

int main()
{
    string  s = "AABBBABAA";
    // we check the first A and the last B, and then we claim we can swap every bit in the middle
    int first = -1;
    int last = s.size()-1;
    for (int i = 0; i < s.size()-1; i++)
    {
        char c = s[i];
        if (c == "A" and first == -1)
        {
            first = i;
        }
        if (c == "B")
        {
            last = i;
        }
    }
    int res = last - first;
    return 0;
}
