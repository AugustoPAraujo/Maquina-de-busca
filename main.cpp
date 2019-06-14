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
    //Retornar vetor set<string> com o documento consulta
    set<string> con=indice_consulta.documentos();

    if(docs.size() == 0){
      cout<<"Nao existe esse texto no banco de dados"<<endl;
      continue;
    }
    //Ranking
    //Calcular IDF
    map<string,double> idf_ = indiceinvertido.idf();
    //Calcular W de todos os documentos e armazenar em um map<string,w>
    Ranking ranking_d;
    ranking_d.inserir(docs,idf_);
    //Calcular W da consulta e armazenar em um map<string,w>
    Ranking ranking_c;
    ranking_c.inserir(con,idf_);
    //Retornar vetor similaridade
    vector<double> sim = ranking_c.sim(ranking_d);
    //Mapa com nome dos documentos e similaridade
    map<double,set<string>> link_ = link(docs,sim);
    //imprimir o ranking
    cout<<endl<<endl;
    imprimir_ranking(link_);
    cout<<endl<<endl;

    cout<<"Digite 1 para realizar outra busca e 0 para fechar o programa ";
    cin>>loop;
    system("cls");
  }
}
