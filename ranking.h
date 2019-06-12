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
    Ranking(set<string> docs);
	private:
    vector< map<string,double> > documentos_;
};







#endif //RANKING_H
