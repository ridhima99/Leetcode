class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;
        
        // Lambda to check if alphanumeric 
        auto isAlnum = [](char c) {
            return (c >= 'a' && c <= 'z') || 
                   (c >= 'A' && c <= 'Z') || 
                   (c >= '0' && c <= '9');
        }; 

        // Lambda for lowercase conversion 
        auto toLower = [](char c) {
            if (c >= 'A' && c <= 'Z') {
                return (char)(c + 32);
            }
            return c;
        };
        while(l < r){
            // Skip non-alphanumeric from left
            while(l < r && !isAlnum(s[l])) {
                l++;
            }
            // Skip non-alphanumeric from right
            while(l < r && !isAlnum(s[r])) {
                r--;
            }
            // compare 
            if(toLower(s[l]) != toLower(s[r])){
                return false; 
            }
            
            // Move pointers inward
            l++;
            r--;
        }
        
        return true;
    }
};




// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.length();
//         string clean = "";
//         for (int i = 0; i < n; i++) {
//             if (isalnum(s[i])) {
//                 clean += tolower(s[i]);
//             }
//         }

//         int m = clean.length();
//         for (int i = 0; i < m / 2; i++) {
//             if (clean[i] != clean[m - i - 1])
//                 return false;
//         }
//         return true;
//     }
// };