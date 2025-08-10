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
	
    ll n,k; std::cin>>n>>k;
    vector<ll> a(n);
    for(auto &x:a) cin>>x;

    // i must have numbers in the form a=a+x*k
    // pair the numbers , but choose the one with min ops 
    map<ll,vector<ll>> mp;
	
	for(auto &x:a){
        mp[x%k].push_back(x);
	}
    
    ll ans=0;
    int odd=0;

    for(auto &[_,x]:mp){
        int sz=x.size();
        sort(x.begin(),x.end());
        odd+=(sz&1);

        vector<ll> pref(sz+1),suff(sz+1);

        // 2 offset
        for(int i=1;i<sz;i+=2){
            pref[i+1]=pref[i-1] + (x[i]-x[i-1]);
        }

        ll res=pref[sz];
        for(int i=sz-2;i>=0;i-=2){
            suff[i]=suff[i+2]+(x[i+1]-x[i]);
        }

        if(sz&1){
            res=pref[sz-1];
            // consider the current element as odd and skip it
            for(int i=0;i<sz;i+=2){
                res=min(res,pref[i]+suff[i+1]);
            }
        }
        ans+=res;
    }
    if(odd>1){
        ans=-1;
    }
    else ans=ans/k;
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