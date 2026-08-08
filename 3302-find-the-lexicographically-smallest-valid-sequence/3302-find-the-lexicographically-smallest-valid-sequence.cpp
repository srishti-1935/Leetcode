class Solution {
public:
    vector<int> validSequence(string s, string t) {
        // we need lexicographically smallest... means we have to choose the min index if possible. 

        // so we need to know at each index,  if with the suffix is it possible to make the string atmost equal to word2 or not? 
        int n = s.length();
        int m = t.length();
        int i = n - 1, j= m - 1; 
        vector<int> dp(n + 1, 0); 
        for(; i >= 0; i--) {
            if(j >= 0 && s[i] == t[j]) {
                // if these are equal 
                dp[i] = dp[i + 1] + 1; 
                j--; 
            } else dp[i] = dp[i + 1]; 
        }

        // Now for each index greedily I have to tell If I can form the answer or not. 
        vector<int> ans; 
        j = 0; 
        bool flag = true; // means match available 
        for(int i = 0; i < n && j < m; i++) {
            int rem = m - j - 1; // if we pick cur 
            // match possible in suffix dp[i + 1], else possible what can I choose? 
            if( s[i] == t[j]) {
                // means both are equal 
                ans.push_back(i); // adding this will form lexicographical string. 
                j++; 
            } else if(flag && dp[i + 1] >= rem) {
                // words are not equal 
                // I have to make a choice 
                // If i change cur than for next index ... what is the suffix length which is still possible? 

                // then I can choose this means i can still form rest of the string 
                ans.push_back(i); 
                j++; 
                flag = false; 
            }
        }

        if (j == m) return ans; 
        return {}; 
    }
};