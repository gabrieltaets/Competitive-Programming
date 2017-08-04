#include <bits/stdc++.h>

using namespace std;

#define fori(i, n) for(int i= 0; i < (n); ++i)
#define forr(i, a, b) for(int i = (a); i <= (b); ++i)
#define ford(i, a, b) for(int i = (a); i >= (b); --i)

#define tr(T, i) for (typeof(T.begin()) i = T.begin(); i != T.end(); ++i )
#define sz size()
#define all(x) (x).begin(),(x).end()
#define _sort(x) sort(all(x))
#define pb push_back
#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
const double EPS = 1e-9; const int INF = 0x3F3F3F3F;
int cmpD(double x, double y = 0, double tol = EPS) {
return ( x <= y + tol ) ? ( x + tol < y ) ? -1 : 0 : 1; }

int cmpD(double a, double b = 0.0) 
{ return a+EPS < b ? -1 : a-EPS > b; }

struct Point {
    double x, y, z;
    Point(double a=0.0,double b=0.0,double c=0.0){x=a,y=b,z=c;}
    Point operator+(const Point &P) const {return Point(x+P.x,y+P.y,z+P.z);}
    Point operator-(const Point &P) const {return Point(x-P.x,y-P.y,z-P.z);}
    Point operator*(double c) const {return Point(x*c,y*c,z*c);}
    Point operator/(double c) const {return Point(x/c,y/c,z/c);}
    double operator!() const {return sqrt(x*x+y*y+z*z);}
};

double dot(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }

Point cross(Point A, Point B) {
    return Point(A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x);
}

Point project(Point W, Point V) { return V * dot(W,V) / dot(V,V); }

bool seg_intersect(Point A, Point B, Point C, Point D) {
    return cmpD(dot(cross(A-B,C-B),cross(A-B,D-B))) <= 0 &&
            cmpD(dot(cross(C-D,A-D),cross(C-D,B-D))) <= 0;
}

double dist_point_seg(Point P, Point A, Point B) {
    Point PP = A + project(P-A,B-A);
    if (cmpD(!(A-PP)+!(PP-B),!(A-B)) == 0) return !(P-PP);//distance point-line!
        return min(!(P-A),!(P-B));
}

double dist_seg_seg(Point A, Point B, Point C, Point D) {
    Point E = project(A-D,cross(B-A,D-C)); // distance between lines!
    if (seg_intersect(A,B,C+E,D+E)) return !E;
    return min( min( dist_point_seg(A,C,D), dist_point_seg(B,C,D) ),
            min( dist_point_seg(C,A,B), dist_point_seg(D,A,B) ) );
}
// point-triangle distance. dps = dist_point_seg
double dist_point_tri(Point P, Point A, Point B, Point C) {
    Point N = cross(A-C,B-C);
    Point PP = P + project(C-P,N);
    Point V1 = cross(PP-A,B-A);
    Point V2 = cross(PP-B,C-B);
    Point V3 = cross(PP-C,A-C);
    if (cmpD(dot(V1,V2)) >= 0 && cmpD(dot(V1,V3)) >= 0 && cmpD(dot(V2,V3)) >= 0)
        return !(PP-P); // distance point-plane!
    return min(dps(P,A,B),min(dps(P,A,C),dps(P,B,C)));
}

double dist_tet_tet(Point T1[4], Point T2[4]) {
    double ans = INF;
    for (int i=0; i < 4; i++) // arestas -> arestas
        for (int j=i+1; j < 4; j++)
            for (int ii=0; ii < 4; ii++)
                for (int jj=ii+1; jj < 4; jj++)
                    ans = min( ans, dist_seg_seg(T1[i],T1[j],T2[ii],T2[jj]) );
    for (int i=0; i < 4; i++)
        for (int j=i+1; j < 4; j++)
            for (int k=j+1; k < 4; k++)
                for (int x=0; x < 4; x++)
                    ans = min( ans, dist_point_tri(T1[x],T2[i],T2[j],T2[k]) ),
    ans = min( ans, dist_point_tri(T2[x],T1[i],T1[j],T1[k]) );
return ans;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        double x,y, z;
        Point a[4];
        Point b[4];
        for(int i = 0; i < 4; ++i)
        {
            cin >> x >> y >> z;
            a[i] = Point(x,y,z);
        }
        for(int i = 0; i < 4; ++i)
        {
            cin >> x >> y >> z;
            b[i] = Point(x,y,z);
        }
        cout << dist_tet_tet(a,b) << endl;
    }
}