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

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;


void solve() {
	vector<pair<int,int>> p(3);
    for(int i=0;i<3;i++){
    	cin>>p[i].first>>p[i].second;
    }

    bool ok=false;
    auto f=[&](vector<pair<int,int>> p){
    	if(p[0].first==p[1].first && p[1].first==p[2].first && p[0].second+p[1].second+p[2].second==p[0].first) ok=true;
    	sort(p.begin(),p.end());

    	if(p[2].first==p[0].first+p[1].first && p[2].second+p[0].second==p[2].first && p[0].second==p[1].second) ok=true;
    };
    f(p);
    for(auto &x:p) 
    	swap(x.first,x.second);
    f(p);
    cout<<(ok?"Yes\n":"No\n");
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