// https://leetcode.com/problems/find-common-characters/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char, int>> v(words.size());
        vector<string> ans;

        for(int i=0; i<words.size(); i++){
            for(const char& ch: words[i]){
                v[i][ch]++;
            }
        }


        for(int i=0; i<1; i++){
            for(const char& ch: words[i]){
                bool found = true;
                for(int j=0; j<words.size(); j++){
                    if(v[j][ch] <= 0){
                        found = false;
                        break;
                    }else{
                        v[j][ch]--;
                    }
                }
                string s(1, ch);
                if(found) {
                    ans.push_back(s);
                }
            }
            
        }
        return ans;
    }
};