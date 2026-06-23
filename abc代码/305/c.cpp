#include<iostream>
#include<algorithm>

using namespace std;
const int N =510;

char a[N][N];
 int x1,y11,y2,x2;
int main()
{

    int h,w;
    cin>>h>>w;

   
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='#')
            {
                if(x1==0||i<x1)x1=i;
                if(y11==0||j<y11)y11=j;
                x2=max(i,x2);
                y2=max(j,y2);
            }
        }
    }

    for(int i=x1;i<=x2;i++)
    {
        for(int j=y11;j<=y2;j++)
        {
            if(a[i][j]=='.'){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }

}