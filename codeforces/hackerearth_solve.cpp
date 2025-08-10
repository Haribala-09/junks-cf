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

int lpf(int x){
    if(x<=3) return x;

    int ans=1;
    for(int i=2;i*i<=x;i++){
        if(x%i!=0) continue;
        ans=max(ans,i);
        while(x%i==0) x/=i;
    }
    ans=max(ans,x);
    return ans;
}
void solve() {
    int a,b;
    cin>>a>>b;

    if(a>b){
        // k=1
        cout<<a-b<<'\n';
    }
    else{
        int k=b/a;
        int mod=b%a;
        int x=(k+mod-1)/k;
        int y=k*(a+x)-b;

        int mn=((b+a-1)/a)*a-b;
        // if(mn<x+y) cout<<0<<' '<<mn<<'\n';
        // else cout<<x<<" "<<y<<'\n';
        if(mn<x+y) cout<<mn<<'\n';
        else cout<<x<<' '<<y<<'\n';
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
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}