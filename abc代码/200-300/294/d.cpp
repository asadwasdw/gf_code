#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

bool st[N];

void solve()
{
    priority_queue<int ,vector<int>,greater<int>>heap;

    int n;cin>>n;
    int q;cin>>q;
    int mn=1;

    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            heap.push(mn);
            mn++;
        }
        else if(t==2)
        {
            int x;
            cin>>x;
            st[x]=true;
        }
        else {
            while(st[heap.top()]){
                heap.pop();
            }
            cout<<heap.top()<<endl;
        }
    }




}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}