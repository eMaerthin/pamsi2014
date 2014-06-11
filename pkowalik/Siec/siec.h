#include<iostream>
#include<fstream>
using namespace std;

template<class typ>
class siec{
protected:
	unsigned int _v;
	unsigned int _e;
	unsigned int _s;
	unsigned int _u;
	typ** _tab;

public:
	siec();
	siec(const siec<typ>& S);
	unsigned int v() const;
	unsigned int e() const;
	unsigned int s() const;
	unsigned int u() const;
	typ tab(unsigned int i, unsigned int j) const;
	unsigned int iWierzcholkow();
	unsigned int iPolaczen();
	unsigned int wZrodlo();
	unsigned int wTerminal();
	void utworz();
	void wczytaj(string file);
	virtual void zapisz(string file);
};

template<class typ>
siec<typ>::siec(){
	_tab=new typ*;
	_v=0;
	_e=0;
	_s=0;
	_u=0;
}

template<class typ>
siec<typ>::siec(const siec<typ>& S){
	unsigned int i, j;
	_v=S._v;
	_e=S._e;
	_s=S._s;
	_u=S._u;
	delete _tab;
	_tab=new typ*[_v];						//utworzenie tablicy jedno wymiarowej
	for(i=0; i<_v; i++){					//tworzenie tablicy dwuwymiarowej
		_tab[i]=new typ[_v];
		for(j=0; j<_v; j++){				//przypisywanie nowym kolumn¹ wartoœci -1
			_tab[i][j]=S._tab[i][j];
		}
	}
}

template<class typ>
unsigned int siec<typ>::v() const{
	return _v;
}

template<class typ>
unsigned int siec<typ>::e() const{
	return _e;
}

template<class typ>
unsigned int siec<typ>::s() const{
	return _s;
}

template<class typ>
unsigned int siec<typ>::u() const{
	return _u;
}

template<class typ>
typ siec<typ>::tab(unsigned int i, unsigned int j) const{
	return _tab[i][j];
}

template<class typ>
unsigned int siec<typ>::iWierzcholkow(){
	return _v;
}

template<class typ>
unsigned int siec<typ>::iPolaczen(){
	return _e;
}

template<class typ>
unsigned int siec<typ>::wZrodlo(){
	return _s;
}

template<class typ>
unsigned int siec<typ>::wTerminal(){
	return _u;
}

template<class typ>
void siec<typ>::utworz(){
	unsigned int i, j;
	delete _tab;
	_tab=new typ*[_v];						//utworzenie tablicy jedno wymiarowej
	for(i=0; i<_v; i++){					//tworzenie tablicy dwuwymiarowej
		_tab[i]=new typ[_v];
		for(j=0; j<_v; j++){				//przypisywanie nowym kolumn¹ wartoœci -1
			_tab[i][j]=-1;
		}
	}
}

template<class typ>
void siec<typ>::wczytaj(string file){
	ifstream plik;
	unsigned int i, j;
	typ w;

	plik.open(file);
	if(plik.is_open()){
		plik>>_v;						//wczytanie ilosci wierzcholków
		plik>>_e;						//wczytanie ilosci polaczen
		plik>>_s;						//wczytanie wierzcholka startowego(Ÿród³o)
		plik>>_u;						//wczytanie wierzcholka koñcowego(terminal)
		utworz();						//tworzenie nowej sieci
		while(!plik.eof()){				//wczytywanie polaczeñ
			plik>>i;
			plik>>j;
			plik>>w;
			_tab[i][j]=w;
		}
	}
}

template<class typ>
void siec<typ>::zapisz(string file){
	ofstream plik;
	unsigned int i, j;

	cout<<"Zapisywanie Graf"<<endl;
	plik.open(file);
	if(plik.is_open()){
		plik<<_v<<" ";						//zapisanie ilosci wierzcholków
		plik<<_e;							//zapisanie ilosci polaczen
		plik<<endl;
		plik<<_s<<" ";						//zapisanie wierzcholka startowego(Ÿród³o)
		plik<<_u;							//zapisanie wierzcholka koñcowego(terminal)
		plik<<endl;
		for(i=0; i<_v; i++){
			for(j=0; j<_v; j++){			//Zapisywanie tablicy
				if(_tab[i][j]>0){
					plik<<i<<"\t"<<j<<"\t"<<_tab[i][j]<<endl;
				}
			}
		}
	}
	cout<<"Zapisywanie zakonczone"<<endl;
}

