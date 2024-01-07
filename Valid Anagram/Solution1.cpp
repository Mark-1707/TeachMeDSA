// https://leetcode.com/problems/valid-anagram/

#include <algorithm>
#include <string>
using namespace std;

// Sorting Approach

class Solution {
public:
    bool isAnagram(string s, string t) {

        // sort the strings and compare
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t) return true;
        return false;
    }
};