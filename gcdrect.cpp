#include <bits/stdc++.h>
using namespace std;
int snt[1000005];
int N,M;
void txl(){
    for(int i=2;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i) if(snt[j]==0) snt[j]=i;
    } 
}
int ans=0;
void cok(int val, vector<vector <int> >& a){
    vector <vector <int> >  ma(N,vector <int> (M,0));
    vector <vector <int> >  h(N,vector <int> (M,0));
    vector <vector <int> >  l(N,vector <int> (M,0));
    vector <vector <int> >  r(N,vector <int> (M,0));
    int cc=0;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(a[i][j]%val==0) {ma[i][j]=1;cc++;}
    if(cc<ans) return;
    int m = ma.size();
    int n = ma[0].size();
//    vector<int> h(n + 1, 0);
    int sss = 0;
    for (int j = 0; j < n; ++j)  h[0][j]=ma[0][j];
    stack<int> s;
    for (int j = 0; j <n; ++j) {
        while (!s.empty()&& h[0][j] <= h[0][s.top()]) s.pop();
        if(!s.empty())l[0][j]=s.top();
        else l[0][j]=-1;
        s.push(j);
    }
    for (int i=1;i<m;++i) {
        for (int j = 0; j < n; ++j) {
            if (ma[i][j]) h[i][j] =h[i-1][j]+1;
            else h[i][j]=0;
        }
        stack<int> st;
        for (int j = 0; j < n; ++j) {
            while (!st.empty()&& h[i][j] <= h[i][st.top()]) st.pop();
            if(!st.empty())l[i][j]=st.top();
            else l[i][j]=-1;
            st.push(j);
        }
    }
    while(!s.empty()) s.pop();
    for (int j = n-1; j>=0; --j) {
        while (!s.empty()&& h[0][j] <= h[0][s.top()]) s.pop();
        if(!s.empty())r[0][j]=s.top();
        else r[0][j]=n;
        s.push(j);
    }
    for (int i=1;i<m;++i) {
        stack<int> st;
        for (int j = n-1; j >=0; --j) {
            while (!st.empty()&& h[i][j] <= h[i][st.top()]) st.pop();
            if(!st.empty())r[i][j]=st.top();
            else r[i][j]=n;
            st.push(j);
        }
    }
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		sss=max(sss,(r[i][j]-l[i][j]-1)*h[i][j]);
		}
	}
    ans=max(ans,sss);
}
int st[22][1000005];
int b[1000005];
void build(){
    for(int i=1;i<=M;i++) st[0][i]=b[i];
    for(int i=1;i<=21;i++){
        for(int j=1;j<=M;j++) st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
}
int query(int l, int r){
    if(l>r) return 0;
    int x=__lg(r-l+1);
    return __gcd(st[x][l],st[x][r-(1<<x)+1]);
}
void sub1(){
    
    for(int i=1;i<=M;i++) cin >> b[i];
    build();
    int j=1;
    int res=0;
    for(int i=1;i<=M;i++){
        while (query(j,i)==1) j++;
        res=max(res,i-j+1); 
    }
    cout << res;
    exit(0);
}
bool seen[1000005];
int main(){
    freopen("gcdrect.inp","r",stdin);
    freopen("gcdrect.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin >> N >> M;
     if(N==1) sub1();
    vector <vector <int> >  a(N,vector <int> (M,0));
    vector <int> lit;
    txl();
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> a[i][j];
            int x=a[i][j];
            while(x>1){
                if(seen[snt[x]]==0){
                    lit.push_back(snt[x]);
                    seen[snt[x]]=1;
                }
                x/=snt[x];
            }
        }
    }
    for(auto val:lit){
        cok(val,a);
    }
    cout << ans;
    return 0;
}