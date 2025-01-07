class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int hIdx = 0;
        for(int i=n-1; i>=0; i--){
            if(citations[i] >= n-i) hIdx = n-i;
        }
        return hIdx;
    }
};