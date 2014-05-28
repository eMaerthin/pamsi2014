#include <iostream>
#include <cmath>
#include "CKruskal.cpp"

using namespace std;

double logP(int n)
{
	return 3 * log(n) / log(2) / ((double)n);
}
double asdp(int n)
{
	return pow(n, (-1 / 3.0));
}
double sqrtP(int n)
{
	return  pow(n, (-1 / 2.0));
}

int main()
{
	CKruskal* k = new CKruskal();
	int n = 1;
	
	//k->readGraphM();
	//cout << k->DFS(8);
	//k->showGraph(k->convert(k->randomGraph(10, 0.5f)));
	//cout << "----------------------" << endl;
	//k->showGraph(k->minTree(15));
	//CKruskal* k = new CKruskal();
	int n1 = 500, n2 = 1000, n3 = 2000, n4 = 4000;
	int p = 1;
	
	/*cout << "Kruskal" << endl;
	cout << "time: " << (double)k->liczKruskal(10, n1, logP(n1)) << "ms dla n = " << n1 << endl;
	cout << "time: " << (double)k->liczKruskal(10, n2, logP(n2)) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczKruskal(n, n3, logP(n3)) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczKruskal(n, n4, logP(n4)) << "ms dla n =" << n4 << endl;;
	cout << "time: " << (double)k->liczKruskal(10, n1, asdp(n1)) << "ms dla n =" << n1 << endl;;
	cout << "time: " << (double)k->liczKruskal(10, n2, asdp(n2)) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczKruskal(n, n3, asdp(n3)) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczKruskal(n, n4, asdp(n4)) << "ms dla n =" << n4 << endl;;
	cout << "time: " << (double)k->liczKruskal(10, n1, sqrtP(n1)) << "ms dla n =" << n1 << endl;;
	cout << "time: " << (double)k->liczKruskal(10, n2, sqrtP(n2)) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczKruskal(n, n3, sqrtP(n3)) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczKruskal(n, n4, sqrtP(n4)) << "ms dla n =" << n4 << endl;
	cout << "time: " << (double)k->liczKruskal(10, n1, 1) << "ms dla n =" << n1 << endl;;
	cout << "time: " << (double)k->liczKruskal(10, n2, 1) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczKruskal(n, n3, 1) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczKruskal(n, n4, 1) << "ms dla n =" << n4 << endl;
	cout << "________________________________" << endl;
	cout << endl;*/
	cout << "Prim" << endl;
	cout << "time: " << (double)k->liczPrime(1, n1, logP(n1)) << "ms dla n =" << n1 << endl;
	cout << "time: " << (double)k->liczPrime(10, n2, logP(n2)) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczPrime(n, n3, logP(n3)) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczPrime(n, n4, logP(n4)) << "ms dla n =" << n4 << endl;;
	cout << "time: " << (double)k->liczPrime(10, n1, asdp(n1)) << "ms dla n =" << n1 << endl;;
	cout << "time: " << (double)k->liczPrime(10, n2, asdp(n2)) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczPrime(n, n3, asdp(n3)) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczPrime(n, n4, asdp(n4)) << "ms dla n =" << n4 << endl;;
	cout << "time: " << (double)k->liczPrime(10, n1, sqrtP(n1)) << "ms dla n =" << n1 << endl;;
	cout << "time: " << (double)k->liczPrime(10, n2, sqrtP(n2)) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczPrime(n, n3, sqrtP(n3)) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczPrime(n, n4, sqrtP(n4)) << "ms dla n =" << n4 << endl;
	cout << "time: " << (double)k->liczPrime(10, n1, 1) << "ms dla n =" << n1 << endl;;
	cout << "time: " << (double)k->liczPrime(10, n2, 1) << "ms dla n =" << n2 << endl;;
	cout << "time: " << (double)k->liczPrime(n, n3, 1) << "ms dla n =" << n3 << endl;;
	//cout << "time: " << (double)k->liczPrime(n, n4, 1) << "ms dla n =" << n4 << endl;
	cout << "time: " << (double)k->liczPrime(n, n4, logP(n4)) << "ms dla n =" << n4 << endl;
	cout << "time: " << (double)k->liczKruskal(n, n4, 1) << "ms dla n =" << n4 << endl;

	system("pause");
	return 0;

}