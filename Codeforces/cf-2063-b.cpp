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
const int N=1e5+5;
const int MOD=1e9+7;

int ar[N], br[N];

signed main() {
	OSN
	int t;
	cin >> t;

	while (t--){
		int n,l,r;
		cin >> n >> l >> r;

		for (int i=1 ; i<=n ; i++) {
			cin >> ar[i];
			br[i]=ar[i];
		}

		sort(ar+1,ar+r+1);
		sort(br+l, br+n+1);

		// for (int i=1 ; i<=1+r-l+1 ; i++){
		// 	cout << ar[i] << ' ';
		// }
		// cout << "\n";

		// for (int i=l ; i<=r+1 ; i++){
		// 	cout << br[i] << ' ';
		// }
		// cout << "\n";

		int ans=0;
		int ans2=0;
		for (int i=1 ; i<=r-l+1 ; i++){
			ans+=ar[i];
		}

		for (int i=l ; i<=r ; i++){
			ans2+=br[i];
		}

		cout << min(ans, ans2) << "\n";

	}
}