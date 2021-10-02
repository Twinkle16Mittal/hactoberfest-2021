// Rishabh Agarwal aka ranger2k

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define F first
#define S second
#define ll long long int

class Solution{
private:

    const ll mod = 1e9+7;
    const ll INF = 1e18;
    const long double PI = 3.1415926;

    ll power(ll a, ll b)
    {
        if (b == 0)
            return 1;
        ll temp = power(a, b / 2) % mod;
        if (b % 2 == 0)
        {
            return (temp * temp) % mod;
        }
        else
        {
            return ((a * temp) % mod * temp) % mod;
        }
    }

    ll gcd(ll a, ll b)
    {
        if (a<b)
            return gcd(b,a);
        else if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    ll modInverse(ll a)
    {
        return power(a, mod - 2) % mod;
    }

    void reverse(vector<ll> &a, ll i, ll j)
    {
        if (i > j)
        {
            swap(i, j);
        }
        ll len = j - i + 1;
        for (ll x = i; x < i + len / 2; x++)
        {
            swap(a[x], a[j]);
            j--;
        }
    }

    // ll prime[1000006];

    // void sieve(ll MAXN=1000006)
    // {
    //     prime[1] = 1;
    //     for (ll i=2; i<MAXN; i++)
    //         prime[i] = i;
    //     for (ll i=4; i<MAXN; i+=2)
    //         prime[i] = 2;
    //     for (ll i=3; i*i<MAXN; i++)
    //     {
    //         if (prime[i] == i)
    //         {
    //             for (ll j=i*i; j<MAXN; j+=i)
    //                 if (prime[j]==j)
    //                     prime[j] = i;
    //         }
    //     }
    // }

    // map<ll,ll> divisors(ll x){
    //     map<ll,ll>ump;
    //     while (x != 1)
    //     {
    //         ump[prime[x]]++;
    //         x = x / prime[x];
    //     }
    //     return ump;
    // }

public:

    void done(ll &Case)
    {  
        string s;
        cin>>s;
        map<char,ll>mp;
        ll n= s.length();
        string vowels = "AEIOU";
        ll vow=0, cons=0;
        for(ll x=0; x<n; x++){
            mp[s[x]]++;
            ll flag=1;
            for(ll y=0; y<5; y++){
                if(s[x]==vowels[y]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cons++;
            }
            else{
                vow++;
            }
        }
        ll ans = min(2*cons+vow,2*vow+cons);
        for(auto i:mp){
            ll flag=1;
            for(ll y=0; y<5; y++){
                if(i.F==vowels[y]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans = min(ans,2*(cons-i.S)+vow);
            }
            else{
                ans = min(ans,2*(vow-i.S)+cons);
            }
        }
        cout << "Case #" << Case << ": "<<ans<<"\n";
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   #ifndef ONLINE_JUDGE
       freopen("inp.txt", "r", stdin);
       freopen("out.txt", "w", stdout);
   #endif

    ll No_of_cases;
    No_of_cases = 1;
    cin >> No_of_cases;
    ll Case = 1;
    while (No_of_cases--)
    {
        Solution *inprocess = new Solution();
        inprocess->done(Case);
        Case++;
    }
    return 0;
}
