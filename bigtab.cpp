#include <bits/stdc++.h>
using namespace std;
int h[1005][1005];
int l[1005][1005],r[1005][1005];
int xuli(vector<vector<int>> ma) {
    if (ma.empty()) return 0;
    int m = ma.size();
    int n = ma[0].size();
//    vector<int> h(n + 1, 0);
    int sss = 0;
    for (int j = 0; j < n; ++j)  h[0][j]=1;
    stack<int> s;
    for (int j = 0; j <n; ++j) {
        while (!s.empty()&& h[0][j] <= h[0][s.top()]&&ma[0][j]==ma[0][s.top()]) s.pop();
        if(!s.empty())l[0][j]=s.top();
        else l[0][j]=-1;
        s.push(j);
    }
    for (int i=1;i<m;++i) {
        for (int j = 0; j < n; ++j) {
            if (ma[i][j] == ma[i-1][j]) h[i][j] =h[i-1][j]+1;
            else h[i][j] = 1;
        }
        stack<int> st;
        for (int j = 0; j < n; ++j) {
            while (!st.empty()&& h[i][j] <= h[i][st.top()]&&ma[i][j]==ma[i][st.top()]) st.pop();
            if(!st.empty())l[i][j]=st.top();
            else l[i][j]=-1;
            st.push(j);
        }
    }
    while(!s.empty()) s.pop();
    for (int j = n-1; j>=0; --j) {
        while (!s.empty()&& h[0][j] <= h[0][s.top()]&&ma[0][j]==ma[0][s.top()]) s.pop();
        if(!s.empty())r[0][j]=s.top();
        else r[0][j]=n;
        s.push(j);
    }
    for (int i=1;i<m;++i) {
        stack<int> st;
        for (int j = n-1; j >=0; --j) {
            while (!st.empty()&& h[i][j] <= h[i][st.top()]&&ma[i][j]==ma[i][st.top()]) st.pop();
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
    return sss;
}
int main() {
//	freopen("maxrect.inp","r",stdin);
//	freopen("maxrect.out","w",stdout);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << xuli(a);
    return 0;
}
