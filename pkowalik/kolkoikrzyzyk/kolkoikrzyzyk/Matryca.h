#include<iostream>
#include <msclr/marshal_cppstd.h>
#include"pole.h"
#include<cmath>
class Matryca{
public:
	int wolnych;
	pole ostatni;
	pole matrix[4][4][4];
	pole* szablon[76][4];
//Metody
	Matryca();
	Matryca(const Matryca & M);
	Matryca & operator=(const Matryca & M);
	bool Wygrana(System::String^ gamer);
	bool Wygrana(char gracz);
	vector<pole*> Wygrana1(System::String^ gamer);
	bool Pelny();
	void Add(int x, int y, int z, System::String^ gamer);
	void Add(int x, int y, int z, char gracz);
	void WypelnijSzablon();
	int Analizuj(char znak);
};

Matryca::Matryca(){
	pole p;
	wolnych=64;
	ostatni.get(-1, -1, -1, '-');
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				p.get(i, j, k, '-');
				matrix[i][j][k]=p;
			}
		}
	}
	for(int i=0; i<76; i++){
		for(int j=0; j<4; j++){
			szablon[i][j]=new pole;
		}
	}
	WypelnijSzablon();
}

void Matryca::WypelnijSzablon(){
	int x=0;
	int y=0;

	for(int k=0; k<4; k++){
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				szablon[x][y%4]=&matrix[i][j][k];
				y++;
			}
			x++;
		}
	}
	for(int k=0; k<4; k++){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				szablon[x][y%4]=&matrix[i][j][k];
				y++;
			}
			x++;
		}
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				szablon[x][y%4]=&matrix[i][j][k];
				y++;
			}
			x++;
		}
	}


	for(int i=0; i<4; i++){
		for(int f=0; f<4; f++){
			szablon[x][y%4]=&matrix[i][f][f];
			y++;
		}
		x++;
	}
	for(int i=0; i<4; i++){
		for(int f=0; f<4; f++){
			szablon[x][y%4]=&matrix[i][f][3-f];
			y++;
		}
		x++;
	}
	for(int j=0; j<4; j++){
		for(int f=0; f<4; f++){
			szablon[x][y%4]=&matrix[f][j][f];
			y++;
		}
		x++;
	}
	for(int j=0; j<4; j++){
		for(int f=0; f<4; f++){
			szablon[x][y%4]=&matrix[f][j][3-f];
			y++;
		}
		x++;
	}
	for(int k=0; k<4; k++){
		for(int f=0; f<4; f++){
			szablon[x][y%4]=&matrix[f][f][k];
			y++;
		}
		x++;
	}
	for(int k=0; k<4; k++){
		for(int f=0; f<4; f++){
			szablon[x][y%4]=&matrix[3-f][f][k];
			y++;
		}
		x++;
	}


	for(int f=0; f<4; f++){
		szablon[x][y%4]=&matrix[f][f][f];
		y++;
	}
	x++;
	for(int f=0; f<4; f++){
		szablon[x][y%4]=&matrix[3-f][f][3-f];
		y++;
	}
	x++;
	for(int f=0; f<4; f++){
		szablon[x][y%4]=&matrix[f][f][3-f];
		y++;
	}
	x++;
	for(int f=0; f<4; f++){
		szablon[x][y%4]=&matrix[3-f][f][f];
		y++;
	}
}

Matryca::Matryca(const Matryca& M){
	wolnych=M.wolnych;
	ostatni=M.ostatni;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				matrix[i][j][k]=M.matrix[i][j][k];
			}
		}
	}
}

Matryca& Matryca::operator=(const Matryca& M){
	wolnych=M.wolnych;
	ostatni=M.ostatni;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				matrix[i][j][k]=M.matrix[i][j][k];
			}
		}
	}
	return *this;
}

bool Matryca::Wygrana(System::String^ gamer){
	std::string gracz=msclr::interop::marshal_as< std::string >(gamer);
	int iloscznacznika=0;

	for(int x=0; x<76; x++){
		for(int y=0; y<4; y++){
			if(szablon[x][y]->znacznik==gracz[0]){
				iloscznacznika++;
			}
		}
		if(iloscznacznika==4){
			return true;
		} else {
			iloscznacznika=0;
		}
	}
	return false;
}

bool Matryca::Wygrana(char gracz){
		int iloscznacznika;
		for(int x=0; x<76; x++){
		for(int y=0; y<4; y++){
			if(szablon[x][y]->znacznik==gracz){
				iloscznacznika++;
			}
		}
		if(iloscznacznika==4){
			return true;
		} else {
			iloscznacznika=0;
		}
	}
	return false;
}

vector<pole*> Matryca::Wygrana1(System::String^ gamer){
		std::string gracz=msclr::interop::marshal_as< std::string >(gamer);
		int iloscznacznika;
		for(int x=0; x<76; x++){
		for(int y=0; y<4; y++){
			if(szablon[x][y]->znacznik==gracz[0]){
				iloscznacznika++;
			}
		}
		if(iloscznacznika==4){
			vector<pole*> vec;
			vec.clear();
			for(int i=0; i<4; i++){
				vec.push_back(szablon[x][i]);
			}
			return vec;
		} else {
			iloscznacznika=0;
		}
	}
}

bool Matryca::Pelny(){
	for(int k=0; k<4; k++){
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				if(matrix[i][j][k].znacznik=='-'){
					return false;
				}
			}
		}
	}
	return true;
}

void Matryca::Add(int x, int y, int z, System::String^ gamer){
	std::string gracz=msclr::interop::marshal_as< std::string >(gamer);
	wolnych--;
	ostatni.get(x, y, z, gracz[0]);

	matrix[x][y][z]=ostatni;
}

void Matryca::Add(int x, int y, int z, char gracz){
	wolnych--;
	ostatni.get(x, y, z, gracz);

	matrix[x][y][z]=ostatni;
}

int Matryca::Analizuj(char znak){
	int ty=0;
	int przeciw=0;
	int zysk=0;
	int strata=0;

	for(int x=0; x<76; x++){
		ty=0;
		przeciw=0;
		for(int y=0; y<4; y++){
			if((*szablon[x][y])==przeciwnik(znak)){
				przeciw+=1;
			}
			if((*szablon[x][y])==znak){
				ty+=1;
			}
		}
		if(ty>0 && przeciw>0){
			ty=0;
			przeciw=0;
		} else {
			if(ty==4){
				return (numeric_limits<int>::max)();
			}
			if(przeciw==3){
				return (numeric_limits<int>::min)()+1;
			}
			strata+=przeciw*przeciw*5;
			zysk+=ty;
		}
	}
	return zysk-strata;
}