#include<bits/stdc++.h>
using namespace std;
#define bs ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
#define deb(a) cerr << #a << " = " << a << '\n'
#define deb2(a, b) cerr << #a << " = " << a << ", " << #b << " = " << b << '\n'
#define rep(var,start,end) for(int var=start;var<end;var++)
#define erep(var,start,end) for(int var=start;var<=end;var++)
#define rrep(var,start,end) for(int var=start;var>=end;var--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pci pair<char,int>
#define pll pair<ll,ll>
#define test int t;cin>>t;while(t--)

template<typename T>
void read(T &a){
    cin >> a;
}
template<typename T, typename T0>
void read(T &a, T0 &b){
    cin >> a >> b;
}

template<typename T>
void read(vector<T> &a){
    for(int i = 0; i < a.size(); ++i)
        read(a[i]);
}

template<typename T>
void read(T a[], int n){
    for(int i = 0; i < n; ++i)
        read(a[i]);
}

ll expo(ll n, ll p, ll M){
    ll res = 1;
    while(p){
        if(p&1)
            res = (res * n)%M;
        n = (n*n)%M;
        p >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    map<int,int> f;
    int homo = 0, hetero = 0;  
    rep(i,0,n){
        string op;
        cin >> op;
        int a;
        cin >> a;
        if(op == "insert"){
            f[a]++;
            if(f[a] == 1)
                ++hetero;
            else if(f[a] == 2) ++homo, --hetero;
        }
        else{
            if(f[a]){
                f[a]--;
                if(f[a] == 1) --homo, hetero++;
                if(f[a] == 0) --hetero;
            }
        }
        // deb2(homo, hetero);
        if((hetero <= 1 and homo == 0)){
            puts("neither");
        }
        else if((homo > 0 and hetero > 0) or homo > 1){
            puts("both");
        }
        else if(homo > 0 and hetero == 0){
            puts("homo");
        }
        else puts("hetero");
    }
}

int main()
{
    bs;
    #ifdef LOCAL
    freopen("Contest/input.txt","r",stdin);
    freopen("Contest/output.txt","w",stdout);
    #endif
    solve();
    // test{
    //    solve(); 
    // }
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}