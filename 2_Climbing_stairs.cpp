#include<bits/stdc++.h>
using namespace std;

// This question is similar to fibonacci

// Recursion

int steps(int n){
    if(n<=1){
        return 1;
    }

    int one=steps(n-1);
    int two=steps(n-2);

    return one+two;
}


// Memoization

int steps_mem(int n,vector<int> &mem){
    if(n<=1){
        return 1;
    }

    if(mem[n]!=-1){
        return mem[n];
    }

    int one =steps_mem(n-1,mem);
    int two= steps_mem(n-2,mem);

    return mem[n]=one+two;
}
int main(){
    int n;
    cin>>n;

    cout<<"Using recursion: "<<steps(n)<<endl;

    vector<int> mem(n+1,-1);
    cout<<"Using memoization: "<<steps_mem(n,mem)<<endl;

    
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<"Using DP: "<<dp[n]<<endl;


    return 0;
}