class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cursor = 0;
        for(int i=0; i<t.length(); i++){
            if(s[cursor] == t[i] && cursor < s.length())
                cursor++;
        }

        if(cursor == s.length()) return true;
        else return false;
    }
};