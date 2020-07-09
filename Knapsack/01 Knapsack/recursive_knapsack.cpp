//Himangshu Shekhar Jha

#include <bits/stdc++.h>

using namespace std;

//For writing the base condition, think of the smallest valid input.

int knapsack(vector<int> wt,vector<int> val,int w,int n){
    if(n==0 || w==0)
        return 0;

    if(wt[n-1] <= w)
        return max((val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1)),knapsack(wt,val,w,n-1));

    return knapsack(wt,val,w,n-1);
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

    cout<<"The Maximum Profit is :: "<<knapsack(wt,val,w,n);

}