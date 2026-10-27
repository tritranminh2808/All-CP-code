#include <bits/stdc++.h>
using namespace std;
struct P{int x,y,i;P*l,*r;};
int D;
struct Cmp{bool operator()(P const &a,P const &b)const{return D? a.y<b.y : a.x<b.x;}};
vector<P> v;
P* b(int l,int r,int d){
    if(l>=r) return nullptr;
    int m=(l+r)/2; D=d%2;
    nth_element(v.begin()+l, v.begin()+m, v.begin()+r, Cmp());
    P* p=&v[m];
    p->l=b(l,m,d+1); p->r=b(m+1,r,d+1);
    return p;
}
int bd, ans;
void q(P* p, P const &t, int d){
    if(!p) return;
    int d0=abs(p->x-t.x)+abs(p->y-t.y);
    if(p->i!=t.i && (d0<bd || (d0==bd && p->i<ans))){ bd=d0; ans=p->i; }
    int diff=(d==0? t.x-p->x : t.y-p->y);
    P* f=diff<0? p->l : p->r;
    P* g=diff<0? p->r : p->l;
    q(f,t,1-d);
    if(abs(diff)<bd) q(g,t,1-d);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; if(!(cin>>n)) return 0;
    v.resize(n);
    for(int i=0;i<n;i++){ cin>>v[i].x>>v[i].y; v[i].i=i+1; v[i].l=v[i].r=nullptr; }
    P* r=b(0,n,0);
    vector<int> a(n);
    for(int i=0;i<n;i++){ bd=INT_MAX; ans=-1; q(r,v[i],0); a[i]=ans; }
    for(int i=0;i<n;i++) cout<<a[i]<<(i+1<n?' ':'\n');
}

