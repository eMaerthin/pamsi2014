//#include <GL/glut.h>
#include "funkcje_ekranowe.h"

using namespace std;

extern Postac gracz, komputer;
extern int wind; //Nr okna

int main(int argc, char * argv[])
{
	gracz.dodajPrzeciwnika(&komputer); //Dodajemy przeciwnika graczowi

	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// rozmiary g��wnego okna programu
	glutInitWindowSize(_w, _h);

	// utworzenie g��wnego okna programu
	wind = glutCreateWindow("Double Snake");

	// do��czenie funkcji generuj�cej scen� 3D
	glutDisplayFunc(Display);

	// do��czenie funkcji obs�ugi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeys); //Strzalek

	// utworzenie menu podr�cznego
	glutCreateMenu(Menu);

	glutAddMenuEntry("Wyjscie", EXIT1); //Dodanie opcji do menu podrecznego

	// okre�lenie przycisku myszki obs�uguj�cej menu podr�czne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// podczas zadnej akcji w peli bedzie wykonywana funkcja 'bezczynnosc'
	glutIdleFunc(bezczynnosc);

	// wprowadzenie programu do obs�ugi p�tli komunikat�w
	glutMainLoop();

	return 0;
}