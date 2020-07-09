//Himangshu Shekhar Jha
#include <bits/stdc++.h>

using namespace std;

bool isPresent(vector<int> arr,int sum, int n){

    // Base Conditions
    if(sum == 0)
        return true;
    if(n==0 && sum != 0 )
        return false;

    //Recursion
    if(arr[n-1] <= sum)
        return isPresent(arr,sum-arr[n-1],n-1) || isPresent(arr,sum,n-1);

    return isPresent(arr,sum,n-1);
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
        sum+= arr[i];
    }
    //If sum is odd the the no equal partition exists.
    if(sum & 1){
        cout<<"Not Present"<<endl;
    }
    else
    {
        bool ans = isPresent(arr,sum/2,n);
        ans == true ? cout<<"Present" : cout<<"Not Present"; 
    }
    

}