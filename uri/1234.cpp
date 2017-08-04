#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define UPPER 1
#define LOWER 0
int main(){
	char input[51];
	int last, x;
	while(scanf("%[^\n]",input)!=EOF){
		getchar();
		x = 0;
		while(!isalpha(input[x]))
			x++;
		input[x] = toupper(input[x]);
		last = UPPER;
		for(++x; x < strlen(input); x++){
			if(isalpha(input[x])){
				if(last){
					input[x] = tolower(input[x]);
					last = LOWER;
				}
				else {
					input[x] = toupper(input[x]);
					last = UPPER;
				}
			}
		}
		printf("%s\n",input);
	}
	return(0);
}
