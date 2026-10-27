#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],id[100005];
bool cmp(int x,int y){
    return a[x]>a[y];
}
struct pl{
    vector <int> line;
    vector <long double> point;
    pl(){
        point.push_back(-1e18);
    }
    long double g(int i, int j){
        return (long double) 1.0*(b[j]-b[i])/(a[i]-a[j]);
    }
    void add(int id){
        while(!line.empty()){ 
            // song song
            if(a[line.back()]==a[id]){
                if(b[line.back()]>b[id]){
                    line.pop_back();
                    if(!line.empty()) point.pop_back();
                }
                else break;
            }
            else{
                if(line.size()>=2&&g(id,line.back())<=g(id,line[line.size()-2])){
                    line.pop_back();
                    point.pop_back();
                }
                else break;
                
            }
            
        }
        if(line.empty()||a[line.back()]!=a[id]){
            if(!line.empty()) point.push_back(g(id,line.back()));
            line.push_back(id);
        }
    }
    long long get(int x){
        int j=lower_bound(point.begin(),point.end(),x)-point.begin()-1;
        return 1ll*a[line[j]]*x+b[line[j]];
    }
};
pl f;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[id[i]=i] >> b[i];
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;++i) f.add(id[i]); 
    int m; cin >> m;
    while(m--){
        int x; cin>> x;
        cout<< f.get(x) << "\n";
    }
    return 0;
}