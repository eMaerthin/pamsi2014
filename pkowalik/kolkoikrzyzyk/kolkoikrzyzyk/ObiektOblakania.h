#include"Matryca.h"

class ObiektOblakania{
public:
	int WinLooseBalance;
//	ObiektOblakania* starszy;
	char gracz;
	Matryca situation;
	vector<ObiektOblakania> mlodsze;

	ObiektOblakania();
//	~ObiektOblakania();
	ObiektOblakania(const ObiektOblakania& X);
	ObiektOblakania& operator=(const ObiektOblakania& X);
	void UtworzMlodsze();
	void Oblicz();
};
//typedef ObiektOblakania Objekt;

ObiektOblakania::ObiektOblakania(){
//	starszy=new ObiektOblakania;
//	starszy=NULL;
	WinLooseBalance=0;
	gracz='-';
	mlodsze.clear();
}
/*
ObiektOblakania::~ObiektOblakania(){
	mlodsze.clear();
	delete this;
}
*/
ObiektOblakania::ObiektOblakania(const ObiektOblakania& X){
	WinLooseBalance=X.WinLooseBalance;
	gracz=X.gracz;
//	starszy=X.starszy;
	situation=X.situation;
	mlodsze=X.mlodsze;
}

ObiektOblakania& ObiektOblakania::operator=(const ObiektOblakania& X){
	WinLooseBalance=X.WinLooseBalance;
	gracz=X.gracz;
//	starszy=X.starszy;
	situation=X.situation;
	mlodsze=X.mlodsze;
	return *this;
}

void ObiektOblakania::UtworzMlodsze(){
	ObiektOblakania O;
//	O->starszy=this;
	O.gracz=przeciwnik(gracz);
	O.mlodsze.clear();
	for(int k=0; k<4; k++){
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				if(situation.matrix[i][j][k]=='-'){
					O.situation=situation;
					O.situation.Add(i, j, k, O.gracz);
					O.WinLooseBalance=0;
					O.Oblicz();
					mlodsze.push_back(O);
				}
			}
		}
	}
}

void ObiektOblakania::Oblicz(){
	WinLooseBalance=situation.Analizuj(gracz);
}