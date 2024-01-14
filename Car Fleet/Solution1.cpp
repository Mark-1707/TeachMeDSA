// https://leetcode.com/problems/car-fleet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> s;
        vector<float> time;

        unordered_map<int, int> map;

        for(int i=0; i<speed.size(); i++){
            map[position[i]] = speed[i];
        }

        sort(position.begin(), position.end(), greater<int>());

        for(int i=0; i<speed.size(); i++){            
            time.emplace_back(float(float(target) - float(position[i]))/ float(map[position[i]]));
        }

        for(float& it: time){
            if(!s.empty()){
                if(s.top() < it){
                    s.push(it);
                }
            }else{
                s.push(it);
            }
        }

        return s.size();
    }
};
