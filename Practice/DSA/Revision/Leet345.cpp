class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() == 0) {
            return s;
        }
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' &&
                   s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' &&
                   s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
                i++;
            }
            while (i < j && s[j] != 'a' && s[j] != 'e' && s[j] != 'i' &&
                   s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' &&
                   s[j] != 'I' && s[j] != 'O' && s[j] != 'U') {
                j--;
            }
            if(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        }
        return s;
    }
};
