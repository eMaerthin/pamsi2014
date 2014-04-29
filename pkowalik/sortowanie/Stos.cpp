#include"Stos.h"

void Stos::push(__int64 x){
	S.push(x);
}

void Stos::pop(){
	if(!empty()){
		S.pop();
	}
}

__int64 Stos::top(){
	return S.top();
}

bool Stos::empty(){
	return S.empty();
}

__int64 Stos::srednia(){
	__int64 x=0;
	int size;
	size=S.size();
	while(!empty()){
		x+=top();
		pop();
	}
	return x/size;
}

void Stos::clear(){
	while(!S.empty()){
		S.pop();
	}
}