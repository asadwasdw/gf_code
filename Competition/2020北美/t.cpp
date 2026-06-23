#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

set<int>st[N][N];

int id(int x,int y) {
    return x/3*3 + y/3;
}

int a[N][N];
queue<array<int,3>>q;
void oph(int x,int y,int k) {
    for(int i = x; i <= x; i ++) {
        for(int j = 0; j < 9;j ++) {
            st[i][j].erase(k);
            if(st[i][j].size() == 1)  {
                q.push({i,j,*st[i][j].begin()});    
            }
        }
    }
}

void op(int x,int y,int k) {
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9;j ++) {
            if(id(i,j) == id(x,y)){
                st[i][j].erase(k);
                if(st[i][j].size() == 1)  {
                      q.push({i,j,*st[i][j].begin()});   
                }
            }
        }
    }
}
void opl(int x,int y,int k) {
    for(int i = 0; i < 9; i ++) {
        for(int j = y; j <= y;j ++) {
            st[i][j].erase(k);
            if(st[i][j].size() == 1)  {
                 q.push({i,j,*st[i][j].begin()});   
            }
            
        }
    }
}

void tj() {
    int num[10][10] = {0};
    for(int i = 0; i < 9;i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j]) continue;
            for(auto t : st[i][j]) num[id(i,j)][t]++;
        }
    }

    for(int i = 0; i < 9;i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j]) continue;
            for(int k = 1; k <= 9; k ++) {
                if(num[id(i,j)][k] == 1 && st[i][j].find(k) != st[i][j].end()) {
                    q.push({i,j,k});
                }
            }
        }
    }
}

void tjl() {
    int num[10][10] = {0};
    for(int i = 0; i < 9;i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j]) continue;
            for(auto t : st[i][j]) num[i][t]++;
        }
    }

    for(int i = 0; i < 9;i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j]) continue;
            for(int k = 1; k <= 9; k ++) {
                if(num[i][k] == 1 && st[i][j].find(k) != st[i][j].end()) {
                    q.push({i,j,k});
                }
            }
        }
    }
}



void tjh() {
    int num[10][10] = {0};
    for(int i = 0; i < 9;i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j]) continue;
            for(auto t : st[i][j]) num[j][t]++;
        }
    }

    for(int i = 0; i < 9;i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j]) continue;
            for(int k = 1; k <= 9; k ++) {
                if(num[j][k] == 1 && st[i][j].find(k) != st[i][j].end()) {
                    q.push({i,j,k});
                }
            }
        }
    }
}



void solve()
{
    for(int i = 0; i < 9; i ++) {
        for(int j  = 0; j < 9; j ++) {
            cin >> a[i][j];
            if(!a[i][j]) {
                for(int k = 1; k <= 9; k ++) st[i][j].insert(k);
            }
        }
    }

    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j]) {
                op(i,j,a[i][j]);
                opl(i,j,a[i][j]);
                oph(i,j,a[i][j]);
                // tj();
            } 
        }
    }

    tj();
    tjh();
    tjl();


    while(q.size()) {
        auto[x,y,k] = q.front();q.pop();
        if(a[x][y]) continue;
        a[x][y] = k;
        op(x,y,k);
        opl(x,y,k);
        oph(x,y,k);
        tj();
        tjh();
        tjl();
    }

    bool iseasy = true;
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            if(a[i][j] == 0) iseasy = false;
        }
    } 
    if(iseasy) cout << "Easy\n";
    else cout << "Not easy\n";

    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++)  {
            if(a[i][j]) cout << a[i][j];
            else cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}