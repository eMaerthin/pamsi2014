#include"ObiektOblakania.h"
#include <cstdlib>
#include <cstdio>
#include <random>
#include <ctime>
class CPU{
public:
	ObiektOblakania* plan;
//	vector<ObiektOblakania>^ ostatniododane;

	CPU();
//	~CPU();
//	void dodajPoziomy(Int32 poziomy);
	void dodajpoziom();
	pole CPUmove(int tura);
	void PLAYERmove(Matryca X);
	void Utworz(Matryca X);
};

CPU::CPU(){
	plan=new ObiektOblakania;
//	ostatniododane=gcnew vector<ObiektOblakania^>;
}
/*
CPU::~CPU(){
	delete this;
}
*/
void CPU::Utworz(Matryca X){
//	plan->starszy=NULL;
	plan->WinLooseBalance=0;
	plan->situation=X;
	plan->gracz='O';
	plan->mlodsze.clear();
	plan->UtworzMlodsze();
}

pole CPU::CPUmove(int tura){
	if(tura==0){
		while(1){
			srand((unsigned int)time(NULL));
			if(plan->situation.matrix[rand()%2+1][rand()%2+1][rand()%2+1].znacznik=='-'){
				return plan->situation.matrix[rand()%2+1][rand()%2+1][rand()%2+1];
			}
		}
	}
	ObiektOblakania* newplan=new ObiektOblakania;

	int max=(numeric_limits<int>::min)();
	vector<ObiektOblakania>::iterator it;
	for(it=plan->mlodsze.begin(); it!=plan->mlodsze.end(); it++){
		if(it->WinLooseBalance>max || max==(numeric_limits<int>::min)()){
			*newplan=*it;
			max=it->WinLooseBalance;
		}
	}
//	delete plan;
//	plan=new ObiektOblakania;
	plan=newplan;
	return plan->situation.ostatni;
}

void CPU::PLAYERmove(Matryca X){
	Utworz(X);
}

void CPU::dodajpoziom(){
	plan->UtworzMlodsze();

}