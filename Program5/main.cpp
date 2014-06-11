// ******************************************************************************************************/
//                                            Normalne                                                   /
// ******************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <windows.h>
#include <cmath>
// ******************************************************************************************************/
//                                             Boost                                                     /
// ******************************************************************************************************/
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/linear_congruential.hpp>
// ******************************************************************************************************/
//                                Nazwy standardowe i z boost                                            /
// ******************************************************************************************************/
using namespace std;
using namespace boost;
// ******************************************************************************************************/
//                                  Definicja listy sasiedztwa                                           /
// ******************************************************************************************************/
typedef adjacency_list<vecS, vecS, undirectedS> Graph;
typedef boost::erdos_renyi_iterator<boost::minstd_rand, Graph> ERGen;
// ******************************************************************************************************/
//                              Definicja generatora liczb losowych                                      /
// ******************************************************************************************************/
default_random_engine jednostajny;
uniform_int_distribution<int> distribution(1,100);
// ******************************************************************************************************/
//                                     Parametry grafów                                                  /
// ******************************************************************************************************/
int ilosc_wierzcholkow_grafu = 4000;

//double prawdopodobienstwo = 1.0;  // pelny graf
//double prawdopodobienstwo = 3*log(ilosc_wierzcholkow_grafu)/ilosc_wierzcholkow_grafu; // 3*log(n)/n
//double prawdopodobienstwo = pow(ilosc_wierzcholkow_grafu, (-1.0/3.0));  // n^(-1/3)
double prawdopodobienstwo = pow(ilosc_wierzcholkow_grafu, (-1.0/2.0));  // n^(-2/3)
// ******************************************************************************************************/
//                                        Parametry                                                      /
// ******************************************************************************************************/
int liczba_krawedzi;

int liczba_powtorzen = 10;
double wynik_prime;
double wynik_kruskal;
//double* wynik_zbiorczy_prime = new double[liczba_powtorzen];
//double* wynik_zbiorczy_kruskal = new double[liczba_powtorzen];
double wynik_ostateczny_prime = 0;
double wynik_ostateczny_kruskal = 0;
// ******************************************************************************************************/
//                                       Mierzenie czasu                                                 /
// ******************************************************************************************************/
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000.0; // mikrosekundy

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}


// ******************************************************************************************************/
//                                         Prime                                                         /
// ******************************************************************************************************/

struct EdgePrime
{
  int v1,v2,weight;               // Wierzcholki krawedzi, waga krawedzi
};

class QueuePrime
{
  private:
    EdgePrime * Heap;
    int hpos;
  public:
    QueuePrime(int n);
    ~QueuePrime();
    EdgePrime front();
    void push(EdgePrime e);
    void pop();
};

// Definicja obiektu minimalnego drzewa rozpinajacego
//---------------------------------------------------
struct TNodePrime
{
  TNodePrime * next;
  int v,weight;
};

class MSTreePrime
{
  private:
    TNodePrime ** A;                   // Tablica list sasiedztwa
    int Alen;                     // Liczba komorek w tablicy
    int weight;                   // Waga calego drzewa
  public:
    MSTreePrime(int n);
    ~MSTreePrime();
    void addEdgePrime(EdgePrime e);
    TNodePrime * getAList(int n);
    void print();
    void print_do_pliku();
};

// Definicje metod obiektu QueuePrime
//------------------------------

// Konstruktor - tworzy n elementowa tablice heap na kopiec
//---------------------------------------------------------
QueuePrime::QueuePrime(int n)
{
  Heap = new EdgePrime [n];            // Tworzymy tablice
  hpos = 0;                       // Pozycja w kopcu
}

// Destruktor - usuwa kopiec z pamieci
//------------------------------------
QueuePrime::~QueuePrime()
{
  delete [] Heap;
}

// Zwraca krawedz z poczatku kopca
//--------------------------------
EdgePrime QueuePrime::front()
{
  return Heap[0];
}

// Umieszcza w kopcu nowa krawedz i odtwarza strukture kopca
//----------------------------------------------------------
void QueuePrime::push(EdgePrime e)
{
  int i,j;

  i = hpos++;                     // i ustawiamy na koniec kopca
  j = (i - 1) >> 1;               // Obliczamy pozycje rodzica

  // Szukamy miejsca w kopcu dla e

  while(i && (Heap[j].weight > e.weight))
  {
    Heap[i] = Heap[j];
    i = j;
    j = (i - 1) >> 1;
  }

  Heap[i] = e;                    // Krawedz e wstawiamy do kopca
}

// Usuwa korzen z kopca i odtwarza jego strukture
//-----------------------------------------------
void QueuePrime::pop()
{
  int i,j;
  EdgePrime e;

  if(hpos)
  {
    e = Heap[--hpos];

    i = 0;
    j = 1;

    while(j < hpos)
    {
      if((j + 1 < hpos) && (Heap[j + 1].weight < Heap[j].weight)) j++;
      if(e.weight <= Heap[j].weight) break;
      Heap[i] = Heap[j];
      i = j;
      j = (j << 1) + 1;
    }

    Heap[i] = e;
  }
}

// Definicje metod obiektu MSTreePrime
//-------------------------------

// Konstruktor - tworzy tablice pustych list sasiedztwa
//-----------------------------------------------------
MSTreePrime::MSTreePrime(int n)
{
  int i;

  A = new TNodePrime * [n];            // Tworzymy tablice dynamiczna
  for(i = 0; i < n; i++) A[i] = NULL; // i wypelniamy ja pustymi listami
  Alen = n - 1;                   // Zapamietujemy dlugosc tablicy
  weight = 0;                     // Zerujemy wage drzewa
}

// Destruktor - usuwa listy oraz tablice sasiedztwa
//-------------------------------------------------
MSTreePrime::~MSTreePrime()
{
  int i;
  TNodePrime *p,*r;

  for(i = 0; i <= Alen; i++)
  {
    p = A[i];
    while(p)
    {
      r = p;                      // Zapamietujemy wskazanie
      p = p->next;                // Przesuwamy sie do nastepnego elementu listy
      delete r;                   // Usuwamy element
    }
  }

  delete [] A;                    // Usuwamy tablice list sasiedztwa
}

// Dodaje krawedz do drzewa
//-------------------------
void MSTreePrime::addEdgePrime(EdgePrime e)
{
  TNodePrime *p;

  weight += e.weight;             // Do wagi drzewa dodajemy wage krawedzi
  p = new TNodePrime;                  // Tworzymy nowy wezel
  p->v = e.v2;                    // Wierzcholek koncowy
  p->weight = e.weight;           // Waga krawedzi
  p->next = A[e.v1];              // Dodajemy p do listy wierzcholka v1
  A[e.v1] = p;

  p = new TNodePrime;                  // To samo dla krawedzi odwrotnej
  p->v = e.v1;                    // Wierzcholek koncowy
  p->weight = e.weight;           // Waga krawedzi
  p->next = A[e.v2];              // Dodajemy p do listy wierzcholka v2
  A[e.v2] = p;
}

// Zwraca wskaznik poczatku listy sasiadow wierzcholka
//----------------------------------------------------
TNodePrime * MSTreePrime::getAList(int n)
{
  return A[n];
}

// Wyswietla zawartosc drzewa oraz jego wage
//------------------------------------------
void MSTreePrime::print()
{
  int i;
  TNodePrime *p;

  cout << endl;
  for(i = 0; i <= Alen; i++)
  {
    cout << "Vertex " << i << " - ";
    for(p = A[i]; p; p = p->next) cout << p->v << ":" << p->weight << " ";
    cout << endl;
  }
  cout << endl << endl << "Minimal Spanning Tree Weight = " << weight << endl << endl;
}
// ******************************************************************************************************/
//                              Metoda zapisu do pliku w MSTree Prime                                    /
// ******************************************************************************************************/
void MSTreePrime::print_do_pliku()
{
TNodePrime *p;
fstream plik_zapis("C:/Users/S3/Desktop/Boosttest/zapisprime.txt", ios::out); //Users/S3/Desktop/Zaladunekbeta/
int poczatek, koniec, waga;
if (plik_zapis.good()){
for(int i = 0; i <= Alen; i++)
{
    for(p = A[i]; p; p = p->next){
    poczatek = i;
    koniec = p->v;
    waga = p->weight;
    plik_zapis <<  poczatek << " " << koniec << " " << waga << endl;
    }
}
plik_zapis << weight << endl;
plik_zapis.flush();
plik_zapis.close();
}
//cout << " Zapisalem plik prime " << endl;

}



// ******************************************************************************************************/
//                                         Kruskal                                                       /
// ******************************************************************************************************/
// Definicja obiektu kolejki priorytetowej
//----------------------------------------
struct EdgeKruskal
{
  int v1,v2,weight;               // Wierzcholki krawedzi, waga krawedzi
};

class QueueKruskal
{
  private:
    EdgeKruskal * Heap;
    int hpos;
  public:
    QueueKruskal(int n);
    ~QueueKruskal();
    EdgeKruskal front();
    void push(EdgeKruskal e);
    void pop();
};

// Definicja obiektu struktury zbiorow rozlacznych
//------------------------------------------------
struct DSNodeKruskal
{
  int up,rank;
};

class DSStructKruskal
{
  private:
    DSNodeKruskal * Z;
  public:
    DSStructKruskal(int n);
    ~DSStructKruskal();
    void MakeSet(int v);
    int FindSet(int v);
    void UnionSets(EdgeKruskal e);
};

// Definicja obiektu minimalnego drzewa rozpinajacego
//---------------------------------------------------
struct TNodeKruskal
{
  TNodeKruskal * next;
  int v,weight;
};

class MSTreeKruskal
{
  private:
    TNodeKruskal ** A;                   // Tablica list sasiedztwa
    int Alen;                     // Liczba komorek w tablicy
    int weight;                   // Waga calego drzewa
  public:
    MSTreeKruskal(int n);
    ~MSTreeKruskal();
    void addEdgeKruskal(EdgeKruskal e);
    void print();
    void print_do_pliku();
};

// Definicje metod obiektu QueueKruskal
//------------------------------

// Konstruktor - tworzy n elementowa tablice heap na kopiec
//---------------------------------------------------------
QueueKruskal::QueueKruskal(int n)
{
  Heap = new EdgeKruskal [n];            // Tworzymy tablice
  hpos = 0;                       // Pozycja w kopcu
}

// Destruktor - usuwa kopiec z pamieci
//------------------------------------
QueueKruskal::~QueueKruskal()
{
  delete [] Heap;
}

// Zwraca krawedz z poczatku kopca
//--------------------------------
EdgeKruskal QueueKruskal::front()
{
  return Heap[0];
}

// Umieszcza w kopcu nowa krawedz i odtwarza strukture kopca
//----------------------------------------------------------
void QueueKruskal::push(EdgeKruskal e)
{
  int i,j;

  i = hpos++;                     // i ustawiamy na koniec kopca
  j = (i - 1) >> 1;               // Obliczamy pozycje rodzica

  // Szukamy miejsca w kopcu dla e

  while(i && (Heap[j].weight > e.weight))
  {
    Heap[i] = Heap[j];
    i = j;
    j = (i - 1) >> 1;
  }

  Heap[i] = e;                    // Krawedz e wstawiamy do kopca
}

// Usuwa korzen z kopca i odtwarza jego strukture
//-----------------------------------------------
void QueueKruskal::pop()
{
  int i,j;
  EdgeKruskal e;

  if(hpos)
  {
    e = Heap[--hpos];

    i = 0;
    j = 1;

    while(j < hpos)
    {
      if((j + 1 < hpos) && (Heap[j + 1].weight < Heap[j].weight)) j++;
      if(e.weight <= Heap[j].weight) break;
      Heap[i] = Heap[j];
      i = j;
      j = (j << 1) + 1;
    }

    Heap[i] = e;
  }
}

// Definicje metod obiektu DSStructKruskal
//---------------------------------

// Konstruktor
DSStructKruskal::DSStructKruskal(int n)
{
  Z = new DSNodeKruskal [n];             // Tworzymy tablice dla elementow zbiorow
}

// Destruktor
//-----------
DSStructKruskal::~DSStructKruskal()
{
  delete [] Z;                    // Usuwamy tablice ze zbiorami
}

// Tworzy wpis w tablicy Z
//------------------------
void DSStructKruskal::MakeSet(int v)
{
  Z[v].up   = v;
  Z[v].rank = 0;
}

// Zwraca indeks reprezentanta zbioru, w ktorym jest wierzcholek v
//----------------------------------------------------------------
int DSStructKruskal::FindSet(int v)
{
  if(Z[v].up != v) Z[v].up = FindSet(Z[v].up);
  return Z[v].up;
}

// £aczy ze soba zbiory z v i u
//-----------------------------
void DSStructKruskal::UnionSets(EdgeKruskal e)
{
  int ru,rv;

  ru = FindSet(e.v1);             // Wyznaczamy korzen drzewa z wezlem u
  rv = FindSet(e.v2);             // Wyznaczamy korzen drzewa z wezlem v
  if(ru != rv)                    // Korzenie musza byc rozne
  {
    if(Z[ru].rank > Z[rv].rank)   // Porownujemy rangi drzew
      Z[rv].up = ru;              // ru wieksze, dolaczamy rv
    else
    {
      Z[ru].up = rv;              // rowne lub rv wieksze, dolaczamy ru
      if(Z[ru].rank == Z[rv].rank) Z[rv].rank++;
    }
  }
}

// Definicje metod obiektu MSTreeKruskal
//-------------------------------

// Konstruktor - tworzy tablice pustych list sasiedztwa
//-----------------------------------------------------
MSTreeKruskal::MSTreeKruskal(int n)
{
  int i;

  A = new TNodeKruskal * [n];            // Tworzymy tablice dynamiczna
  for(i = 0; i < n; i++) A[i] = NULL; // i wypelniamy ja pustymi listami
  Alen = n - 1;                   // Zapamietujemy dlugosc tablicy
  weight = 0;                     // Zerujemy wage drzewa
}

// Destruktor - usuwa listy oraz tablice sasiedztwa
//-------------------------------------------------
MSTreeKruskal::~MSTreeKruskal()
{
  int i;
  TNodeKruskal *p,*r;

  for(i = 0; i <= Alen; i++)
  {
    p = A[i];
    while(p)
    {
      r = p;                      // Zapamietujemy wskazanie
      p = p->next;                // Przesuwamy sie do nastepnego elementu listy
      delete r;                   // Usuwamy element
    }
  }

  delete [] A;                    // Usuwamy tablice list sasiedztwa
}

// Dodaje krawedz do drzewa
//-------------------------
void MSTreeKruskal::addEdgeKruskal(EdgeKruskal e)
{
  TNodeKruskal *p;

  weight += e.weight;             // Do wagi drzewa dodajemy wage krawedzi
  p = new TNodeKruskal;                  // Tworzymy nowy wezel
  p->v = e.v2;                    // Wierzcholek koncowy
  p->weight = e.weight;           // Waga krawedzi
  p->next = A[e.v1];              // Dodajemy p do listy wierzcholka v1
  A[e.v1] = p;

  p = new TNodeKruskal;                  // To samo dla krawedzi odwrotnej
  p->v = e.v1;                    // Wierzcholek koncowy
  p->weight = e.weight;           // Waga krawedzi
  p->next = A[e.v2];              // Dodajemy p do listy wierzcholka v2
  A[e.v2] = p;
}

// Wyswietla zawartosc drzewa oraz jego wage
//------------------------------------------
void MSTreeKruskal::print()
{
  int i;
  TNodeKruskal *p;

  cout << endl;
  for(i = 0; i <= Alen; i++)
  {
    cout << "Vertex " << i << " - ";
    for(p = A[i]; p; p = p->next) cout << p->v << ":" << p->weight << " ";
    cout << endl;
  }
  cout << endl << endl << "Minimal Spanning Tree Weight = " << weight << endl << endl;
}
// ******************************************************************************************************/
//                                Metoda zapisu do pliku w MSTreeKruskal                                 /
// ******************************************************************************************************/
void MSTreeKruskal::print_do_pliku()
{

TNodeKruskal *p;
fstream plik_zapis("C:/Users/S3/Desktop/Boosttest/zapiskruskal.txt", ios::out); //Users/S3/Desktop/Zaladunekbeta/
int poczatek, koniec, waga;
if (plik_zapis.good()){
for(int i = 0; i <= Alen; i++)
{
    for(p = A[i]; p; p = p->next){
    poczatek = i;
    koniec = p->v;
    waga = p->weight;
    plik_zapis <<  poczatek << " " << koniec << " " << waga << endl;
    }
}
plik_zapis << weight << endl;
plik_zapis.flush();
plik_zapis.close();
}
//cout << " Zapisalem plik kruskal " << endl;

}

// ******************************************************************************************************/
//                                         Funkcje                                                       /
// ******************************************************************************************************/
void wyswietl_vector(vector <int> tab){
vector<int>::iterator it;
for( it=tab.begin(); it!=tab.end(); ++it )  cout<< *it <<'\n';
}

int main(){

boost::minstd_rand gen;
cout << prawdopodobienstwo << endl;
Graph g(ERGen(gen, ilosc_wierzcholkow_grafu, prawdopodobienstwo), ERGen(),ilosc_wierzcholkow_grafu);
cout << " Wygenerowalem krawedzie grafu " << endl;
// ******************************************************************************************************/
//                                                                                                       /
// ******************************************************************************************************/
vector<int> poczatki;
vector<int> konce;
typedef property_map<Graph, vertex_index_t>::type IndexMap;
IndexMap index;
//std::cout << "edges(g) = ";
graph_traits<Graph>::edge_iterator ei, ei_end;
for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei){

poczatki.push_back((index[source(*ei, g)]));
konce.push_back((index[target(*ei, g)]));

//  std::cout << "(" << index[source(*ei, g)]
//            << "," << index[target(*ei, g)] << ") ";
//            std::cout << std::endl;
}
liczba_krawedzi = poczatki.size(); // przypisanie ilosci krawedzi
cout << " Liczba krawedzi " << liczba_krawedzi << endl;
// ******************************************************************************************************/
//                               Modul losujacy wartosci krawedzi                                        /
// ******************************************************************************************************/
vector<int> wartosci_krawedzi;
for (int i = 0; i< liczba_krawedzi;i++){
    wartosci_krawedzi.push_back(distribution(jednostajny));
}
cout << " Wyliczylem wartosci wag dla krawedzi grafu " << endl;
// ******************************************************************************************************/
//                                  Modul zapisujacy do pliku                                            /
// ******************************************************************************************************/
fstream plik_zapis("C:/Users/S3/Desktop/Boosttest/zapis.txt", ios::out); //Users/S3/Desktop/Zaladunekbeta/
if (plik_zapis.good()){
plik_zapis << ilosc_wierzcholkow_grafu << " " << liczba_krawedzi << endl;
for (int i = 0; i<liczba_krawedzi;i++) plik_zapis << poczatki.at(i) << "    " << konce.at(i) << "   " << wartosci_krawedzi.at(i) << endl;
plik_zapis.flush();
plik_zapis.close();
}
cout << " Zapisalem plik " << endl;
// ******************************************************************************************************/
//                                  Modul odczytujacy z  pliku                                           /
// ******************************************************************************************************/
fstream plik_odczyt;
plik_odczyt.open( "C:/Users/S3/Desktop/Boosttest/zapis.txt", ios::in);
if( plik_odczyt.good() == true ) cout << " Plik otworzono pomyslnie - sciezka jest poprawna" << endl;
else cout << " Blad w dostepie do pliku - prawdopodobnie niepoprawna sciezka do pliku" << endl;
// ******************************************************************************************************/
//                                     Pierwsze dwie liczby                                              /
// ******************************************************************************************************/
string linia;
string *rozm_ilosc_str = new string[2];
int liczniczek = 0;
getline(plik_odczyt, linia);
tokenizer<> rozm(linia);
for(tokenizer<>::iterator beg=rozm.begin(); beg!=rozm.end();++beg){
       rozm_ilosc_str[liczniczek]= *beg;
        liczniczek++;
}
int *rozm_ilosc_int = new int[2];
for (int i = 0; i<2;i++){
try {
    rozm_ilosc_int[i] = boost::lexical_cast<int>(rozm_ilosc_str[i]);
} catch( boost::bad_lexical_cast const& ) {
    std::cout << " Error: input string was not valid" << std::endl;
    }
} cout << " Odczytalem parametry grafu " << endl;
// ******************************************************************************************************/
//                                        Pozostale liczby                                               /
// ******************************************************************************************************/
string value;
while ( plik_odczyt.good() )
{
     getline ( plik_odczyt, value, ',' ); // odczyt calego pliku poniewaz ',' nie wystapi
}
 cout << " Odczytalem dane do lancucha tekstowego " << endl;
// ******************************************************************************************************/
//                                Modul wyluskujacy liczby ze stringu                                    /
// ******************************************************************************************************/
    string *tab_stringow = new string[3*rozm_ilosc_int[1]];
int licznik = 0;
tokenizer<> tok(value);
        for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
        //cout << *beg << "\n";
        tab_stringow[licznik] = *beg;
        licznik++;
        }

cout << " Wyluskalem liczby ze stringu " << endl;
// ******************************************************************************************************/
//                                Konwersja string -> integer                                            /
// ******************************************************************************************************/
int *tab_intow = new int[3*rozm_ilosc_int[1]];
for (int i = 0; i<3*rozm_ilosc_int[1]; i++){
try {
    tab_intow[i] = boost::lexical_cast<int>(tab_stringow[i]);
} catch( boost::bad_lexical_cast const& ) {
    std::cout << " Error: input string was not valid" << std::endl;
    }
}
cout << " Przekonwertowalem je do liczb calkowitych" << endl;
/*
for (int i = 0; i< 3*rozm_ilosc_int[1]; i++){
cout << tab_intow[i] << endl;
}
*/

for(int iteracja = 0; iteracja<liczba_powtorzen; iteracja++){
// ******************************************************************************************************/
//                                              Prime                                                    /
// ******************************************************************************************************/

StartCounter();
  int n,m;                        // Liczba wierzcholkow i krawedzi
  EdgePrime e;
  TNodePrime * p;
  int i,v;

 // cin >> n >> m;                  // Czytamy liczbe wierzcholkow i krawedzi

    n = rozm_ilosc_int[0];
    m = rozm_ilosc_int[1];


  QueuePrime Q(m);                     // Kolejka priorytetowa oparta na kopcu
  MSTreePrime T(n);                    // Minimalne drzewo rozpinajace
  MSTreePrime G(n);                    // Graf
  bool * visited = new bool [n];

  for(i = 0; i < n; i++)
    visited[i] = false;           // Inicjujemy tablice odwiedzin

  for(i = 0; i < m; i++)
  {
                                      // Odczytujemy kolejne krawedzie grafu
        e.v1 = tab_intow[i*3];
        e.v2 = tab_intow[(i*3+1)];
        e.weight = tab_intow[(i*3+2)];

    G.addEdgePrime(e);                 // i umieszczamy je w G
  }
  //  cout << " Wczytalem graf " << endl;
  // Tworzymy minimalne drzewo rozpinajace
  v = 0;                          // Wierzcholek startowy
  visited[v] = true;              // Oznaczamy go jako odwiedzonego

  for(i = 1; i < n; i++)          // Do drzewa dodamy n - 1 krawedzi grafu
  {
    for(p = G.getAList(v); p; p = p->next) // Przegladamy liste sasiadow
      if(!visited[p->v])          // Jesli sasiad jest nieodwiedzony,
      {
        e.v1 = v;                 // to tworzymy krawedz
        e.v2 = p->v;
        e.weight = p->weight;
        Q.push(e);                // Dodajemy ja do kolejki priorytetowej
      }

    do
    {
      e = Q.front();              // Pobieramy krawedz z kolejki
      Q.pop();
    } while(visited[e.v2]);       // Krawedz prowadzi poza drzewo?

    T.addEdgePrime(e);                 // Dodajemy krawedz do drzewa rozpinajacego
    visited[e.v2] = true;         // Oznaczamy drugi wierzcholek jako odwiedzony
    v = e.v2;
  }

wynik_prime = GetCounter();
//cout << " Oto wynik algorytmu prime " << wynik_prime << endl;
  // Wyswietlamy wyniki

  // T.print();
  T.print_do_pliku();
  //cout << " Zapisalem wyniki algorytmu prime do pliku " << endl;

  delete [] visited;

// ******************************************************************************************************/
//                                         Kruskal                                                       /
// ******************************************************************************************************/

 StartCounter();
                       // Liczba wierzcholkow i krawedzi
  EdgeKruskal ee;
   n = rozm_ilosc_int[0];
    m = rozm_ilosc_int[1];                 // Czytamy liczbe wierzcholkow i krawedzi

  DSStructKruskal ZZ(n);                  // Struktura zbiorow rozlacznych
  QueueKruskal QQ(m);                     // Kolejka priorytetowa oparta na kopcu
  MSTreeKruskal TT(n);                    // Minimalne drzewo rozpinajace

  for(i = 0; i < n; i++)
    ZZ.MakeSet(i);                 // Dla kazdego wierzcholka tworzymy osobny zbior

  for(i = 0; i < m; i++)
  {
    ee.v1 = tab_intow[i*3];
        ee.v2 = tab_intow[(i*3+1)];
        ee.weight = tab_intow[(i*3+2)];
                                    // Odczytujemy kolejne krawedzie grafu
    QQ.push(ee);                    // i umieszczamy je w kolejce priorytetowej
  }

  for(i = 1; i < n; i++)          // Petla wykonuje sie n - 1 razy !!!
  {
    do
    {
      ee = QQ.front();              // Pobieramy z kolejki krawedz
      QQ.pop();                    // Krawedz usuwamy z kolejki
    } while(ZZ.FindSet(ee.v1) == ZZ.FindSet(ee.v2));
    TT.addEdgeKruskal(ee);                 // Dodajemy krawedz do drzewa
    ZZ.UnionSets(ee);               // Zbiory z wierzcholkami laczymy ze soba
  }
wynik_kruskal = GetCounter();
//cout << " Oto wynik algorytmu kruskala " << wynik_kruskal << endl;
  // Wyswietlamy wyniki
  //TT.print();
  TT.print_do_pliku();
  //cout << " Zapisalem wyniki algorytmu kruskal do pliku " << endl;



wynik_ostateczny_prime+=wynik_prime;
wynik_ostateczny_kruskal+=wynik_kruskal;
cout << " Wynik w iteracji " <<  wynik_prime << " " << wynik_kruskal << endl;
} // TO OD ITERACJI
wynik_ostateczny_prime = wynik_ostateczny_prime/liczba_powtorzen;
wynik_ostateczny_kruskal= wynik_ostateczny_kruskal/liczba_powtorzen;
cout << wynik_ostateczny_prime << " " << wynik_ostateczny_kruskal << endl;

  return 0;


}
