#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

int f(int x) {
    int s = 0;
    while (x > 0) {
        int d = x % 10;
        s += d * d;
        x /= 10;
    }
    return s;
}

pair<int, vector<int>> seq(int x) {
    unordered_set<int> seen;
    vector<int> res;
    while (seen.find(x) == seen.end()) {
        seen.insert(x);
        res.push_back(x);
        x = f(x);
    }
    res.push_back(x);
    return make_pair(res.size(), res);
}

int main() {
	freopen("TIMSO.inp","r",stdin);
	freopen("TIMSO.out","w",stdout);
    int a, b;
    cin >> a >> b;

    int mx_len = 0;
    vector<int> mx_seq;
    int best_x = a;

    for (int x = a; x <= b; ++x) {
        pair<int, vector<int>> r = seq(x);
        int len = r.first;
        vector<int> s = r.second;

        if (len > mx_len) {
            mx_len = len;
            mx_seq = s;
            best_x = x;
        }
    }

    cout << best_x << " " << mx_len << endl;
    for (int num : mx_seq) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

