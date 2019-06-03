#include <iostream>
#include <fstream>
#include "funcoes.h"
#include <string>

using namespace std;

int main(){
  ifstream arquivos;
  arquivos.open("arquivos.txt");
  string titulo;
  while (arquivos>>titulo){
    ifstream palavras;
    string palavra;
    palavras.open(titulo);
    while (palavras>>palavra){
      minusculo(palavra);
      cout<<palavra<<endl;
    }
    cout<<endl;
  }
}
