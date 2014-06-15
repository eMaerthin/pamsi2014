#include <stdlib.h>
#include <Windows.h>
#include "funkcje_ekranowe.h"

// wpolrzedne kwadratu
Postac gracz("Gracz", Wspolrzedne(-10, 0), 10, DOL, 1.0, 0.0, 1.0);
Postac komputer("Komputer", Wspolrzedne(10, 0), 10, GORA, 0.5, 1.0, 0.25, true, &gracz);

GLdouble xx = 0, yy = 0;
int wind; //zapamietanie nr okna

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
void Display()
{
	// kolor t³a - zawartoœæ bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru
	glClear(GL_COLOR_BUFFER_BIT);

	rysujPlansze();

	gracz.wyswietlPostac();
	komputer.wyswietlPostac();

	// skierowanie poleceñ do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}
///////////////////////////////////////////////////////////////////////////////////////
void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		gracz.skrec_w(LEWO);
		break;

		// kursor w górê
	case GLUT_KEY_UP:
		gracz.skrec_w(GORA);
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		gracz.skrec_w(PRAWO);
		break;

		// kursor w dó³
	case GLUT_KEY_DOWN:
		gracz.skrec_w(DOL);
		break;

	case GLUT_KEY_F1: //Pauza
		_getch();
		break;

	default:
		break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
void Menu(int value)
{
	switch (value)
	{
	case EXIT1:
		exit(0);
		break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
void bezczynnosc()
{
	static int licznik = 0;

	if (licznik++ % 5 == 0) {
		gracz.wydluz_ogon();
		komputer.wydluz_ogon();
	}

	gracz.wykonaj_ruch();
	if (gracz.czyKolizja()) {
		wypiszZwyciezceIZakonczGre("Komputer");
		_getch();
		exit(0);
	}
	Display();

	komputer.wykonaj_ruch();
	if (komputer.czyKolizja()) {
		wypiszZwyciezceIZakonczGre("Gracz");
		_getch();
		exit(0);
	}
	Display();
}
///////////////////////////////////////////////////////////////////////////////////////
void rysujPlansze()
{
	GLfloat wymiar = 1 - jeden_piksel * 12;
	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex3f(-1.00, 1.00, 0.00); glVertex3f(1.00, 1.00, 0.00);
	glVertex3f(1.00, wymiar, 0.00); glVertex3f(-1.00, wymiar, 0.00);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-1.00, -1.00, 0.00); glVertex3f(1.00, -1.00, 0.00);
	glVertex3f(1.00, -wymiar, 0.00); glVertex3f(-1.00, -wymiar, 0.00);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-1.00, -1.00, 0.00); glVertex3f(-1.00, 1.00, 0.00);
	glVertex3f(-wymiar, 1.00, 0.00); glVertex3f(-wymiar, -1.00, 0.00);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1.00, -1.00, 0.00); glVertex3f(1.00, 1.00, 0.00);
	glVertex3f(wymiar, 1.00, 0.00); glVertex3f(wymiar, -1.00, 0.00);
	glEnd();
}
///////////////////////////////////////////////////////////////////////////////////////
void wypiszZwyciezceIZakonczGre(const std::string& nazwa)
{
	string tekst("Zwyciezyl: " + nazwa + "!!!");
	ofstream plik("Log", ios::app);
	
	plik << nazwa[0] << endl;

	boost::this_thread::sleep(boost::posix_time::milliseconds(5000));
	glutDestroyWindow(wind);

	cout << string(79, '*') << endl
		<< "*" << string(77, ' ') << "*" << endl
		<< string(40 - tekst.length() / 2, ' ') << tekst << string(39 - tekst.length() / 2, ' ')
		<< "*" << string(77, ' ') << "*" << endl
		<< string(79, '*') << endl;
}