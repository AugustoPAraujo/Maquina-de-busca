#include <iostream>
#include <fstream>
#include "funcoes.h"
#include <string>
#include <math.h>
#include <windows.h>

using namespace std;

int main(){
  system("cls");
  Dicionario indiceinvertido;
  string palavra;
  int loop=1;

  while(loop!=0){
    double n=0,nt=0;
    cout<<"Digite a palavra que deseja buscar: ";
    cin>>palavra;
    if(palavra == "fecharprog"){
      break;
    }
    set<string> docs = indiceinvertido.consulta(palavra);
    if(docs.size() > 0){
      for(set<string>::iterator it = docs.begin();it != docs.end();it++){
        nt++;
        cout << *it << endl;
      }
    }
    else{
      cout<<"Nao existe essa palavra no banco de dados"<<endl;
      continue;
    }

    //TF
    vector<int> tf_ = tf(docs,palavra);
    cout<<"TF: ";
    for(vector<int>::iterator it = tf_.begin();it != tf_.end();it++){
      cout << *it << endl;
    }

    //IDF;
    double idf_=0;
    n = indiceinvertido.numdoc();
    cout<<n<<"  "<<nt<<endl;
    idf_ = log(n/nt);
    cout<<"idf= "<<idf_<<endl;
    // w
    vector<double> w;
    for (int i=0;i<tf_.size();i++){
      double aux = tf_[i]*idf_;
      w.push_back(aux);
      cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }
  }
}
