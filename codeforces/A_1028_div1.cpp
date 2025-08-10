#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <numeric>
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

const int MAX=50001;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    int g=0;
    for(auto &x:a) {
    	cin>>x;
    	g=gcd(g,x);
    }
    // making it equal to a common factor of all the elements
    // is the ideal operation to do

    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(a[i]==g);
    }
    if(cnt){
        cout<<n-cnt<<'\n';
        return;
    }

    // multisource bfs
    // kind of moving higher to lower by considering all pairs of numbers 
    vector<int> ans(MAX,MAX);
    std::queue<int> q;
    for(int x:a) {
        q.push(x);
        ans[x]=0; // 0 ops to reach current number
    }

    int ops=0;
    while(!q.empty()){
        auto f=q.front(); q.pop();

        for(auto &x:a){
            int gc=gcd(x,f);
            // ans[gc]>ans[f]+1 is not necessary since im checking each pair
            // so basically if a factor is not visited i have to visit it 
            // it is guarenteed it is the min no.of ops to reach that factor
            // because im checking for each of the pair each time
            // like if a factor is there it will be reached earliest as im checking for each pair
            // by this way the max no of elements in the queue is N
            // but it passes buddy
            if(ans[gc]==MAX){ 
                ans[gc]=ans[f]+1;
                q.push(gc);
            }
        }
    }
    cout<<n-1+ans[g]<<'\n';
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