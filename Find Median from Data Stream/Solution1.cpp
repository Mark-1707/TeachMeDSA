// https://leetcode.com/problems/find-median-from-data-stream/description/

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {

private:
    priority_queue<int> maxHeap;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        maxHeap.push(num);

        int diff = maxHeap.size() - minHeap.size();
        if (abs(diff) > 1) {
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(!maxHeap.empty() && !minHeap.empty() && minHeap.top() < maxHeap.top()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        diff = maxHeap.size() - minHeap.size();
        if (abs(diff) > 1) {
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        
        if(minHeap.size() > maxHeap.size()){            
            return minHeap.top();
        }

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */