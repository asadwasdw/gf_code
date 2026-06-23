#include<iostream>
#include<algorithm>
#include<map>


using namespace std;

int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};


char s[110][110];

int main()
{
    string ans="snuke";

    int n,m;
    cin>>n>>m;


    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {

            for(int k=0;k<8;k++)
            {
                bool zd = false;
                string t="";
                for(int bs=0;bs<5;bs++)
                {
                    int x=i+dx[k]*bs;
                    int y=j+dy[k]*bs;

                    if(x<1||x>n||y<1||y>m)continue;

                    t+=s[x][y];
                }
                

                if(t==ans)
                {

                for(int bs=0;bs<5;bs++)
                {
                    int x=i+dx[k]*bs;
                    int y=j+dy[k]*bs;

                    cout<<x<<" "<<y<<endl; 

                }

                return 0;

                }

            }
        }

    }
    

}