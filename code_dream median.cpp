#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<
    pair<long long,int>,
    null_type,
    less<pair<long long,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> oset;
int n; 
int a[100005];
struct fenwick {
    int n;
    vector<int> f;
    fenwick(int _n): n(_n), f(n+1,0) {}
    void update(int i, int v=1){
        for(; i<=n; i+=i&-i) f[i]+=v;
    }
    int query(int i) const {
        int s=0;
        for(;i>0;i-=i&-i) s+=f[i];
        return s;
    }
};
int esp;
bool check(int x){
	vector <int> v(n+1);
	v[0]=0;
	for(int i=1;i<=n;i++){
		v[i]=a[i];
		if(v[i]>=x) v[i]=1;
		else v[i]=-1;
		v[i]=v[i-1]+v[i];
	}
	fenwick st(2*n+5);
    long long cnt=0;
    st.update(esp,1);
    for(int i=1;i<=n;i++){
        cnt+=st.query(v[i]+esp);
        st.update(v[i]+esp, 1);
    }
//	cout << x << " " ;
//	for(int i=1;i<=n;i++) cout << v[i] << " ";
//	cout << endl;
	long long S=1LL*(n+1)*n/2;
	return cnt>=(S+1)/2;
}
void cook(){
	int l=0,r=1000000001;
	int sol=0;
	while(l<=r){
		int mid=(l+r)/2;
//		cout << mid << endl;
		if(check(mid)) {
			l=mid+1;
			sol=mid;
		}
		else r=mid-1;
	}
	cout << sol;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	esp=n+1;
	for(int i=1;i<=n;i++) cin >> a[i];
	cook();
	return 0;
}


