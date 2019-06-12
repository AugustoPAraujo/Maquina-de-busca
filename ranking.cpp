#include "ranking.h"
#include "indice.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using std::string;
using namespace std;

Ranking::Ranking(set<string> docs){
  for(set<string>::iterator it = docs.begin();it != docs.end();it++){
    ifstream texto;
    texto.open(*it);
    string palavra;
    map<string,int> mapa;
    while(texto>>palavra){
      minusculo(palavra);
      map<string, double >::iterator i;
    	i = mapa.find(palavra);
    	if(i != mapa.end()) {
    		i->second;
    	}
      else{
        mapa[palavra]=1;
      }
    }
    this->documentos_.push_back(mapa);
  }
}
