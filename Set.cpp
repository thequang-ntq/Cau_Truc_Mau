#include <bits/stdc++.h>
#define ll long long
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("omit-frame-pointer")
// #pragma GCC optimize("unroll-loops")

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    s="0"+s;
    for (int i=1;i<=n;i++) {
        set<string> st;
        
        for (int j=1;j<=n-i+1;j++) {
           st.insert(s.substr(j,i));
        }
        if (st.size()==(n-i+1)) {
            cout<<i<<endl;
            return 0;
        
        }
    }
}
