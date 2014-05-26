#include <iomanip>
#include <iostream>
#include <random>
	
const int n=5000;
using namespace std;


	default_random_engine generator;
	uniform_int_distribution<int> jednostajny(0,100);
	normal_distribution<double> normalny(50.0, 20.0);
	poisson_distribution<int> poisson(50);
 
class kopiec
{
public:
int tablica[n];
int rozmiar;

kopiec()
{
rozmiar = 0;
}


void dodaj_element(int a)
{
	tablica[rozmiar+1] = a;
	int r = rozmiar+1;
	while(r!=1) 
	{
		if(tablica[r/2] < tablica[r])
		{
			swap(tablica[r/2],tablica[r]);r/=2;
		}
		else
			break;
	}
	rozmiar++;
}



int usun_korzen()
{
	int korzen;
	korzen=tablica [1];
tablica[1] = tablica[rozmiar];
rozmiar--;
int tmp = 1;
while(tmp*2 <= rozmiar)
{
	if(tablica[tmp] < tablica[tmp*2] || tablica[tmp] < tablica[tmp*2+1]) 
	{
		if(tablica[tmp*2] > tablica[tmp*2+1] || tmp*2+1 > rozmiar) 
			{
				swap(tablica[tmp],tablica[tmp*2]);
				tmp=tmp*2;
			}
		else
			{
				swap(tablica[tmp],tablica[tmp*2+1]);
				tmp=tmp*2+1;
			}
	}
	else
	break;
}
return korzen;
}





void wyswietl()
{
	int i, j, k, x;
  	x = (rozmiar + 1) / 2; k = 2;
  	for(i = 1; i <= rozmiar; i++)
  	{
    	for(j = 1; j < x; j++)
			cout <<" ";
    	cout << tablica[i];
    	for(j = 1; j <= x; j++)
			cout <<" ";
    	if(i + 1 == k)
    	{
      		k += k;
			x /= 2;
			cout <<"\n";
    	}
  	}
  	cout<<"\n";
}


};
 

 



int main()
{
	kopiec k;
	int rozmiar,rozklad;
	cout<<"Podaj wielkosc kopca\n";
	cin>>rozmiar;
	cout<<"Wybierz rozklad losowanych elementow:\n0-Jednostajny\n1-Normalny\n2-Poissona\n";
	cin>>rozklad;
	
	if(rozklad==0)
		for(int i=0; i<rozmiar; i++)
		k.dodaj_element(jednostajny(generator));
	if(rozklad==1)
		for(int i=0; i<rozmiar; i++)
		k.dodaj_element(normalny(generator));
	if(rozklad==2)
		for(int i=0; i<rozmiar; i++)
		k.dodaj_element(poisson(generator));
	k.wyswietl();
	k.usun_korzen();
	k.wyswietl();

}
 
