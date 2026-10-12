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
const int N=1e3+5;
const int MOD=1e9+7;

int x[]={0,1,0,-1};
int y[]={1,0,-1,0};

queue<pair<int,pii>> q;

int n,m,t;
bool vis[N][N];
bool cek[N][N];
int dis[N][N];
int ar[N][N];
int br[N][N];
map<int,int> mp;

void dfs(int i, int j, int val){
	if (vis[i][j]) return;
	if (i<1 or i>n or j<1 or j>m) return;
	// cout << i << ' ' << j << " ---\n";
	vis[i][j]=1;
	br[i][j]=val;
	mp[val]++;
	for (int k=0 ; k<4 ; k++){
		int inew=i+x[k];
		int jnew=j+y[k];
		// cout << ar[inew][jnew] << ' ' << ar[i][j] << " ++\n";

		if (ar[inew][jnew]==ar[i][j]){
			dfs(inew,jnew,val);
		}
	}
}

signed main() {
	OSN
	/*freopen("input.txt", "r", "stdin");
	freopen("output.txt", "w", "stdout");*/
	
	cin >> n >> m >> t;

	for (int i=1 ; i<=n ; i++){
		for (int j=1 ; j<=m ; j++){
			dis[i][j]=-1;
			char z;
			cin >> z;

			ar[i][j]=z-'0';
		}
	}

	// for (int i=1 ; i<=n ; i++){
	// 	for (int j=1 ; j<=m ; j++){
	// 		cout << ar[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }

	int cnt=1;
	for (int i=1 ; i<=n ; i++){
		for (int j=1 ; j<=m ; j++){
			if (!vis[i][j]) dfs(i,j,++cnt);
		}
	}

	for (int i=1 ; i<=n ; i++){
		for (int j=1 ; j<=m ; j++){
			if (mp[br[i][j]]>1){
				q.push({0,{i,j}});
			}
		}
	}

	while (!q.empty()){
		auto tp = q.front();
		q.pop();
		int val=tp.fi;
		int i=tp.se.fi;
		int j=tp.se.se;
		if (cek[i][j]) continue;
		if (i<1 or i>n or j<1 or j>m) continue;
		cek[i][j]=1; 
		dis[i][j]=val;

		for (int k=0 ; k<4 ; k++){
			int inew=i+x[k];
			int jnew=j+y[k];
			q.push({val+1, {inew,jnew}});
		}
	}

	// for (int i=1 ; i<=n ; i++){
	// 	for (int j=1 ; j<=m ; j++){
	// 		cout << dis[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	while (t--){
		int i,j,k;
		cin >> i >> j >> k;

		if (dis[i][j]==-1) cout << ar[i][j] << "\n";
		else {
			if (dis[i][j]>=k) cout << ar[i][j] << "\n";
			else cout << (ar[i][j]+(k-dis[i][j]))%2 << "\n";
		}
	}
}

// xia_viaq