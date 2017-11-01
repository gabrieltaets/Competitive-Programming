/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void show(ull x){
	int i;
	for(i = 63; i >= 0 && (x & (1LL << i)) == 0; i--);
	for(; i >= 0; i--){
		putchar('0'+(bool)(x&(1LL<<i)));
	}
	putchar('\n');
}

int main(){
	ull l, r;
	set<ull> s;
	cin >> l >> r;
	for(int i = 1; i <= 63; i++){
		ull aux = (1LL<<i)-1;
		if(aux >= l && aux <= r) {
			//show(aux);
			s.insert(aux);
		}
		for(int j = 1; j+i <= 64; j++){
			for(int k = 0; k < 64/(i+j); k++){
				ull num = aux;
				int bu = i;
				for(int z = 0; z <= k; z++){
					num <<= j;
					bu += j;
					if(num >= l && num <= r) {
						if(s.insert(num).S)
							;//show(num);
					}
					if(bu + i > 64) break;
					num <<= i;
					num |= aux;
					if(num >= l && num <= r) {
						if(s.insert(num).S)
							;//show(num);
					}
					bu += i;
				}
			}
		}
	}
	cout << s.size() << endl;
	return 0;
}
