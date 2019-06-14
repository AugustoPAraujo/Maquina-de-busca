#ifndef RANKING_H
#define RANKING_H

#include "indice.h"
#include <map>
#include <set>
#include <string>
#include <vector>
using std::string;
using namespace std;

//Retorna map com o valor da similaridade e os documentos correspondentes
map<double,set<string>> link(set<string> doc, vector<double> sim);
//Imprime o ranking
void imprimir_ranking(map<double,set<string>> doc);
class Ranking{
  public:
    //Construtor ranking
    Ranking();
    //Cria documentos_ com o idf de cada palavra
    void inserir(set<string>docs,map<string,double>idf);
    //Cria w_ com o w de cada palavra
    void w(map<string,double> idf);
    //Retorna a similaridade de cada documento com this
    vector<double> sim(Ranking indice);
	private:
    vector<map<string,double>> documentos_;
    vector<map<string,double>> w_;
    vector<double> norma_;
};
#endif //RANKING_H
