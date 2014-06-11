#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <vector>
#include<algorithm>
#include<string>
#include <windows.h>

#define MX 100000
using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}


int main()
{

 int ** A,n,i,j;
 int v1,v2,w;
 double k=0,K=0;

int odwiedzone[MX];
int waga[MX];
int nastepnik[MX];
int wiersz,wierzcholki,cost;
vector <pair< int,pair<int,int> > > vec;


cout << "ile bedzie wieszcholkow? :";
 cin >> n;
cout<<endl;
for(int gu=0;gu<100;gu++)
{
  StartCounter();
 A = new int * [n];
 for(i = 0; i < n; i++)
 {
    A[i] = new int [n];
 }


for(i=0; i < n; i++  )
{
nastepnik[i]=odwiedzone[i]=0;
waga[i]=MX;
for(int r=0; r < n; r++  )
    {
A[i][r]=-1;
    }
}
ifstream dane("extra.txt");

       while(!dane.eof())
        {
        dane>>v1>>v2>>w;
        A[v1][v2]= A[v2][v1] = w;

               }
               dane.close();
wiersz=1;
waga[wiersz]=0;
wierzcholki=1;
odwiedzone[wiersz]=1;


while(wierzcholki!=n)
{
for(i=0;i<n;i++)
{
if(A[wiersz][i]>=0)
{
if(odwiedzone[i]==0)
{
if(waga[i]>A[wiersz][i])
{
waga[i]=A[wiersz][i];
}
}
}
}

cost=MX;
for(i=0;i<n;i++)
{
if(odwiedzone[i]==0)
{
if(waga[i]<cost)
{
cost=waga[i];
wiersz=i;
}
}
}

odwiedzone[wiersz]=1;
wierzcholki++;
}

cost=0;
for(i=0;i<n;i++)
{
cost+=waga[i];
}
 if (gu==0){
cout<<"MST Prim: "<<cost<<"\n";}

for(i = 0; i < n; i++) delete [] A[i];
 delete [] A,odwiedzone,waga,nastepnik;
 k+=GetCounter();
}
K=k/100;
cout<<"Czas dla Prim MST: "<<setprecision(2)<<fixed<< K <<"ms"<<endl;
 return 0;
}
