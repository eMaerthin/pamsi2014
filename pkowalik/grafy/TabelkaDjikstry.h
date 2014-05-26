#include<iostream>
#include<map>
#include<list>
#include"Element.h"
#include"InfoSciezki.h"
#include<limits>
using namespace std;

template<class typ>
struct TabelkaDjikstry{
	bool brakSpojnosci;
	map<unsigned int, list<InfoSciezki<typ>>> Tab;
	vector<unsigned int> Odwiedzone;

	TabelkaDjikstry();
	void Utworz(unsigned int rozmiar, unsigned int w_start);
	InfoSciezki<typ> OstatniElListy(list<InfoSciezki<typ>> lista);
	bool Odwiedzony(unsigned int x);
	void Add(Element<typ> Elem);
	Element<typ> NaTabele(vector<Element<typ>> X);
	void Wypisz();
	void OstateczaSciezka(unsigned int s);
};

template<class typ>
TabelkaDjikstry<typ>::TabelkaDjikstry(){
	Tab.clear();
	Odwiedzone.clear();
	brakSpojnosci=false;
}

template<class typ>
void TabelkaDjikstry<typ>::Utworz(unsigned int rozmiar, unsigned int w_start){
	list<InfoSciezki<typ>> Z, Start;
	InfoSciezki<typ> ergo;
	Tab.clear();
	Odwiedzone.clear();
	brakSpojnosci=false;
	Odwiedzone.push_back(w_start);
	Z.clear();
	Start.clear();
	ergo.get(0, 0, 0);
	Start.push_back(ergo);
	ergo.get(0, 0, numeric_limits<typ>::max());
	Z.push_back(ergo);
	for(unsigned int i=0; i<rozmiar; i++){
		if(i!=w_start){
			Tab[i]=Z;
		}else{
			Tab[i]=Start;
		}
	}
}

template<class typ>
bool TabelkaDjikstry<typ>::Odwiedzony(unsigned int x){
	vector<unsigned int>::iterator it;
	bool odw=false;
	for(it=Odwiedzone.begin(); it!=Odwiedzone.end(); it++){
		if(*it==x){
			odw=true;
			break;
		}
	}
	return odw;
}

template<class typ>
void TabelkaDjikstry<typ>::Add(Element<typ> Elem){
	InfoSciezki<typ> S;
	map<unsigned int, list<InfoSciezki<typ>>>::iterator it;

	if(Tab[Elem.w2()].back().wagaSciezki>Elem.waga()+Tab[Elem.w1()].back().wagaSciezki){
		S.get(Elem.w1(), Elem.waga(), Elem.waga()+Tab[Elem.w1()].back().wagaSciezki);
		Tab[Elem.w2()].push_back(S);
	}
	
}

template<class typ>
InfoSciezki<typ> TabelkaDjikstry<typ>::OstatniElListy(list<InfoSciezki<typ>> lista){
	list<InfoSciezki<typ>>::iterator it, jt;
	InfoSciezki<typ> x;
	for(it=lista.begin(); it!=lista.end(); it++){
		jt=it;
	}
	x.get(jt->w1, jt->wagaPolaczenia, jt->wagaSciezki);
	return x;
}

template<class typ>
Element<typ> TabelkaDjikstry<typ>::NaTabele(vector<Element<typ>> X){
	vector<Element<typ>>::iterator it, jt;
	map<unsigned int, list<InfoSciezki<typ>>>::iterator mt;
	Element<typ> Elem;
	InfoSciezki<typ> Minimalny;
	unsigned int x2;

	for(it=X.begin(); it!=X.end(); it++){
		jt=it;
		if(!Odwiedzony(it->w2())){
			Add(*it);
		}
	}
	
	Minimalny.get(0, 0, numeric_limits<typ>::max());
	for(mt=Tab.begin(); mt!=Tab.end(); mt++){
		if(!Odwiedzony(mt->first)){
			if(mt->second.back().wagaSciezki<Minimalny.wagaSciezki){
				Minimalny.get(mt->second.back().w1, mt->second.back().wagaPolaczenia, mt->second.back().wagaSciezki);
				x2=mt->first;
			}
		}
	}
	Odwiedzone.push_back(x2);
	Elem.Utworz(Minimalny.w1, x2, Minimalny.wagaPolaczenia);
	return Elem;
}

template<class typ>
void TabelkaDjikstry<typ>::Wypisz(){
	map<unsigned int, list<InfoSciezki<typ>>>::iterator mt;
	list<InfoSciezki<typ>>::iterator lt;

	for(mt=Tab.begin(); mt!=Tab.end(); mt++){
		cout<<mt->first<<"->";
		for(lt=mt->second.begin(); lt!=mt->second.end(); lt++){
			cout<<'('<<lt->w1<<' '<<lt->wagaPolaczenia<<' '<<lt->wagaSciezki<<") ";
		}
		cout<<endl;
	}
}

template<class typ>
void TabelkaDjikstry<typ>::OstateczaSciezka(unsigned int s){
	list<unsigned int> Wypis;
	list<unsigned int>::iterator jt;
	vector<unsigned int>::iterator it;
	unsigned int x;
	typ w;
	Element<typ> S;
	for(it=Odwiedzone.begin(); it!=Odwiedzone.end();  it++){
		Wypis.clear();
		w=Tab[*it].back().wagaSciezki;
		x=*it;
		while(x!=s){
			Wypis.push_front(x);
			x=Tab[x].back().w1;
		}
		Wypis.push_front(x);
		cout<<s<<"->"<<*it<<" ="<<w<<"  "<<"Przebieg: ";
		for(jt=Wypis.begin(); jt!=Wypis.end(); jt++){
			cout<<*jt;
			if(*jt!=Wypis.back()){
				cout<<"->";
			}else{
				break;
			}
		}
		cout<<endl;
	}
}