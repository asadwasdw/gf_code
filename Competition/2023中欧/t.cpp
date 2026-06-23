#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n; 
    cin >> n;
    vector<vector<int> > v(16, vector<int>(n + 1));
    cout << "QUERY ";

    for(int i = 1; i <= n; ++i) cout << 1;
    cout << endl;
    
    for(int i = 1; i <= n; ++i) cin >> v[0][i];
    for(int t = 0; t < 15; ++t) {
        cout << "QUERY ";
        for(int i = 1; i <= n; ++i) cout << (i >> t & 1);
        cout << endl;
        for(int i = 1; i <= n; ++i) cin >> v[t + 1][i];
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) if(v[0][i] == 1) q.push(i);
    int T = n - 1;
    cout << "ANSWER" << endl;
    while(T--) {
        int lf = q.front(); q.pop();
        int pa = 0;
        for(int i = 1; i <= 15; ++i) if(v[i][lf]) pa |= 1 << (i - 1);
        cout << lf << ' ' << pa << char(10);

        for(int i = 0; i < 16; ++i) if(i == 0 || (lf >> (i - 1) & 1)) {
            v[i][pa] -= 1;
            if(i == 0 && v[i][pa] == 1) q.push(pa);
        }
    }
    cout << flush;
    return 0;
}