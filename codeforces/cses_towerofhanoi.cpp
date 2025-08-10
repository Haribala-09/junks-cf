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

    vector<pair<int,int>> ans;
    ans.reserve((1<<n)-1);

    auto f=[&](auto &&self,int n,int st,int m,int end) -> void
    {
    	if(!n) return;
    	self(self,n-1,st,end,m);
    	ans.emplace_back(st,end);
    	self(self,n-1,m,st,end);
    };

    f(f,n,1,2,3);

    cout<<ans.size()<<'\n';
    for(auto &[x,y]:ans){
    	cout<<x<<' '<<y<<'\n';
    }

    return;
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