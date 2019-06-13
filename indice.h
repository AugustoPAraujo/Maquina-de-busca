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


//Cria set<string> com a intersecção dos documentos que contem a c_consulta
//set<string> documentos(Dicionario indiceinvertido);

class Dicionario{
  public:
		Dicionario();
    Dicionario(string s);
    set<string> documentos();
    set<string> consulta(string palavra);
    double numdoc();
    map<string,double> idf();
	private:
    map<string,set<string>> iv;
    int ndoc_;
};

#endif //INDICE_H
