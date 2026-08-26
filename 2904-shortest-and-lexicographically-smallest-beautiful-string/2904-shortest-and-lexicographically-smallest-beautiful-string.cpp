class Solution {
private:
    string solve(string &s, int k) {
        int oneCount = 0, left = 0, right = 0, len = s.size();
        string result = string(s.size(), '1'), curr = "";
        while(right < s.size()) {
            if(s[right] == '1') oneCount++;

            while(left <= right && oneCount > k) {
                if(s[left] == '1') oneCount--;
                left++;
            }
            if(oneCount == k) {
                while(left < right && s[left] == '0') {
                    left++;
                }
                if(right - left + 1 < len) {
                    len = right - left + 1;
                    result = string(s.begin() + left, s.begin() + right + 1);
                    //result = s.substr(left, right - left + 1)
                }
                else if(right - left + 1 == len) {
                    curr = string(s.begin() + left, s.begin() + right + 1);
                    if(curr < result) result = curr;
                }
            }
            right++;
        }       
        if(result != s && s.size() == result.size()) {
            int count = 0;
            for(auto ch : result) if(ch == '1') count++;
            if(count == s.size()) return "";
        }
        return result;

    }
public:
    string shortestBeautifulSubstring(string s, int k) {
        return solve(s, k);
    }
};