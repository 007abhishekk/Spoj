#include<bits/stdc++.h>
using namespace std;
#define bs ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
// #define LOCAL_DEFINE
// #define LOCAL
#define deb(a) cout << #a << " = " << a << '\n'
#define deb2(a, b) cout << #a << " = " << a << ", " << #b << " = " << b << '\n'
#define rep(var,start,end) for(int var=start;var<end;var++)
#define erep(var,start,end) for(int var=start;var<=end;var++)
#define rrep(var,start,end) for(int var=start;var>=end;var--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pci pair<char,int>
#define pll pair<ll,ll>
#define test int t;cin>>t;while(t--)

ll modularExponentiation(ll n, ll p, ll M){
    ll res = 1;
    while(p){
        if(p&1)
            res = (res * n)%M;
        n = (n*n)%M;
        p >>= 1;
    }
    return res;
}
const int N = 100100;
int a[N];
bool isValid(int dist, int n, int c){
    int last = a[0], cnt = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] - last >= dist){
            last = a[i];
            cnt++;
        }
    }
    return (cnt >= c);
}
void solve(){
    int n,c;
    cin >> n >> c;
    rep(i,0,n) cin >> a[i];
    sort(a, a+n);
    int ans = 0;
    int l = 0, r = a[n-1] - a[0];
    while(l <= r){
        int m = l + r >> 1;
        if(isValid(m, n, c)){
            ans = max(ans, m);
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout << ans << '\n';
}

int main(){
    bs;
    #ifdef LOCAL
    freopen("Contest/input.txt","r",stdin);
    freopen("Contest/output.txt","w",stdout);
    #endif
    //solve();
    test{
       solve(); 
    }
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}