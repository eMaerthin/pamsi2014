#include<iostream>
#include"Algorytmy.h"
using namespace std;

int main(){
	Graf<double> D;
	Graf_Lista<double> L;
	Algorytmy<double> AlgRand, AlgKruskalM, AlgKruskalL, AlgPrimM, AlgPrimL, AlgDjikstraM, AlgDjikstraL, AlgFordM, AlgFordL;
	vector<long> VecKruskalM, VecKruskalL, VecPrimM, VecPrimL, VecDjikstraM, VecDjikstraL, VecFordM, VecFordL;
	unsigned int i, j, h;
	int N[]={50, 100, 200, 300};
	double p[]={0.25, 0.5, 0.75, 1};
	ofstream plik;

	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			AlgKruskalM.reset();
			AlgKruskalL.reset();
			AlgPrimM.reset();
			AlgPrimL.reset();

			for(h=0; h<50; h++){
				cout<<"Powtorzenie "<<h<<"/50 z N="<<N[i]<<" i p="<<p[j]<<endl;
				if(AlgRand.Random(N[i], p[j], D)){
					L.convert(D);
					AlgKruskalM.Kruskal(D);
					AlgKruskalL.Prim(D);
					AlgPrimM.Kruskal(L);
					AlgPrimL.Prim(L);
				}else {
				h--;
				}
			}

			VecKruskalM.push_back(AlgKruskalM.Czas());
			VecKruskalL.push_back(AlgKruskalL.Czas());
			VecPrimM.push_back(AlgPrimM.Czas());
			VecPrimL.push_back(AlgPrimL.Czas());
		}
	}

	plik.open("KruskalM.txt");
	if(plik.is_open()){
		plik<<"Algorytm Kruskal'a Macierz"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecKruskalM[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();

	plik.open("KruskalL.txt");
	if(plik.is_open()){
		plik<<"Algorytm Kruskal'a Listy"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecKruskalL[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();

	plik.open("PrimM.txt");
	if(plik.is_open()){
		plik<<"Algorytm Prim'a Macierz"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecPrimM[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();

	plik.open("PrimL.txt");
	if(plik.is_open()){
		plik<<"Algorytm Prim'a Listy"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecPrimL[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();

	cout<<"Algorytm Kruskala i Prima zosta³ wykonany"<<endl;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			AlgDjikstraM.reset();
			AlgDjikstraL.reset();
			AlgFordM.reset();
			AlgFordL.reset();
			
			for(h=0; h<50; h++){
				cout<<endl<<endl<<"Powtorzenie "<<h<<"/50 z N="<<N[i]<<" i p="<<p[j]<<endl<<endl;
				if(AlgRand.Random(N[i], p[j], D)){
					L.convert(D);
					AlgDjikstraM.Djikstry(D);
					AlgDjikstraL.Djikstry(L);
					AlgFordM.Bellman_Ford(D);
					AlgFordL.Bellman_Ford(L);
				}else{
				h--;
				}
			}
			
			VecDjikstraM.push_back(AlgDjikstraM.Czas());
			VecDjikstraL.push_back(AlgDjikstraL.Czas());
			VecFordM.push_back(AlgFordM.Czas());
			VecFordL.push_back(AlgFordL.Czas());
		}
	}

	plik.open("DjikstraM.txt");
	if(plik.is_open()){
		plik<<"Algorytm Djikstry Macierz"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecDjikstraM[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();

	plik.open("DjikstraL.txt");
	if(plik.is_open()){
		plik<<"Algorytm Djikstry Listy"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecDjikstraL[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();

	plik.open("FordM.txt");
	if(plik.is_open()){
		plik<<"Algorytm Bellman-Ford'a Macierz"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecFordM[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();

	plik.open("FordL.txt");
	if(plik.is_open()){
		plik<<"Algorytm Bellman-Ford'a Listy"<<endl;
		plik<<"Liczba wierzcholkow"<<'\t'<<"Prawdopodobieñstwo"<<'\t'<<"Czas"<<endl;
		h=0;
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				plik<<N[i]<<'\t'<<p[j]<<'\t'<<VecFordL[h]/50<<endl;
				h++;
			}
		}
	}
	plik.close();
}