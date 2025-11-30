class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;

        return true;
    }
    
    bool remove(int val) {
    if (mp.find(val) == mp.end()) return false;

    int idx = mp[val];        
    int last = arr.back();    

    arr[idx] = last;        
    mp[last] = idx;           
    arr.pop_back();          
    mp.erase(val);            

    return true;
}
    
    int getRandom() {
        int n = rand() % arr.size();
        return arr[n];
    }
};