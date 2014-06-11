#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <vector>
#include<algorithm>
#include<string>
#include <windows.h>
//W celu zmiany grafu nalezy zmienic nazwe pliku badz edytowac plik z ktorego czytamy , w primie to samo.
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

int findSet(int x,int * parent)
{
    if (parent[x]==x)return x;
    parent[x] = findSet(parent[x],parent);
    return parent [x];
}



int main()
{
 int ** A,n,i,j;
 int v1,v2,waga;
int parent [1001];
int cost = 0;
double k=0,K=0;





vector <pair< int,pair<int,int> > > vec;
vector <pair< int,pair<int,int> > > MST;
string ilosc;




cout << "ile bedzie wieszcholkow? :";
 cin >> n;
cout<<endl;

for(int gu=0;gu<100;gu++)
{
 StartCounter();

 A = new int * [n];

 for(i = 0; i < n; i++) A[i] = new int [n];


 for(i = 0; i < n; i++)
   for(j = 0; j < n; j++) A[i][j] = 0;


        ifstream dane("extra.txt");
while(!dane.eof())
{
dane>>v1>>v2>>waga;
A[v1][v2]= A[v2][v1] = waga;
vec.push_back((make_pair( waga, make_pair(v1,v2) )));
}
dane.close();



ofstream plik("maciez.txt", ios::trunc);
for(i = 0; i < n; i++)
{
 plik << endl <<setw(2) << i << ":";
   for(j = 0; j < n; j++) {
   plik << setw(2) << A[i][j];

   }
}
plik.close();


 for(i = 0; i < n; i++) delete [] A[i];
 delete [] A;



sort(vec.begin(),vec.begin() + vec.size());



for( i=1; i<=n; i++)
    {
        parent[i] = i;
    }
 for( i=0; i<vec.size(); i++)
    {
        int pu = findSet(vec[i].second.first,parent);
        int pv = findSet(vec[i].second.second,parent);
        if(pu!=pv)
        {
            cost+=vec[i].first;
            MST.push_back(vec[i]);
            parent[pu] = parent[pv];
        }
    }
    if (gu==0){
        cout<<"Kruskal MST: "<<cost<<"\n";}
    k+=GetCounter(); //STOP
    vec.clear();
    MST.clear();


}

K=k/100;


    cout<<"Czas dla Kruskal MST: "<<setprecision(2)<<fixed<< K <<"ms"<<endl;

 return 0;
}
