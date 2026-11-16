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
vi vis, answer;
bool is_cyclic = false;

// vis[u] = 0  -> Unvisited
// vis[u] = 1  -> Visited & in the recursion stack
// vis[u] = 2  -> Visited & ! in the recursion stack

void dfs(int u) {
    vis[u] = 1;
    for (auto v: a[u]) {
        if (!vis[v]) {
            dfs(v);
        } else if (vis[v] == 1) {
            is_cyclic = true;
        }
    }

    answer.push_back(u);
    vis[u] = 2;
}

void __fouda_0x01() {
    int n, m; cin >> n >> m;
    a.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);

    if (is_cyclic) {
        answer.clear();
        answer.push_back(-1);
    }

    cout << answer << endl;
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