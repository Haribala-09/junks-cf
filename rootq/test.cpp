#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

typedef long long ll;

ll f(ll x, ll k, ll a, ll b) {
    return x + k * (a + x) - b;
}

ll g(ll x, ll a, ll b) {
    ll denom = a + x;
    ll k = (b + denom - 1) / denom;
    return f(x, k, a, b);
}

ll solve2(ll a, ll b) {
    if (a >= b) {
        return a % b;
    }

    ll bound = LLONG_MAX;
    ll i = 0;

    while (i < bound) {
        ll current = g(i, a, b);
        if (current < bound) {
            bound = current;
        }
        i++;
    }

    return bound;
}

int main() {
    ofstream input("input.txt"), output("output.txt");
    int T = 1000;
    input << T << '\n';

    for (int i = 0; i < T; ++i) {
        ll A = 1 + rand() % 10000000;
        ll B = A + 1 + rand() % 10000000;

        input << A << '\n' << B << '\n';
        output << solve2(A, B) << '\n';
    }

    input.close();
    output.close();
    return 0;
}
