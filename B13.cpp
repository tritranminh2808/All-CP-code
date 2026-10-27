#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("B13.inp","r",stdin);
	freopen("B13.out","w",stdout);
    long double a1, b1, c1;
    long double a2, b2, c2;

   
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    
    long double det = 1.0*a1 * b2 - 1.0*a2 * b1;

    if (det != 0) {
       
        long double x = (c1 * b2*1.0 - c2 * b1*1.0) / 1.0/det;
        long double y = (a1 * c2*1.0 - a2 * c1*1.0) / 1.0/det;
        cout << fixed << setprecision(2) << x << " " << fixed << setprecision(2) << y << endl;
    } else {
       
        if (a1 == 0 && b1 == 0 && a2 == 0 && b2 == 0) {
            if (c1 == 0 && c2 == 0) {
                cout << "vo so nghiem"; return 0;
            } else {
                cout << "vo nghiem"; return 0;
            }
        } else if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) {
            cout << "vo so nghiem"; return 0;
        } else {
            cout <<  "vo nghiem"; return 0;
        }
    }

    return 0;
}

