class MinStack {
public:
    vector<int> arr;
    vector<int> mini;
    MinStack() {
        
    }
    
    void push(int val) {
        int n = mini.size();
        if (mini.size() > 0){
            int minii = mini[n - 1];
            minii = min(minii , val);
            mini.push_back(minii);
            arr.push_back(val);
        }
        else {
            arr.push_back(val);
            mini.push_back(val);
        }
    }
    
    void pop() {
        int size = arr.size();
        int element = arr[size - 1];
        arr.pop_back();
        mini.pop_back();
    }
    
    int top() {
        int n = arr.size();
        int element = arr[n - 1];
        return element;
    }
    
    int getMin() {
        int n = mini.size();
        int element = mini[n - 1];

        return element;
    }
};

