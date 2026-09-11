class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int, int> mp;
        int c = 0;
        for (int i = 0; i < n; i++)
            mp[digits[i]]++;
        for (int i = 0; i < 9; i += 2) {
            if (mp[i] == 0)
                continue;
            mp[i]--;
            for (int j = 1; j < 10; j++) {
                if (mp[j] == 0)
                    continue;
                mp[j]--;

                for (int k = 0; k <= 9; k++) {
                    if (mp[k] > 0)
                        c++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return c;
    }
};