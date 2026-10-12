#include <bits/stdc++.h>
using namespace std;
#define OSN ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define int long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<long,long>
const int INF=1e18;
const int N=2e5+5;
const int MOD=1e9+7;

vector<pii> v;
pii ans;

int binpow(int a, int b){
	if (b==0) return 1;	
	int ret=binpow(a,b/2);
	ret*=ret;
	if (b%2) ret*=a;
	return ret;
}

signed main() {
	OSN
	/*freopen("input.txt", "r", "stdin");
	freopen("output.txt", "w", "stdout");*/
	
	int n;
	cin >> n;

	int mn=INF;

	for (int i=1 ; i*i<=n ; i++){
		if (n%i!=0) continue;
		int a=i;
		int b=n/i;

		if (gcd(a,b)==1) {
			if (max(a,b)<mn) {
				ans={a,b};
				mn=max(a,b);
			}
		}
	}

	cout << ans.fi << ' ' << ans.se << "\n";
}
