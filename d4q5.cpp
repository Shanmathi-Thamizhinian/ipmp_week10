class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> f;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        f.push(num);
        s.push(f.top());
        f.pop();
        if(f.size()<s.size()){
            f.push(s.top());
            s.pop();
        }
    }
    
    double findMedian() {
        return f.size()>s.size()?f.top():(f.top()+s.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
