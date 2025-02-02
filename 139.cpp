class Solution {

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;

        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] && wordSet.find(s.substr(j,i-j))!=wordSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


// editorial

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> arr(s.size(), false);  
        
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0 && !arr[i - 1]) 
                continue;

            for (string str : wordDict) {
                if (str.size() + i <= s.size() && s.substr(i, str.size()) == str) {
                    arr[str.size() + i - 1] = true;  

                    if (arr[arr.size() - 1])  
                        return true;
                }
            }
        }
        return false;
    }
};