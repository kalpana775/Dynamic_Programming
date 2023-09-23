#include<bits/stdc++.h>
using namespace std;


// Recursive 
 int fibonacci_rec(int n){
    if(n<=1){
        return n;
    }

    return fibonacci_rec(n-1)+fibonacci_rec(n-2);
 }

 //Memoize Code ; TC--> O(N),  SC--> O(N)+O(N) 
int fibonacci_mem(int n,vector<int> &mem){
    if(n<=1){
        return n;
    }
    if(mem[n]!=-1){
        return mem[n];
    }

    return mem[n]=fibonacci_mem(n-1,mem)+fibonacci_mem(n-2,mem);
 }

 



int main(){
    int n;
    cin>>n;
    
    cout<<"By using recursion: "<<fibonacci_rec(n)<<endl;

    vector<int> mem(n+1,-1);
    cout<<"By using memoization: "<<fibonacci_mem(n,mem)<<endl;


    // DP ; TC--> O(N), SC--> O(N)
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<"By using DP: "<<dp[n]<<endl;

    //Other way by using no extra space
    int prev,prev2;
    for(int i=0;i<=n;i++){
        if(i==0){
            prev=0;
            continue;
        }
        if(i==1){
            prev=1;
            prev2=0;
            continue;
        }

        int curr=prev+prev2;
        prev2=prev;
        prev=curr;

    }

    cout<<"By using constant space: "<<prev<<endl;

    return 0;
}