//Himangshu Shekhar Jha
#include <bits/stdc++.h>

using namespace std;

bool isPresent(vector<int> arr,int sum, int n,vector<vector<bool> >& dp){

    // Base Conditions
    if(sum == 0)
        return dp[n][sum] = true;
    
    if(n==0 && sum != 0 )
        return dp[n][sum] = false;

    
    //Memoization
    if(dp[n][sum] != false)
        return dp[n][sum];


    //Recursion
    if(arr[n-1] <= sum)
        return dp[n][sum] = isPresent(arr,sum-arr[n-1],n-1,dp) || isPresent(arr,sum,n-1,dp);

    return dp[n][sum] = isPresent(arr,sum,n-1,dp);
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

    vector<vector<bool > > dp(n+1,vector<bool>(sum+1,false));

    bool ans = isPresent(arr,sum,n,dp);

    ans == true ? cout<<"Present" : cout<<"Not Present";

    cout<<endl<<"DP array :: "<<endl;

    for(auto el : dp){
        for(int data : el)
            cout<<data<<" ";
        
        cout<<endl;
    }
     
}