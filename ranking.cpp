#include "ranking.h"
#include "indice.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
using std::string;
using namespace std;

Ranking::Ranking(set<string> docs,map<string,double> idf){
  for(set<string>::iterator it = docs.begin();it != docs.end();it++){
    ifstream texto;
    texto.open(*it);
    string palavra;
    map<string,double> mapa;
    while(texto>>palavra){
      minusculo(palavra);
      map<string, double >::iterator ite;
    	ite = mapa.find(palavra);
    	if(ite != mapa.end()) {
    		ite->second++;
    	}
      else{
        mapa[palavra]=1;
      }
    }
    this->documentos_.push_back(mapa);
  }
  w(idf);
}

void Ranking::w(map<string,double> idf){
  for(int i=0;i<documentos_.size();i++){
    map<string,double> mapa = documentos_[i];
    map<string, double >::iterator it;
    double norma=0;
    for (it = mapa.begin(); it != mapa.end();it++){
      map<string,double> aux;
      string palavra = it->first;
      double tf=it->second;
      map<string,double>::iterator iter;
      iter = idf.find(palavra);
      double idf__=iter->second;
      double w = tf*idf__;
      aux[palavra]=w;
      norma += pow(w,2);
    }
    norma= sqrt(norma);
    this->norma_.push_back(norma);
  }
}
