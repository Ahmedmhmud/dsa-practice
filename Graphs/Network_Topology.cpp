// To understand what is happening in this file, please go to the end of the file.

#include "bits/stdc++.h"

#define int long long
#define vi  vector< int >
#define vvi vector< vi >
#define vb  vector< bool >
#define vp  vector< pair < int, int > >
#define fastIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(x) x.begin(),x.end()
#define endl '\n'

using namespace std;

/*

___________              .___       
░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░  
░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░ 
░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░      ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░ 
                                                                  

*/

template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

vvi a;
vb vis;
bool isCyclic = false, center = false;
int ones = 0, twos = 0;

void DFS(int u, int p) {
    vis[u] = true;
    for (auto v : a[u]) {
        if (v != p && vis[v]) isCyclic = true; 
        if (! vis[v]) DFS(v, u);
    }
}

void __fouda_0x01() {
    int n, m; cin >> n >> m;
    a.assign(n + 1, {});
    vis.assign(n + 1, false);
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    DFS(1, 1);

    for (int i = 1; i <= n; ++i) {
        int s = a[i].size();
        if (s == 1) ++ones;
        else if (s == 2) ++twos;
        else if (s == m) center = true; 
    }

    if (ones == 2 && twos == n - 2) cout << "bus topology";
    else if (twos == n && isCyclic) cout << "ring topology";
    else if (center && ones == n - 1) cout << "star topology";
    else cout << "unknown topology";
    cout << endl;
}
 
int32_t main()
{
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        __fouda_0x01();
    }
    return 0;
}

// to understand what is happening in this file, please go to the starting of the file.