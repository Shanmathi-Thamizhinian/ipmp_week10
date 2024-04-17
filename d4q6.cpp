vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int N=A.size();
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());

    priority_queue<int> pq; 

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int sum=A[i]+B[j];
            pq.push(sum);
        }
    }

    vector<int> result;
    while (C--) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
