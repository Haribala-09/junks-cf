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
    int n,q; cin>>n>>q;

    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    sort(a.begin(),a.end());

    vector<ll> psum(n+1);
    for(int i=0;i<n;i++){
        psum[i+1]=psum[i]+a[i];
    }

    while(q--){
        ll b; cin>>b;
        if(b>a.back()){
            cout<<-1<<'\n';
            continue;
        }
        auto it=lower_bound(a.begin(),a.end(),b)-a.begin();
        // psum is one based indexing and lb is zero based so adds all elts <b
        cout<<psum[it]+1ll*(b-1)*(n-it)+1<<'\n';
    }
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