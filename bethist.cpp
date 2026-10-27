#include <bits/stdc++.h>
using namespace std;

const int cur=100,w=201;
bool f[10005][w];
char t[10005][w];
int p[10005][w];

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> x(n);
    for(int&v:x)cin>>v;

    f[0][cur]=1;

    for(int i=1;i<=n;i++){
        for(int s=0;s<w;s++)
			if(f[i-1][s]){
            	int v=x[i-1],u=s-cur;
            	for(int d:{-v,v}){
            	    int j=u+d;
       		         if(j<a||j>b)continue;

           		     j+=cur;
             	   if(!f[i][j]){
             	       f[i][j]=1;
             	       t[i][j]=(d>0?'1':'0');
             	       p[i][j]=s;
             	   }
            	}
        	}

        bool ok=0;
        for(int s=0;s<w;s++)if(f[i][s]){
            ok=1;
            break;
        }

        if(!ok){
            cout<<"Impossible\n";
            return 0;
        }
    }

    int e=-1;
    for(int s=a;s<=b;s++)if(f[n][s+cur]){
        e=s+cur;
        break;
    }

    if(e<0){
        cout<<"Impossible\n";
        return 0;
    }
    string res;
    for(int i=n;i;i--){
        res+=t[i][e];
        e=p[i][e];
    }

    reverse(res.begin(),res.end());
    cout<<res<<'\n';
}

