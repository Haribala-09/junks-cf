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
    for(auto &x:a) cin>>x;

    // try to toggle >,<,>
    // if i pick min in even idx then max in odd
    // lets say a[l] is min and a[r]>a[l] so next i will pick 
    // max(a[l+1],a[r]) so this time obvious next element chosen will be greater than the prev and smaller in next turn

    string ans;
	ans.reserve(n);

	for(int i=0,l=0,r=n-1;i<n;i++){
		
		// choose max
		bool left=1;
		if(i&1){
			left=a[l]>a[r];
		}
		else left=a[l]<a[r];

		if(left){
			ans+='L';
			l++;
		}
		else{
			ans+='R';
			r--;
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