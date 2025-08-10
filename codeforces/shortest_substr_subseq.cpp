#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

string minWindowSubsequence(string A, string B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> next(m + 1, vector<int>(26, -1));

    vector<int> last(26, -1);
    for (int i = m - 1; i >= 0; --i) {
        last[A[i] - 'a'] = i;
        for (int c = 0; c < 26; ++c)
            next[i][c] = last[c];
    }

    int minLen = INT_MAX, start = -1;

    for (int i = 0; i < m; ++i) {
        if (A[i] != B[0]) continue;

        int pos = i;
        for (int j = 0; j < n; ++j) {
            if (pos == -1 || next[pos][B[j] - 'a'] == -1) {
                pos = -1;
                break;
            }
            pos = next[pos][B[j] - 'a'] + 1;
        }

        if (pos != -1) {
            int end = pos - 1;
            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                start = i;
            }
        }
    }

    return (start == -1) ? "" : A.substr(start, minLen);
}

// apprach 2 i think this would be o(m+n)
string match2(const string &a,const string &b)
{
    int n=a.size(),m=b.size();
    int ans=INT_MAX,st=-1;

    int i=0;
    while(i<n){
        int j=0;
        while(i<n){
            if(a[i]==b[j]){
                j++;
                if(j==m) break;
            }
            i++;
        }
        if(j<n) break; // not present

        // move back to find early start like 
        // string axaxaxabcaxabc now a at 0 then bc now when i move back i find the shorest window then start from the next char again

        int j=m-1,itr=i;
        while(j>=0){
            if(a[i]==b[j]){
                j--;
            }
            i--;
        }
        i++;

        if(itr-i+1<ans){
            st=i;
            ans=itr-i+1;
        }

        i+=1;
    }

    cout<<"Len:"<<ans<<'\n';
    if(st==-1) return "";
    return s.substr(st,ans);
}

int main() {
    cout << minWindowSubsequence("abcedbaced", "bed") << endl;  // Output: "bced"
    cout << minWindowSubsequence("abcdbad", "bd") << endl;      // Output: "bcd"
    cout << minWindowSubsequence("axaxaxabcaxabc", "abc") << endl; // Output: "abc"
    return 0;
}
