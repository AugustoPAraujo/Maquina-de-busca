#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "ranking.h"
#include "indice.h"

#include "doctest.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <cmath>

using std::string;
using std::to_string;

class Teste {
public:
  static map<string,set<string> > ii(const Dicionario& d) {
  	 return d.iv;
  }
  static int numdoc(const Dicionario& d) {
    return  d.ndoc_;
  }
};

TEST_SUITE("Indice") {
  TEST_CASE("Dicionario()") {
    Dicionario d;
    map<string, set<string> >::iterator it;
    CHECK(Teste::numdoc(d) == 0);
	int i = 0;
    for(it = iv.begin(); it != iv.end();it++){
    	i++;
    }
    CHECK(i == 12)  
  }

  TEST_CASE("Dicionario(string)") {
    Dicionario d("a");
    map<string, set<string> >::iterator it;
    CHECK(Teste::numdoc(d) == 1);
    int i = 0;
    for(it = iv.begin(); it != iv.end();it++){
    	i++;
    }
    CHECK(i == 12)
  }

  TEST_CASE("minusculo(string)") {
    string st = "TESTE teste TeStE";
    st = minusculo(teste);
    for (int i = 0; i < st.size(); i++) {
       CHECK(st[i] >='a' && st[i] <='z')
    }
  }
  
} 
