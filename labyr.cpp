#include <bits/stdc++.h>
using namespace std;
int m,n,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
string a[1000];
bool vat[1000][1000];
pair<int,int> trc[1000][1000];

int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++)cin>>a[i];
    int sx,sy;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(a[i][j]=='E')sx=i,sy=j;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vat[sx][sy]=1;
    pair<int,int> endP={-1,-1};
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        if(x==0||x==m-1||y==0||y==n-1){endP={x,y};break;}
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<0||ny<0||nx>=m||ny>=n)continue;
            if(vat[nx][ny]||a[nx][ny]!='O')continue;
            vat[nx][ny]=1;
            trc[nx][ny]={x,y};
            q.push({nx,ny});
        }
    }
    if(endP.first==-1){
        cout<<-1;
        return 0;
    }
    vector<pair<int,int>> trace;
    for(auto p=endP;!(p.first==sx&&p.second==sy);p=trc[p.first][p.second])
        trace.push_back(p);
    trace.push_back({sx,sy});
    reverse(trace.begin(),trace.end());
    cout<<trace.size()<<'\n';
    for(auto [x,y]:trace)cout<<x+1<<" "<<y+1<<'\n';
}
