#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

vector<PII>a,b;

void solve()
{
    string s;
    cin>>s;
    int cnt = 0;
    for(auto t:s) {
        if(t=='b') {
            if(a.size())a.pop_back();
        }
        else if( t == 'B') {
            if(b.size())b.pop_back();
        }
        else {
            if(t<='Z') {
                b.push_back({cnt,t});
            }
            else a.push_back({cnt,t});
        }
        cnt ++;
    }

    // for(auto t:a)cout<<t.second<<endl;
    // for(auto t:b)cout<<t.second<<endl;

    int i = 0,j = 0;
    while(i<a.size() && j < b.size()) {
        if(a[i].first<b[j].first) {
            cout << a[i].second;
            i++;
        }
        else {
            cout << b[j].second;
            j++;
        }
    }

    while(i<a.size()) {
        cout << a[i].second;
        i++;
    }

    while(j < b.size()) {
        cout<<b[j].second;
        j++;
    }
    cout <<endl;
    a.clear();
    b.clear();







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