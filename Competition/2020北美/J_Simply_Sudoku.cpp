#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[10][10];

void solve()
{
    n = 9;
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)cin >> a[i][j];
    auto check = [&](set<int> &p, int i, int op){
        if(op == 1){
            for(int j=1; j<=n; ++j)p.insert(a[i][j]);
        }
        else{
            for(int j=1; j<=n; ++j)p.insert(a[j][i]);
        }
    };
    auto del = [&](set<int> &p, int i, int op){
        if(op == 1){
            for(int j=1; j<=n; ++j)if(p.count(a[i][j]))p.erase(a[i][j]);
        }
        else{
            for(int j=1; j<=n; ++j)if(p.count(a[j][i]))p.erase(a[j][i]);
        }
    };

    while(1){
        bool f = false;
        // for(int i=1; i<=n; i+=3){
        //     for(int j=1; j<=n; j+=3){
        //         set<int> p;
        //         for(int ii=0; ii<3; ++ii){
        //             for(int jj=0; jj<3; ++jj){
        //                 if(a[i+ii][j+jj])
        //                 p.insert(a[i+ii][j+jj]);
        //             }
        //         }
        //         for(int ii=0; ii<3; ++ii){
        //             for(int jj=0; jj<3; ++jj){
        //                 if(a[i+ii][j+jj])continue;
        //                 // only val
        //                 {
        //                     auto pp = p;
        //                     check(pp, ii+i, 1);check(pp, jj+j, 2);
        //                     if(pp.find(0) != pp.end())pp.erase(0);
        //                     if(pp.size() == 8){
        //                         int k = 1;
        //                         while(pp.count(k))++k;
        //                         a[i+ii][j+jj] = k;
        //                         f = true;
        //                     }    
        //                 }
                        
        //                 if(f)break;
        //                 // only pos
        //                 while(0){
        //                     set<int> s;
        //                     for(int i=1; i<=n; ++i)s.insert(i);
        //                     for(auto v : p)if(s.count(v))s.erase(v);
        //                     del(s, i+ii, 1);del(s, j+jj, 2);
        //                     int x = i, y = i;//up down
        //                     if(ii == 0)x ++, y += 2;
        //                     else if(ii == 1)y+=2;
        //                     else y++;   
        //                     int xx = j, yy = j;//left right
        //                     if(jj == 0)xx++, yy += 2;
        //                     else if(jj == 1)yy+=2;
        //                     else ++yy;
        //                     // cout << ii+i << " " << jj+j << endl;
        //                     // cout << xx << ' ' << yy << ' ' << x << ' ' << y << endl;
        //                     set<int> up, down, left, right;
        //                     for(int i=1; i<=n; ++i){
        //                         if(i == j || i == j+1 || i == j+2)continue;
        //                         up.insert(a[x][i]), down.insert(a[y][i]);
        //                     }
        //                     for(int k=1; k<=n; ++k){
        //                         if(k == i || k == i+1 || k == i+2)continue;
        //                         left.insert(a[k][xx]), right.insert(a[k][yy]);
        //                     }
                            
        //                     for(auto v : s){
        //                         if((up.count(v) || (a[x][j] && a[x][j+1] && a[x][j+2])) && (down.count(v) || (a[y][j] && a[y][j+1] && a[y][j+2]))){
        //                             if((a[i+ii][xx] || left.count(v)) && (a[i+ii][yy] || right.count(v))){
        //                                 a[i+ii][j+jj] = v;
        //                                 f = true;
        //                                 break;
        //                             }
        //                         }
        //                         if((left.count(v) || (a[i][xx] && a[i+1][xx] && a[i+2][xx])) && (right.count(v) || (a[i][yy] && a[i+1][yy] && a[i+2][yy]))){
        //                             if((a[x][j+jj] || up.count(v)) && (a[y][j+jj] || down.count(v))){
        //                                 a[i+ii][j+jj] = v;
        //                                 f = true;
        //                                 break;
        //                             }
        //                         }
        //                     }
        //                     // if(f)exit(0);
        //                 }
        //                 if(f)break;
        //             }
        //             if(f)break;
        //         }
        //         if(f)break;
        //     }
        //     if(f)break;
        // }
        // if(!f){
        //     set<int> cnt[10][10];
        //     for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j){
        //         for(int k=1; k<=n; ++k)cnt[i][k].insert(a[i][j]);
        //         for(int k=1; k<=n; ++k)cnt[k][j].insert(a[i][j]);
        //         int x = (i-1)/3 + 1, y = (j-1)/3 + 1;
        //         for(int ii=0; ii<3; ++ii)for(int jj=0; jj<3; ++jj)cnt[x+ii][y+jj].insert(a[i][j]);
        //     }
        //     for(int i=1; i<=n; ++i){
        //         for(int j=1; j<=n; ++j){
        //             if(cnt[i][j].size() == 8){
        //                 int k = 1;
        //                 while(cnt[i][j].count(k))++k;
        //                 a[i][j] = k;
        //                 f = true;
        //                 break;
        //             }
        //         }
        //         if(f)break;
        //     }
        // }
        if(!f)break;
    }
    bool f = true;
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)if(!a[i][j])f = false;
    if(f){
        cout << "Easy\n";
        for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)cout << a[i][j] << " \n"[j == n];
    }
    else{
        cout << "Not easy" << endl;
        for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j){
            if(a[i][j])cout << a[i][j] << " \n"[j == n];
            else
            cout << '.' << " \n"[j == n];
        }
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