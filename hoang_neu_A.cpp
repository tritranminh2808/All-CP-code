#include <bits/stdc++.h>
using namespace std;
int n,q;
vector <int> adj[500005];
int tin[500005],tout[500005],t[500005],eu[500005],need[500005],timer=0;
const long long inf=1e16;
static const int IN_BUF = 1<<20;
static char ibuf[IN_BUF];
static int ipos = 0, ilen = 0;
inline int readChar() {
    if (ipos >= ilen) {
        ilen = (int)fread(ibuf,1,IN_BUF,stdin);
        ipos = 0;
        if (ilen == 0) return EOF;
    }
    return ibuf[ipos++];
}
template<typename T>
bool readInt(T &out) {
    int c;
    do {
        c = readChar();
        if (c == EOF) return false;
    } while (c!='-' && (c<'0' || c>'9'));
    int sign = 1;
    if (c == '-') {
        sign = -1;
        c = readChar();
    }
    long long val = 0;
    while (c >= '0' && c <= '9') {
        val = val*10 + (c - '0');
        c = readChar();
    }
    out = (T)(val * sign);
    return true;
}
string out;
void dfs(int u, int v){
    tin[u]=++timer;
    eu[timer]=u;
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
    }
    tout[u]=timer;
}
struct pl{
    long long val,lazy,idx;
};
pl st1[2000005],st2[2000005];
pl merge1(pl x, pl y){
    pl c;
    if(x.val<=y.val){
        c.val=x.val;
        c.idx=x.idx;
    }
    else{
        c.val=y.val;
        c.idx=y.idx;
    }
    c.lazy=0;
    return c;
}
void build1(int id, int l, int r){
    st1[id].lazy=0;
    if(l==r){
        st1[id].val=need[l];
        st1[id].idx=l;
        
        return;
    }
    int mid=(l+r)/2;
    build1(id*2,l,mid);
    build1(id*2+1,mid+1,r);
    st1[id]=merge1(st1[id*2],st1[id*2+1]);
}
void push1(int id){
    if(st1[id].lazy==0) return;
    st1[id*2].val+=st1[id].lazy;
    st1[id*2].lazy+=st1[id].lazy;
    st1[id*2+1].val+=st1[id].lazy;
    st1[id*2+1].lazy+=st1[id].lazy;
    st1[id].lazy=0;
}
void up_range(int id, int l, int r, int lf, int rt, long long v){
    if(lf>r||rt<l) return;
    if(lf<=l&&rt>=r){
        st1[id].val+=v;
        st1[id].lazy+=v;
        return;
    }
    push1(id);
    int mid=(l+r)/2;
    up_range(id*2,l,mid,lf,rt,v);
    up_range(id*2+1,mid+1,r,lf,rt,v);
    st1[id]=merge1(st1[id*2],st1[id*2+1]);
}
void up_point(int id, int l, int r, int u, long long v){
    if(u<l||u>r) return;
    if(l==r){
        st1[id].val=v;
        st1[id].lazy=0;
        st1[id].idx=l;
        return;
    }
    push1(id);
    int mid=(l+r)/2;
    up_point(id*2,l,mid,u,v);
    up_point(id*2+1,mid+1,r,u,v);
    st1[id]=merge1(st1[id*2],st1[id*2+1]);
}
int find1(int id, int l,int r,long long v){
    if(st1[id].val>v) return -1;
    if(l==r) return l;
    push1(id);
    int mid=(l+r)/2;
    int k1=find1(id*2,l,mid,v);
    if(k1!=-1) return k1;
    return find1(id*2+1,mid+1,r,v);
}











void build2(int id, int l, int r){
    
    st2[id].val = 0;
    st2[id].lazy = 0;
    st2[id].idx = l;
    if(l==r) return;
    int mid=(l+r)/2;
    build2(id*2,l,mid);
    build2(id*2+1,mid+1,r);
    st2[id].val = max(st2[id*2].val, st2[id*2+1].val);
}


void push2(int id){
    if(st2[id].lazy==0) return;
    st2[id*2].val+=st2[id].lazy;
    st2[id*2].lazy+=st2[id].lazy;
    st2[id*2+1].val+=st2[id].lazy;
    st2[id*2+1].lazy+=st2[id].lazy;
    st2[id].lazy=0;
}
void up_range2(int id, int l, int r, int lf, int rt, long long v){
    if(lf>r||rt<l) return;
    if(lf<=l&&rt>=r){
        st2[id].val+=v;
        st2[id].lazy+=v;
        return;
    }
    push2(id);
    int mid=(l+r)/2;
    up_range2(id*2,l,mid,lf,rt,v);
    up_range2(id*2+1,mid+1,r,lf,rt,v);
    st2[id].val=max(st2[id*2].val,st2[id*2+1].val);
}












int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readInt(n);
    readInt(q);
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int u;readInt(u);
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        int u; readInt(u);
        t[i]=u;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)    need[tin[i]] = t[i];
    build1(1,1,n);  
    build2(1,1,n);
    while(1){
         int pos=find1(1,1,n,0);
        if(pos==-1) break;
        int node=eu[pos];
        up_point(1,1,n,pos,inf);
        up_range2(1,1,n,tin[node],tout[node],1);
    }
    while(q--){
        int u;long long x; 
        readInt(u);
        readInt(x);
        // cin >> u >> x;
        up_range(1,1,n,tin[u],tout[u],-x);
        while(1){
            int pos=find1(1,1,n,0);
            if(pos==-1) break;
            int node = eu[pos];
            up_point(1,1,n,pos,inf);
            up_range2(1,1,n,tin[node],tout[node],1);
        }
        out+=to_string(st2[1].val);
        out+='\n';
        // cout << st2[1].val << "\n";
    }
    fwrite(out.c_str(), 1, out.size(), stdout);
    return 0;
}