// Author : HBK
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
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    // two conditions need to be maintained a+b>c and a+b+c>mx
    // find c using binary search
    ll ans=0;
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		int v1=a[i]+a[j];
    		int v2=a[n-1]-v1;
    		int l=upper_bound(a.begin(),a.end(),v2)-a.begin();
    		l=max(l,j+1); // below j+1 is already counted
    		int r=lower_bound(a.begin(),a.end(),v1)-a.begin();
    		ans+=max(0,r-l);
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