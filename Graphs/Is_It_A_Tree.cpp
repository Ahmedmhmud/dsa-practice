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

void __fouda_0x01(const multiset<int>& parent, const multiset<int>& child, int caseNum) {
    int rootCount = 0;
    set<int> computed;
    for (auto i : parent) if (! child.count(i) && ! computed.count(i)) {
        ++rootCount;
        computed.insert(i);
    }
    
    if (rootCount != 1) {
        cout << "Case " << caseNum << " is not a tree." << endl;
        cout << "rootCount: " << rootCount << endl;
        return;
    }

    bool notTree = false;
    for (auto i : child) if (child.count(i) > 1) notTree = true;

    if (notTree) cout << "Case " << caseNum << " is not a tree." << endl;
    else cout << "Case " << caseNum << " is a tree." << endl;
}
 
int32_t main()
{
    fastIO();
    int caseNumber = 1;
    // cin >> t;
    multiset<int> from, to;
    while (1)
    {
        int a, b; cin >> a >> b;
        if (a == 0 && b == 0) {
            __fouda_0x01(from, to, caseNumber);
            ++caseNumber;
            from.clear();
            to.clear();
        } else if (a == -1 && b == -1) break;
        else {
            from.insert(a);
            to.insert(b);
        }
    }
    return 0;
}

// to understand what is happening in this file, please go to the starting of the file.