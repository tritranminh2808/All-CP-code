#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

struct Query { int l, r, id; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if(!(cin >> n >> q)) return 0;

    vector<ll> origA(n+1), origB(n+1);
    for(int i=1;i<=n;i++) cin >> origA[i];
    for(int i=1;i<=n;i++) cin >> origB[i];

    vector<Query> Q1(q+1), Q2(q+1);
    for(int i=1;i<=q;i++){
        int l,r,x,y; cin >> l >> r >> x >> y;
        Q1[i] = {l,r,i};
        Q2[i] = {x,y,i};
    }

    // assign a random 64-bit hash to each distinct original value
    unordered_map<ll, ull> H;
    H.reserve( (size_t)(n*2) );
    mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    auto getHash = [&](ll v)->ull{
        auto it = H.find(v);
        if(it!=H.end()) return it->second;
        ull h = rng();
        if(h==0) h = 1; // avoid zero (optional)
        H[v]=h;
        return h;
    };

    vector<ull> A(n+1), B(n+1);
    for(int i=1;i<=n;i++) A[i] = getHash(origA[i]);
    for(int i=1;i<=n;i++) B[i] = getHash(origB[i]);

    // Fenwick tree with XOR
    auto make_bit = [&](int sz){ return vector<ull>(sz+1, 0ULL); };
    auto fenwick_update = [&](vector<ull> &bit, int idx, ull val){
        int N = (int)bit.size()-1;
        for(; idx<=N; idx += idx & -idx) bit[idx] ^= val;
    };
    auto fenwick_pref = [&](vector<ull> &bit, int idx){
        ull res = 0;
        for(; idx>0; idx -= idx & -idx) res ^= bit[idx];
        return res;
    };

    // Helper to process one array (A or B)
    auto process = [&](const vector<ull>& arr, const vector<Query>& queries)->vector<ull>{
        // build nxt array: nxt[i] = next index > i with same value, or 0
        vector<int> nxt(n+2, 0);
        unordered_map<ull,int> last;
        last.reserve(n*2);
        for(int i=n;i>=1;i--){
            auto it = last.find(arr[i]);
            nxt[i] = (it==last.end() ? 0 : it->second);
            last[arr[i]] = i;
        }

        // copy queries [1..q] into vector and sort by l ascending
        vector<Query> qs;
        qs.reserve(q);
        for(int i=1;i<=q;i++) qs.push_back(queries[i]);
        sort(qs.begin(), qs.end(), [](const Query &x, const Query &y){
            if(x.l != y.l) return x.l < y.l;
            return x.r < y.r;
        });

        vector<ull> bit = make_bit(n);
        unordered_map<ull,int> seen; seen.reserve(n*2);

        // initialize with first sorted query's l
        int curL = qs[0].l;
        for(int i=curL;i<=n;i++){
            if(seen.find(arr[i])==seen.end()){
                fenwick_update(bit, i, arr[i]);
                seen[arr[i]] = 1;
            }
        }
        vector<ull> out(q+1);
        // answer first
        out[ qs[0].id ] = fenwick_pref(bit, qs[0].r) ^ fenwick_pref(bit, qs[0].l - 1);

        // process next queries (move L to right)
        for(size_t qi=1; qi<qs.size(); ++qi){
            int newL = qs[qi].l;
            // move curL -> newL: for each j in [curL, newL-1] remove contribution at j,
            // and if nxt[j] exists, add contribution at nxt[j]
            for(int j=curL; j<newL; ++j){
                // remove arr[j] at position j (it was the current first occurrence)
                fenwick_update(bit, j, arr[j]); // XOR again removes
                if(nxt[j]) fenwick_update(bit, nxt[j], arr[j]); // add next occurrence as first
            }
            curL = newL;
            out[ qs[qi].id ] = fenwick_pref(bit, qs[qi].r) ^ fenwick_pref(bit, qs[qi].l - 1);
        }
        return out;
    };

    // process A and B
    vector<ull> resA = process(A, Q1);
    vector<ull> resB = process(B, Q2);

    // compare by original query id order 1..q
    for(int i=1;i<=q;i++){
        if(resA[i] == resB[i]) cout << "YES\n"; else cout << "NO\n";
    }

    return 0;
}
