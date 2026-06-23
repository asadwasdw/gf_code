#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


bool cmp(int a,int b){
    return a>b;
}

void solve()
{
    unordered_map<char,vector<int>>st;
    int n;
    cin>>n;
    char wp;
    cin>>wp;

    
    for(int i=1;i<=2*n;i++) {
        string s;
        cin>>s;
        int num = s[0]-'0';
        st[s[1]].push_back(num);
    }
    int cnt = 0;
    for(auto &t:st) {
        if(t.first==wp)continue;
        cnt+=t.second.size()%2;
    }
    if(cnt>st[wp].size()){
        cout<<"IMPOSSIBLE\n";

        for(auto &t:st){
            t.second.clear();
        }
        return;
    }


    for(auto &t:st) {
        sort(t.second.begin(),t.second.end(),cmp);
        if(t.first==wp)continue;

        while(t.second.size()>=2) {
            cout<<*t.second.rbegin()<<t.first<<" ";
            t.second.pop_back();

            cout<<*t.second.rbegin()<<t.first<<endl;
            t.second.pop_back();
        }
    }

    for(auto &t:st) {
        if(t.first==wp)continue;

        while(t.second.size()&&st[wp].size()) {
            cout<<*t.second.rbegin()<<t.first<<" ";
            t.second.pop_back();

            cout<<*st[wp].rbegin()<<wp<<endl;
            st[wp].pop_back();
        }
    }

    for(auto &t:st) {
        if(t.first!=wp)continue;

        while(t.second.size()>=2) {
            cout<<*t.second.rbegin()<<t.first<<" ";
            t.second.pop_back();

            cout<<*t.second.rbegin()<<t.first<<endl;
            t.second.pop_back();
        }
    }

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}