#include <bits/stdc++.h>
using namespace std;
#define OSN ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define int long long
#define pb push_back
// #define pii pair<int,int>
#define pii pair<long,long>
const int INF=1e18;
const int N=2e5+5;
const int MOD=1e9+7;

pii ar[N];
priority_queue<int> pq[2];

signed main() {
	OSN
	int t;
	cin >> t;

	while (t--){
		int n,k;
		cin >> n >> k;

		for (int i=1 ; i<=n ; i++) cin >> ar[i].fi;
		for (int i=1 ; i<=n ; i++) cin >> ar[i].se;

		sort(ar+1, ar+n+1);
		int ans=INF;
		int sum=0;
		for (int i=1 ; i<=n ; i++){
			if (pq[1].size()<k){
				pq[1].push(ar[i].se);
				sum+=ar[i].se;
			}
			else pq[0].push(-ar[i].se);
			if (i>=k){
				while (!pq[0].empty() && (-pq[0].top())<pq[1].top()){
					pq[1].push(-pq[0].top());
					sum-=pq[1].top();
					sum-=pq[0].top();
					pq[0].pop();
					pq[1].pop();
				}

				// cout << "ke - " << i << " : " << sum << ' ' << ar[i].fi << "\n";
				// cout << "\n" << sum*ar[i].fi << "HAYUKS\n";
				ans=min(ans, sum*ar[i].fi);
			}
		}

		cout << ans << "\n";
		while (!pq[0].empty()) pq[0].pop();
		while (!pq[1].empty()) pq[1].pop();
	}
}