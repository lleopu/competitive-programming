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

signed main() {
	OSN
	
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		bool ans=1;

		for (int i=1 ; i<=n ; i++){
			int a;
			cin >> a;

			if (a<=max(2*(i-1), 2*(n-i))){
				ans=0;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}