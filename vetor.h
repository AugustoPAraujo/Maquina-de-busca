#ifndef VETOR_H
#define VETOR_H

#include <string>

using std::string;

struct No;

class Vetor {
 public:
  // Cria um vetor vazio.
  Vetor();

  // Cria um vetor unitário contendo s;
  Vetor(string s);

  // Testa se o vetor é vazio.
  bool vazio() const;

  // Retorna a cardinalidade do vetor.
  int cardinalidade() const;

  // Testa se s pertence ao vetor.
  bool pertence(string s) const;

  // Retorna um elemento qualquer do vetor.
  // RECONDIÇÃO: o vetor tem pelo menos um elemento.
  string elemento() const;
  
    // Retorna quantas ocorrências de s estão no vetor.
  int ocorrencias(string s) const;
  
  //Insere o nome do doc do vetor
  void documento(string s) ;

  // Insere s no vetor, se lá ele não está.
  void inserir(string s);
  /*
  Vetor uniao(const Vetor& x);

 /* // Remove s do vetor, se lá ele está.
  void remover(string s);

  // Faz com que *this tenha os mesmos elementos de x.
  void operator=(const Vetor& x);

  // Desaloca toda a memória alocada para o conjunto.
  ~Vetor();*/
  
 private:
	No* fim_;  // Ponteiro para o sentinela do vetor;
    int cardinalidade_;  // Número de elementos no vetor;
    string documento_;
};

#endif  // VETOR_H

