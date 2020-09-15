#include<bits/stdc++.h>
using namespace std;
#define bs ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
// #define LOCAL_DEFINE
// #define LOCAL
#define rep(var,start,end) for(int var=start;var<end;var++)
#define erep(var,start,end) for(int var=start;var<=end;var++)
#define rrep(var,start,end) for(int var=start;var>=end;var--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pci pair<char,int>
#define pll pair<ll,ll>
#define test int t;cin>>t;while(t--)

ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
int dp[2001][2001];
int lcs(int a[],int b[],int n, int m){
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    else if(m == 0 || n == 0){
        return 0;
    }
    else if(a[n - 1] == b[m - 1]){
        return dp[n][m] = 1 + lcs(a,b,n-1,m-1);
    }
    else if(a[n - 1] != b[m - 1]){
        return dp[n][m] = max(lcs(a,b,n-1,m), lcs(a,b,n,m-1));
    }
}
void solve(){
    int a[2001],b[2001],n = 0,m = 0,mx = -1;
    int i;
    for(i = 0;  ; i++){
        cin >> a[i];
        if(a[i] == 0){
            n = i;
            break;
        }
    }
    i = 0;
    while(true){
        rep(p,0,2001){
            rep(j,0,2001){
                dp[p][j] = -1;
            }
        }
        // i = 0;
        for(; ; i++){
            cin >> b[i];
            if(b[i] == 0){
                int res = lcs(a,b,n,i);
                if(res > mx){
                    mx = res;
                }
                break;
            }
        } 
        cin >> b[0];
        i = 1;
        if(b[0] == 0)break;
    }
    cout << mx << '\n'; 
}



int main()
{
    bs;
    #ifdef LOCAL
    // freopen("Contest/input.txt","r",stdin);
    // freopen("Contest/output.txt","w",stdout);
    #endif
    //solve();
    test{
       solve(); 
    }
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}