#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

const double pi =acos(-1.0);
const double eps =1e-8;

int sgn(double x){
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}

struct Point{
    double x,y;
    Point(){};
    Point(double x,double y):x(x),y(y){};

    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    Point operator * (double k){return Point(x*k,y*k);}
    Point operator / (double k){return Point(x/k,y/k);}
    bool operator == (Point B){return sgn(x-B.x)==0&&sgn(y-B.y)==0;}

    void print(){
        cout<<x<<" "<<y<<endl;
    }
}p[5];

typedef Point Vector;

double Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}

//A x B > 0,B在A的逆时针方向
//A x B < 0,B在A的顺时针方向
//A x B = 0,AB同向或者逆向

void solve()
{
    for(int i=0;i<4;i++)
    {
        cin>>p[i].x>>p[i].y;
    }

    for(int i=0;i<4;i++)
    {
        Vector t1 = p[(i+1)%4] - p[i]; 
        Vector t2 = p[(i+2)%4] - p[(i+1)%4]; 
        double t = Cross(t1,t2);
        if(t<0){
            cout<<"No"<<endl;
            return ;
        }
    }

    cout<<"Yes"<<endl;
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