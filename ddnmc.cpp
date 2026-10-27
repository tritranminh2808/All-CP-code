#include <bits/stdc++.h>
#define int int64_t
#define str string
#define vtr vector
#define vi vtr<int>
#define vc vtr<char>
#define vb vtr<bool>
#define vs vtr<str>
#define pii pair<int, int>
#define fd(v, s, e) for(size_t v = s; v <= e; ++v)
#define bk(v, s, e) for(size_t v = s; v >= e; --v)
#define farr(i, arr) for(auto i: arr)
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()
using namespace std;
const int
 dx[4] = {0, 1, 0, -1},
 dy[4] = {1, 0, -1, 0};
int m, n, x, y;
vtr<vi> a, trace;
signed main()
{

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("DDNNMC.inp", "r", stdin);
	freopen("DDNNMC.out", "w", stdout);
	cin >> m >> n >> x >> y;
	a.assign(m + 2, vi(n + 2, -1));
	fd (i, 1, m) fd (j, 1, n) cin >> a[i][j];
	if (a[x][y] == 1) return cout << 0, 0;
	trace.assign(m + 2, vi(n + 2, -1));
	trace[x][y] = 0;
	queue<pii> q;
	q.push({x, y});
	while (q.size())
	{
		pii xy = q.front(); q.pop();
		x = xy.first; y = xy.second;
		fd (d, 0, 3)
		{
			int _x = x + dx[d], _y = y + dy[d];
			if (trace[_x][_y] >= 0) continue;
			if (a[_x][_y] == 1) continue;
			if (_x < 1 || _x > m || _y < 1 || _y > n)
				return cout << trace[x][y], 0;
			q.push({_x, _y});
			trace[_x][_y] = trace[x][y] + 1;
		}
	}
	cout << 0;
	return 0;

}
