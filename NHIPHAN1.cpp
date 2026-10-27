#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sinhDay(int n, string s, vector<string> &ds) {
    if (s.length() == n) {
        ds.push_back(s);
        return;
    }
    if (s.empty() || s.back() == '1') {
        sinhDay(n, s + "1", ds);
        sinhDay(n, s + "0", ds);
    } else {
        sinhDay(n, s + "1", ds);
    }
}

int main() {
		freopen("NHIPHAN1.inp","r",stdin);
	freopen("NHIPHAN1.out","w",stdout);
    int n;
  
    cin >> n;

    vector<string> ds;
    sinhDay(n, "", ds);
    sort(ds.begin(), ds.end());

    for (const auto &s : ds) {
        cout << s << endl;
    }
    
    return 0;
}

