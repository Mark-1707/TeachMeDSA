// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> map;
    vector<int> v;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)  != map.end()) return false;
        v.emplace_back(val);
        map[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!(map.find(val) != map.end())) return false;
        int index = map[val];
        int last_ele = v.back();
        map[last_ele] = index;
        swap(v[index],v[v.size()-1]); 
        v.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */