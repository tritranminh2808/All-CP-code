#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    stack<pair<ll,ll>> st; // {height, count}
    ll sum = 0, best = 0;

    for(int i = 0; i < n; i++){
        ll cnt = 1;
        while(!st.empty() && st.top().first < a[i]){
            auto [h, c] = st.top(); st.pop();
            sum -= h * c;
            cnt += c;
        }
        st.push({a[i], cnt});
        sum += a[i] * cnt;

        best = max(best, sum);
    }

    cout << best << "\n";
}
