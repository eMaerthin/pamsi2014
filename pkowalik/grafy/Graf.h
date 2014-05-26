#ifndef GRAF_H
#define GRAF_H
#include<iostream>
#include"ListaElem.h"
#include<list>
using namespace std;

template<class typ>
class Graf{
	typ **G;
	unsigned int rozmiar;
	unsigned int w_start;
	unsigned int w_last;
	unsigned int ilosc_w;
	unsigned int ilosc_p;
public:
	Graf();
	Graf(const Graf<typ> &Gr);
	~Graf();
	unsigned int size();
	void Utworz(unsigned int r);
	bool NieMaPolaczen();
	typ* operator[](unsigned int i);
	Graf<typ>& operator=(Graf<typ> &Gr);
	void przepisz(ListaElem<typ> X);
	void Wczytaj(string file);
	void Zapisz(string file);
	void Zapisz2(string file, string file2);
	void Kruskal();
	void Prima();
	void Djikstra();
	void Start(unsigned int s);
	void PobierzOstatni();
	unsigned int Start();
	unsigned int Ostatni();
	unsigned int Wierzcholki();
	unsigned int Polaczenia();
	void Start_Koniec(unsigned int s, unsigned int o);
	bool Spojnosc();
};

template<class typ>
Graf<typ>::Graf(){
	unsigned int x, y;
	rozmiar=0;
	w_start=0;
	w_last=0;
	ilosc_w=0;
	ilosc_p=0;
	G=new typ* [rozmiar];
	for(unsigned int i=0; i<rozmiar; i++){
		G[i]=new typ[rozmiar];
	}
	for(x=0; x<rozmiar; x++){
		for(y=0; y<rozmiar; y++){
			G[x][y]=-1;
		}
	}
}

template<class typ>
Graf<typ>::Graf(const Graf<typ> &Gr){
	unsigned int x, y;
	rozmiar=Gr.rozmiar;
	w_start=Gr.w_start;
	w_last=Gr.w_last;
	ilosc_w=Gr.ilosc_w;
	ilosc_p=Gr.ilosc_p;
	G=new typ* [rozmiar];
	for(unsigned int i=0; i<rozmiar; i++){
		G[i]=new typ[rozmiar];
	}
	for(x=0; x<rozmiar; x++){
		for(y=0; y<rozmiar; y++){
			G[x][y]=Gr.G[x][y];
		}
	}
}

template<class typ>
Graf<typ>& Graf<typ>::operator=(Graf<typ> &Gr){
	unsigned int x, y;
	for(x=0; x<rozmiar; x++){
		for(y=0; y<rozmiar; y++){
			G[x][y]=Gr.G[x][y];
		}
	}
	return *(this);
}

template<class typ>
Graf<typ>::~Graf(){
	for(unsigned int i=0; i<rozmiar; i++){
	 delete G[i];
	}
	delete []G;
}

template<class typ>
typ* Graf<typ>::operator[](unsigned int i){
	return G[i];
}

template<class typ>
unsigned int Graf<typ>::size(){
	return rozmiar;
}

template<class typ>
void Graf<typ>::przepisz(ListaElem<typ> X){
	for(unsigned int i=0; i<X.size(); i++){
		G[X[i].w1()][X[i].w2()]=X[i].waga();
		G[X[i].w2()][X[i].w1()]=X[i].waga();
	}
}

template<class typ>
void Graf<typ>::Utworz(unsigned int r){
	unsigned int x,y;
	rozmiar=r+1;
	G=new typ* [rozmiar];
	for(unsigned int i=0; i<rozmiar; i++){
		G[i]=new typ[rozmiar];
	}
	for(x=0; x<rozmiar; x++){
		for(y=0; y<rozmiar; y++){
			G[x][y]=-1;
		}
	}
}

template<class typ>
bool Graf<typ>::NieMaPolaczen(){
	unsigned int i, j;

	for(i=0; i<rozmiar; i++){
		for(j=0; j<rozmiar; j++){
			if(G[i][j]!=-1){
				return false;
			}
		}
	}
	return true;
}

template<class typ>
void Graf<typ>::Wczytaj(string file){
	ifstream plik;
	unsigned int x1, x2;
	typ y;
	Element<typ> S;
	ListaElem<typ> lista;
	int x;
	
	plik.open(file);
	if(plik.is_open()){
		while(!plik.eof()){
			plik>>x1;
			plik>>x2;
			plik>>y;
			S.Utworz(x1,x2,y);
			lista.push(S);
			x++;
			cout<<"Wczytanych: "<<x;
		}
		Utworz(lista.rozpientosc());
		przepisz(lista);
		ilosc_w=rozmiar+1;
		ilosc_p=ilosc_w-1;
	}
}

template<class typ>
void Graf<typ>::Zapisz(string file){
	ofstream plik;
	unsigned int i,j;

	plik.open(file);
	if(plik.is_open()){
		for(i=0; i<rozmiar; i++){
			for(j=0; j<rozmiar; j++){
				if(G[i][j]!=-1){
					plik<<i<<"     "<<j<<"     "<<G[i][j]<<endl;
					G[j][i]=-1;//----------------------------------------------------------------------------------------
				}
			}
		}
	}
	plik.close();
}

template<class typ>
void Graf<typ>::Zapisz2(string file, string file2){
	ofstream plik, plik2;
	unsigned int i,j;
	int x=-1;

	plik.open(file);
	plik2.open(file2);
	if(plik.is_open() && plik2.is_open()){
		for(i=0; i<rozmiar; i++){
			x++;
			cout<<"Kolumna:"<<x<<endl;
			for(j=0; j<rozmiar; j++){
				if(G[i][j]!=-1){
					plik<<i<<"     "<<j<<"     "<<G[i][j]<<endl;
					plik2<<i<<"     "<<j<<"     "<<G[i][j]<<endl;
					G[j][i]=-1;//----------------------------------------------------------------------------------------
				}
			}
		}
	}
	plik.close();
	plik2.close();
}

template<class typ>
void Graf<typ>::Kruskal(){
	vector<unsigned int> kolory;
	unsigned int i, j, z, y, k, czy_juz;
	unsigned int x=0;
	ListaElem<typ> Lista, Lista_wlasciwa;
	Element<typ> El;
	bool koniec=false, juz=false;

	for(i=0; i<rozmiar; i++){
		for(j=0; j<rozmiar; j++){
			if(G[i][j]!=-1){
				El.Utworz(i,j,G[i][j]);
				Lista.push_waga(El);
				G[i][j]=-1;
			}
		}
	}
	this->~Graf();
	for(i=0; i<rozmiar; i++){
		kolory.push_back(i);
	}
	while(!koniec && x<Lista.size()){
		if(kolory[Lista[x].w1()]!=kolory[Lista[x].w2()]){
			z=kolory[Lista[x].w2()];
			Lista_wlasciwa.push(Lista[x]);
			for(y=0; y<kolory.size(); y++){
				if(kolory[y]==z){
					kolory[y]=kolory[Lista[x].w1()];
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
	Utworz(Lista_wlasciwa.rozpientosc());
	przepisz(Lista_wlasciwa);
}

template<class typ>
void Graf<typ>::Prima(){
	vector<unsigned int> Zebrane;
	ListaElem<typ> Lista_wlasciwa;
	Element<typ> Min;
	bool koniec, brak_spojnosci, zapetlenie;
	unsigned int wiezcholek, j, i;

	koniec=false;
	brak_spojnosci=false;
	Zebrane.push_back(0);
	while(!koniec){
		zapetlenie=false;
		Min.Utworz(0, 0, 0);
		for(wiezcholek=0; wiezcholek<Zebrane.size(); wiezcholek++){
			for(j=0; j<rozmiar; j++){
				if((G[Zebrane[wiezcholek]][j]<Min.waga() && G[Zebrane[wiezcholek]][j]!=-1) || (Min.waga()==0 && G[Zebrane[wiezcholek]][j]!=-1)){
					Min.Utworz(Zebrane[wiezcholek], j, G[Zebrane[wiezcholek]][j]);
				}
			}
		}
		G[Min.w1()][Min.w2()]=-1;
		G[Min.w2()][Min.w1()]=-1;
		if(Min.waga()==0){
			cout<<"brak spojnosci"<<endl;
			koniec=true;
		} else {
			for(i=0; i<Zebrane.size(); i++){
				if(Zebrane[i]==Min.w2()){
					zapetlenie=true;
				}
			}
			if(!zapetlenie){
				Zebrane.push_back(Min.w2());
				Lista_wlasciwa.push(Min);
			}
			if(Lista_wlasciwa.size()==rozmiar-1){
				koniec=true;
			}
		}
		
	}
	this->~Graf();
	Utworz(rozmiar-1);
	przepisz(Lista_wlasciwa);

}
/*
template<class typ>
void Graf<typ>::Djikstra(){
	vector<unsigned int> visited;
	visited.push_back(0);

	cout<<*(visited.end()-1)<<endl;
	while(visited.size()<rozmiar){
		for(down=0; down<rozmiar; down++){
			if(G[*(visited.end()-1)][down]!=-1){
				push_back(G[*(visited.end()-1)][down]);
			}
		}
	}
	
}
*/
template<class typ>
void Graf<typ>::Start(unsigned int s){
	if(s<rozmiar){
		w_start=s;
	}
	else{
		w_start=0;
	}
}

template<class typ>
void Graf<typ>::PobierzOstatni(){
	unsigned int o;
	while(1){
		cout<<"Wpisz wierzcholek do ktorego chcesz sie dostac: ";
		cin>>o;
		if(o<rozmiar){
			w_last=o;
			break;
		} else {
			cout<<"Wierzcholka nie ma na grafie."<<endl;
		}
	}
}

template<class typ>
unsigned int Graf<typ>::Start(){
	return w_start;
}

template<class typ>
unsigned int Graf<typ>::Ostatni(){
	return w_last;
}

template<class typ>
void Graf<typ>::Start_Koniec(unsigned int s, unsigned int o){
	w_start=s;
	w_last=o;
}

template<class typ>
unsigned int Graf<typ>::Wierzcholki(){
	return ilosc_w;
}

template<class typ>
unsigned int Graf<typ>::Polaczenia(){
	return ilosc_p;
}

template<class typ>
bool Graf<typ>::Spojnosc(){
	vector<unsigned int> Spojne;
	unsigned int i, j, h;
	bool jest;
	int befor_size;

	Spojne.push_back(0);
	for(i=0; i<Spojne.size(); i++){
		befor_size=Spojne.size();
		for(j=0; j<rozmiar; j++){
			if(G[Spojne[i]][j]!=-1){
				jest=false;
				for(h=0; h<Spojne.size(); h++){
					if(Spojne[h]==j){
						jest=true;
						break;
					}
				}
				if(!jest){
					Spojne.push_back(j);
				}
			}
		}
		if(Spojne.size()==rozmiar){
			return true;
		}
		if(Spojne.size()==befor_size){
			return false;
		}
	}
	return false;
}
#endif