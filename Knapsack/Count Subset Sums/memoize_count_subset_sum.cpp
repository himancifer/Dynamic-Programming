//Himangshu Shekhar Jha
#include <bits/stdc++.h>

using namespace std;

int Count(vector<int> arr,int sum, int n,vector<vector<int> >& dp){

    // Base Conditions
    if(sum == 0)
        return dp[n][sum] = 1;
    
    if(n==0 && sum != 0 )
        return dp[n][sum] = 0;

    
    //Memoization
    if(dp[n][sum] != -1)
        return dp[n][sum];


    //Recursion
    if(arr[n-1] <= sum)
        return dp[n][sum] = Count(arr,sum-arr[n-1],n-1,dp)  +  Count(arr,sum,n-1,dp);

    return dp[n][sum] = Count(arr,sum,n-1,dp);
}

int main(){
    int n;
    cout<<"How many Numbers in the array "<<endl;
    cin>>n;

    vector<int> arr(n);
    int sum;

    for(int i = 0;i<n;i++){
        cout<<"Enter the number :: "<<i+1<<endl;
        cin>>arr[i];
    }

    cout<<"Enter the required sum "<<endl;
    cin>>sum;

    vector<vector<int > > dp(n+1,vector<int>(sum+1,-1));

    int ans = Count(arr,sum,n,dp);

    cout<<"Total subsets = "<<ans; 

    cout<<endl<<"DP array :: "<<endl;

    for(auto el : dp){
        for(int data : el)
            cout<<data<<" ";
        
        cout<<endl;
    }
     
}