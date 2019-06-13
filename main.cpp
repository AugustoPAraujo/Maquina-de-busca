#include <iostream>
#include <fstream>
#include "indice.h"
#include "ranking.h"
#include <string>
#include <math.h>
#include <windows.h>

using namespace std;

int main(){
  system("cls");
  //Criar indice invertido
  Dicionario indiceinvertido;
  string palavra;
  int loop=1;

  while(loop!=0){
    //Criar documento consulta
    int c_consulta;
    c_consulta = criar_consulta();
    if(c_consulta==0)return 0;
    //Indice invertido da consulta
    Dicionario indice_consulta("a");
    //Retornar vetor set<string> com a intersecção dos documentos
    set<string> docs=indiceinvertido.documentos();
    cout<<"Os arquivos que contem a consulta sao: "<<endl;
    if(docs.size() > 0){
      for(set<string>::iterator it = docs.begin();it != docs.end();it++){
        cout << *it << endl;
      }
    }
    else{
      cout<<"Nao existe esse texto no banco de dados"<<endl;
      continue;
    }

    //Ranking

    //Calcular IDF
    map<string,double> idf_ = indiceinvertido.idf();
    //Calcular TF
    Ranking rank(docs,idf_);
    //Calcular W de todos os documentos e armazenar em um map<string,w>


    /*
    //SIM
    vector<double> sim_;
    double q = idf_;
    for (int i=0;i < w.size();i++){
    }
    */
  }
}
