#include <time.h>
#include "CKappa.cpp"
 
using namespace std;

double srednia(double * czasy)
{
		double sum = 0;
		for (int i = 0; i < 10; i++)
			sum += czasy[i];
		return sum / (double)10;
}

int main()
{
 
 CKappa kappa;
 double times[10];
 char* nazwa;
 nazwa = new char[100];
 clock_t start, koniec;
 cout << "Podaj nazwe pliku: ";
 cin >> nazwa;
 for(int i = 0; i < 10; i++)
 {
 kappa.readFile(nazwa);
 clock_t init, final;
 start = clock();
 kappa.maksPrzeplyw();
 koniec = clock();
 times[i] = (long)(koniec - start);
 }
 cout << "Czas wykonania "<< srednia(times) << endl;
  system("PAUSE");
  
}
