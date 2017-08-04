#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define EPS 1e-5
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
  int s, x1, x2, t1, t2, p, d;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  int ivan = t2*abs(x2-x1); // tempo para Ivan chegar a pé até x2
  int tram = p;             // tram representa a posição do bonde
  bool onTram = (x1 == p);  // se o bonde estiver no mesmo lugar de Ivan, Ivan entra no bonde
  int time = 0;
  // agora, calculamos o tempo para o bonde chegar até o destino
  // no entanto, não basta que o bonde chegue no destino,
  // é também necessário que Ivan esteja no bonde, por isso a verificação do onTram
  while(tram != x2 || !onTram){
    tram += d;  // d representa o sentido em que o bonde anda, uma unidade por cada t1 segundos
    time += t1;
    if(tram < 0) {  // se o bonde chegar no limite, ele vira
      tram = d = 1;
    }
    if(tram > s){   // se o bonde chegar no limite, ele vira
      tram = s-1;
      d = -1;
    }
    if(tram == x1) onTram = true; // se o bonde passar por Ivan, Ivan entra no bonde
  }
  // note que para calcular o tempo do bonde, pode-se considerar
  // que Ivan fica parado esperando o bonde, pois o tempo do bonde
  // chegar no destino vai ser o mesmo, independente de onde Ivan
  // estava quando entrou nele.
  // agora só precisamos verificar se o tempo do bonde pegar Ivan e
  // chegar no destino é maior ou menor queo tempo de Ivan ir a pé:
  cout << min(time,ivan) << endl; 
  return 0;
}
