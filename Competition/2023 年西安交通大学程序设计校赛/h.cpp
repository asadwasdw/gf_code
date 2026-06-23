#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int cnt[30];

set<int>st[30];

void solve()
{

    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(auto t:s )
        {
            cnt[t-'a']++;
        }

        for(int i=0;i<=25;i++)
        {
            st[i].insert(cnt[i]);
        }
        memset(cnt,0,sizeof cnt);
    }

    //for(int i=0;i<=25;i++)cout<<i<<" "<<st[i].size()<<endl;

    int ky=-1;
    for(int i=0;i<=25;i++)
    {
       //st[i].insert(0);
        if(st[i].size()>=n){
            ky=i;
        }
    }

    if(ky==-1)cout<<"no"<<endl;
    else {
        cout<<"yes"<<endl;
        for(int i=0;i<=25;i++)
        {
            if(i==ky)continue;
            if(st[i].size()==1&& *st[i].begin()==0)continue;
            cout<<char('a'+i);
        }
        cout<<char('a'+ky);
    }

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}