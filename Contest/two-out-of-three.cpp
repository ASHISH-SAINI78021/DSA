// method -> 1
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        int o = nums3.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int k = 0; k < o; k++){
                    if (nums1[i] == nums2[j]){
                        st.insert(nums1[i]);
                    }
                    else if (nums2[j] == nums3[k]) st.insert(nums2[j]);
                    else if (nums1[i] == nums3[k]) st.insert(nums1[i]);
                }
            }
        }

        for (auto it : st){
            ans.push_back(it);
        }

        return ans;
    }
};


// Method -> 2
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        int o = nums3.size();
        vector<int> freq1(101, 0);
        vector<int> freq2(101, 0);
        vector<int> freq3(101, 0);

        for (int i = 0; i < n; i++){
            freq1[nums1[i]] = 1;
        }
        for (int j = 0; j < m; j++){
            freq2[nums2[j]] = 1;
        }
        for (int k = 0; k < o; k++){
            freq3[nums3[k]] = 1;
        }

        for (int i = 0; i < freq1.size(); i++){
            if (freq1[i] + freq2[i] + freq3[i] >= 2){
                ans.push_back(i);
            }
        }

        return ans;
    }
};