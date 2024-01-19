// https://leetcode.com/problems/time-based-key-value-store/description/

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:

    unordered_map<string, unordered_map<int, string>> map;
    unordered_map<string, vector<int>> max_map;
    

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
        max_map[key].emplace_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(map.find(key) == map.end()) return "";

        if(map[key].find(timestamp) != map[key].end()) return map[key][timestamp];

        if(timestamp >= max_map[key][max_map[key].size()-1] ) return map[key][max_map[key][max_map[key].size()-1]];

        if(timestamp < max_map[key][0]) return "";

        int l = 0;
        int r = max_map[key].size()-1;

        string prev = "";
        int min = 0;

        while(l<=r){
            int mid = (l+r)/2;
            if(timestamp > max_map[key][mid]){
                l = mid + 1;
                min = max_map[key][mid];
            }else{
                r = mid -1;
                if(max_map[key][mid] < timestamp && min < timestamp){
                    min = timestamp;
                }else if(max_map[key][mid] < timestamp){
                    min = max_map[key][mid];
                }
            }
        }
        return map[key][min];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */