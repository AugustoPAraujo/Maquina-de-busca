#include "indice.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
using std::string;
using namespace std;

void minusculo (string& s){
  for(int i=0; i<s.size();i++){
    if(s[i]>='A' && s[i]<='Z'){
      s[i]+=32;
    }
    else if(!(s[i]>='a' && s[i]<='z')){
      s.erase(i);
    }
  }
}

int criar_consulta(){
  ofstream consulta;
  consulta.open("consulta.txt");
  string palavra;
  cout<<"Digite o texto que deseja buscar (digite 'pause' para terminar ou 'STOP' para fechar o programa): ";
  while(palavra != "pause"){
    cin>>palavra;
    if(palavra == "pause" || palavra =="PAUSE"){
      break;
    }
    if(palavra == "STOP"){
      return 0;
    }
    consulta<<palavra<<" ";
  }
  consulta.close();
  return 1;
}

Dicionario::Dicionario(){
  ndoc_ = 0;
  ifstream arquivos;
  arquivos.open("arquivos.txt");
  string titulo;
  while (arquivos>>titulo){
    ndoc_++;
    ifstream palavras;
    string palavra;
    palavras.open(titulo);
    while (palavras>>palavra){
      minusculo(palavra);
      this->iv[palavra].insert(titulo);
    }
  }
}

Dicionario::Dicionario(string s){
  ndoc_ = 1;
  ifstream texto;
  texto.open("consulta.txt");
  string palavra;
  while (texto>>palavra){
    minusculo(palavra);
    this->iv[palavra].insert("consulta.txt");
  }
  texto.close();
}

set<string> Dicionario::documentos(){
  ifstream p;
  p.open("consulta.txt");
  int a=0;
  set<string> docs;
  string palavra;
  while(p>>palavra){
    minusculo(palavra);
    if(a==0){
      docs = consulta(palavra);
      a++;
      continue;
    }
    set<string> aux = consulta(palavra);
    for(set<string>::iterator it = docs.begin();it != docs.end();it++){
      if(aux.count(*it)==0){
        docs.erase(*it);
      }
    }
  }
  return docs;
}

set<string> Dicionario::consulta(string palavra) {
	map<string, set<string> >::iterator it;
	it = iv.find(palavra);
	if(it != iv.end()) {
		return it->second;
	}
	else {
		set<string> bla;
		return bla;
	}
}

double Dicionario::numdoc(){
  return ndoc_;
}

map<string,double> Dicionario::idf(){
  map<string,double> ret;
  double n= this->numdoc();
  map<string, set<string> >::iterator it;
  for (it = iv.begin(); it != iv.end();it++){
    string s=it->first;
    set<string> aux = it->second;
    double nt = aux.size();
    double idf_=log(n/nt);
    ret[s]=idf_;
  }
  return ret;
}
