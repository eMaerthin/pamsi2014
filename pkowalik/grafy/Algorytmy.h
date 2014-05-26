#include<iostream>
#include"Graf.h"
#include"Graf_Lista.h"
#include"KoloryKruskala.h"
#include"TabelkaDjikstry.h"
#include<random>
#include<ctime>
#include<string>
#include<sstream>
using namespace std;

template<class typ>
class Algorytmy{
	long czas;
public:
	Algorytmy();
	void reset();
	long Czas();
	Graf<typ> Kruskal(Graf<typ> GrafPierwotny);
	Graf_Lista<typ> Kruskal(Graf_Lista<typ> GrafPierwotny);
	Graf<typ> Prim(Graf<typ> GrafPierwotny);
	Graf_Lista<typ> Prim(Graf_Lista<typ> GrafPierwotny);
	void Djikstry(Graf<typ> GrafPierwotny);
	void Djikstry(Graf_Lista<typ> GrafPierwotny);
	void Bellman_Ford(Graf<typ> GrafPierwotny);
	void Bellman_Ford(Graf_Lista<typ> GrafPierwotny);
	bool Random(unsigned int N, double p, Graf<typ>& D);
};

template<class typ>
Algorytmy<typ>::Algorytmy(){
	czas=0;
}

template<class typ>
void Algorytmy<typ>::reset(){
	czas=0;
}

template<class typ>
long Algorytmy<typ>::Czas(){
	return czas;
}

template<class typ>
Graf<typ> Algorytmy<typ>::Kruskal(Graf<typ> GrafPierwotny){
	KoloryKruskala K;
	Graf<typ> GrafWlasciwy;
	unsigned int i, j;
	Element<typ> Min, poczatkowy;
	int x=0;
	clock_t start, koniec;

	start=clock();

	GrafWlasciwy.Utworz(GrafPierwotny.size()-1);
	poczatkowy.Utworz(0, 0, 0);
	K.Pokoloruj_Start(GrafPierwotny.size());
	
	while(!K.WszystkieTegoSamegoKoloru()){

		Min.Utworz(poczatkowy.w1(), poczatkowy.w2(), poczatkowy.waga());
	
		for(i=0; i<GrafPierwotny.size(); i++){
			for(j=0; j<GrafPierwotny.size(); j++){
				if(GrafPierwotny[i][j]!=-1){
					if(GrafPierwotny[i][j]<Min.waga() || Min.waga()==0){
						if(K.Colors.find(i)->second!=K.Colors.find(j)->second){
							Min.Utworz(i, j, GrafPierwotny[i][j]);
						}
					}
				}
			}
		}
		
		if(!Min.porownaj(poczatkowy)){
			GrafPierwotny[Min.w1()][Min.w2()]=-1;
			GrafPierwotny[Min.w2()][Min.w1()]=-1;
			GrafWlasciwy[Min.w1()][Min.w2()]=Min.waga();
			GrafWlasciwy[Min.w2()][Min.w1()]=Min.waga();
			K.Przekoloruj(Min.w2(), Min.w1());
		}else{
			break;
		}
		x++;
	}
	
	koniec=clock();
	czas+=(long)(koniec-start);
	return GrafWlasciwy;
}

template<class typ>
Graf_Lista<typ> Algorytmy<typ>::Kruskal(Graf_Lista<typ> GrafPierwotny){
	KoloryKruskala K;
	Graf_Lista<typ> GrafWlasciwy;
	map<unsigned int, list<Elem<typ>>>::iterator i;
	list<Elem<typ>>::iterator j, jta;
	Element<typ> Min, poczatkowy;
	int x=0;
	clock_t start, koniec;

	start=clock();
	
	GrafWlasciwy.Utworz(GrafPierwotny.size());
	poczatkowy.Utworz(0, 0, 0);
	K.Pokoloruj_Start(GrafPierwotny.size());
	
	while(!K.WszystkieTegoSamegoKoloru()){
		
		Min.Utworz(poczatkowy.w1(), poczatkowy.w2(), poczatkowy.waga());

		for(i=GrafPierwotny.mapa().begin(); i!=GrafPierwotny.mapa().end(); i++){
			for(j=i->second.begin(); j!=i->second.end(); j++){
				if(j->waga!=-1){
					if(j->waga<Min.waga() || Min.waga()==0){
						if(K.Colors.find(i->first)->second!=K.Colors.find(j->w2)->second){
							Min.Utworz(i->first, j->w2, j->waga);
							jta=j;
						}
					}
				}
			}
		}
		
		if(!Min.porownaj(poczatkowy)){
			GrafWlasciwy.pushpol(Min);
			jta->waga=-1;
			K.Przekoloruj(Min.w2(), Min.w1());
		}else{
			break;
		}
		x++;
	}
	
	koniec=clock();
	czas+=(long)(koniec-start);
	return GrafWlasciwy;
}

template<class typ>
Graf<typ> Algorytmy<typ>::Prim(Graf<typ> GrafPierwotny){
	vector<unsigned int> WiezcholkiPolaczone;
	vector<unsigned int>::iterator it, jt;
	unsigned int j, jta;
	bool JuzJest=false;
	Graf<typ> GrafWlasciwy;
	Element<typ> Min, poczatkowy;
	clock_t start, koniec;

	start=clock();
	
	GrafWlasciwy.Utworz(GrafPierwotny.size()-1);
	WiezcholkiPolaczone.push_back(0);
	poczatkowy.Utworz(0, 0, 0);
	
	while(WiezcholkiPolaczone.size()<GrafPierwotny.size()){
		Min.Utworz(poczatkowy.w1(), poczatkowy.w2(), poczatkowy.waga());
	
		for(it=WiezcholkiPolaczone.begin(); it!=WiezcholkiPolaczone.end(); it++){
			for(j=0; j<GrafPierwotny.size(); j++){
				if(GrafPierwotny[*it][j]!=-1){
					if(GrafPierwotny[*it][j]<Min.waga() || Min.waga()==0){
						for(jt=WiezcholkiPolaczone.begin(); jt!=WiezcholkiPolaczone.end(); jt++){
							if(j==*jt){
								JuzJest=true;
								break;
							}
						}
						if(!JuzJest){
							Min.Utworz(*it, j, GrafPierwotny[*it][j]);
							jta=j;
						}
						JuzJest=false;
					}
				}
			}
		}
		
		if(!Min.PorownajElementy(poczatkowy)){
			GrafPierwotny[Min.w1()][Min.w2()]=-1;
			GrafPierwotny[Min.w2()][Min.w1()]=-1;
			GrafWlasciwy[Min.w1()][Min.w2()]=Min.waga();
			GrafWlasciwy[Min.w2()][Min.w1()]=Min.waga();
			WiezcholkiPolaczone.push_back(Min.w2());
		}else{
			break;
		}
	}
	
	koniec=clock();
	czas+=(long)(koniec-start);
	return GrafWlasciwy;
}

template<class typ>
Graf_Lista<typ> Algorytmy<typ>::Prim(Graf_Lista<typ> GrafPierwotny){
	vector<unsigned int> WiezcholkiPolaczone;
	vector<unsigned int>::iterator it, jt;
	list<Elem<typ>>::iterator j, jta;
	bool JuzJest=false;
	Graf_Lista<typ> GrafWlasciwy;
	Element<typ> Min, poczatkowy;
	clock_t start, koniec;

	start=clock();
	
	GrafWlasciwy.Utworz(GrafPierwotny.size());
	WiezcholkiPolaczone.push_back(0);
	poczatkowy.Utworz(0, 0, 0);
	
	while(WiezcholkiPolaczone.size()<GrafPierwotny.size()){
		Min.Utworz(poczatkowy.w1(), poczatkowy.w2(), poczatkowy.waga());
	
		for(it=WiezcholkiPolaczone.begin(); it!=WiezcholkiPolaczone.end(); it++){
			for(j=GrafPierwotny[*it].begin(); j!=GrafPierwotny[*it].end(); j++){
				if(j->waga!=-1){
					if(j->waga<Min.waga() || Min.waga()==0){
						for(jt=WiezcholkiPolaczone.begin(); jt!=WiezcholkiPolaczone.end(); jt++){
							if(j->w2==*jt){
								JuzJest=true;
								break;
							}
						}
		
						if(!JuzJest){
							Min.Utworz(*it, j->w2, j->waga);
							jta=j;
						}
						
						JuzJest=false;
					}
				}
			}
		}
		
		if(!Min.PorownajElementy(poczatkowy)){
			GrafWlasciwy.pushpol(Min);
			jta->waga=-1;
			WiezcholkiPolaczone.push_back(Min.w2());
		}else{
			break;
		}
	}
	
	koniec=clock();
	czas+=(long)(koniec-start);
	return GrafWlasciwy;
}

template<class typ>
void Algorytmy<typ>::Djikstry(Graf<typ> GrafPierwotny){
	TabelkaDjikstry<typ> Tabela;
	Graf<typ> GrafWlasciwy;
	ListaElem<typ> PolaczeniaMinimalne;
	vector<Element<typ>> Polaczenia;
	Element<typ> El, ElMin;
	unsigned int i, j;
	int x=0;
	clock_t start, koniec;

	start=clock();
	
	GrafWlasciwy.Utworz(GrafPierwotny.size()-1);
	Tabela.Utworz(GrafPierwotny.size(), GrafPierwotny.Start());
	
	while(1){
		x++;
		Polaczenia.clear();
		i=Tabela.Odwiedzone.back();
	
		for(j=0; j<GrafPierwotny.size(); j++){
			if(GrafPierwotny[i][j]!=-1){
				El.Utworz(i, j, GrafPierwotny[i][j]);
				Polaczenia.push_back(El);
			}
		}
		
		ElMin.Utworz(Tabela.NaTabele(Polaczenia));
		
		if(Tabela.Odwiedzone.back()<GrafPierwotny.size()){
			PolaczeniaMinimalne.push(ElMin);
		} else{
			cout<<"Brak spojnosci"<<endl;
			break;
		}
		
		if(Tabela.Odwiedzone.size()==GrafPierwotny.size()){
			break;
		}
	}
	
	koniec=clock();
	czas+=(long)(koniec-start);

	Tabela.OstateczaSciezka(GrafPierwotny.Start());
}

template<class typ>
void Algorytmy<typ>::Djikstry(Graf_Lista<typ> GrafPierwotny){
	TabelkaDjikstry<typ> Tabela;
	Graf_Lista<typ> GrafWlasciwy;
	ListaElem<typ> PolaczeniaMinimalne;
	vector<Element<typ>> Polaczenia;
	Element<typ> El, ElMin;
	unsigned int i;
	list<Elem<typ>>::iterator j;
	clock_t start, koniec;

	start=clock();
	
	GrafWlasciwy.Utworz(GrafPierwotny.size());
	Tabela.Utworz(GrafPierwotny.size(), GrafPierwotny.Start());
	
	while(1){
		Polaczenia.clear();
		i=Tabela.Odwiedzone.back();
	
		for(j=GrafPierwotny[i].begin(); j!=GrafPierwotny[i].end(); j++){
			if(j->waga!=-1){
				El.Utworz(i, j->w2, j->waga);
				Polaczenia.push_back(El);
			}
		}

		ElMin.Utworz(Tabela.NaTabele(Polaczenia));

		if(Tabela.Odwiedzone.back()<GrafPierwotny.size()){
			PolaczeniaMinimalne.push(ElMin);
		} else{
			cout<<"Brak spojnosci"<<endl;
			break;
		}

		if(Tabela.Odwiedzone.size()==GrafPierwotny.size()){
			break;
		}
	}

	koniec=clock();
	czas+=(long)(koniec-start);
	Tabela.OstateczaSciezka(GrafPierwotny.Start());
}

template<class typ>
void Algorytmy<typ>::Bellman_Ford(Graf<typ> GrafPierwotny){
	Element<typ> S;
	vector<Element<typ>> W;
	vector<typ> dl;
	vector<unsigned int> poprzedni;
	list<unsigned int> Wypis;
	list<unsigned int>::iterator jt;
	unsigned int i, j;
	int x=0;
	clock_t start, koniec;

	start=clock();

	for(i=0; i<GrafPierwotny.size(); i++){
		for(j=0; j<GrafPierwotny.size(); j++){
			if(GrafPierwotny[i][j]!=-1){
				S.Utworz(i, j, GrafPierwotny[i][j]);
				W.push_back(S);
			}
		}
	}

	for(i=0; i<GrafPierwotny.size(); i++){
        dl.push_back(numeric_limits<typ>::max());
        poprzedni.push_back(-1);
    }
	
	x=0;
    dl[GrafPierwotny.Start()]=0;
	for(i=0; i<GrafPierwotny.size(); i++){
		for(vector<Element<typ>>::iterator vt=W.begin(); vt!=W.end(); vt++){
			x++;
			if(dl[vt->w2()] > dl[vt->w1()]+vt->waga()){
				dl[vt->w2()] = dl[vt->w1()] + vt->waga();
                poprzedni[vt->w2()]=vt->w1();
            }
        }
    }
	
	koniec=clock();
	czas+=(long)(koniec-start);

	int v;
	for(i=0; i<GrafPierwotny.size(); i++){
            if(i!=GrafPierwotny.Start()){
                cout<<GrafPierwotny.Start()<<"->"<<i<<" dl. "<<dl[i]<<", przebieg: ";
				v=i;
				Wypis.clear();

				do{
					Wypis.push_front(v);
					v=poprzedni[v];
				}while(poprzedni[v]!=-1);

				cout<<GrafPierwotny.Start()<<"->";

				for(jt=Wypis.begin(); jt!=Wypis.end(); jt++){
					cout<<*jt;
					if(*jt!=Wypis.back()){
					cout<<"->";
					}
				}
				cout<<endl;
            }
        }
}

template<class typ>
void Algorytmy<typ>::Bellman_Ford(Graf_Lista<typ> GrafPierwotny){
	Element<typ> S;
	vector<Element<typ>> W;
	vector<typ> dl;
	unsigned int i;
	vector<unsigned int> poprzedni;
	list<unsigned int> Wypis;
	list<unsigned int>::iterator jt;
	unsigned int im;
	list<Elem<typ>>::iterator jl;
	int x=0;
	clock_t start, koniec;

	start=clock();

	for(im=0; im<GrafPierwotny.size(); im++){
		for(jl=GrafPierwotny[im].begin(); jl!=GrafPierwotny[im].end(); jl++){
			if(jl->waga!=-1){
				S.Utworz(im, jl->w2, jl->waga);
				W.push_back(S);
			}
		}
	}

	for(i=0; i<GrafPierwotny.size(); i++){
        dl.push_back(numeric_limits<typ>::max());
        poprzedni.push_back(-1);
    }
	x=0;
    dl[GrafPierwotny.Start()]=0;

	for(i=0; i<GrafPierwotny.size(); i++){
		for(vector<Element<typ>>::iterator vt=W.begin(); vt!=W.end(); vt++){
			x++;
			if(dl[vt->w2()] > dl[vt->w1()]+vt->waga()){
				dl[vt->w2()] = dl[vt->w1()] + vt->waga();
                poprzedni[vt->w2()]=vt->w1();
            }
        }
    }

	koniec=clock();
	czas+=(long)(koniec-start);

	int v;
	for(i=0; i<GrafPierwotny.size(); i++){
            if(i!=GrafPierwotny.Start()){
                cout<<GrafPierwotny.Start()<<"->"<<i<<" dl. "<<dl[i]<<", przebieg: ";
				v=i;
				Wypis.clear();

				do{
					Wypis.push_front(v);
					v=poprzedni[v];
				}while(poprzedni[v]!=-1);
				cout<<GrafPierwotny.Start()<<"->";

				for(jt=Wypis.begin(); jt!=Wypis.end(); jt++){
					cout<<*jt;
					if(*jt!=Wypis.back()){
					cout<<"->";
					}
				}
				cout<<endl;
            }
        }
}

template<class typ>
bool Algorytmy<typ>::Random(unsigned int N, double p, Graf<typ>& D){
	int prawdopodobienstwo=static_cast<int>(p * 100000);
	unsigned int i, j;

	if(p<0){
		return false;
	}
	if(p>1){
		p=1;
	}
	srand((int)time(NULL));
	D.~Graf();
	D.Utworz(N);

	D.Start(rand()% (N-1));
	for (i=0; i < D.size(); ++i){
		for (j=i+1; j < D.size(); ++j){
			if (rand() % 100000 <= prawdopodobienstwo && j != i){
				D[i][j] = D[j][i] = rand() % (N * N / 2) + 1;
			}
		}
	}

	if(D.Spojnosc()){
/*		ostringstream sN, sp;
		sN<<N;
		sp<<p;
		string strN=sN.str();
		string strp=sp.str();
		string file="GrafKP_N="+strN+"_p="+strp+".txt";
		D.Zapisz2("obecny.txt", file);*/
	//	cout<<"spojny"<<endl;
		return true;
	}else{
		return false;
	}
}