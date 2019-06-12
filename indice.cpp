#include "indice.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
using std::string;
using namespace std;

// Transforma as palavras em minusculo e retira os caracteres especiais
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

//Cria um arquivo txt com a consulta
int criar_consulta(){
  ofstream consulta;
  consulta.open("consulta.txt");
  string palavra;
  cout<<"Digite o texto que deseja buscar (digite 'pause' para terminar): ";

  while(palavra != "pause"){
    cin>>palavra;
    if(palavra == "pause"){
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

/*
//Cria set<string> com a intersecção dos documentos que contem a c_consulta
set<string> documentos(Dicionario indiceinvertido){
  ifstream p;
  p.open("consulta.txt");
  int a=0;
  set<string> docs;
  while(p>>palavra){
    cout<<palavra<<" ";
    if(a==0){
      docs = indiceinvertido.consulta(palavra);
      a++;
      if(docs.size() > 0){
        for(set<string>::iterator it = docs.begin();it != docs.end();it++){
          cout << *it << endl;
        }
        cout<<endl;
      }
      continue;
    }
    set<string> aux = indiceinvertido.consulta(palavra);
    for(set<string>::iterator it = docs.begin();it != docs.end();it++){
      if(aux.count(*it)==0){
        docs.erase(*it);
      }
    }
    if(docs.size() > 0){
      for(set<string>::iterator it = docs.begin();it != docs.end();it++){
        cout << *it << endl;
      }
      cout<<endl;
    }
  }
}
*/

//Define quantas vezes a palavra esta nos documentos "TF"
vector<int> tf(set<string> doc, string palavra){
  vector<int> r;
  for(set<string>::iterator i = doc.begin(); i != doc.end(); i++){
    ifstream texto;
    texto.open(*i);
    string p;
    int aux=0;
    while (texto>>p){
      minusculo(p);
      if (p==palavra){
        aux++;
      }
    }
    r.push_back(aux);
  }
  return r;
}

//   mp   palavra     id         st      tf                //
//   |     |            |         |      |                 //
//	map<string,       map< set<string>, int >     -> mapa  //
//       |                      |                          //
//     palavra             doc(chave)                      //
// map< string, map< string , int> > indinv
// indinv[string][string]=int;
//

/*
Dicionario::Dicionario(string doc, string palavra){
	if(mp.count(palavra) == 0){ //se não houver a palavra no mapa
		st.insert(doc);
		set<string>::iterator i=st.begin();
		id[st[*i]] = 1;
		mp[palavra] = id;
	}else{
		if(!st.count(doc)){
			st.insert(doc);
			set<string>::iterator i=st.begin();
			id[st[*i]] = 1;
		}else{
			for(set<string>::iterator i=st.begin(); i != st.end(); i++){
				if(*i == doc){
					id[st[*i]] += 1;
				}
			}
		}
		mp[palavra] = id;
	}
}
*/

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
