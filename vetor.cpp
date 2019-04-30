#include <iostream>
#include <stdlib.h>
#include "vetor.h"
#define n_doc 3

using namespace std;
using std::string;

struct No {
  	string palavra;
  	int ocorrencias;
  	No* esq;
  	No* dir;
};

Vetor::Vetor(){
	cardinalidade_ = 0;
	fim_=new No;
	fim_->dir =fim_;
	fim_->esq =fim_;
}

Vetor::Vetor(string s) : Vetor() {
	inserir(s);
}

bool Vetor::vazio() const {
  return (cardinalidade_ == 0);
}

int Vetor::cardinalidade() const {
  return cardinalidade_;
}

bool Vetor::pertence(string s) const {
	No* aux = fim_->dir ;
	for(int i=0;i<cardinalidade_;i++){
		string a;
		a = aux->palavra;
		if(a==s) return true;
		aux = aux->dir;
	}
	return false;
}

string Vetor::elemento() const {
	No* aux = fim_->dir;
	return aux->palavra;
}

int Vetor::ocorrencias(string s) const {
		if (pertence(s)){
		No* aux = fim_->dir;
		string a;
		a = aux->palavra;
		while(a!=s){
			aux = aux->dir;
			a = aux->palavra;
		}
		return aux->ocorrencias;
	}
	else return 0;
}


void Vetor::documento(string s) {
	documento_=s;
}

void Vetor::inserir(string s) {
	if(this->pertence(s) ){
		No* aux = fim_->dir;
		string a = aux->palavra;
		while (a!=s){
			aux = aux->dir;
			a = aux->palavra;
		} 	
		aux->ocorrencias++;
	}
	else{	
		No* z = new No;
		z->palavra = s;
		No* ultimo = fim_->esq;
		z->esq = ultimo;
		z->dir = fim_;
		ultimo->dir = z;
		fim_->esq = z;
		z->ocorrencias = 1;
		this->cardinalidade_++;
	}
}
/*
Vetor Vetor::uniao(const Vetor& x){
	Vetor une(*this);
	No* aux = x.fim_->dir; 
	for(int i = 0; i < x.cardinalidade() ; i++){
		No* novo = new No;
		No* ultimo = une.fim_->esq;
		
		ultimo->dir = novo;
		novo->esq = ultimo;
		novo->dir = une.fim_;
		une.fim_->esq = novo;
		
		novo->valor = aux->valor;
		une.cardinalidade_++;
		aux = aux->dir;
	}
	return une;
}
*/
/*void Vetor::remover(string s) {
	for(int i=0; i<cardinalidade_;i++){
		if(palavra_[i] == s){
			palavra_[i] = palavra_[cardinalidade_ - 1];
			ocorrencias_[i] = ocorrencias_[cardinalidade_ - 1];
			cardinalidade_--;
		}
	}
}*/

/*void Vetor::operator=(const Vetor& x) {
	while (this->cardinalidade_ == 0){
		this->remover(this->elemento());
	}
	redimensionar(x.capacidade_);
	for (int i = 0; i < x.cardinalidade_;i++){
		this->inserir(x.palavra_[i]);
		this->ocorrencias_[i] = x.ocorrencias_[i];
	}
}*/
/*
Vetor::~Vetor(){
	delete [] palavra_;
	delete [] ocorrencias_;
}*/

