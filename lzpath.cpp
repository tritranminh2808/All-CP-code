#include<bits/stdc++.h>
#define int long long
using namespace std;
int f2(int x){
    if(x==0)return 100000000008;
    int c=0;
    while(x%2==0){
        x/=2;
        c++;
    }
    return c;
}
int f5(int x){
    if(x==0)return 100000000008;
    int c=0;
    while(x%5==0){
        x/=5;
        c++;
    }
    return c;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>>A(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           	cin>>A[i][j];
			
    const int I=100000000008;
    vector<vector<int>>d2(n+1,vector<int>(n+1,I)),d5(n+1,vector<int>(n+1,I));
    d2[1][1]=f2(A[1][1]);
    d5[1][1]=f5(A[1][1]);
    for(int j=2;j<=n;j++){
        d2[1][j]=d2[1][j-1]+f2(A[1][j]);
        d5[1][j]=d5[1][j-1]+f5(A[1][j]);
    }
    for(int i=2;i<=n;i++){
        d2[i][1]=d2[i-1][1]+f2(A[i][1]);
        d5[i][1]=d5[i-1][1]+f5(A[i][1]);
    }
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++){
            int c2=f2(A[i][j]),c5=f5(A[i][j]);
            d2[i][j]=min(d2[i-1][j],d2[i][j-1])+c2;
            d5[i][j]=min(d5[i-1][j],d5[i][j-1])+c5;
        }
    if(min(d2[n][n],d5[n][n])>=100000000008) cout << 1;
    else cout<<min(d2[n][n],d5[n][n]);
}

