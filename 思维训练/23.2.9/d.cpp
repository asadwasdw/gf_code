#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int N=2e5+10;

int a[N],b[N];
queue<int>q[N];

void solve()
{
    
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        q[a[i]].push(i);
    }

    int idx=0;
    int m=0;

    while(idx<n)
    {
        int cur=idx;
        int i=0;
        for(;i<=n;i++){
            if(q[i].size()==0)break;
            cur=max(cur,q[i].front());
        }
        b[m++]=i;
       // cout<<i<<" "<<bj<<" "<<r<<endl;

        for(;idx<=cur;idx++){
            q[a[idx]].pop();
        }
        // for (int j = idx; j <= cur; ++j) {
		// 	q[a[j]].pop();
		// }
		// idx = cur + 1;// 更新起始下标 

       // cout<<idx<<endl;
    }

    cout<<m<<endl;

    for(int i=0;i<m;i++)cout<<b[i]<<" ";
    cout<<endl;
    return;


}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}