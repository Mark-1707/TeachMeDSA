// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    int ans = 0;
    vector<string> subset;
    void backTrack(vector<string>& words, int i, vector<int>& scoreArr, unordered_map<char, int> map){

        if(i >= words.size()){
            unordered_map<char, int> tempMap(map.begin(), map.end());

            int score = 0;
            bool isValid = true;
            for(const string& s: subset){
                int tempScore = 0;
                for(const char& ch: s){
                    if(tempMap.find(ch) == tempMap.end()){
                        isValid = false;
                        break;
                    }

                    tempScore += scoreArr[ch - 97];
                    tempMap[ch]--;

                    if(tempMap[ch] == 0){
                        tempMap.erase(ch);
                    }
                }
                if(isValid){
                    score += tempScore;
                    
                }else{
                    break;
                }
            }

            ans = max(ans, score);
            return;
        }

        subset.push_back(words[i]);
        backTrack(words, i + 1, scoreArr, map);

        subset.pop_back();
        backTrack(words, i + 1, scoreArr, map);

    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> map;

        for(const char& ch: letters) map[ch]++;

        backTrack(words, 0, score, map);

        return ans;
        
    }
};