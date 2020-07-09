//Himangshu Shekhar Jha
#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> wt,vector<int> val,int w,int n,vector<vector<int> >&dp){

    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=w ; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max((val[i-1] + dp[i-1][j-wt[i-1]]),dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];

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

    vector<vector<int> > dp((n+1),vector<int>(w+1,0));
    

    cout<<"The Maximum Profit is :: "<<knapsack(wt,val,w,n,dp);

}