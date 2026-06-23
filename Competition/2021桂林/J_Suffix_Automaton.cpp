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
int a[N];
string s;
int len[N * 2], fail[N * 2], tr[N * 2][26];
int idx, last;

void sam_init(){
    idx = 0;
    len[0] = 0;
    fail[0] = -1;
    idx++;
    last = 0;
}

void sam_extend(int c){
    int cur = idx++;
    len[cur] = len[last] + 1;
    int p = last;
    while(p != -1 && !tr[p][c]){
        tr[p][c] = cur;
        p = fail[p];
    }
    if(p == -1){
        fail[cur] = 0;
        
    }
    else{
        int q = tr[p][c];
        if(len[p] + 1 == len[q]){
            fail[cur] = q;
        }
        else{
            int clone = idx++;
            len[clone] = len[p] + 1;
            for(int i=0; i<26; ++i)tr[clone][i] = tr[q][i];
            fail[clone] = fail[q];
            while(p != -1 && tr[p][c] == q){
                tr[p][c] = clone;
                p = fail[p];
            }
            fail[q] = fail[cur] = clone;
        }
    }
    last = cur;
}

void solve()
{
    cin >> s;
    n = s.size();
    for(int i=0; i<n; ++i){
        
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