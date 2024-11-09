#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
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
    ll n;
    cin>>n;

    ll sum=n*(n+1)/2;

    if(sum%2==1){
        cout<<"NO"<<endl;
        return;
    }

    vector<int>left,right;
    sum/=2;
    while(n>0){
        if(n<=sum){
            sum-=n;
            left.pb(n);
        }
        else right.pb(n);
        n--;
    }
    if(sum!=0){
        cout<<"NO"<<endl;
        return;
    }
    int k=left.size(),m=right.size();
    cout<<"YES\n"<<k<<"\n";
    for(int i=0;i<k;i++)cout<<left[i]<<" ";
    cout<<"\n"<<m<<endl;
    for(int i=0;i<m;i++)cout<<right[i]<<" ";
    cout<<endl;

}
int main(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    fast_cin();
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
        // cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}