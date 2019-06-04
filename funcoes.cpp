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

//   mp   palavra     id         st      tf                //
//   |     |            |         |      |                 //
//	map<string,       map< set<string>, int >     -> mapa  //
//       |                      |                          //
//     palavra             doc(chave)                      //
                                                        
Dicionario::Dicionario(string doc, string palavra){
	if(mp.count(palavra) == 0){ //se não houver a palavra no mapa
		st.insert(doc);
		set<string>::iterator i=st.begin();
		id[st[*i]] = 1;
		mp[palavra] = id;
	}else{
		if(!st.count(doc)){
			st.insert(doc);
			set<string>::iterator i=st.begin();
			id[st[*i]] = 1;
		}else{
			for(set<string>::iterator i=st.begin(); i != st.end(); i++){
				if(*i == doc){
					id[st[*i]] += 1;
				}
			}
		}
		mp[palavra] = id;
	}
}
