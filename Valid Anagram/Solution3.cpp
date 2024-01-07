#include <bits/stdc++.h>
using namespace std;

// maintaing count in the map to 0

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq1;

        if(s.length() != t.length()) return false;

        for(auto it = s.begin(); it != s.end(); it++){
            freq1[*it]++;
        }

        for(auto it = t.begin(); it != t.end(); it++){
            freq1[*it]--;
        }

        for(auto it = s.begin(); it != s.end(); it++){            
            if(freq1.at(*it) != 0) return false;
        }
        return true;
    }
};