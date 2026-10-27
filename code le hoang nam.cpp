#pragma GCC optimize("03, unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int m, n;
int x, y, aa, bb;
int mark[1001][1001], mark2[5][1001][1001];
struct cap
{
    int fi;
    int se;
    int di;
    string way;
};
string res;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> x >> y >> aa >> bb;
    int u, v;
    while(cin >> u >> v)
    {
        mark[u][v] = 1;
    }
    queue<cap> q;
    q.push({x, y, 0, res});
    while(q.size())
    {
        auto h = q.front();
        q.pop();
        pair<int, int> a = {h.fi - 1, h.se};
        pair<int, int> b = {h.fi, h.se - 1};
        pair<int, int> c = {h.fi, h.se + 1};
        pair<int, int> d = {h.fi + 1, h.se};
        if (h.fi == aa && h.se == bb)
        {
            if (res.empty() || h.way.size() < res.size() || (h.way.size() == res.size() && h.way < res))
            {
                res = h.way;
            }
            continue;
        }
        if (res.size() && res.size() < h.way.size()) break;
        if (h.di == 0)
        {
            if (c.se <= n && !mark[c.fi][c.se] && !mark2[1][c.fi][c.se])
            {
                mark2[1][c.fi][c.se] = 1;
                q.push({c.fi, c.se, 1, h.way + "E"});
            }
            if (a.fi >= 0 && !mark[a.fi][a.se] && mark2[4][a.fi][a.se] == 0)
            {
                mark2[4][a.fi][a.se] = 1;
                q.push({a.fi, a.se, 4, h.way + "N"});
            }
            if (d.fi <= m && !mark[d.fi][d.se] && mark2[2][d.fi][d.se] == 0)
            {
                mark2[2][d.fi][d.se] = 1;
                q.push({d.fi, d.se, 2, h.way + "S"});
            }
            if (b.se >= 0 && !mark[b.fi][b.se] && mark2[3][b.fi][b.se] == 0)
            {
                mark2[3][b.fi][b.se] = 1;
                q.push({b.fi, b.se, 3, h.way + "W"});
            }
        }
        else if (h.di == 1)
        {
            if (0) ;
            else
            {
                if (a.fi >= 0 && !mark[a.fi][a.se] && mark2[4][a.fi][a.se] == 0)
                {
                    mark2[4][a.fi][a.se] = 1;
                    q.push({a.fi, a.se, 4, h.way + "N"});
                }
                if (d.fi <= m && !mark[d.fi][d.se] && mark2[2][d.fi][d.se] == 0)
                {
                    mark2[2][d.fi][d.se] = 1;
                    q.push({d.fi, d.se, 2, h.way + "S"});
                }
                if (b.se >= 0 && !mark[b.fi][b.se] && mark2[3][b.fi][b.se] == 0)
                {
                    mark2[3][b.fi][b.se] = 1;
                    q.push({b.fi, b.se, 3, h.way + "W"});
                }
            }
        }
        else if (h.di == 2)
        {
            if (0)
            {
                ;
            }
            else
            {
                if (c.se <= n && !mark[c.fi][c.se] && mark2[1][c.fi][c.se] == 0)
                {
                    mark2[1][c.fi][c.se] = 1;
q.push({c.fi, c.se, 1, h.way + "E"});
                }
                if (a.fi >= 0 && !mark[a.fi][a.se] && mark2[4][a.fi][a.se] == 0)
                {
                    mark2[4][a.fi][a.se] = 1;
                    q.push({a.fi, a.se, 4, h.way + "N"});
                }
                if (b.se >= 0 && !mark[b.fi][b.se] && mark2[3][b.fi][b.se] == 0)
                {
                    mark2[3][b.fi][b.se] = 1;
                    q.push({b.fi, b.se, 3, h.way + "W"});
                }
            }
        }
        else if (h.di == 3)
        {
            if (0)
            {
                ;
            }
            else
            {
                if (c.se <= n && !mark[c.fi][c.se] && mark2[1][c.fi][c.se] == 0)
                {
                    mark2[1][c.fi][c.se] = 1;
                    q.push({c.fi, c.se, 1, h.way + "E"});
                }
                if (a.fi >= 0 && !mark[a.fi][a.se] && mark2[4][a.fi][a.se] == 0)
                {
                    mark2[4][a.fi][a.se] = 1;
                    q.push({a.fi, a.se, 4, h.way + "N"});
                }
                if (d.fi <= m && !mark[d.fi][d.se] && mark2[2][d.fi][d.se] == 0)
                {
                    mark2[2][d.fi][d.se] = 1;
                    q.push({d.fi, d.se, 2, h.way + "S"});
                }
            }
        }
        else if (h.di == 4)
        {
            if (0)
            {
                ;
            }
            else
            {
                if (c.se <= n && !mark[c.fi][c.se] && mark2[1][c.fi][c.se] == 0)
                {
                    mark2[1][c.fi][c.se] = 1;
                    q.push({c.fi, c.se, 1, h.way + "E"});
                }
                if (b.se >= 0 && !mark[b.fi][b.se] && mark2[3][b.fi][b.se] == 0)
                {
                    mark2[3][b.fi][b.se] = 1;
                    q.push({b.fi, b.se, 3, h.way + "W"});
                }
                if (d.fi <= m && !mark[d.fi][d.se] && mark2[2][d.fi][d.se] == 0)
                {
                    mark2[2][d.fi][d.se] = 1;
                    q.push({d.fi, d.se, 2, h.way + "S"});
                }
            }
        }
    }
    cout << res;
    return 0;
}
