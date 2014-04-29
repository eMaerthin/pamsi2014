/*Program sluzacy do pomiarow czasu wykonywania algorytmow sortujacych.
	Zamieszczone algorytmy sortowania:
		-sortowanie babelkowe
		-sortowanie przez kopcowanie
		-sortowanie przez wstawianie
		-sortowanie szybkie
		*/
#include <random>
#include <iostream>
#include <boost/progress.hpp>
using namespace std;

	default_random_engine generator;
	uniform_int_distribution<int> jednostajny(0,100);
	normal_distribution<double> normalny(50.0, 20.0);
	poisson_distribution<int> poisson(50);

void sortowanie_przez_kopcowanie(int* tab, int rozmiar)
{
	int i,j,k,m,x,tmp;
	for(int i=0; i<rozmiar; i++)
	{
		j=i; k=j/2;
		x=tab[i];
		while((k>0)&&(tab[k]<x))
		{
			tab[j]=tab[k];
			j=k; k=j/2;
		}
		tab[j]=x;
	}
	for(int i=rozmiar-1; i>0; i--)
	{
		tmp=tab[1];
		tab[1]=tab[i];
		tab[i]=tmp;
		j=1; k=2;
		while(k<i)
		{
			if((k+1<i)&&(tab[k+1]>tab[k]))
			m=k+1;
			else
			m=k;
			if(tab[m]<=tab[j])
			break;
			tmp=tab[j];
			tab[j]=tab[m];
			tab[m]=tmp;
			j=m; k=j+j;
		}
	}
}

void sortowanie_babelkowe(int* tab, int rozmiar)
{
	int tmp;
    int n=rozmiar;
    do
    {
         for(int i=0; i<n; i++)
         {
                 if(tab[i]>tab[i+1])
                 {
                    tmp=tab[i];
                    tab[i]=tab[i+1];
                    tab[i+1]=tmp;              
                 }
         }
         n=n-1;
    }
         while(n>1);
}

void sortowanie_przez_wstawianie(int* tab, int rozmiar)
{
	int tmp,i,j;
	for(i=1; i<rozmiar; i++)
	{
		tmp=tab[i];
		for(j=i-1;j>=0&&tab[j]>tmp; j--)
		{
			tab[j+1]=tab[j];
		}
		tab[j+1]=tmp;
	}
}

void sortowanie_szybkie(int* tab, int l, int p)
{
	int i, j, rozdzielajacy;
	rozdzielajacy=tab[(l+p)>>1];
	i=l;
	j=p;
	do
	{
		while(tab[i]<rozdzielajacy)
		i++;
		while(tab[j]>rozdzielajacy)
		j--;
		if(i<=j)
		{
			int tmp=tab[i];
			tab[i]=tab[j];
			tab[j]=tmp;
			i++;
			j--;
		}
	}
	while(i<j);
	if(l<j)
	sortowanie_szybkie(tab, l, j);
	if(p>i)
	sortowanie_szybkie(tab, i, p);
}


/*Funkcja odpowiadajaca za wypelnianie tabeli wedlug podanych zalozen.
	Parametrami wejsciowymi fukncki sa:
		-rozmiar tablicy
		-typ - odpowiada za ilosc posortowanych elementow
		-rozklad - rozklad na podstawie ktorego losowane sa elementy
		*/	
int* wypelnij(int rozmiar, int typ, int rozklad)
{
	int* tab=new int[rozmiar];
	float ile;
	if(rozklad==0)
		for(int i=0; i<rozmiar; i++)
		tab[i]=jednostajny(generator);
	if(rozklad==1)
		for(int i=0; i<rozmiar; i++)
		tab[i]=normalny(generator);
	if(rozklad==2)
		for(int i=0; i<rozmiar; i++)
		tab[i]=poisson(generator);
	if(typ==0)
		ile=0;
	if(typ==1)
		ile=0.1;
	if(typ==2)
		ile=0.5;
	if(typ==3)
		ile=0.9;		
	sortowanie_szybkie(tab,0,(ile*rozmiar-1));
	return tab;				
}



void wyswietl(int* T, int rozmiar)
{
	for(int i=0; i<rozmiar; i++)
	cout<<T[i]<<" ";
	cout<<"\n";
}



int main()
{
	int ilosc,rozklad,typ,n=100; //n-ilosc powtorzen eksperymentu
	int * T;
	char wybor='y';
	float czas1=0,czas2=0,czas3=0,czas4=0;
	do
	{
	cout<<"Wybierz ilosc elementow\n";
	cin>>ilosc;
	cout<<"Wybierz rozklad\n0-jednostajny\n1-normalny\n2-Poissona\n";
	cin>>rozklad;
	cout<<"Wybierz typ tablicy\n0-tablica nieuporzadkowana\n1-10% posortowane\n2-50% posortowane\n3-90% posortowane\n";
	cin>>typ;
	for(int i=0; i<n; i++)
	{
	T=wypelnij(ilosc,typ,rozklad);
	boost::timer t2;
	sortowanie_przez_kopcowanie(T,ilosc);
	czas4+=t2.elapsed();
	}
    cout<<"1.Sortowanie przez kopcowanie:\nSredni czas obliczony dla "<<n<<" powtorzen wynosi: "<<czas4/n<<" s.\n";
    for(int i=0; i<n; i++)
	{
	T=wypelnij(ilosc,typ,rozklad);
	boost::timer t2;
	sortowanie_przez_wstawianie(T,ilosc);
	czas2+=t2.elapsed();
	}
    cout<<"2.Sortowanie przez wstawianie:\nSredni czas obliczony dla "<<n<<" powtorzen wynosi: "<<czas2/n<<" s.\n";
	for(int i=0; i<n; i++)
	{
	T=wypelnij(ilosc,typ,rozklad);
	boost::timer t3;
	sortowanie_szybkie(T,0,ilosc-1);
	czas3+=t3.elapsed();
	}
    cout<<"3.Sortowanie szybkie:\nSredni czas obliczony dla "<<n<<" powtorzen wynosi: "<<czas3/n<<" s.\n";
	for(int i=0; i<n; i++)
	{
	T=wypelnij(ilosc,typ,rozklad);
	boost::timer t1;
	sortowanie_babelkowe(T,ilosc);
	czas1+=t1.elapsed();
	}
    cout<<"4.Sortowanie babelkowe:\nSredni czas obliczony dla "<<n<<" powtorzen wynosi: "<<czas1/n<<" s.\n";
    cout<<"Czy powtorzyc eksperyment? (y/n)\n";
    cin>>wybor;
	}while(wybor!='n');
    
    



}

	
	
	
	
	
	
	
	
	
