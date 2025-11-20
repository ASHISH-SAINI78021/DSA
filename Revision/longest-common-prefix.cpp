string Solution::longestCommonPrefix(vector<string> &arr) {
    string ans = "";
    int n = arr.size();
    int j = 0;
    string temp;
    while (j < arr[0].size()){
        int i = 1;
        for (; i < n; i++){
            if (j < arr[i].size() && j < arr[i - 1].size() && arr[i - 1][j] == arr[i][j]){
                continue;
            }
            else break;
        }
        temp.push_back(arr[i - 1][j]);
        if (i < n){
            if (!temp.empty()){
                temp.pop_back();
            }
            return temp;
        }
        j++;
    }
    
    return temp;
}