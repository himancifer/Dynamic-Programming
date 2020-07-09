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

int ans = INT_MAX; 
bool isPresent(vector<int> arr,int sum, int n,int size){

    bool isCandidate;
    // Base Conditions
    if(sum == 0)
        isCandidate = true;
    else if(n==0 && sum != 0 )
        isCandidate = false;

    //Recursion
    else if(arr[n-1] <= (sum/2))
        isCandidate = isPresent(arr,(sum/2)-arr[n-1],n-1,size) || isPresent(arr,(sum/2),n-1,size);

    else
        isCandidate = isPresent(arr,(sum/2),n-1,size);

    if(isCandidate && (n == size))
        ans = min(ans,sum/2);

    return isCandidate;
}

int main(){
    cout<<"==============Recursive Minimum Subset Sum Partition================"<<endl;

    int n;
    cout<<"How many Numbers in the array "<<endl;
    cin>>n;

    vector<int> arr(n);
    int sum = 0;

    for(int i = 0;i<n;i++){
        cout<<"Enter the number :: "<<i+1<<endl;
        cin>>arr[i];
        sum+= arr[i];
    }
    bool helper = isPresent(arr,sum,n,n);

    cout<<"Minimum subset sum difference  = "<<(sum-(2*ans))<<endl;

}