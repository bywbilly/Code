/*
id:bywbill1
LANG:C++
TASK:
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double PIE = acos(-1.0);

typedef long long LL;
typedef long double ld;
typedef pair<int,int> pii;
//#define magic tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 
#define LB(x) (x & (-x))
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1

int sign(double x){
	return x < -eps ? -1 : x > eps;
}

inline void shit(){
	freopen("","r",stdin);
	freopen("","w",stdout);
}

struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    double len() const
    {
        return(sqrt(x*x+y*y));
    }
    point unit() const
    {
        double t=len();
        return(point(x/t,y/t));
    }
    point rotate() const
    {
        return(point(-y,x));
    }
    point rotate(double t) const
    {
         return(point(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t)));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || (sign(a.x-b.x)==0 && sign(a.y-b.y)<0));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double dist(const point &a,const point &b)
{
    return((a-b).len());
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(b-a,p-a)));
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(dot(p-a,p-b))<=0 && sign(det(p-a,p-b))==0);
}
inline bool parallel(const point &a,const point &b,const point &c,const point &d)
{
    return(sign(det(b-a,d-c))==0);
}
inline bool orthogonal(const point &a,const point &b,const point &c,const point &d)
{
    return(sign(dot(b-a,d-c))==0);
}
inline bool cross(const point &a,const point &b,const point &c,const point &d)
{
    return(side(a,c,d)*side(b,c,d)==-1 && side(c,a,b)*side(d,a,b)==-1);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(b-a,c-a),s2=det(b-a,d-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline void convex(int &n,point a[])
{
    static point b[100010];
    int m=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    int rev=m;
    for (int i=n-1;i;i--)
    {
        while (m>rev && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    n=m-1;
    for (int i=1;i<=n;i++)
        a[i]=b[i];
}

const int maxn = 100000 + 10;

int n;
point p[maxn];

int main()
{
	while(scanf("%d",&n) == 1){
	for (int i = 1;i <= n;i++){
		double x,y; scanf("%lf%lf",&x,&y);
		p[i] = point(x,y);
	}
	convex(n,p);
	p[n + 1] = p[1];
	double ans = 0;
	for (int i = 2;i <= n + 1;i++){
//		double ret = det(p[i] - p[1],p[i + 1] - p[1]) / 2.0;
//		if (sign(ret) < 0) ret = -ret;
//		ans += ret;
		ans += det(p[i], p[i - 1]) / 2.0;
	}
	printf("%d\n",(int)(fabs(ans) / 50));
	//cout << (int)(fabs(ans) / 50) <<endl;
	}
	return 0;
}

