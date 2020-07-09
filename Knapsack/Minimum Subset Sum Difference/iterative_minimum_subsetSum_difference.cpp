//Himangshu Shekhar Jha
// Problem :: Given a set of integers, the task is to divide it into two sets S1 and S2 such that
// the absolute difference between their sums is minimum.

// Input:  arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 

#include <bits/stdc++.h>

using namespace std;

int isPresent(vector<int> arr,int sum,int n,vector<vector<bool> >&dp){

    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=sum/2 ; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int ans;

    for(int j = sum/2;j>=0;j--){
        if(dp[n][j] == true){
            ans = j;
            break;
        }
    }

    return (sum -(2*ans));

}

int main(){
    int n;
    cout<<"How many Numbers in the array "<<endl;
    cin>>n;

    vector<int> arr(n);
    int sum = 0;

    for(int i = 0;i<n;i++){
        cout<<"Enter the number :: "<<i+1<<endl;
        cin>>arr[i];
        sum+=arr[i];
    }

    vector<vector<bool > > dp(n+1,vector<bool>(sum/2+1,false));

    for(int i = 0; i <= n;i++){
        for(int j = 0;j <=sum; j++){
            if(i == 0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    }

    cout<<"Minimum subset sum difference = "<<isPresent(arr,sum,n,dp)<<endl;


    cout<<"The dp table is :: "<<endl;    
    for(auto el : dp){
        for(int data : el)
            cout<<data<<" ";

        cout<<endl;
    }

     
}