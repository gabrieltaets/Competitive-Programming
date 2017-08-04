#include <bits/stdc++.h>
using namespace std;

int main() {
	double ci = clock();
	long long v[110];
	vector<long long> a1;
	vector<long long> a2;

	long long n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%lld", &v[i]);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				a1.push_back(v[i] * v[j] + v[k]);

	for (int i = 0; i < n; ++i)
		if (v[i] != 0)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				a2.push_back(v[i] * (v[j] + v[k]));

	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	int l = 0, r = 0;
	long long ans = 0;
	long long n3 = n * n * n;
	while (l < a1.size() && r < a2.size()) {
		//printf("a1[%d] = %lld    a2[%d] = %lld\n", l, a1[l], r, a2[r]);
		if (a1[l] == a2[r]) {
			long long val = a1[l];
			long long t1 = 1, t2 = 1;
			l++; r++;

			while (l < a1.size() && a1[l] == val) {
				t1++;
				l++;
			}

			while (r < a2.size() && a2[r] == val) {
				t2++;
				r++;
			}
			ans += t1 * t2;
			//cout << ans << endl;
		}
		else if (a1[l] > a2[r]) r++;
		else l++;
	}
	cout << ans << endl;
	double cf = (clock()-ci)/CLOCKS_PER_SEC;
	printf("%lfs\n",cf);
}