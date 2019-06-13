#ifndef RANKING_H
#define RANKING_H

#include <map>
#include <set>
#include <string>
#include <vector>
using std::string;
using namespace std;
class Ranking{
  public:
    //Cria documentos com o idf de cada palavra
    Ranking(set<string> docs,map<string,double> idf);
    //Cria documentos com o w de cada palavra
    void w(map<string,double> idf);
	private:
    vector< map<string,double> > documentos_;
    vector< map<string,double> > w_;
    vector<double> norma_;

};


#endif //RANKING_H
