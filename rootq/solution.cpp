#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std;

using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;
void solve() {
    int a, b;
    cin >> a >> b;

    if (a > b) {
        cout << a - b << " " << 0 << '\n';
    } else {
        int mn = ((b + a - 1) / a) * a - b;
        int best_x = 0, best_y = mn;

        for (int k = (b + a - 1) / a; k <= 1000000; ++k) {
            int delta = b - k * a;
            int x = (delta + k - 1) / k;
            if (x < 0) continue;

            int y = k * (a + x) - b;
            if (y < 0) continue;

            if (x + y < best_x + best_y) {
                best_x = x;
                best_y = y;
            }
        }

        cout << best_x + best_y << '\n';
    }
}


int f(int x, int k, int a, int b) {
    return x + k * (a + x) - b;
}

int g(int x, int a, int b) {
    int denom = a + x;
    int k = (b + denom - 1) / denom;
    return f(x, k, a, b);
}

void solve2() {
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        cout<<a % b<<'\n';
        return;
    }

    int result = INT_MAX;
    int i = 0;
    while (i < result) {
        int current = g(i, a, b);
        if (current < result) {
            result = current;
        }
        i++;
    }
    cout<<result<<'\n';
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t=1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}