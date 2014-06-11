#include"siecres.h"
#include<time.h>
#include<string>
using namespace std;

int main(){
	siec<double> S;
	siecres<double> Sr;
	clock_t start, koniec;
	long czas;
	double max;
	ofstream plik;
	string file[]={"2k100-35.txt", "2k200-89.txt", "2k300-53.txt", "2k400-37.txt", "2k500-92.txt",
					"4k100-23.txt", "4k200-93.txt", "4k300-72.txt", "4k400-64.txt", "4k500-16.txt",
					"16k100-67.txt", "16k200-48.txt", "16k300-19.txt"};

	plik.open("wyniki.txt");
	if(plik.is_open()){


	for(unsigned int i=0; i<13; i++){
		S.wczytaj(file[i]);
		long s=0;
		for(unsigned int j=0; j<5; j++){
			Sr=S;
			start=clock();
			max=Sr.maxPrzeplyw();
			koniec=clock();
			czas=(long)(koniec-start);
			s+=czas;
		}
		cout<<file[i]<<" "<<s/5<<" "<<max<<endl;
		plik<<Sr.iWierzcholkow()<<"\t"<<Sr.iPolaczen()<<"\t"<<Sr.wZrodlo()<<"\t"<<Sr.wTerminal()<<"\t"<<max<<"\t"<<s/5<<endl;
	}

	}
	plik.close();
	system("Pause");
}
/*
int main(){
	siec<double> S;
	siecres<double> Sr;
	clock_t start, koniec;
	double czas;

	double max;
	S.wczytaj("2k300-53.txt");
	Sr=S;

	start=clock();
	max=Sr.maxPrzeplyw();
	koniec=clock();
	czas=(long)(koniec-start);
	cout<<max<<endl;
	cout<<czas<<endl;
//	Sr.wypisz();
//	Sr.zapisz("siec2.txt");
	system("Pause");
}
*/