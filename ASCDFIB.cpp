#include<bits/stdc++.h>
using namespace std;
#define bs ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back

#define rep(var,start,end) for(int var=start;var<end;var++)
#define erep(var,start,end) for(int var=start;var<=end;var++)
#define rrep(var,start,end) for(int var=start;var>=end;var--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pci pair<char,int>
#define pll pair<ll,ll>
#define test int t;cin>>t;while(t--)

const int N = 1100000;
int MOD = 100000;
ll fib[N];
int id = 1;
void solve(){
    int a,b;
    cin >> a >> b;
    cout << "Case " << id++ << ": ";
    int arr[MOD] = {0};
    rep(i,a,a+b+1){
        arr[fib[i]]++;
    }
    rep(i,1,MOD){
        arr[i] += arr[i-1];
    }
    int done = 0;
    for(int i = 0; i < MOD; ++i){
        while(arr[i] - done > 0 and done < 100)
            cout << i << ' ',
            ++done;
        if(done == 100) {
            break;
        }
    }
    cout << '\n';
}

int main()
{
    bs;
    fib[1] = 0;
    fib[2] = 1;
    rep(i,3,N){
        fib[i] = (fib[i-1] + fib[i-2]);
        if(fib[i] >= MOD) 
            fib[i] %= MOD;
    }
    //solve();
    test{
       solve(); 
    }
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}