#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
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
 

struct interval
{
    /* data */
    ll start,end;
    ll index;
};

void solve(){
    int n;
    cin>>n;

    vector<interval> intervals(n);
    for(int i=0;i<n;i++){
        interval intvl;
        cin>>intvl.start;
        cin>>intvl.end;

        intvl.index=i;
        intervals[i]=intvl;
    }

    sort(intervals.begin(),intervals.end(),[&](interval &a, interval &b){
        if(a.start==b.start){
            return a.end<b.end;
        }
        return a.start<b.start;
    });

    // for(int i=0;i<n;i++){
    //     cout<<intervals[i].start<<" "<<intervals[i].end<<" "<<intervals[i].index<<endl;
    // }
    priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > rooms;

    vector<int> allotedRooms(n,0);
    int roomNo=1;
    for(int i=0;i<n;i++){
        if(!rooms.empty() && rooms.top().first<intervals[i].start){
            int room= rooms.top().second;
            rooms.pop();

            allotedRooms[intervals[i].index]=room;
            rooms.push({intervals[i].end,room});
        }
        else{
            allotedRooms[intervals[i].index]=roomNo;

            rooms.push({intervals[i].end,roomNo});
            roomNo++;
        }
    }
    cout<<roomNo-1<<endl;
    for(int i=0;i<n;i++){
        cout<<allotedRooms[i]<<" ";
    }
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