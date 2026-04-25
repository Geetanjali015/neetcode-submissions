class Solution { //dp top down memoization
public:
    vector<int>memoization;
    int dfs(vector<int>&cost,int i){
        if(i>=cost.size())return 0;

        if(memoization[i]!=-1)return memoization[i]; //-1:not solved,if solved reuse
        memoization[i]=cost[i]+min(dfs(cost,i+1),dfs(cost,i+2));
        return memoization[i];
    }
    int minCostClimbingStairs(vector<int>& cost)//dp top down memoization
     {
        int n=cost.size();
        memoization.resize(n,-1); //initialize
        return min(dfs(cost, 0), dfs(cost, 1)); //can start from 0 and step 1


    /*recursion
        return min(dfs(cost,0),dfs(cost,1));
    }
    int dfs(vector<int>&cost,int i){
    if(i>=cost.size())}{//reach top or beyond
        return 0;}
    return cost[i]+min(dfs(cost,i+1),dfs(cost,i+2));
*/
    }
};
