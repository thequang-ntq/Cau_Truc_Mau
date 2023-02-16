#pragma GCC optimize("03,unroll-loops")
#pragma GCC targer("sse,sse2,sse3,ssse3,sse4,avx,abm,mmx,abx,tune=native")
#pragma GCC optimization("-funroll-all-loops, no-stack-protector")
//#include <bits/stdc++.h>
#include<stdio.h>
#include<string>
#include<math.h>
#define MO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MAX(a,b) ((a > b ) ? a : b)
#define MIN(a,b) ( (a < b) ? a : b)
#define ABS(x) (x < 0 ? -x : x)
#define ll long long
#define MOD 1000000007
#define mod 998244353
#define div6 166666668
#define taskname "__Quang__"
#define double long double
//using namespace std;
//using ull = unsigned long long;
//const ll inf = 1000000003;
//const int maxn = 3e5 + 19;
//const double Pi = 3.1415926535897323846;
//const double eps = 1e-9;
//int sign(double x){
//    if(x > eps) return 1;
//    if( x < -eps) return -1;
//    return 0;
//}
//ll __lcm(ll a, ll b){
//    return (a / __gcd(a,b) * b);
//}
//bool pr(ll n){
//    if (n <= 1) return false;
//    if(n <= 3) return true;
//    for(ll i=2; i*i <= n; i++){
//        if( (n % i) == 0) return false;
//    }
//    return true;
//}
//bool cp(ll n){
//	return sqrt(n) * sqrt(n) == n;
//}
//ll binpow(ll a, ll b){
//    ll res =1 ;
//    a %= MOD;
//    while(b){
//        if(b & 1){
//            res = res * a % MOD;
//        }
//        a = a * a % MOD;
//        b >>= 1;
//    }
//    return res;
//}
//// ull npk(ll n, ll k){
//// 	return fac(n) / fac(n-k);
//// }
//// ull nck(ll k, ll n){
//// 	if(k==0 || k==n ) return 1;
//// 	if(k==1) return n;
//// 	return nck(k-1, n-1) + nck(k, n-1);
//// }
//class SegTree{
//private:
//    int n;
//    vector<ll>a,lazy,st;
//public:
//    SegTree(){}
//    SegTree(const vector<ll>&x){
//        this -> n = x.size() - 1;
//        this -> lazy.resize(n*4+5);
//        this -> st.resize(n*4+5);
//        this -> a = x;
//        build(1,1,n);
//    }
//    void build(int id, int l, int r){
//        if(l == r){
//            st[id] = a[l];
//            return;
//        }
//        int mid = (l+r)>>1;
//        build(id*2, l , mid);
//        build(id * 2 + 1, mid + 1, r);
//        st[id] = (st[id*2] + st[id*2+1]);
//    }
//    void fix(int id, int l, int r){
//        if(!lazy[id]) return;
//        st[id] += lazy[id];
//        if(l != r){
//            lazy[id*2] += lazy[id];
//            lazy[id*2+1] += lazy[id];
//        }
//        lazy[id] = 0;
//    }
//    void update(int id, int l, int r, int u, int v, int val){
////        fix(id, l , r);
//        if( u > r || v < l) return;
//        if(u <= l && v >= r ){
//            lazy[id] += val;
////            fix(id, l , r);
//             st[id] = val;
//            return;
//        }
//        int mid = (l+r)>>1;
//        update(id*2 , l, mid, u, v, val);
//        update(id*2+1, mid + 1, r , u , v, val);
//        st[id] = (st[id*2] + st[id*2+1]);
//    }
//    ll get(int id, int l, int r, int u, int v){
////        fix(id, l , r);
//        if(u > r || v < l) return 0; // tim min return 1e7
//        								//tim max return -1e7
//        if( u <= l && v >= r){
//            return st[id];
//        }
//        int mid = (l+r)>>1;
//        ll get1 = get(id*2, l, mid, u, v);
//        ll get2 = get(id*2+1, mid+1, r, u, v);
//        return (get1 + get2); 
//    }
//};
void manacher(const string &s, vector<int> &odd, vector<int> &even)
{
    int n = s.size();
    odd.clear();
    even.clear();
    odd.resize(n);
    even.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        odd[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
 
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        even[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}
const int MAX_N = 2e6 + 5;
long long strt[MAX_N], fnsh[MAX_N], countCover[MAX_N];
void calcCover(const vector<int> &odd, const vector<int> &even)
{
    int n = odd.size();
    for (int i = 0; i < n; ++i)
    {
        // odd
        int st = i - odd[i], en = i + odd[i];
        fnsh[i]++, fnsh[en + 1]--;
        strt[st]++, strt[i + 1]--;
 
 
        if (even[i])
        {
            st = i - even[i], en = i + even[i] - 1;
            fnsh[i]++, fnsh[en + 1]--;
            strt[st]++, strt[i]--;
        }
    }
 
    for (int i = 1; i < n; ++i)
    {
        strt[i] += strt[i - 1];
        fnsh[i] += fnsh[i - 1];
    }
    long long activePalindromes = 0;
    for (int i = 0; i < n; ++i)
    {
        activePalindromes += strt[i];
        countCover[i] = activePalindromes;
        activePalindromes -= fnsh[i];
    }
    cout<<activePalindromes << '\n';
}
int main(){
    MO;
    if(fopen( taskname".inp","r")){
		freopen( taskname".inp","r", stdin);
		freopen( taskname".out","w", stdout);
	}
	int Quang = 1;
//	scanf("%d",&Quang);
//	cin>>Quang;
	while(Quang--){
		string s; cin>>s;
		int q; cin>>q;
		while(q--){
			int l,r; cin>>l>>r;
			l--;r--;
			vector<int>odds, evens;
			string u = s.substr(l, r - l + 1);
			manacher(u, odds, evens);
			calcCover(odds, evens);
			
		}
    }
    return 0;
}
