#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

string s;
int a, b;


void solve()
{
    map<string, int> mp, mp2;
    set<string> p;
    while(cin >> s){
        if(s[0] == '-')break;
        string t;
        cin >> b >> t;
        a = 0;
        for(int i=0; i<s.size(); ++i)a = a*10 + s[i] - '0';
        p.insert(t);
        mp[t] += b - a;
    }
    while(cin >> s){
        if(s[0] == '=')break;
        string t;
        cin >> b >> t;
        a = 0;
        for(int i=0; i<s.size(); ++i)a = a*10 + s[i] - '0';
        p.insert(t);
        mp2[t] += b - a;
    }
    bool f = false;
    for(auto it : p){
        if(mp2[it] != mp[it]){
            f = true;
            int val = mp2[it] - mp[it];
            cout << it << ' ' << ( val > 0 ? '+' : '-') << abs(val) << '\n';
        }
    }
    if(!f){
        cout << "No differences found.\n";
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