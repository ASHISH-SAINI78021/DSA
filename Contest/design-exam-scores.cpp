class ExamTracker {
private:
    vector<int> t;              
    vector<long long> preSum;  

public:
    ExamTracker() {
    }
    
    void record(int a, int b) {
        t.push_back(a);
        
        long long x = preSum.empty() ? 0 : preSum.back();
        preSum.push_back(x + (long long)b);
    }
    
    long long totalScore(int l, int r) { 
        auto it2 = upper_bound(t.begin(), t.end(), r);
        
        if (it2 == t.begin()) {
            return 0;
        }
        
        int j = it2 - t.begin() - 1;
        long long endSum = preSum[j];

        auto it1 = lower_bound(t.begin(), t.end(), l);

        if (it1 == t.begin()) {
            return endSum;
        }

        int i = it1 - t.begin() - 1;
        long long startSum = preSum[i];
        
        return endSum - startSum;
    }
};
©leetcode