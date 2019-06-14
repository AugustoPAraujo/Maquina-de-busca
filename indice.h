#ifndef INDICE_H
#define INDICE_H

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
using std::string;

//Transforma a palavra toda em minusculo e retira caracter especial
void minusculo (string& s);
//Cria um arquivo txt com a consulta
int criar_consulta();

class Dicionario{
  public:
    //Construtor indice invertido
		Dicionario();
    //COnstrutor consulta
    Dicionario(string s);

    set<string> documentos();
    //Retorna os documentos em que tem a palavra
    set<string> consulta(string palavra);
    //Retorna quantidade de documentos do indice
    double numdoc();
    //Retorna IDF
    map<string,double> idf();
	private:
    map<string,set<string>> iv;
    int ndoc_;
};

#endif //INDICE_H
