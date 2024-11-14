#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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

int n,k;
multiset<int>firstHalf;
multiset<int>secondHalf;

void ins(int val){
    if(firstHalf.empty()){
        firstHalf.insert(val);
    }
    else{
        int med =  *firstHalf.rbegin();
        if(val<med){
            firstHalf.insert(val);
            if(firstHalf.size()>(k+1)/2){
                firstHalf.erase(firstHalf.find(med));
                secondHalf.insert(med);
            }
        }
        else{
            secondHalf.insert(val);
            if(secondHalf.size()>(k/2)){
                firstHalf.insert(*secondHalf.begin());
                secondHalf.erase(secondHalf.find(*secondHalf.begin()));
            }
        }
    }
    
    return;
}

void rem(int val){
    if(firstHalf.find(val)!=firstHalf.end()){
        firstHalf.erase(firstHalf.find(val));
    }
    else if(secondHalf.find(val)!=secondHalf.end()){
        secondHalf.erase(secondHalf.find(val));
    }

    if(firstHalf.empty() && !secondHalf.empty()){
        firstHalf.insert(*secondHalf.begin());
        secondHalf.erase(secondHalf.find(*secondHalf.begin()));
    }
}
void solve(){
    cin>>n>>k;

    vector<int> nums(n);
    forn(i,n)cin>>nums[i];

    forn(i,k){
        ins(nums[i]);
    }
    if(k%2==0){
        cout<<min(*firstHalf.rbegin(),*secondHalf.begin())<<" ";
    }else{
        cout<<*firstHalf.rbegin()<<" ";
    }

    forsn(i,k,n){
        rem(nums[i-k]);
        ins(nums[i]);

        if(k%2==0){
            cout<<min(*firstHalf.rbegin(),*secondHalf.begin())<<" ";
        }else{
            cout<<*firstHalf.rbegin()<<" ";
        }
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