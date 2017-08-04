#include <stdio.h>
int main(){
	int n, id[50010], i, m, saiu[50010], pos[100010];
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&id[i]);
		pos[id[i]] = i;
	}
	scanf("%d",&m);
	for(i = 0; i < m; i++){
		scanf("%d",&saiu[i]);
		id[pos[saiu[i]]] = -1;
	}
	for(i = 0; i < n; i++){
		if(id[i] != -1){
			printf("%d ",id[i]);
		}
	}
	printf("\n");
	return 0;
}