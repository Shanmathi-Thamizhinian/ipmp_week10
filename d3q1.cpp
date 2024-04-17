class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int l;
    KthLargest(int k, vector<int>& nums) {
        l=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>l) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>l) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
