#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "vetor.h"
//#include "arquivo.h"
using namespace std;
using std::string;

void minusculo(string& x){
	for(int i=0;i<x.size();i++){
		if(x[i]>=65 && x[i]<=90){
			x[i]=x[i]+32;
		}	
	}	
}

void palavra(string& s){
	string aux;
	for(int i=0;i<s.size();i++){
		if(!(s[i]>=97 && s[i]<= 122)){
			s.erase(i);
		}
	}
}

void ler_arquivos( Vetor& vt, Vetor& v1, Vetor& v2, Vetor& v3) {
	ifstream in1,in2,in3;
	in1.open("doc1.txt");
	in2.open("doc2.txt");
	in3.open("doc3.txt");
	
	if (in1.fail( )){
	cout << "A abertura do arquivo doc1.txt de entrada falhou.\n";
	exit(1);
	}
	string aux;
	while (in1 >> aux){
		minusculo(aux);
		palavra(aux);
		v1.inserir(aux,"doc1");
		vt.inserir(aux,"doc1");
	}	
	in1.close();
	
	if (in2.fail( )){
	cout << "A abertura do arquivo doc2.txt de entrada falhou.\n";
	exit(1);
	}
	while (in2 >> aux){
		minusculo(aux);
		palavra(aux);
		v2.inserir(aux,"doc2");
		vt.inserir(aux,"doc2");
	}	
	in2.close();
	
	if (in3.fail( )){
	cout << "A abertura do arquivo doc3.txt de entrada falhou.\n";
	exit(1);
	}
	while (in3 >> aux){
		minusculo(aux);
		palavra(aux);
		v3.inserir(aux,"doc3");
		vt.inserir(aux,"doc3");
	}	
	in3.close();
}

int main(){
	system("cls");
	int tf1,tf2,tf3;
	Vetor v1,v2,v3,vt;
	ler_arquivos(vt,v1,v2,v3);
	vt.documento("casa");
	
}


