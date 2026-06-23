#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e4+10;
const int INF=0x3f3f3f3f;
int a[N],tr[N];
int n;
int lowbit(int x)
{
    return x&-x;
}


void update(int x,int v)
{
    while(x<=n)
    {
        tr[x]=max(tr[x],v);
        for(int i=1;i<lowbit(x);i<<=1)
        {
            tr[x]=max(tr[x],tr[x-i]);
        }
        x+=lowbit(x);
    }
}


int query(int l,int r)
{
    int ans=0;
    while(l<=r)
    {
        ans=max(ans,a[r]);
        r--;
        while(r-l>=lowbit(r)){
            ans=max(tr[r],ans);
            r-=lowbit(r);
        }
    }
    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }

    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        
        cout<<query(l+1,r+1)<<endl;
    }

}