#include<iostream>
#include<algorithm>

using namespace std;

#define int long long 
int n,q;

const int N = 9e5+10;
int tr[N];
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
    for(int i=x;i<N;i+=lowbit(i))tr[i]+=c;
}

signed main()
{
    cin>>n>>q;

    while(q--)
    {
        char c;
        int a,b;
        cin>>c>>a;

        if(c=='-')
        {
            add(a,1);
        }
        else if(c=='+')
        {
            add(a,-1);
        }
        else 
        {
            cin>>b;

            bool ky=false;

            if(a>b)swap(a,b);

            if(sum(b)==sum(a-1))ky=true;

            if(sum(n+1)-(sum(b-1)-sum(a))==0)ky=true;

            if(ky)cout<<"possible"<<endl;
            else cout<<"impossible"<<endl;


        }

    }
}