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
    string s; cin>>s;
    int n=s.size();
    vector<string> ans;

    auto f=[&](auto &&self,int i,string &s) -> void
    {
    	if(i==n)
    	{
    		ans.push_back(s);
    		return;
    	}
    	unordered_set<char> used;
    	for(int j=i;j<n;j++){
    		if (used.count(s[j])) continue;
    		used.insert(s[j]);
    		swap(s[j],s[i]);
    		self(self,i+1,s);
    		swap(s[j],s[i]);
    	}
    };
    f(f,0,s);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto &s:ans){
    	cout<<s<<'\n';
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