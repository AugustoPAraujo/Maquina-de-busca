#ifndef FUNCOES_H
#define FUNCOES_H

#include <string>
using std::string;

//Transforma a palavra toda em minusculo e retira caracter especial
void minusculo (string& s);

class Dicionario{
    public:
		Dicionario();
	private:
		set< string > st;
		map< set< string >, int> id;
		map< string, map< set< string >, int> > mp;
};

#endif //FUNCOES_H
