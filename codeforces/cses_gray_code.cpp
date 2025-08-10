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

	vector<string> ans;
	ans.push_back(string("0"));
	ans.push_back(string("1"));

	for(int i=1;i<n;i++){
		vector<string> res;

		for (int j = 0; j < (int)ans.size(); j++) {
            res.push_back("0" + ans[j]);
        }

        for (int j = (int)ans.size() - 1; j >= 0; j--) {
            res.push_back("1" + ans[j]);
        }

        ans = move(res);
	}

	for(auto &s:ans){
		cout<<s<<'\n';
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