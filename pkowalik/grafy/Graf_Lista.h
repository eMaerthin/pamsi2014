#include<iostream>
#include"Graf.h"
#include"Elem.h"
#include<list>
#include<map>
using namespace std;

template<class typ>
class Graf_Lista{
	map<unsigned int, list<Elem<typ>>> GL;
	unsigned int w_start;

public:
	Graf_Lista();
	void clear();
	unsigned int size();
	map<unsigned int, list<Elem<typ>>> &mapa();
	void pushpol(Elem<typ> x);
//	list<Elem<typ>>::iterator begin_listy();
//	list<Elem<typ>>::iterator end_listy();
	void przepisz(ListaElem<typ> X);
	void Utworz(unsigned int l);
	list<Elem<typ>> &operator[](unsigned int x);
	void Wczytaj(string file);
	void Zapisz(string file);
	void Start(unsigned int s);
	unsigned int Start();
	void Kruskal();
	void Prima();
	void pushpol(Element<typ> x);
	void convert(Graf<typ> GRAF);
};

template<class typ>
Graf_Lista<typ>::Graf_Lista(){
	GL.clear();
	w_start=0;
}

template<class typ>
void Graf_Lista<typ>::clear(){
	GL.clear();
}

template<class typ>
unsigned int Graf_Lista<typ>::size(){
	return GL.size();
}

template<class typ>
unsigned int Graf_Lista<typ>::Start(){
	return w_start;
}

template<class typ>
map<unsigned int, list<Elem<typ>>> &Graf_Lista<typ>::mapa(){
	return GL;
}

template<class typ>
void Graf_Lista<typ>::przepisz(ListaElem<typ> X){
	unsigned int i;
	Elem<typ> elem;
	list<Elem<typ>> Z;
	 map<unsigned int, list<Elem<typ>>>::iterator it;
	 Z.clear();
	 GL.clear();

	for(i=0; i<X.rozpientosc()+1; i++){
		GL[i]=Z;
	}

	for(i=0; i<X.size(); i++){
		it=GL.find(X[i].w1());
		elem.w2=X[i].w2();
		elem.waga=X[i].waga();
		it->second.push_back(elem);
	}
}

template<class typ>
void Graf_Lista<typ>::Utworz(unsigned int l){
	unsigned int i;
	list<Elem<typ>> Z;
	 Z.clear();
	 GL.clear();
	for(i=0; i<l; i++){
		GL[i]=Z;
	}
}

template<class typ>
list<Elem<typ>> &Graf_Lista<typ>::operator[](unsigned int x){
	return GL[x];
}

template<class typ>
void Graf_Lista<typ>::Wczytaj(string file){
	ifstream plik;
	int x1, x2;
	typ y;
	Element<typ> S;
	ListaElem<typ> lista;
	
	plik.open(file);
	if(plik.is_open()){
		while(!plik.eof()){
			plik>>x1;
			plik>>x2;
			plik>>y;
			S.Utworz(x1,x2,y);
			lista.push(S);
			S.Utworz(x2,x1,y);
			lista.push(S);
		}
		przepisz(lista);
	}
}

template<class typ>
void Graf_Lista<typ>::pushpol(Element<typ> Min){
	Elem<typ> x;
	x.w2=Min.w2();
	x.waga=Min.waga();
	GL[Min.w1()].push_back(x);
}

template<class typ>
void Graf_Lista<typ>::Zapisz(string file){
	ofstream plik;
	map<unsigned int, list<Elem<typ>>>::iterator it;
	list<Elem<typ>>::iterator jt;
	plik.open(file);
	if(plik.is_open()){
		for(it=GL.begin(); it!=GL.end(); it++){
			for(jt=it->second.begin(); jt!=it->second.end(); jt++){
				if(!it->second.empty()){
					plik<< it->first <<"     "<< jt->w2 <<"     "<< jt->waga <<endl;
				}
			}
		}
	}
	plik.close();
}

template<class typ>
void Graf_Lista<typ>::Kruskal(){
	vector<unsigned int> kolory;
	map<unsigned int, list<Elem<typ>>>::iterator it;
	list<Elem<typ>>::iterator jt;
	Element<typ> El;
	ListaElem<typ> Lista_wg_wagi, Lista_wlasciwa;
	unsigned int i, z, y, k, czy_juz;
	unsigned int x=0;
	bool koniec=false, juz=false;

	for(it=GL.begin(); it!=GL.end(); it++){
		for(jt=it->second.begin(); jt!=it->second.end(); jt++){
			if(!it->second.empty()){
				El.Utworz(it->first, jt->w2, jt->waga);
				Lista_wg_wagi.push_waga(El);
			}
		}
	}
	for(i=0; i<GL.size(); i++){
		kolory.push_back(i);
	}
	while(!koniec && x<Lista_wg_wagi.size()){
		if(kolory[Lista_wg_wagi[x].w1()]!=kolory[Lista_wg_wagi[x].w2()]){
			z=kolory[Lista_wg_wagi[x].w2()];
			Lista_wlasciwa.push(Lista_wg_wagi[x]);
			for(y=0; y<kolory.size(); y++){
				if(kolory[y]==z){
					kolory[y]=kolory[Lista_wg_wagi[x].w1()];
				}
			}
		}
		czy_juz=kolory[0];
		juz=true;
		for(k=0; k<kolory.size(); k++){
			if(kolory[k]!=czy_juz){
				juz=false;
			}
		}
		if(juz){
			koniec=true;
		}
		x++;
	}
	clear();
	przepisz(Lista_wlasciwa);
}

template<class typ>
void Graf_Lista<typ>::Prima(){
	vector<unsigned int> Zebrane;
	ListaElem<typ> Lista_wlasciwa;
	Element<typ> Min;
	bool koniec, brak_spojnosci, zapetlenie;
	unsigned int wiezcholek, i;
	list<Elem<typ>>::iterator it, jt;
	int x=0;
	koniec=false;
	brak_spojnosci=false;
	Zebrane.push_back(0);
	while(!koniec){
		zapetlenie=false;
		Min.Utworz(0, 0, 0);
		for(wiezcholek=0; wiezcholek<Zebrane.size(); wiezcholek++){
			for(it=GL.find(Zebrane[wiezcholek])->second.begin(); it!=GL.find(Zebrane[wiezcholek])->second.end(); it++){
				cout<<Zebrane[wiezcholek]<<' '<<it->w2<<' '<<it->waga<<endl;
				if((it->waga<Min.waga() && it->waga!=-1) || (Min.waga()==0 && it->waga!=-1)){
					Min.Utworz(Zebrane[wiezcholek], it->w2, it->waga);
					jt=it;
				}
			}
		}
		if(Min.waga()==0){
			cout<<"brak spojnosci"<<endl;
			koniec=true;
		} else {
			for(i=0; i<Zebrane.size(); i++){
				if(Zebrane[i]==Min.w2()){
					jt->waga=-1;
					zapetlenie=true;
				}
			}
			if(!zapetlenie){
				Zebrane.push_back(Min.w2());
				Lista_wlasciwa.push(Min);
				jt->waga=-1;
				system("Pause");
			}
			if(Lista_wlasciwa.size()==GL.size()-1){
				koniec=true;
			}
		}
		
	}
	clear();
	przepisz(Lista_wlasciwa);

}
/*
template<class typ>
void Graf_Lista<typ>::Djikstra(){


	
}*/

template<class typ>
void Graf_Lista<typ>::Start(unsigned int s){
	if(s<GL.size()){
		w_start=s;
	}
	else{
		w_start=0;
	}
}

template<class typ>
void Graf_Lista<typ>::convert(Graf<typ> GRAF){
	unsigned int i, j;
	Elem<typ> U;

	clear();
	w_start=GRAF.Start();
	for(i=0; i<GRAF.size(); i++){
//		cout<<"Przepisuje Kolumne: "<<i<<endl;
		for(j=0; j<GRAF.size(); j++){
			if(GRAF[i][j]!=-1){
				U.w2=j;
				U.waga=GRAF[i][j];
				GL[i].push_back(U);
			}
		}
	}
}