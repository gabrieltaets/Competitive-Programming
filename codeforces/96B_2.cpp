#include <bits/stdc++.h>


using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

void pr(int l){
    l/=2;
    for(int i=0;i<l;i++)
        printf("4");
    for(int i=0;i<l;i++)
        printf("7");
    printf("\n");
    exit(0);
}


int main(){
    string str;
    cin>>str;
    if(str.size()%2){
        pr(str.size()+1);
    }
    int conts=0,contq=0;
    int i;

    for(i=0;i<str.size();i++){

		puts("here\n");
		
        if(conts>str.size()/2){
            pr(str.size()+2);
        }

        if(str[i]<'4'){
            str[i]='4';
            for(;i<str.size();i++)
                str[i]='4';
        }
        else if(str[i]=='4'){
			
            if(contq<=str.size()/2)
                contq++;
            else{
                str[i]='7';
                i++;
                for(;i<str.size();i++)
                    str[i]='4';
            }
        }
        else if(str[i]<'7'){
            str[i]='7';
            i++;
            for(;i<str.size();i++)
                str[i]='4';
        }
        else if(str[i]=='7'){
            if(conts<=str.size()/2)
                conts++;
            else{
                pr(str.size()+2);
            }
        }
        else{
            if(i==0)
                pr(str.size()+2);
			else {
                str[i+1]++;
                i=0;
                conts=0;
                contq=0;
            }
        }
    }
	int n7=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='7')n7++;
    }
    i=str.size()-1;
    while(n7<str.size()/2){
        if(str[i]!='7'){
            str[i]='7';
            n7++;
        }
        i--;
    }

    cout<<str<<endl;

return 0;
}