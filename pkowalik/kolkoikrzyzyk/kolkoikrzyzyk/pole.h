#include<limits>
using namespace std;
class pole{
public:
	int x;
	int y;
	int z;
	char znacznik;
//Metody
	pole();
	pole(const pole & X);
	pole & operator=(const pole & X);
	pole & operator=(const char X);
	bool operator==(pole X);
	void get(int i, int j, int k, char znak);
	bool operator==(char znak);
};

pole::pole(){
	x=-1;
	y=-1;
	z=-1;
	znacznik='-';
}

pole::pole(const pole& X){
	x=X.x;
	y=X.y;
	z=X.z;
	znacznik=X.znacznik;
}

pole & pole::operator=(const pole & X){
	x=X.x;
	y=X.y;
	z=X.z;
	znacznik=X.znacznik;
	return *this;
}

pole & pole::operator=(const char X){
	znacznik=X;
	return *this;
}

bool pole::operator==(pole X){
	if(x==X.x && y==X.y && z==X.z){
		return true;
	} else {
		return false;
	}
}

void pole::get(int i, int j, int k, char znak){
	this->x=i;
	this->y=j;
	this->z=k;
	this->znacznik=znak;
}

bool pole::operator==(char znak){
	if(znacznik==znak){
		return true;
	} else {
		return false;
	}
}

char przeciwnik(char znak){
	if(znak=='O'){
		return 'X';
	} else {
		return 'O';
	}
}