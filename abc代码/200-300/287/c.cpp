#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10;
int p[N],w[N];
int d[N];
int cnt1=0;
int cnt2=0;
int find(int x)
{
    if(p[x]!=x)return p[x]=find(p[x]);
    return x;
}



int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;w[i]=1;
    }
    
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        d[a]++;
        d[b]++;
        if(find(a)!=find(b))
        {
            w[find(b)]+=w[find(a)];
           p[find(a)]=find(b);
        }
    }

	for(int i=1;i<=n;i++)
	{
		if(d[i]==1)cnt1++;
		if(d[i]==2)cnt2++;
	}
    //cout<<cnt1<<cnt2<<w[find(1)]<<endl;
    if(cnt1==2&&cnt2==n-2&&w[find(1)]==n&&n==m+1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


}