// Comparing the frequency of each character in both strings


#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        if(s.length() != t.length()) return false;

        for(auto it = s.begin(); it != s.end(); it++){
            freq1[*it]++;
        }

        for(auto it = t.begin(); it != t.end(); it++){
            freq2[*it]++;
        }

        for(auto it = s.begin(); it != s.end(); it++){
            int c = 0;
            try{
                c = freq2.at(*it);
            }catch(exception e){
                return false;
            }
            
            if(freq1.at(*it) != c) return false;
        }
        return true;
    }
};