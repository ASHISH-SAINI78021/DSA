class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {0};
        bool used[26] = {false};

        for (char ch : s)
            freq[ch - 'a']++;

        string stack = "";

        for (char ch : s) {
            freq[ch - 'a']--;

            // 🔴 FIX 1: skip if already used
            if (used[ch - 'a'])
                continue;

            while (!stack.empty() &&
                   stack.back() > ch &&
                   freq[stack.back() - 'a'] > 0) {

                // 🔴 FIX 2: store before popping
                char removed = stack.back();
                stack.pop_back();
                used[removed - 'a'] = false;
            }

            stack.push_back(ch);
            used[ch - 'a'] = true;
        }

        return stack;
    }
};
