class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> temp;
        int i = 0;
        string result = "";
        while (i < n){
            while (i < n && path[i] == '/') i++;
            string t = "";
            while (i < n && path[i] != '/'){
                t += path[i++];
            }
            if (t == "" || t == ".") continue ;
            else if (t == ".."){
                if (!temp.empty()) temp.pop_back();
            }
            else{
                // cout << "t : " << t << "  ";
                temp.push_back(t);
            }
            i++;
        }
        
        for (auto it : temp){
            result = result + "/" + it;
            // cout << result << " ";
        }

        return (result.empty()) ? "/" : result;
    }
};