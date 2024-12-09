class MedianFinder {
public:
    priority_queue<int> maxHeap;  // left_max_heap
    priority_queue<int, vector<int>, greater<int>> minHeap;  // right_min_heap
    
    MedianFinder() { 
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            double mean = (maxHeap.top() + minHeap.top()) / 2.0;
            return mean;
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