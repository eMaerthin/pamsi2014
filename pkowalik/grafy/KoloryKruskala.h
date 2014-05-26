#include<iostream>
#include<map>
using namespace std;

struct KoloryKruskala{
	map<unsigned int, int> Colors;

	KoloryKruskala();
	void Pokoloruj_Start(int rozmiar);
	void Przekoloruj(unsigned int w1, unsigned int w2);
	bool WszystkieTegoSamegoKoloru();
};

KoloryKruskala::KoloryKruskala(){
	Colors.clear();
}

void KoloryKruskala::Pokoloruj_Start(int rozmiar){
	int i;
	for(i=0; i<rozmiar; i++){
		Colors[i]=i;
	}
}

void KoloryKruskala::Przekoloruj(unsigned int w2, unsigned int w1){
	int KolorDoZmiany, KolorWlasciwy;
	map<unsigned int, int>::iterator it;
	KolorDoZmiany=Colors.find(w2)->second;
	KolorWlasciwy=Colors.find(w1)->second;
	
	for(it=Colors.begin(); it!=Colors.end(); it++){
		if(it->second==KolorDoZmiany){
			it->second=KolorWlasciwy;
		}
	}
}

bool KoloryKruskala::WszystkieTegoSamegoKoloru(){
	bool TenSamKolor=true;
	int Kolor1;
	map<unsigned int, int>::iterator it;
	Kolor1=Colors.begin()->second;
	for(it=Colors.begin(); it!=Colors.end(); it++){
		if(it->second!=Kolor1){
			TenSamKolor=false;
		}
	}
	return TenSamKolor;
}