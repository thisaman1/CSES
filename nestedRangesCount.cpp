#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;



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


template <typename T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
    int n;
    cin>>n;

    vector<pair<ll,ll>> ran(n);
    map<pair<ll,ll>,ll> index;

    ordered_set<pair<ll,ll>> ost;

    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;

        ran[i]={x,y};
        index[ran[i]]=i;
    }

    sort(ran.begin(),ran.end(),[&](pair<ll,ll>& a, pair<ll,ll>& b){
        if(a.first == b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    });
    vector<int> coveredBy(n,0);
    vector<int> covers(n,0);

    ll mxr=0;
    for(int i=0;i<n;i++){
        if(ran[i].second<=mxr){
            int lessThanR = ost.order_of_key({ran[i].second,-1});
            int sz=ost.order_of_key({1e9+1,-1});

            int len = sz-lessThanR;

            coveredBy[index[ran[i]]]=len;
        }
        mxr=max(mxr,ran[i].second);
        ost.insert({ran[i].second,index[ran[i]]});
    }

    sort(ran.begin(),ran.end(),[&](pair<ll,ll>& a, pair<ll,ll>& b){
        if(a.first == b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    });

    ost.clear();
    ll mnr=INT_MAX;
    for(int i=0;i<n;i++){
        if(ran[i].second>=mnr){
            int lessThanR = ost.order_of_key({ran[i].second,n});

            int len = lessThanR;

            covers[index[ran[i]]]=len;
        }
        mnr=min(mnr,ran[i].second);
        ost.insert({ran[i].second,index[ran[i]]});
    }

    for(int i:covers)cout<<i<<" ";
    cout<<endl;

    for(int i:coveredBy)cout<<i<<" ";
    cout<<endl;
    
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