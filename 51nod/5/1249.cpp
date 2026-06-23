#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
typedef pair<int,int>PII;
const int N=5e5+10;

PII L[N],R[N];

int tr[N];
int n;

int a[N];

int lowbit(int x)
{
    return x&-x;
}

int sum(int x)
{
    if(x==0)return 0;
    int res=0;
    //cout<<x<<" "<<n<<endl;
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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    stack<int>s;

    for(int i=1;i<=n;i++)
    {
        while(s.size()&&a[s.top()]<=a[i])s.pop();
        
        if(s.size()){
            L[i].first=s.top()+1;
        }
        else L[i].first=1;
        L[i].second=i;
        s.push(i);
    }

    while(s.size())s.pop();

    for(int i=n;i;i--)
    {
        while(s.size()&&a[s.top()]>=a[i])s.pop();
        
        if(s.size()){
            R[i].first=s.top()-1;
        }
        else R[i].first=n;
        R[i].second=i;
        s.push(i);
    }

    sort(L+1,L+n+1);

    int num=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(num<=n&&L[num].first<=i)add(L[num++].second,1);
        ans+=sum(R[i].first)-sum(i-1);
       // cout<<R[i].first<<" "<<i-1<<endl;
    }

    cout<<ans<<endl;






}