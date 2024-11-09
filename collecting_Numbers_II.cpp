#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;

/**
* Limits in C++ for reference
    _____________________________________________________________________________________
    * |Sr| Macro Name | Description                     | Value
    * |No|____________|_________________________________|__________________________________
    * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
    * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
    * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
    * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
    * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int>p(n+1),pos(n+1);
    map<int,int> pairs;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        pos[p[i]]=i;
    }
    
    ll cnt=1;
    for(int i=2;i<=n;i++){
        if(pos[i]<pos[i-1]){
            cnt++;
        }
    }

    while(m--){
        int a,b;
        cin>>a>>b;

        int val1=p[a],val2=p[b];
        
        if(val1-1>=1 && pos[val1-1]>pos[val1])cnt--;
        if(val1+1<=n && pos[val1]>pos[val1+1])cnt--;
        if(val2-1>=1 && val2-1!=val1 && pos[val2-1]>pos[val2])cnt--;
        if(val2+1<=n && val2+1!=val1 && pos[val2]>pos[val2+1])cnt--;
        swap(p[a],p[b]);
        pos[val1]=b;
        pos[val2]=a;
        if(val1-1>=1 && pos[val1-1]>pos[val1])cnt++;
        if(val1+1<=n && pos[val1]>pos[val1+1])cnt++;
        if(val2-1>=1 && val2-1!=val1 && pos[val2-1]>pos[val2])cnt++;
        if(val2+1<=n && val2+1!=val1 && pos[val2]>pos[val2+1])cnt++;

        cout<<cnt<<"\n";
    }
    return;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fast_cin();

    ll t=1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}