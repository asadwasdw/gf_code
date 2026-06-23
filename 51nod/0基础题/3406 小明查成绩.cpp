#include<iostream>
#include<algorithm>

using namespace std;


struct stu
{
    int yw,sx,yy;
    string name;
}s[10010];


int main()
{
    int n;cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].name>>s[i].yw>>s[i].sx>>s[i].yy;
    }

    int k;cin>>k;
    while(k--)
    {
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;

        for(int i=1;i<=n;i++)
        {
            if(s[i].yw<a||s[i].yw>b||s[i].sx<c||s[i].sx>d||s[i].yy<e||s[i].yy>f)continue;
            cout<<s[i].name<<endl;
        }

    }

}