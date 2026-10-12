#include <bits/stdc++.h>
using namespace std;
#define OSN ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define int long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<long,long>
const int INF=1e9;
const int N=2e5+5;
const int MOD=1e9+7;

map<int,int> mp;

signed main() {
	OSN
	/*freopen("input.txt", "r", "stdin");
	freopen("output.txt", "w", "stdout");*/
	
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		mp.clear();

		for (int i=1 ; i<=n ; i++){
			int a;
			cin >> a;
			mp[a-i]++;
		}

		int ans=0;
		for (auto x : mp) ans+=(x.se)*(x.se-1)/2;

		cout << ans << "\n";
	}
}