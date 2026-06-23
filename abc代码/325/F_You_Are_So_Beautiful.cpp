#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e6+10;
int p[N];
int n,m;
int ne[N];

int main()
{
    int n;
    
    cin>>n;
    for(int i =1;i<=n;i++)cin>>p[i];


    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&p[j+1]!=p[i])
        {
            j=ne[j];
        }
        
        if(p[j+1]==p[i])j++;
        
        ne[i]=j;
        cout<<ne[i]<<endl;
    }



 
}
