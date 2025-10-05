class Solution {
public:
    void solve(string temp, char arr[26], string &result, unordered_map<char, int> &mp){
        int n = temp.length();
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += mp[temp[i]];
        }
        // cout << "Sum : " << sum << " ";
        sum = sum % 26;
        result.push_back(arr[sum]);
    }
    string stringHash(string s, int k) {
        int n = s.length();
        int size = n/k;
        char arr[26]; int count = 0;
        unordered_map<char, int> mp;
        for (char ch = 'a'; ch <= 'z'; ch++) arr[count++] = ch;
        count = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) mp[ch] = count++;

        string temp = "";
        string result = "";
        // cout << "Size : " << size << endl;
        for (int i = 0; i < n; i += k){
            temp = s.substr(i, k);
            solve(temp, arr, result, mp);
        }

        return result;
    }
};©leetcode