**Question**

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

**Solution Approach**

Making use of recursion.

**Solution**

class Solution {
public:
    bool isSubsequence(string s, string t) {
        return isSubsequence(s, t, 0, 0);
    }
    bool isSubsequence(string s, string t, int i, int j) {
        if(i == s.length()) return true;
        if(j == t.length()) return false;
        return s[i] == t[j] ? isSubsequence(s, t, i + 1, j + 1) : isSubsequence(s, t, i, j + 1);
    }
    
};
