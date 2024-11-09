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
 
// unordered_map<char,int>dir={{'R',0},{'D',1},{'L',2},{'U',3}};
#define R 0
#define D 1
#define L 2
#define U 3
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
int vis[7][7];

bool isValid(int a,int b,int c){
    return (a>=b && a<c);
}

int f(int ind,int i,int j,string &s){
    if(ind==48)return (i==6 && j==0);
    if((i==6 && j==0) || vis[i][j]==true)return 0;

    vector<bool>isVis(4,-1);
    for(int k=0;k<4;k++){
        if(isValid(i+x[k],0,7) && isValid(j+y[k],0,7))isVis[k]=vis[i+x[k]][j+y[k]];
    }

    if(!isVis[D] && !isVis[U] && isVis[R] && isVis[L])return 0;
    if(!isVis[R] && !isVis[L] && isVis[D] && isVis[U])return 0;

    if(isValid(i-1,0,7) && isValid(j-1,0,7) && vis[i-1][j-1]) if(!isVis[L] && !isVis[U])return 0;
    if(isValid(i-1,0,7) && isValid(j+1,0,7) && vis[i-1][j+1]) if(!isVis[R] && !isVis[U])return 0;
    if(isValid(i+1,0,7) && isValid(j-1,0,7) && vis[i+1][j-1]) if(!isVis[L] && !isVis[D])return 0;
    if(isValid(i+1,0,7) && isValid(j+1,0,7) && vis[i+1][j+1]) if(!isVis[R] && !isVis[D])return 0;

    vis[i][j]=1;
    int ans=0;

    if(s[ind]=='?'){
        for(int k=0;k<4;k++){
            if(isValid(i+x[k],0,7) && isValid(j+y[k],0,7))ans+=f(ind+1,i+x[k],j+y[k],s);
        }
    }
    else if(s[ind]=='R' && j+1<7){
        ans+=f(ind+1,i,j+1,s);
    }
    else if(s[ind]=='D' && i+1<7){
        ans+=f(ind+1,i+1,j,s);
    }
    else if(s[ind]=='L' && j-1>=0){
        ans+=f(ind+1,i,j-1,s);
    }
    else if(s[ind]=='U' && i-1>=0){
        ans+=f(ind+1,i-1,j,s);
    }
    vis[i][j]=0;
    return ans;
}
void solve(){
    string s;
    cin>>s;
    cout<<f(0,0,0,s)<<endl;
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