class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> rem = cnt;
            bool ok = true;
            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';
                if (rem[x] == 0) {
                    ok = false;
                    break;
                }
                rem[x]--;
            }
            if (!ok) continue;
            int tar = target[i] - 'a';
            for (int c = tar + 1; c < 26; c++) {
                if (rem[c] == 0) continue;
                string ans = target.substr(0, i);
                ans += char('a' + c);
                rem[c]--;
                for (int x = 0; x < 26; x++) {
                    ans.append(rem[x], char('a' + x));
                }
                return ans;
            }
        }
        return "";
    }
};