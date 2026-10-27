#include<bits/stdc++.h>
using namespace std;
struct Q{long long y,x1,x2;int i;long long a;};
struct E{long long y1,y2,x;};
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;cin>>n;vector<Q>q(n);
for(int i=0;i<n;i++){
long long x1,x2,y;cin>>x1>>x2>>y;
if(x2<x1)swap(x1,x2);
q[i]={y,x1,x2,i,0};
}
int m;cin>>m;vector<long long>vx(m),vy(m);
for(int i=0;i<m;i++)cin>>vx[i]>>vy[i];
vector<E>e;e.reserve(m);
for(int i=0;i<m;i++){
long long xA=vx[i],yA=vy[i],xB=vx[(i+1)%m],yB=vy[(i+1)%m];
if(xA==xB && yA!=yB){
if(yA<yB)e.push_back({yA,yB,xA});
else e.push_back({yB,yA,xA});
}
}
vector<long long>Y;Y.reserve(2*m+n);
for(auto &v:e){Y.push_back(v.y1);Y.push_back(v.y2);}
for(auto &v:q)Y.push_back(v.y);
sort(Y.begin(),Y.end());
Y.erase(unique(Y.begin(),Y.end()),Y.end());
unordered_map<long long,vector<pair<long long,int>>>ev;
ev.reserve(2*m);ev.max_load_factor(0.7f);
for(auto &v:e){
ev[v.y1].push_back({v.x,1});
ev[v.y2].push_back({v.x,-1});
}
sort(q.begin(),q.end(),[](auto&a,auto&b){return a.y<b.y;});
multiset<long long>s;int qi=0;vector<long long>ans(n,0);
for(auto v:Y){
 if(ev.find(v)!=ev.end()){
  for(auto &c:ev[v]){
   long long x=c.first;int f=c.second;
   if(f==1)s.insert(x);
   else{auto it=s.find(x);if(it!=s.end())s.erase(it);}
  }
 }
 if(s.empty()){
  while(qi<n && q[qi].y==v){ans[q[qi].i]=0;qi++;}
 }else{
  vector<long long>t;t.reserve(s.size());
  for(auto &x:s)t.push_back(x);
  sort(t.begin(),t.end());
  t.erase(unique(t.begin(),t.end()),t.end());
  vector<pair<long long,long long>>g;
  for(int j=0;j+1<(int)t.size();j+=2)g.push_back({t[j],t[j+1]});
  while(qi<n && q[qi].y==v){
   long long l=q[qi].x1,r=q[qi].x2,c=0;
   for(auto &seg:g){
    long long x1=seg.first,x2=seg.second;
    if(x2<=l)continue;
    if(x1>=r)break;
    long long L=max(x1,l),R=min(x2,r);
    if(R>L)c+=(R-L);
   }
   ans[q[qi].i]=c;qi++;
  }
 }
}
for(int i=0;i<n;i++)cout<<ans[i]<<'\n';
return 0;
}

