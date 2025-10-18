// Method -> 1
class Solution {
public:
    bool isUgly(int n) {
        if (n == 1) return true;
        if (n <= 0) return false;
        unordered_set<int> st;
        while (n % 2 == 0){
            st.insert(2);
            n = n/2;
        }

        for (int i = 3; i <= sqrt(n); i += 2){
            while (n % i == 0){
                st.insert(i);
                n = n / i;
            }
        }

        if (n > 1) st.insert(n);

        if (st.size() > 3) return false;
        for (auto it : st){
            if (it == 2 || it == 3 || it == 5) continue ;
            else return false;
        }

        return true;
    }
};


// Method -> 2
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        while (n % 2 == 0) n = n/2;
        while (n % 3 == 0) n = n/3;
        while (n % 5 == 0) n = n/5;

        return n == 1;
    }
};