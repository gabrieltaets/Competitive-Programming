#include <bits/stdc++.h> 
using namespace std;
 
int main(){
 
    int qt_ap,qt_switch,lim,seq, swt_act,pw_max,pw_act,flag;
    bool status[30];
    int pot[30];
    seq = 1;
 
    while(scanf("%d %d %d",&qt_ap,&qt_switch,&lim) != EOF && qt_ap){
 
        memset(status, 0, sizeof status);
        pw_act = 0;
        flag = 1;
        pw_max = 0;
 
        for(int i = 1; i <= qt_ap; i++){
            scanf("%d",&pot[i]);
        }
        for(int i = 1; i <= qt_switch; i++){
            scanf("%d",&swt_act);
            if(status[swt_act])
                pw_act -=pot[swt_act];
            else{
                pw_act+=pot[swt_act];
 
                if(pw_act > lim){
                    flag = 0;
                }
                else if(pw_act > pw_max)
                    pw_max = pw_act;
            }
            status[swt_act] = !status[swt_act];
        }
 
        printf("Sequence %d\n",seq);
        printf("Fuse was %s\n", (flag ? "not blown.":"blown."));
        if(flag)
            printf("Maximal power consumption was %d amperes.\n",pw_max);
        printf("\n");
        seq++;
    }

    return 0;
}