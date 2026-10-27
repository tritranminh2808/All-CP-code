#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int f[200005];
void sub1(){
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        f[i]=INT_MAX;
        for(int j=1;j<=i;j++){
            int cnt=0;
            for(int k=j;k<=i;k++) {
                if(a[k]!=k-j+1) cnt++;
            }
            f[i]=min(f[j-1]+cnt,f[i]);
        }
    }
    cout << f[n];
    exit(0);
}
void sub2(){
    
    // f[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+1;
        int cnt=0;
        if(i-a[i]<0) cnt=n+5;
        else for(int j=i-a[i]+1;j<=i;j++) if(a[j]!=j-(i-a[i]+1)+1) cnt++;
        f[i]=min(f[i],cnt+f[i-a[i]]);
    }
    // for(int i=1;i<=n;i++) cout << f[i] << " ";
    cout << f[n];
    exit(0);
}
vector <int> pos[400005];
const int bn=200002;
void cok(){
    // for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+1;
        int cnt=0;
        // cout << i << ":\n";
        if(i-a[i]<0) cnt=n+5;
        else {
            pos[a[i]-i+bn].push_back(i);
            cnt=upper_bound(pos[a[i]-i+bn].begin(),pos[a[i]-i+bn].end(),i)-lower_bound(pos[a[i]-i+bn].begin(),pos[a[i]-i+bn].end(),i-a[i]+1);
            // for(auto x:pos[a[i]-i+bn]) cout << x << " ";
            // cout << cnt; 
            cnt=a[i]-cnt;
        }
        // cout << endl;
        f[i]=min(f[i],cnt+f[i-a[i]]);
       
    }
    cout << f[n];
    // for(int i=1;i<=n;i++) cout << f[i] << " ";
    exit(0);
}
int main(){
    freopen("mseq.inp","r",stdin);
	freopen("mseq.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>> n;
    if(n<=205) sub1();
    int maxx=0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        maxx=max(maxx,a[i]);
    }
    if(n<=5000||maxx<=300) sub2();
    // cin >> 
    cok();
    return 0;
}