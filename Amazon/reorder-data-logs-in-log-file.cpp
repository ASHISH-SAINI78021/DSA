class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<string> a;
        vector<string> b;
        vector<string> ans;
        for (int i = 0; i < n; i++){
            string word = logs[i];
            int k = 0;
            while (word[k] != ' '){
                k++;
            }
            while (word[k] == ' ') k++;
            if (isdigit(word[k])){
                b.push_back(logs[i]);
            }
            else {
                a.push_back(logs[i]);
            }
        }

        sort(a.begin(), a.end(), [](auto &a, auto &b){
            int PosA = a.find(' ');
            int PosB = b.find(' ');
            string id1 = a.substr(0, PosA);
            string id2 = b.substr(0, PosB);
            string contentA = a.substr(PosA + 1);
            string contentB = b.substr(PosB + 1);
            if (contentA == contentB) return id1 < id2;
            return contentA < contentB;
        });

        ans = a;
        for (auto it : b){
            ans.push_back(it);
        }
        
        return ans;
    }
};