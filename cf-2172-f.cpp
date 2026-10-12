#include<bits/stdc++.h>
using namespace std;
#define OSN ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long,long>
const int INF=1e9;
const int N=2e5+5;
const int MOD=1e9+7;

int ar[N];
int pref[N], suff[N];

signed main(){
    OSN

    int n;
    cin >> n;

    for (int i=1 ; i<=n ; i++){
        cin >> ar[i];
        pref[i]=gcd(ar[i], pref[i-1]);
    }

    for (int i=n ; i>=1 ; i--){
        suff[i]=gcd(ar[i], suff[i+1]);
    }

    int ans=pref[n];
    for (int i=2 ; i<n ; i++){
        ans+=min(pref[i], suff[i]);
    }

    cout << ans << "\n";
}