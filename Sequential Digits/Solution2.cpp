// https://leetcode.com/problems/sequential-digits/description

// Brute force (TLE)

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int len_low = to_string(low).size();
        int len_high = to_string(high).size();
        
        for(int len = len_low; len <= len_high; len++){
            for(int start = 1; start < 10; start++ ){
                if(len + start > 10) break;
                int num = start;
                int prev = start;
                for(int i = 0; i<len-1; i++){
                    num = num*10;
                    prev += 1;
                    num += prev;
                }
                if(num >= low && num <= high) ans.emplace_back(num);
            }
        }
        
        return ans;
    }
};