class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> temp;
        if(hand.size()%groupSize!=0) return false;
        for(int i=0;i<hand.size();i++){
            pq.push(hand[i]);
        }
        int k=0;
        while(k<hand.size()){
            int n=1;
            int prev=pq.top();
            pq.pop();
            while(n<groupSize && !pq.empty()){
                if(prev+1==pq.top()){
                    prev=pq.top();
                    pq.pop();
                    n++;
                }
                else if(prev==pq.top()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
                else return false;
            }
            if(n!=groupSize) return false;
            for(int i=0;i<temp.size();i++) pq.push(temp[i]);
            temp.resize(0);
            k=k+n;
            n=1;
        }
        return true;
    }
};
