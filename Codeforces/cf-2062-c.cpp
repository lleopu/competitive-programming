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

int ar[N];

int choose(int n, int k){
	k=min(k,n-k);
	int ans=1;
	for (int i=n ; i>n-k ; i--) {
		ans*=i;
		ans/=n-i+1;
	}
	return ans;
}

signed main() {
	OSN
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		int ans=0;
		int total=0;
		for (int i=1 ; i<=n ; i++){
			cin >> ar[i];
			total+=ar[i];		
		}

		for (int i=1 ; i<=n ; i++){
			if (i%2==1) ans-=ar[i]*choose(n-1,i-1);
			if (i%2==0) ans+=ar[i]*choose(n-1,i-1);
		}

		if (n==1) cout << total << "\n";
		else {
			cout << max({ans, total,-ans}) << "\n";
		}
	}
}