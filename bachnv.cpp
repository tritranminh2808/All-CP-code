#include <bits/stdc++.h>
using namespace std;
map<pair<long long,long long>, pair<long long,int>> ok;
int n, md;
vector<array<long long,3>> a;
long long res = LLONG_MIN;
int mk1 = 0, mk2 = 0;
void backtrack(int id, long long sl, long long sm, long long sw, int mk)
{
    if (id == md)
    {
        long long dm = sl - sm;
        long long dw = sl - sw;
        long long ln = sl + sm + sw;
        auto ck = make_pair(dm, dw);
        auto it = ok.find(ck);
        if (it == ok.end() || it->second.first < ln)
        {
            ok[ck] = {ln, mk};
        }
        return;
    }
    auto &v = a[id];
    backtrack(id+1, sl+v[0], sm+v[1], sw, mk*3 + 0);
    backtrack(id+1, sl+v[0], sm, sw+v[2], mk*3 + 1);
    backtrack(id+1, sl,sm+v[1], sw+v[2], mk*3 + 2);
}

void backtrack2(int id, long long sl, long long sm, long long sw, int mk)
{
    if (id == n)
    {
        long long dm = sl - sm;
        long long dw = sl - sw;
        auto ck = make_pair(-dm, -dw);
        auto it = ok.find(ck);
        if (it != ok.end())
        {
            long long tn = sl + sm + sw + it->second.first;
            if (tn > res)
            {
                res = tn;
                mk1 = it->second.second;
                mk2 = mk;
            }
        }
        return;
    }
    auto &v = a[id];
    backtrack2(id+1, sl+v[0], sm+v[1], sw, mk*3 + 0);
    backtrack2(id+1, sl+v[0], sm, sw+v[2], mk*3 + 1);
    backtrack2(id+1, sl, sm+v[1], sw+v[2], mk*3 + 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    md = n / 2;
    backtrack(0,0,0,0,0);
    backtrack2(md,0,0,0,0);
    if (res == LLONG_MIN)
    {
        cout << "Impossible\n";
        return 0;
    }
    vector<string> res(n);
    int mk = mk2;
    for(int i = n-1; i >= md; i--)
    {
        int t = mk % 3;
        mk /= 3;
        if (t == 0) res[i] = "LM";
        else if (t == 1) res[i] = "LW";
        else res[i] = "MW";
    }
    mk = mk1;
    for(int i = md-1; i >= 0; i--)
    {
        int t = mk % 3;
        mk /= 3;
        if (t == 0) res[i] = "LM";
        else if (t == 1) res[i] = "LW";
        else res[i] = "MW";
    }
    for(int i = 0; i < n; i++)
    {
        cout << res[i] << "\n";
    }
}