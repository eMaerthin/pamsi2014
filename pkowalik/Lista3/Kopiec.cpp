#include"Kopiec.h"
using namespace std;

Kopiec::Kopiec(){
	K.clear();
}

void Kopiec::Wypelnij(int koniec){
	vector<int> H;
	int i;
	for(i=0; i<koniec; i++) {
		H.push_back(rand()%100);
	}
	for(i=0;  i<koniec; i++) {
		make_heap(H.begin(), H.end());
		K.push_back(H.front());
		sort_heap(H.begin(), H.end());
		H.pop_back();
	}
}

void Kopiec::WypiszKopiec(){
	bool koniec=false;
	int x=1;
	int j=1;
	int i=1;
	int n, d, z;
	int x2;
	vector<int>::iterator it;

	while(!koniec){
		if(K.size()>x){
			x+=x+1;
		}else{
			koniec=true;
		}
	}
	x=x/2;
	for(n=0; n<x; n++){
			cout.width(2);
			cout.fill(' ');
			cout<<' ';
		}

//	cout<<left<<'[';
	cout.width(2);
	cout.fill(' ');
	cout<<right<<K[0];
//	cout<<']';
	for(n=0; n<x; n++){
			cout.width(2);
			cout.fill(' ');
			cout<<' ';
		}
	z=2;
	d=1;
	cout<<endl;
	for(it=K.begin(); it<K.end(); it++){
		if(it==K.begin()){
			it++;
		}
		if(d==1){
			for(n=0; n<x/2; n++){
			cout.width(2);
			cout.fill(' ');
			cout<<' ';
			}
//			cout<<left<<'[';
			cout.width(2);
			cout.fill(' ');
			cout<<right<<K[i];
//			cout<<']';
			i++;
			d++;
		} else {
			if(d==z){
				d=1;
				z=z*2;
				for(n=0; n<x; n++){
					cout.width(2);
					cout.fill(' ');
					cout<<' ';
				}
//				cout<<left<<'[';
				cout.width(2);
				cout.fill(' ');
				cout<<right<<K[i];
//				cout<<']';
				i++;
				x=x/2;
				for(n=0; n<x; n++){
					cout.width(2);
					cout.fill(' ');
					cout<<' ';
				}
				cout<<endl;
				} else {
					for(n=0; n<x; n++){
					cout.width(2);
					cout.fill(' ');
					cout<<' ';
					}
//					cout<<left<<'[';
					cout.width(2);
					cout.fill(' ');
					cout<<right<<K[i];
//					cout<<']';
					i++;
					d++;
				}
		}
		
	}
}

void Kopiec::Wyswietl(){
	int i=0;
	vector<int>::iterator it;
	for(it=K.begin(); it!=K.end(); it++){
		cout<<K[i]<<' ';
		i++;
	}
}

void Kopiec::Usun(){
	K.clear();
}

void Kopiec::pop(){
	if(!K.empty()){
		pop_heap(K.begin(), K.end());
		K.pop_back();
	}
}