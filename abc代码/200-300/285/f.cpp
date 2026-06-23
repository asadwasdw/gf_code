#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;

int tr[N][30];
typedef long long ll;
void add(int u,int x,int t)
{
    for(int i=u;i<N;i+= i&-i)tr[i][t]+=x;
}

int sum(int u,int t)
{
    int res=0;
    for(int i=u;i;i-= i&-i)res+=tr[i][t];
    return res;
}

int get(int l,int r,int t)
{
    return sum(r,t)-sum(l-1,t);
}

char s[N];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        add(i,1,s[i]-'a');
    }
    //cout<<sum(n,1)<<endl;

    int q;cin>>q;
    while(q--)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int x;char c;
            cin>>x>>c;

            add(x,-1,s[x]-'a');

            s[x]=c;
            add(x,1,s[x]-'a');
        }
        else 
        {
            bool ky=true;

            int l,r;
            cin>>l>>r;
            int mn=26,mx=-1;
            for(int i=0;i<26;i++)
            {
                if(get(l,r,i)>0){
                    mn=min(i,mn);
                    mx=max(mx,i);
                }
            }
           // cout<<mn<<" "<<mx<<endl;

            int x=l;
            for(int i=mn;i<=mx;i++)
            {
                int k=get(l,r,i);
                if(i>mn&&i<mx){
                    if(k<get(1,n,i))ky=false;
                }
                if(get(x,x+k-1,i)!=k)ky=false;
                x+=k;
                if(ky==false)
                {
                   // cout<<i<<" ";
                   break;
                }
            }

            if(ky)cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

}
