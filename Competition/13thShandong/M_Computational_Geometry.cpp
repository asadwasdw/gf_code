#include<bits/stdc++.h>
#define double long double
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

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
};

typedef Point Vector;//向量和点的表示方法一样

double Distance(Point A,Point B){
    return hypot(A.x-B.x,A.y-B.y);
}


double Dist(Point A,Point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double Dot(Vector A,Vector B){//向量A,B的点积
    return A.x*B.x+A.y*B.y;
}

// dot>0 夹角为锐角
// dot<0 夹角为钝角
// dot=0 夹角为直角

double Len(Vector A){
    return sqrt(Dot(A,A));
}

double Len2(Vector A){//长度的平方，防止开平方的小数
    return Dot(A,A);
}

double Angle(Vector A,Vector B){//弧度制，自带一个Pi
    return acos(Dot(A,B)/Len(A)/Len(B));
}

double Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}

//A x B > 0,B在A的逆时针方向
//A x B < 0,B在A的顺时针方向
//A x B = 0,AB同向或者逆向

double Area2(Point A,Point B,Point C){
    return Cross(B-A,C-A);//一个以A为公共点，和BC构成的平行四边形的面积,有正负
}
//三个点构成的三角形面积是Area2的一半

Vector Rotate(Vector A,double rad){//向量逆时针旋转
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

Vector Normal(Vector A,Vector B){//单位法向量
    return Vector(-A.y/Len(A),A.x/Len(A));
}

bool Parallel(Vector A,Vector B){//用法向量判断平行
    return sgn(Cross(A,B))==0;
}

struct Line{
    Point p1,p2;
    Line(){};
    Line(Point p1,Point p2):p1(p1),p2(p2){
        // if(p1.x>p2.x) swap(this->p1,this->p2);//保证方向向右,
    };

    Line (Point p, double angle){
        p1=p;
        if(sgn(angle-pi/2)==0){p2=p1+Point(0,1);}
        else p2 = (p1+Point(1,tan(angle)));
    }

    Line(double a,double b,double c){   /// ax+by+c=0
        if(sgn(a)==0){
            p1=Point(0,-c/b);
            p2=Point(2,-c/b);
        }
        else if(sgn(b)==0){
            p1=Point(-c/a,0);
            p2=Point(-c/a,1);
        }
        else {
            p1=Point(0,-c/b);
            p2=Point(1,(-c-a)/b);
        }
    }
};

int Point_line_relation(Point p,Line v){ //要保证p2在p1的右边，才是跟习惯上一样，否则会因为直线俩个点的位置，导致结果不一样
    int c = sgn(Cross(p-v.p1,v.p2-v.p1));
    if(c<0)return 1;//p在v的左侧
    if(c>0)return 2;//p在v的右侧
    return 0;
}

void Yes_or_NO(bool st){
    if(st)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}


bool Point_on_seg(Point p,Line v){
    return sgn(Cross(p-v.p1,v.p2-v.p1)) ==0 && sgn(Dot(p-v.p1,p-v.p2))<0;
}

double Dis_point_line(Point p,Line v){
    return fabs(Cross(p-v.p1,v.p2-v.p1))/Distance(v.p1,v.p2);
}


Point Point_line_Proj(Point p,Line v){  // 点在直线上的投影
    double k = Dot(v.p2-v.p1,p-v.p1)/Len2(v.p2-v.p1);
    return v.p1+ (v.p2-v.p1)*k;
}


Point Point_line_symmetry(Point p,Line v)//投影点
{
    Point q = Point_line_Proj(p,v);
    return Point(2*q.x-p.x,2*q.y-p.y);
}

double Dis_point_seg(Point p,Line v){
    if(sgn(Dot(p-v.p1,v.p2-v.p1))<0||sgn(Dot(p-v.p2,v.p1-v.p2))<0){
        return min(Distance(p,v.p1),Distance(v.p2,p));
    }
    return Dis_point_line(p,v);
}

int Line_relation(Line v1,Line v2){
    if(sgn(Cross(v1.p2-v1.p1,v2.p2-v2.p1))==0){
        if(Point_line_relation(v1.p1,v2)==0)return 1;//重合
        else return 0;// 平行
    }
    return 2;//相交
}

Point Cross_point(Point a,Point b,Point c,Point d){
    double s1 = Cross(b-a,c-a);
    double s2 = Cross(b-a,d-a);
    return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);
}

bool Cross_segment(Point a,Point b,Point c,Point d){
    double c1 = Cross(b-a,c-a);
    double c2 = Cross(b-a,d-a); // cd在两侧
    double c3 = Cross(d-c,a-c);
    double c4 = Cross(d-c,b-c); // ab在两侧

    return sgn(c1)*sgn(c2)<0&&sgn(c3)*sgn(c4)<0;
}

Point d[N];


double js(int x,int y,int z)
{
    return fabs(Area2(d[x],d[y],d[z])/2);
}




void solve()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>d[i].x>>d[i].y;
    }



    int a,b,c;
    b = 1;
    c = b+k;
    if(c>n)c-=n;
    double ans = 0;
    a=c+1;
    //cout<<a<<b<<c<<endl;
   double jc = 0;

    for(int i = 3 ;i<=c;i++)
    {
        jc+=js(b,i,i-1);
    }

    while(1)
    {
        if(a==c){
            a+=1;
            if(a>n)a-=n;
        }
        double xz = js(a,b,c);
        while(1)
        {
            int ne = a+1;
            if(ne>n)ne-=n;
            double t =  js(ne,b,c);
            if(t<xz||fabs(t-xz)<=eps){
                break;
            }
            else {
                a=ne;
                xz=t;
            }
        }
        

       ans= max(ans,xz+jc);

        int neb = b+1;
        int nec = c+1;
        if(neb>n)neb-=n;
        if(nec>n)nec-=n;
    

        jc-=js(b,neb,c);
        jc+=js(c,nec,neb);
        b=neb;
        c=nec;
      
        if(b==1)break;
    }
   printf("%.12Lf\n",ans);
}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
   // cout << setprecision(15) << fixed;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}