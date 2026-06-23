#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

string js(int l, int r, string &s, int t) {
    string res;
    for(int i = 0; i < 4; i ++) {
        if(l <= i && i <= r) {
            res += (char)((s[i] - '0' + t + 10)%10 + '0');
        } else {
            res += s[i];
        }
    }
    return res;
}

queue<string> q;
map<string,bool> vis;
map<string,int> dis;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i < 4; i ++) {
        s2[i] = (s2[i] - s1[i] + 10) % 10 + '0';
    }
    // cout << s2 << endl;
    cout << dis[s2] << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;


    q.push("0000");
    vis["0000"] = true;
    dis["0000"] = 0;
    while(q.size()) {
        string u = q.front(); q.pop();
        // cout << u << endl;
        for(int l = 0; l < 4; l ++) {
            for(int r = l; r < 4; r ++) {

                string t1 = js(l, r, u, 1);
                string t2 = js(l, r, u, -1);
                // cout << t1 << " " << t2 << endl;
                if(!vis[t1]) {
                    vis[t1] = true;
                    dis[t1] = dis[u] + 1;
                    q.push(t1);
                } 

                if(!vis[t2]) {
                    vis[t2] = true;
                    dis[t2] = dis[u] + 1;
                    q.push(t2);
                } 
            }
        }
    }



    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}