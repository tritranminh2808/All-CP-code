#include <bits/stdc++.h>
using namespace std;
const int N = 60005;
#define ll long long
int n, t[N], x;
ll res = 0ll;

int find(int x) {
	int ans = 0;
	for (; x<N; x+=x&-x) ans += t[x];
	return ans;
}

void update(int x) {
	for (; x>0; x-=x&-x) t[x]++;
}

int main() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		res += find(x+1);
		update(x);
	}

	cout << res <<"\n";


	return 0;
}