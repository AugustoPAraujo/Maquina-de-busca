#include "funcoes.h"
using std::string;
void minusculo (string& s){
  for(int i=0; i<s.size();i++){
    if(s[i]>='A' && s[i]<='Z'){
      s[i]+=32;
    }
    else if(!(s[i]>='a' && s[i]<='z')){
      s.erase(i);
    }
  }
}
