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

    int len=sqrt(n);
	vector<int> b(len+1);

	// divide it into blocks of size sqt(n) 
	// so that each query can be efficiently answered in sqrt(n)
	// b1,b2,.....,bk each block is of size sqrt(n)
	// so for each range query rather than looping from l to r just add the blocks
	// and for the remaining part of it just add it seperately since the count and size of each 
	// block is atmost sqrt(n) the tc will be sqrt(n)


	for(int i=0;i<n;i++){
		b[i/len]+=a[i];
	}

	
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