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

map<double,set<string>> link(set<string> doc, vector<double> sim){
  int i=0;
  map<double,set<string>> ret;
  for(set<string>::iterator it=doc.begin();it!=doc.end();it++){
    string palavra = *it;
    double s = sim[i];
    i++;
    ret[s].insert(palavra);
  }
  return ret;
}

void imprimir_ranking(map<double,set<string>> doc){
  cout<<"     Ranking"<<endl;
  int p=1;
  double w;
  vector<double> wv;
  map<double,set<string>>::iterator it;
  for(it=doc.begin();it!=doc.end();it++){
    w=it->first;
    wv.push_back(w);
  }
  for(int i=(wv.size()-1);i>=0;i--){
    cout<<"Posicao "<<p<<": ";
    map<double,set<string>>::iterator ite;
    ite=doc.find(wv[i]);
    set<string>aux=ite->second;
    set<string>::iterator iter;
    for(iter=aux.begin();iter!=aux.end();iter++){
      cout<<*iter<<" ";
    }
    cout<<endl;
    p++;
  }
}

Ranking::Ranking(){}

void Ranking::inserir(set<string>docs,map<string,double>idf){
  for(set<string>::iterator it=docs.begin();it!=docs.end();it++){
    ifstream texto;
    texto.open(*it);
    string palavra;
    map<string,double>mapa;
    while(texto>>palavra){
      minusculo(palavra);
      map<string, double >::iterator ite;
    	ite=mapa.find(palavra);
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
    map<string,double>aux;
    map<string,double>mapa = documentos_[i];
    map<string,double>::iterator it;
    double norma=0;
    for (it = mapa.begin();it != mapa.end();it++){
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
    this->w_.push_back(aux);
  }
}

vector<double> Ranking::sim(Ranking indice){
  map<string,double>doc_c = this->w_.front();
  vector<map<string,double>>w_i = indice.w_;
  vector<double>ret;
  vector<map<string,double>>::iterator i;
  for (int i=0;i<w_i.size();i++){
    double s=0;
    map<string,double> doc_i = indice.w_[i];
    map<string,double>::iterator it;
    for(it = doc_c.begin();it != doc_c.end();it++){
      string palavra = it->first;
      double dw_c = it->second;
      map<string,double>::iterator ite;
      ite = doc_i.find(palavra);
      double dw_i = ite->second;
      s += dw_c * dw_i;
    }
    s = s /(this->norma_.front()*indice.norma_[i]);
    ret.push_back(s);
  }
  return ret;
}
