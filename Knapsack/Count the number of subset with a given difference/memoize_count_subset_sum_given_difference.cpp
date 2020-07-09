// Author :: Himangshu Shekhar Jha
//Count the number of subset with a given difference


// concept ::  s1 + s2 = sum
//             s1 - s2 = diff
//           --------------------
//             s1 = (sum + diff)/2
// Now just find whether s1 is present as subset sum or not
#include <bits/stdc++.h>
using namespace std;

int countRecursive(vector<int> a,int sum,int n, vector<vector<int> > dp){
    
    if(sum == 0)
        return 1;
    
    if(n == 0 && sum!= 0)
        return 0;

   
    // lookup
        if(dp[sum][n] != -1)
            return dp[sum][n];

    // memoize 
    if(a[n-1] <= sum)
        return dp[sum][n] = countRecursive(a,sum - a[n-1], n-1,dp) + countRecursive(a,sum, n-1,dp);

    return dp[sum][n] = countRecursive(a,sum, n-1,dp);
}


int main(){
    cout<<"Memoized solution to count the subset sum having a given difference :: "<<endl;

    int n,sum = 0,diff;
    cout<<"How many elements in the array? "<<endl;
    cin>>n;

    vector<int> a(n);

    cout<<"Enter the elements :: "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        sum += a[i];
    }

    cout<<"Enter the difference required for the subset sum :: "<<endl;
    cin>>diff;

    int s1 = (sum+diff)/2;

    vector<vector<int> > dp(n+1,vector<int>(s1+1,-1));

    cout<<"Total Number of subsets present :: "<<countRecursive(a,s1,n,dp)<<endl;

    return 0;
}