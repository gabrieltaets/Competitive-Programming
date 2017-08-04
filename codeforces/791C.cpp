#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, k;
bool note[60];
int val[60];
string name[60];

void generate_names(){
	map<int, string> mapa;
	set<string> have;
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		int l = rand()%9+1;
		string str(l,' ');
		do {
			for(int j = 0; j < str.size(); j++){
				char x = rand()%26 + 'a';
				str[j] = x;
			}
			str[0] = toupper(str[0]);
		} while(!have.insert(str).S);
		mapa[i] = str;
	}
	for(int i = 0; i < n; i++){
		name[i] = mapa[i];
	}
}

set<int> diff[60];

int main(){
	cin >> n >> k;
	memset(val, 0, sizeof val);
	bool fuck = true;
	int cont = 1;
	generate_names();
	for(int i = 0; i < n - k + 1; i++){
		string x;
		cin >> x;
		if(x == "NO"){
			name[i+k-1] = name[i];
		}
	}

	for(int i = 0; i < n; i++){
		cout << name[i] << " ";
	}
	cout << endl;
	
	return 0;
}
