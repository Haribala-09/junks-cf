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
    
    // can only contain atmost one element other than -1 and it should not be zero
    set<int> st;
    for(int i=0;i<n;i++){
    	int x; cin>>x;	
    	if(x!=-1) st.insert(x);
    } 

    if(st.size()>1){
    	cout<<"NO\n";
    	return;
    }
    if(st.empty() || *st.begin()>0){
    	cout<<"YES\n";
    	return;
    }
    cout<<"NO\n";
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