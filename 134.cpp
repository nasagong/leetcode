class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, totalGas = 0, currentGas = 0;
        for(int i = 0; i < gas.size(); i++){
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];
            if(currentGas < 0){
                start = i+1;
                currentGas = 0;
            }
        }
        return totalGas >= 0 ? start : -1;
    }
};