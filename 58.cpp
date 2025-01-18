class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int flag = 0;
        int cnt = 0;
        for(int i = len-1; i>=0; i--){
            if(flag == 1 && s[i] == ' ') break;
            if(flag == 0){
                if(s[i] == ' ') continue;
                if(s[i] != ' ') flag = 1;
            }
            cnt++;
        }
        return cnt;
    }
};