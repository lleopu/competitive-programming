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
vector<int> adj[N], ls[N];
bool vis[N];

int par[N], sz[N];

set<pii> st;
map<int,int> mp;


int find(int a){
    if (par[a]==a) return a;
    return par[a]=find(par[a]);
}

void merge(int a, int b){
    if (a>b) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
}

bool cycle(int a, int par){
    vis[a]=1;
    for (auto x : adj[a]){
        if (x==par) continue;
        if (vis[x]) return 1;
        return cycle(x,a);
    }
    return 0;
}

signed main(){
    OSN
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        st.clear();
        mp.clear();
        for (int i=1 ; i<=n ; i++) adj[i].clear(), ls[i].clear();
        for (int i=1 ; i<=n ; i++) par[i]=i, sz[i]=1, vis[i]=0;
        
        for (int i=1 ; i<=n ; i++){
            cin >> ar[i];
            int a=i, b=ar[i];
            if (a>b) swap(a,b);
            st.insert({a,b});
        }

        for (auto x : st){
            if (find(x.fi)!=find(x.se)){
                merge(find(x.fi), find(x.se));
            }
            adj[x.fi].pb(x.se);
            adj[x.se].pb(x.fi);
        }

        int cnt=0;
        for (int i=1 ; i<=n ; i++){
            if (find(i)==i) {
                cnt++;
                mp[i]=cnt;
            }
        }

        for (int i=1 ; i<=n ; i++){
            ls[mp[find(i)]].pb(i);
        }

        int c[2]={};
        for (int i=1 ; i<=cnt ; i++){
            bool cek=1;
            for (int j=0 ; j<ls[i].size() ; j++){
                if (adj[ls[i][j]].size()<2) cek=0;
            }
            if (sz[find(ls[i][0])]==1) c[1]++;
            else {
                if (cek==1) c[0]++;
                else c[1]++;
            }
        }

        // cout << c[0] << ' ' << c[1] << '\n';
        // cout << "=====\n";

        cout << c[0]+min(c[1],1ll) << ' ' << c[0]+c[1] << "\n";
    }
}