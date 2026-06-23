#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int t;cin>>t;
    if(t<=30)
    {
        for(int i = 1;i<=t;i++)
        {
            for(int j = 1 ;j <= t;j++) {
                int z = t - i - j;
                set<int>s;
                s.insert(i);s.insert(j);s.insert(z);
                if(s.size()<=2)continue;
                if(z<=0)continue;
                if(z%3 && i%3 && j%3){
                    cout << "YES\n";
                    cout << i <<" "<< j <<" "<< z<<endl;
                    return;
                }
            }
        }
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        if(t%3==1) {
            cout<<"4 7 "<< t - 11 <<endl;
        }
        else cout<<"2 5 "<<t - 7<<endl;
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