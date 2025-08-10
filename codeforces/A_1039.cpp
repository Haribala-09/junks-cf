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

#define int long long
void solve() {
    int n,c; cin>>n>>c;
    vector<int> a(n);
    for(auto &x:a) cin>>x;

    sort(a.begin(),a.end());
	auto it=upper_bound(a.begin(),a.end(),c)-a.begin();
	int ans=n-it; // these are already >c

	cout<<it<<":"<<a[it]<<' ';
	int pow=1;
	for(int i=it-1;i>=0;i--){
		if(a[i]*pow>c){
			ans++;
		}
		pow*=2;
	}

	cout<<ans<<'\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}