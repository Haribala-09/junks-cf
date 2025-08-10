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
    vector<array<int,3>> a(n);
    for(auto &x:a) cin>>x[0]>>x[1]>>x[2];
    sort(a.begin(),a.end());
    int ans=k;
	
	for(auto &x:a){
		if(x[0]<=ans && x[1]>=ans){
			ans=max(ans,x[2]);
		}
	}

	cout<<ans<<'\n';
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