#include <bits/stdc++.h>
using namespace std;
#define OSN ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<long,long>
const int INF=1e9;
const int N=2e5+5;
const int MOD=1e9+7;

int main() {
	OSN

	int t;
	cin >> t;

	while (t--){
		string s;
		cin >> s;

		int ans=0;

		for (auto x : s){
			if (x=='1') ans++;
		}

		cout << ans << "\n";
	}
}