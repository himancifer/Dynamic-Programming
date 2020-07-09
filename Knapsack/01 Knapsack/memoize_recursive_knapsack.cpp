//Himangshu Shekhar Jha
#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> wt,vector<int> val,int w,int n,vector<vector<int> >&dp){
    if(n==0 || w==0)
        return 0;

    if(dp[n][w] != -1)
        return dp[n][w];

    if(wt[n-1] <= w)
        return dp[n][w] = max((val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1,dp)),knapsack(wt,val,w,n-1,dp));

    return dp[n][w] = knapsack(wt,val,w,n-1,dp);
}

int main(){
    int n;
    cout<<"How many Items "<<endl;
    cin>>n;

    vector<int> wt(n),val(n);
    int w;
    

    for(int i = 0;i<n;i++){
        cout<<"Enter the weight and value of item :: "<<i+1<<endl;
        cin>>wt[i]>>val[i];
    }

    cout<<"Enter the capacity of the knapsack "<<endl;
    cin>>w;

    vector<vector<int> > dp((n+1),vector<int>(w+1,-1));

    cout<<"The Maximum Profit is :: "<<knapsack(wt,val,w,n,dp);

}