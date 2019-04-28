/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0, j = 0, sz = s.size();
        while(i < sz){
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
                s[j++] = s[i++];
            else if(s[i] >= 'A' && s[i] <= 'Z')
                s[j++] = s[i++] - 'A' + 'a';
            else    
                ++i;
        }
        i = 0;
        --j;
        
        while(i < j)    
            if(s[i++] != s[j--])
                return false;
        return true;
    }

/*
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) 
            i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) 
            j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) 
            return false; // Exit and return error if not match
    }
    
    return true;
}*/
};

