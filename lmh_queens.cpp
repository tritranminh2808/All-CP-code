#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
int n,k;
struct pl{
    int x,y,id;
};
const int pp=1e5+5;
pl a[100005],b[100005];
int nxt_ngang[pp],nxt_doc[pp],lst_ngang[pp],lst_doc[pp],nxt_cx[pp],nxt_cl[pp],lst_cx[pp],lst_cl[pp];
bool cmp_hang(pl p, pl q){
    return p.y<q.y;
}
bool cmp_cot(pl p, pl q){
    return p.x<q.x;
}
long long res[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    unordered_map<int, vector <pl> > hang,cot;
    unordered_map<int ,vector <pl> > cheolen,cheoxuong;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        a[i].x=x;
        a[i].y=y;
        a[i].id=i;
        nxt_ngang[i]=-1;
        nxt_cl[i]=-1;
        nxt_cx[i]=-1;
        nxt_doc[i]=-1;
        lst_cl[i]=-1;
        lst_cx[i]=-1;
        lst_doc[i]=-1;
        lst_ngang[i]=-1;
        hang[x].push_back({x,y,i});
        cot[y].push_back({x,y,i});
        cheoxuong[x-y].push_back({x,y,i});
        cheolen[x+y].push_back({x,y,i});
    }
    for(auto &i:hang){
        auto &v=i.second;
        sort(v.begin(),v.end(),cmp_hang);
        for(int i=1;i<v.size()-1;i++){
            lst_ngang[v[i].id]=v[i-1].id;
            nxt_ngang[v[i].id]=v[i+1].id;
        }
        lst_ngang[v[0].id]=0;
        if(v.size()>1)lst_ngang[v[v.size()-1].id]=v[v.size()-2].id;
        if(v.size()>1)nxt_ngang[v[0].id]=v[1].id;
        nxt_ngang[v[v.size()-1].id]=n+1;
    }
    for(auto &i:cot){
        auto &v=i.second;
        sort(v.begin(),v.end(),cmp_cot);
        for(int i=1;i<v.size()-1;i++){
            lst_doc[v[i].id]=v[i-1].id;
            nxt_doc[v[i].id]=v[i+1].id;
        }
        lst_doc[v[0].id]=0;
        if(v.size()>1)lst_doc[v[v.size()-1].id]=v[v.size()-2].id;
        if(v.size()>1)nxt_doc[v[0].id]=v[1].id;
        nxt_doc[v[v.size()-1].id]=n+1;
    }
    for(auto &i:cheoxuong){
        auto& v=i.second;
        sort(v.begin(),v.end(),cmp_cot);
        for(int i=1;i<v.size()-1;i++){
            lst_cx[v[i].id]=v[i-1].id;
            nxt_cx[v[i].id]=v[i+1].id;
        }
        lst_cx[v[0].id]=0;
        if(v.size()>1)lst_cx[v[v.size()-1].id]=v[v.size()-2].id;
        if(v.size()>1)nxt_cx[v[0].id]=v[1].id;
        nxt_cx[v[v.size()-1].id]=n+1;
    }
    for(auto &i:cheolen){
        auto& v=i.second;
        sort(v.begin(),v.end(),cmp_hang);
        for(int i=1;i<v.size()-1;i++){
            lst_cl[v[i].id]=v[i-1].id;
            nxt_cl[v[i].id]=v[i+1].id;
        }
        lst_cl[v[0].id]=0;
        if(v.size()>1)lst_cl[v[v.size()-1].id]=v[v.size()-2].id;
        if(v.size()>1)nxt_cl[v[0].id]=v[1].id;
        nxt_cl[v[v.size()-1].id]=n+1;
    }
    a[0].x=0;
    a[0].y=0;
    a[n+1].x=k+1;
    a[n+1].y=k+1;
    for(int i=1;i<=n;i++){
        // cout << nxt_cx[i] << " " << lst_cx[i] << endl;
        res[i]+=a[i].x-a[lst_doc[i]].x-1;
        res[i]+=a[i].y-a[lst_ngang[i]].y-1;
        res[i]+=a[nxt_doc[i]].x-a[i].x-1;
        res[i]+=a[nxt_ngang[i]].y-a[i].y-1;

        //tinh cheo
        if(lst_cx[i]==0) res[i]+=min(a[i].x-1, a[i].y-1);
        else res[i]+=a[i].x-a[lst_cx[i]].x-1;
        
        if(nxt_cx[i]==n+1) res[i]+=min(k-a[i].x,k-a[i].y);
        else res[i]+=a[nxt_cx[i]].x-a[i].x-1;

        if(lst_cl[i]==0) res[i]+=min(k-a[i].x,a[i].y-1);
        else res[i]+=a[i].y-a[lst_cl[i]].y-1;

        if(nxt_cl[i]==n+1) res[i]+=min(a[i].x-1,k-a[i].y);
        else res[i]+=a[nxt_cl[i]].y-a[i].y-1;
    }
    for(int i=1;i<=n;i++) cout << res[i] << "\n";
    return 0;
}