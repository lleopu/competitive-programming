#include <bits/stdc++.h>
using namespace std;
#define OSN ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define int long long
#define pb push_back
#define pii pair<long,long>
// #define pll pair<long,long>
const int INF=1e9;
const int N=3005;
const int MOD=1e9+7;

int cc;
map<int,int> par;
map<int, pii> cr;
set<pair<int,pii>> st;
vector<pair<int,pii>> lis;

int find(int a){
	if (par[a]==a) return a;
	return par[a]=find(par[a]);
}

void merge(int a, int b){
	if (a>b) swap(a,b);
	par[b]=a;
}

signed main() {
	OSN
	/*freopen("input.txt", "r", "stdin");
	freopen("output.txt", "w", "stdout");*/
	
	int n,q;
	cin >> n >> q;

	cc=n;

	for (int i=1 ; i<=n ; i++){
		int a,b;
		cin >> a >> b;
		cr[i]={a,b};
	}

	for (int i=1 ; i<n ; i++){
		for (int j=i+1 ; j<=n ; j++){
			int dis=abs(cr[i].fi-cr[j].fi)+abs(cr[i].se-cr[j].se);
			st.insert({dis, {i,j}});
		}
	}

	for (int i=1 ; i<=n ; i++){
		par[i]=i;
	}

	while (q--){
		int md;
		cin >> md;

		if (md==1){
			n++;
			cc++;

			par[n]=n;
			int a,b;
			cin >> a >> b;
			cr[n]={a,b};

			for (int i=1 ; i<n ; i++){
				int dis=abs(cr[i].fi-cr[n].fi)+abs(cr[i].se-cr[n].se);
				st.insert({dis, {i,n}});
			}
		}
		else if (md==3){
			int a,b;
			cin >> a >> b;

			if (find(a)==find(b)) cout << "Yes\n";
			else cout << "No\n";
		}
		else {
			if (cc==1) cout << "-1\n";
			else {
				int cnt=0;
				int pref=-1;
				for (auto x : st){
					if (pref==-1) pref=x.fi;
					if (pref!=x.fi){
						if (cnt>0){
							cout << pref << "\n";
							break;
						}
						cnt=0;
						pref=x.fi;
					}
					if (find(x.se.fi)!=find(x.se.se)){
						merge(find(x.se.fi), find(x.se.se));
						cc--;
						cnt++;
					}
					lis.pb(x);
				}
				for (int i=0 ; i<lis.size() ; i++){
					st.erase(lis[i]);
				}
				lis.clear();
			}
		}
	}



}