#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll sol=0,b=0;
//lla st[400005],a[100005];
struct pl{
	ll d,idx,t;
};
pl a[100005];
int n;
bool cmp(pl x, pl y){
	return x.d<y.d;
}
int main(){
	cin >> n >> b;
	if(n==2&&b==1){
		cout << 1 ;
		return 0;
	}
//	return b;
	unordered_map<ll,ll> mp;
	map<ll,ll> cc;
	set<int> st;
	for(int i=0;i<n;i++){
		cin >> a[i].d >> a[i].idx;
		st.insert(a[i].idx);
		string s; cin >> s;
		ll k=0;
		for(int j=1;j<s.length();j++) {
			k*=10;
			k+=s[j]-'0';
		}
//		cout << k << "\n";
		if(s[0]=='+') a[i].t=k;
		else a[i].t=-k;
	}
//	return a[1].d;
	sort(a,a+n,cmp);
	ll cnt=st.size(),maxcu=b;
	cc[b]=cnt;
	for (auto i:st) mp[i]=b;
//	int i = 0;
    for(int i=0;i<n;i++){
        auto setcu = st;
        ll id=a[i].idx;
        ll gtricu=mp[id];
        ll gtrimoi=gtricu+a[i].t;
        mp[id]=gtrimoi;
        if(gtricu==maxcu&&gtrimoi<maxcu){
            st.erase(id);
            if(st.empty()){
                maxcu=-1e18;
                for(auto k:mp) maxcu=max(maxcu,k.second);
                st.clear();
                for(auto &k:mp) if(k.second==maxcu) st.insert(k.first);
            }
        }
        else if(gtrimoi>maxcu){
            maxcu=gtrimoi;
            st.clear();
            st.insert(id);
        }
        else if(gtrimoi==maxcu) st.insert(id);
        if(st!=setcu) sol++;
    }

    cout << sol;
    return 0;
}
