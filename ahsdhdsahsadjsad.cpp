#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, comp_max;
    DSU(int n): p(n+1), comp_max(n+1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    // unite hai comp chứa a và b, trả về root mới
    int unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a==b) return a;
        // gộp b vào a
        p[b] = a;
        comp_max[a] = max(comp_max[a], comp_max[b]);
        return a;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    vector<int> A(N+1), dp(N+1,0);
    for(int i=1; i<=N; i++) 
        cin >> A[i];

    // DSU + comp_max sẽ lưu max dp trong mỗi component
    DSU dsu(N);
    // đánh dấu đã activate (đã union vào DSU) những chỉ số có A[...] < hiện tại
    vector<bool> activated(N+1,false);
    // để tìm predecessor/successor nhanh
    set<int> S;

    // ban đầu dp[i]=1 (bắt đầu từ chính ngày đó)
    for(int i=1; i<=N; i++)
        dp[i] = 1;

    // sắp xếp các vị trí theo A tăng dần
    vector<pair<int,int>> ord;
    ord.reserve(N);
    for(int i=1; i<=N; i++)
        ord.emplace_back(A[i], i);
    sort(ord.begin(), ord.end());

    // xử lý theo nhóm cùng giá trị A để tránh máy lẫn lộn bằng nhau
    for(int ptr = 0; ptr < N; ){
        int j = ptr;
        // tìm nhóm ord[ptr..j-1] cùng A
        while(j < N && ord[j].first == ord[ptr].first) ++j;

        // 1) với mỗi i trong nhóm, tính dp[i] = comp_max[root_of_i] + 1
        //    (nếu không có comp nào, comp_max = 0 → dp = 1 như đã khởi)
        for(int k = ptr; k < j; k++){
            int i = ord[k].second;
            int r = dsu.find(i);
            dp[i] = max(dp[i], dsu.comp_max[r] + 1);
        }

        // 2) rồi mới activate & union vào DSU, để những lần xử sau chỉ dùng các A nhỏ hơn
        for(int k = ptr; k < j; k++){
            int i = ord[k].second;
            activated[i] = true;
            // đặt comp_max tại chính nó
            int ri = dsu.find(i);
            dsu.comp_max[ri] = dp[i];

            // thêm vào set để tìm neighbor
            auto it = S.insert(i).first;

            // check predecessor
            if(it != S.begin()){
                auto itp = prev(it);
                if((long long)i - *itp <= D){
                    int newr = dsu.unite(i, *itp);
                    // đảm bảo comp_max của root mới được cập nhật
                    dsu.comp_max[newr] = max(dsu.comp_max[newr], dp[i]);
                }
            }
            // check successor
            auto its = next(it);
            if(its != S.end()){
                if((long long)*its - i <= D){
                    int newr = dsu.unite(i, *its);
                    dsu.comp_max[newr] = max(dsu.comp_max[newr], dp[i]);
                }
            }
        }

        ptr = j;
    }

    // kết quả: phải chọn ngày N cuối cùng
    cout << dp[N] << "\n";
    return 0;
}
