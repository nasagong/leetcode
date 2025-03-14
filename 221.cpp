class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int r = matrix.size();
            int c = matrix[0].size();
            int ans = 0;
    
            vector<vector<int>> dp(r, vector<int>(c,0));
    
            for(int i=0; i<c; i++) {
                dp[0][i] = matrix[0][i] - '0';
                if(dp[0][i]) ans = 1;
            }
    
            for(int i=0; i<r; i++) {
                dp[i][0] = matrix[i][0] - '0';
                if(dp[i][0]) ans = 1;
            }
    
            for(int i=1; i<r; i++){
                for(int j=1; j<c; j++){
                    if(matrix[i][j] == '1'){
                        dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                        ans = max(dp[i][j], ans);
                    }
                }
            }
    
            return ans*ans;
        }
    };