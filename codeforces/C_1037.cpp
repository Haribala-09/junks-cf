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
    int n,k; cin>>n>>k;

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    int st=a[k-1];
    
    sort(a.begin(),a.end());
    auto end=upper_bound(a.begin(),a.end(),st)-a.begin();
    // cerr<<end<<'\n';
    bool ok=true;
    for(int i=end;i<n;i++){
        if(a[i]-a[i-1]>st){
            ok=false;
            break;
        }
    }
    cout<<(ok?"YES\n":"NO\n");
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