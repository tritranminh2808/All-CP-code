#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const pair< int , int > & x, const pair < int , int > & y){
	return x.first * y.second < y.first * x.second;
}
int gcd(int a, int b) {
    if(b==0)return a;
    else return gcd(b,a%b);
}
vector< pair < int, int > > generateSimpleFractions(int n) {
    vector< pair < int , int > > fractions;
    for (int b = 1; b <= n; ++b) {
        for (int a = 1; a <= n; ++a) {
            if (gcd(a, b) == 1) {
                fractions.push_back(make_pair(a, b));
            }
        }
    }
    
   
    sort(fractions.begin(), fractions.end(),cmp);
    
    return fractions;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair < int , int > > fractions = generateSimpleFractions(n);
    for (int i=0;i< fractions.size();i++) {
        cout << fractions[i].first << " " << fractions[i].second << "\n";
    }
    
    return 0;
}

