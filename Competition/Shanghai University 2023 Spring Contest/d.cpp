#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int bh(char t)
{
    if(t=='R')return 1;
    if(t=='Y')return 2;
    if(t=='B')return 3;
    if(t=='G')return 4;


    return 0;
}

int bh2(char t)
{
    if(t=='+')return 10;
    if(t=='R')return 11;
    if(t=='S')return 12;
    
    return 0;
}

struct per{
    
    int pi[16][20];
    int size=0;

    int st;
}q[N];



// void print(int x)
// {
//     cout<<x<<endl;
//     for(int i=0;i<=15;i++)
//     {
//         for(int j=0;j<=5;j++)
//         {
//             for(int k=1;k<=q[x].pi[i][j];k++)cout<<i<<" "<<j<<" |";
//         }
//     }
//     cout<<endl;
// }
    // if(t=='R')return 1;
    // if(t=='Y')return 2;
    // if(t=='B')return 3;
    // if(t=='G')return 4;

deque<PII>d;
int ne;
int t=1;
int x=1;

void dp(int x,int i,int j)
{
   // cout<<x<<"出牌"<<i<<" "<<j<<endl;
    if(i==10){
        auto T2 = d.front();d.pop_front();
        q[ne].pi[T2.first][T2.second]++;

      // cout<<"倒霉蛋2是"<<ne<<",抽取了"<<T2.first<<T2.second<<endl;
        T2 = d.front();d.pop_front();
        q[ne].pi[T2.first][T2.second]++;
       //cout<<"倒霉蛋2是"<<ne<<",抽取了"<<T2.first<<T2.second<<endl;

       q[ne].size+=2;
        q[ne].st=false;
    }
    else if(i==11)
    {
        t=-t;

        ne = x+t;
        if(ne > 4)ne-=4;
        if(ne < 1)ne +=4;
        //cout<<"翻转了，下一个是"<<ne<<endl;
    }
    else if(i==12)
    {
        q[ne].st=false;
    }

    q[x].pi[i][j]--;
  //  if(x==2&&i==2&&j==1)cout<<"sssssassss"<<endl;

    q[x].size--;

    d.push_back({i,j});
}


void solve()
{


    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=5;j++)
        {
            string s;
            cin>>s;
            PII t;
            t.second=bh(s[0]);
            if(s[1]>='0'&&s[1]<='9')t.first=s[1]-'0';
            else t.first=bh2(s[1]);
            q[i].size++;
            q[i].pi[t.first][t.second]++;
           //cout<<s[0]<<s[1]<<" "<<t.first<<" "<<t.second<<"|";
        }
      //  cout<<endl;
        q[i].st = true;
    }

    int m;
    cin>>m;


    while(m--)
    {
        string s;
        cin>>s;
        PII t;
        t.second=bh(s[0]);
        if(s[1]>='0'&&s[1]<='9')t.first=s[1]-'0';
        else t.first=bh2(s[1]);

        d.push_back(t);
    }

  // for(int i=1;i<=4;i++)print(i);cout<<endl;

    m=2;
    while(m)
    {

        ne = x+t;
        if(ne > 4)ne-=4;
        if(ne < 1)ne +=4;
       
        if(q[x].st==false){
            q[x].st=true;
          //  cout<<x<<"我是倒霉蛋"<<endl;
            x=ne;
            continue;
        }
       
       
        auto card = d.back();

        //cout<<"底牌"<<card.first<<" "<<card.second<<endl;


        bool cp=false;

        for(int i=0;i<card.first&&!cp;i++)
        {
            if(q[x].pi[i][card.second]==0)continue;
            dp(x,i,card.second);
            cp=true;
        }

        for(int i=1;i<=4&& !cp;i++)
        {
            if(q[x].pi[card.first][i]==0)continue;
            dp(x,card.first,i);
             cp=true;
        }
        
         for(int i=card.first+1;i<=12&&!cp;i++)
        {
            if(q[x].pi[i][card.second]==0)continue;
         //   cout<<q[x].pi[i][card.second]<<" "<<x<<" "<<i<<" "<<card.second<<endl;
            dp(x,i,card.second);
             cp=true;
        }
    

        if(cp==false){

            auto T1 = d.front();d.pop_front();
            auto T2 = d.back();
          //  cout<<x<<"抽取了"<<T1.first<<" "<<T1.second<<endl;

                q[x].pi[T1.first][T1.second]++;
                q[x].size++;

        for(int i=0;i<card.first&&!cp;i++)
        {
            if(q[x].pi[i][card.second]==0)continue;
            dp(x,i,card.second);
            cp=true;
        }

        for(int i=1;i<=4&& !cp;i++)
        {
            if(q[x].pi[card.first][i]==0)continue;
            dp(x,card.first,i);
             cp=true;
        }
        
         for(int i=card.first+1;i<=12&&!cp;i++)
        {
            if(q[x].pi[i][card.second]==0)continue;
         //   cout<<q[x].pi[i][card.second]<<" "<<x<<" "<<i<<" "<<card.second<<endl;
            dp(x,i,card.second);
             cp=true;
        }
    






            // if(T1.first==T2.first||T1.second==T2.second){

            //     d.push_back(T1);
            //   // cout<<x<<"zai出牌"<<T1.first<<" "<<T1.second<<endl;

            //     q[x].pi[T1.first][T1.second]++;
            //     q[x].size++;

            //    dp(x,T1.first,T1.second);
                
            // } 
            // else {
            //     q[x].pi[T1.first][T1.second]++;
            //     q[x].size++;
            // }
        }



        if(q[x].size==0){
            cout<<(char)('A'+x-1)<<endl;
            return;
        }
      //  cout<<endl;

        x=ne;

      // for(int i=1;i<=4;i++)print(i);cout<<endl;

       // cout<<ne<<endl;
    }
   

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}