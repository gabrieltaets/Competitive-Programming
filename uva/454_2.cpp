#include <bits/stdc++.h>

using namespace std;


int main(){
    int N;
    string word;
    vector < pair <string, string> > palavras;
    vector <string> saida;
    cin>>N;
    getline(cin,word);
    getline(cin,word);
    while(N){
        N--;
        int cont = 0;
        while(1){
            getline(cin,word);
            if(word.empty()) break;
            string aux = word;
            sort(aux.begin(),aux.end());
            for(int i=0;i<aux.size();i++){
                if(aux[i]==' '){
                    aux.erase(i,1);
                    i--;
                }
            }
            if(!palavras.empty()){
                for(int i=0;i<palavras.size();i++){
                    if(palavras[i].second == aux){
                        string auxiliar;
                        if(palavras[i].first < word){
                            auxiliar = palavras[i].first+" = "+word;
                        }else auxiliar = word+" = "+palavras[i].first;
                        saida.push_back(auxiliar);
                    }
                }
            }
            palavras.push_back(make_pair(word,aux));
            cont++;
        }
        sort(saida.begin(),saida.end());
        for(int i=0;i<saida.size();i++) cout<<saida[i]<<endl;

        saida.clear();
        palavras.clear();

        if(N) cout<<endl;

    }


    return 0;
}


