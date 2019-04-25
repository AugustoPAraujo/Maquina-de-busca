#include "arquivo.h"
#include "vetor.h"
#include <iostream>
#include <fstream>
#include <string>

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
	for(int i=0;i<s.size();i++){
		if(!(s[i]>=97 && s[i]<= 122)){
			s[i]=0;
		}
	}
}

void ler_arquivos(Vetor& v1) {
	ifstream in1,in2,in3;
	in1.open("doc1.txt");
	
	if (in1.fail( )){
	cout << "A abertura do arquivo de entrada falhou.\n";
	exit(1);
	}
	string aux;
	while (in1 >> aux){
		minusculo(aux);
		palavra(aux);
		cout<<aux<<endl;
	}
	
	in1.close();
}
