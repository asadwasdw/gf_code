#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


unordered_map<string,vector<string> >edg;

unordered_map<string,int> pen;
vector<int>ans;
void dfs(string fa) {
    cout << fa << endl;
    for(auto son:edg[fa]) {
        ans.push_back(1);
        dfs(son);
        ans.push_back(0);
    }
}

string Type,Name[N],bits; map <string,int> rst; vector <int> v[N],order; int idx,hasfa[N],fa[N];

inline int getID(const string& name)
{
    if (rst.count(name)) return rst[name];
    return rst[name]=++idx;
}
void solve()
{
    string op;
    cin >> op;
    if(op == "ENCODE") {
        string s;
        string boss;
        while(cin >> s) {
            if(s.back() ==':') {
                s.pop_back();
                boss = s;
                pen[s]++;
            }
            else {
                edg[boss].push_back(s);
                pen[s]--;
            }       
        } 

        string root;
        for(auto [s,t]:pen) {
            if(t == 1) root = s;
        }
        // cout << root << endl;
        dfs(root);

        for(auto t:ans) cout<<t;
    }
    else 
        {
        string s; int n=0;
        while (cin>>s)
        {
            if (s[0]=='0'||s[0]=='1') break;
            Name[++n]=s;
        }
        int cur=1,now=1;
        int i;
        for (i=0;i<s.size();++i)
            if (s[i]=='1') ++cur,v[now].push_back(cur),fa[cur]=now,now=cur; else now=fa[now];
        for (i=1;i<=n;++i) if (!v[i].empty())
        {
            cout<<Name[i]<<":";
            for (auto j:v[i]) cout<<" "<<Name[j];
            cout<<endl;
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