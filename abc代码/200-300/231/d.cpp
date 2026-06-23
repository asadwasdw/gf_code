#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10;
int a[N];
int f[N];

int find(int x){
    if(x!=f[x])return f[x]=find(f[x]);
    return x;
}

int main()
{
    int n;cin>>n;
    int q;cin>>q;
    bool ky=true;

    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]++;
        a[y]++;

        int fx=find(x);
        int fy=find(y);

        if(fx==fy){
            ky=false;
        }
        else {
            f[fx]=fy;
        }
    }

   

    for(int i=1;i<=n;i++)
    {
        if(a[i]>2)ky=false;
    }
    if(ky)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}