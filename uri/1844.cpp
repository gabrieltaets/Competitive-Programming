#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))
using namespace std;
const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;
int cmpD(double a, double b = 0.0) { return a+EPS < b ? -1 : a-EPS > b; }
/*
 Estrutura de dados que define um ponto 3D
*/
struct Point {
  double x, y, z;
  Point(double a=0.0,double b=0.0,double c=0.0){x=a,y=b,z=c;}
  Point operator+(const Point &P) const {return Point(x+P.x,y+P.y,z+P.z);}
  Point operator-(const Point &P) const {return Point(x-P.x,y-P.y,z-P.z);}
  Point operator*(double c) const {return Point(x*c,y*c,z*c);}
  Point operator/(double c) const {return Point(x/c,y/c,z/c);}
  double operator!() const {return sqrt(x*x+y*y+z*z);}
};

double dist_seg_seg(Point A, Point B, Point C, Point D){
  Point E = project(A-D,cross(B-A,D-C)); // distance between lines!
  if (seg_intersect(A,B,C+E,D+E)) return !E;
  return min( min( dist_point_seg(A,C,D), dist_point_seg(B,C,D) ),
  min( dist_point_seg(C,A,B), dist_point_seg(D,A,B) ) );
}

int dist[1010][1010];

int main(){
  int n;
  scanf("%d",&n);
  vector<pair<Point,Point> > v;
  int x1, y1, x2, y2;
  for(int i = 0; i < n; i++){
    scanf("%d %d",&x1,&y1,&x2,&y2);
    v.push_back(make_pair(Point(x1,y1),Point(x2,y2)));
  }
  for(int i = 0; i < n - 1; i++){
    dist[i][i] = 0;
    for(int j = i+1; j < n; j++){
      dist[i][j] = dist_seg_seg(v[i].first,v[i].second,v[j].first,v[j].second);
      
    }
  }
  
}