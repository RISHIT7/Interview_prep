class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if concatenated strings are equal or not, if not return ""
        if(str1 + str2 != str2 + str1)
            return "";
        // If strings are equal than return the substring from 0 to gcd of size(str1), size(str2)
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
