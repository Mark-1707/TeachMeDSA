// https://leetcode.com/problems/contains-duplicate/description/

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // using an unordered_set to store the numbers from given array
        unordered_set<int> validation_set;

        // insert function returns a pair of iterator and bool
        pair<unordered_set<int>::iterator, bool> res;

        for(auto it = nums.begin(); it != nums.end(); it++){
            res = validation_set.insert(*it);

            // if the number is already in the set, iterator will return false
            if(res.second == false) return true;
        }
        return false;
    }
};