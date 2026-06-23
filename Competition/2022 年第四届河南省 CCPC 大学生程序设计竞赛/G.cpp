#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s[1010];

    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=" "+s[i];
    }
    int ans=0;

    int q=0;
    cin>>q;
    while(q--)
    {
        int l,r,i,j,p;
        scanf("%d%d%d%d%d",&i,&j,&l,&r,&p);
    }

    for(int i=1;i<=m;i++)
    {
        bool ky=true;
        for(int j=1;j<=n;j++)
        {
            if(s[j][i]=='0')ky=false;
        }
        if(ky)ans++;
    }
    cout<<ans<<endl;

}