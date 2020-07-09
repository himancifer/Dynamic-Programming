// Author :: Himangshu Shekhar Jha
//Count the number of subset with a given difference


// concept ::  s1 + s2 = sum
//             s1 - s2 = diff
//           --------------------
//             s1 = (sum + diff)/2
// Now just find whether s1 is present as subset sum or not
#include <bits/stdc++.h>
using namespace std;

int countRecursive(vector<int> a,int sum,int n){
    
    if(sum == 0)
        return 1;
    
    if(n == 0 && sum!= 0)
        return 0;

    if(a[n-1] <= sum)
        return countRecursive(a,sum - a[n-1], n-1) + countRecursive(a,sum, n-1);

    return countRecursive(a,sum, n-1);
}


int main(){
    cout<<"Recursive solution to count the subset sum having a given difference :: "<<endl;

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

    cout<<"Total Number of subsets present :: "<<countRecursive(a,s1,n)<<endl;

    return 0;
}