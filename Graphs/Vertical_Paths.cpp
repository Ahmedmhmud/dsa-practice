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

vvi a, answer;
vb vis;
int root;
vi v;

void DFS(int u) {
    vis[u] = true;
    v.push_back(u);
    for (auto v : a[u]) {
        if (! vis[v]) DFS(v);
    }

    if (u != root && a[u].size() == 1) {
        answer.push_back(v);
        v.clear();
    }
}

void __fouda_0x01() {
    int n; cin >> n;
    if (n == 1) {
        cin >> n;
        cout << 1 << endl << 1 << endl << 1 << endl << endl;
        return;
    }

    a.assign(n + 1, {});
    vis.assign(n + 1, false);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (i + 1 == x) {
            root = x;
            continue;
        }

        a[i + 1].push_back(x);
        a[x].push_back(i + 1);
    }

    DFS(root);
    cout << answer.size() << endl;
    for (auto s : answer) {
        cout << s.size() << endl;
        cout << s << endl;
    }

    cout << endl;
    answer.clear();
}
 
int32_t main()
{
    fastIO();
    int t = 1;
    cin >> t;
    while (t--)
    {
        __fouda_0x01();
    }
    return 0;
}

// to understand what is happening in this file, please go to the starting of the file.