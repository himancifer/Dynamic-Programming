//Himangshu Shekhar Jha
#include <bits/stdc++.h>

using namespace std;

int isPresent(vector<int> arr,int sum,int n,vector<vector<bool> >&dp){

    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=sum ; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];

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
    
    for(int i = 0; i <= n;i++){
        for(int j = 0;j <=sum; j++){
            if(i == 0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    }

    bool ans = isPresent(arr,sum,n,dp);

    ans == true ? cout<<"Present" : cout<<"Not Present";

    cout<<endl<<"DP array :: "<<endl;

    for(auto el : dp){
        for(int data : el)
            cout<<data<<" ";
        
        cout<<endl;
    }
     
}