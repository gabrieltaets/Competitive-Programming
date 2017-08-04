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

int main(){
	string str;
	cin >> str;
	if(str.size() % 2){
		str = "0" + str;
	}
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '7' || str[i] == '4') continue;
		if(str[i] > '7'){
			if(i == 0) {
				str = "00" + str;
				for(int j = 0; j < str.size(); j++){
					if(j < str.size()/2) str[j] = '4';
					else str[j] = '7';
				}
				break;
			}
			str[i-1]++;
			i--;
			continue;
		}
		if(str[i] > '4') str[i] = '7';
		else str[i] = '4';
		
		for(int j = i+1; j < str.size(); j++){
			str[j] = '4';
		}
		break;
	}
	int c4 = 0, c7 = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] != '7') str[i] = '4';
		if(str[i] == '4') c4++;
		else c7++;
	}
	if(c7 > c4){
		str = "44" + str;
		c4 += 2;
		for(int i = 0; i < str.size(); i++){
			if(c7 > c4 && str[i] == '7'){
				str[i] = '4';
				c4++;
				c7--;
			}
		}
	}
	else for(int i = str.size()-1; i >= 0; i--){
		if(c4 > c7 && str[i] == '4'){
			str[i] = '7';
			c4--;
			c7++;
		}
	}
	cout << str << endl;
	return 0;
}
