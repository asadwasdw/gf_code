#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N=5e5+10;

int tr[N];
int a[N];
int b[N];
int n;
unordered_map<int,int>st;
int lowbit(int x)
{
    return x&-x;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}

void add(int x,int c)
{
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}

int main()
{
    cin>>n;

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=b[i]=x;
    }

    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)
    {
        st[b[i]]=i;
    }


    for(int i=1;i<=n;i++)
    {
        int t=st[a[i]];

        ans+=sum(n)-sum(t);
        add(t,1);
    }

    cout<<ans<<endl;


}