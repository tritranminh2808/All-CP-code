#include <bits/stdc++.h>
using namespace std;

int main() {
    long double a, b, c;
    long double delta, x1, x2;
    cin >> a >> b >> c;
    if(a==b&&a==c&&a==0){
        cout << "Phuong trinh vo so nghiem";
        return 0;
    }
    delta = b * b - 4.0 * a * c;

    if (delta < 0.0) {
        cout << "Phuong trinh vo nghiem" << endl;
    } else if (delta == 0.0) {
        x1 = -b / (2.0 * a);
        cout << fixed << setprecision(3) << x1;
    } else {
        x1 = (-b - sqrt(delta)) / (2.0 * a);
        x2 = (-b + sqrt(delta)) / (2.0 * a);
        cout << fixed << setprecision(3) <<  min(x1,x2)<< " " << max(x1,x2) << endl;
    }
    return 0;
}
