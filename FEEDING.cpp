#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    long long total_cost = 0;
    int min_price = p[0];

    for (int i = 0; i < n; ++i) {
        if (p[i] < min_price) {
            min_price = p[i];
        }
        total_cost += static_cast<long long>(min_price) * a[i];
    }

    std::cout << total_cost << std::endl;

    return 0;
}

