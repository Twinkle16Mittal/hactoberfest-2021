#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll>  vll;
typedef vector<pll> vpll;
#define quick ios_base::sync_with_stdio(false);cin.tie(0);
#define loop(i,a,b)  for(i=a;i<b;i++)
#define revloop(i,b,a) for(i=b-1;i>=a;i--)
#define pb push_back
#define emb emplace_back
#define mkp make_pair
#define in insert
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define len length
#define sortAsc(x)  sort(x.begin(),x.end());
#define sortDsc(x)  sort(x.begin(),x.end(),greater<int>());

const double pi=3.141592653589793238460;
const ll mod = 1e9+7;
const ll INF = 1000000000000001;
const string no="NO\n",yes="YES\n";

ll min(ll a, ll b){
    return a<b ? a : b ;
}


ll gcd(ll x,ll y){
    return y?gcd(y,x%y):x;
}

ll LCM(ll x,ll y){
    return x/gcd(x,y)*y;
}

ll power(ll x, ull y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}

const ll maxi = 200005; 
/*void dfs(ll src,ll d){
    vis[src] = 1;
    dist[src] = d;
    for(auto child : adj[src]){
        if(!vis[child]){
            parent[child] = src ;
            dfs(child,dist[src]+1);
        }
    }
}
*/

void mysol(){
    ll i,j,k,n,x = 0,ans,sum = 0;
    cin>>n;
    ll a[n];
    map<ll,ll> cnt ;
    loop(i,0,n-1) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    ans = (n*(n-1)/2) ;
    for(auto x: cnt){
        ll cur = x.second;
        if(cur > 1) {
            sum += (cur*(cur-1))/2 ;
        }
    }
    ans = ans - sum ;
    ans *= 2 ;
    cout<<ans<<endl; 
}


int main() {
    quick
    int t=1;
    cin>>t;
    while(t--){
         mysol();  
    }
}
