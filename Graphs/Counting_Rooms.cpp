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

int N = 1001, M = 1001;
vector<string> a;
vector<vb> vis(N, vb(M, 0));

void DFS(int i, int j, int n, int m) {
    vis[i][j] = true;
    if (j > 0 && a[i][j - 1] == '.' && ! vis[i][j - 1]) { // Left
        DFS(i, j - 1, n, m);
    }
    
    if (j < m - 1 && a[i][j + 1] == '.' && ! vis[i][j + 1]) { // right
        DFS(i, j + 1, n, m);
    }
    
    if (i > 0 && a[i - 1][j] == '.' && ! vis[i - 1][j]) { // Up
        DFS(i - 1, j, n ,m);
    }
    
    if (i < n - 1 && a[i + 1][j] == '.' && ! vis[i + 1][j]) {
        DFS(i + 1, j, n ,m);
    }
}

void __fouda_0x01() {
    int n, m; cin >> n >> m;
    a.assign(n + 1, "");
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (! vis[i][j] && a[i][j] == '.') {
                DFS(i, j, n, m);
                ++answer;
            }
        }
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