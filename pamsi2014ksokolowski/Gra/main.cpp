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

	// rozmiary g³ównego okna programu
	glutInitWindowSize(_w, _h);

	// utworzenie g³ównego okna programu
	wind = glutCreateWindow("Double Snake");

	// do³¹czenie funkcji generuj¹cej scenê 3D
	glutDisplayFunc(Display);

	// do³¹czenie funkcji obs³ugi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeys); //Strzalek

	// utworzenie menu podrêcznego
	glutCreateMenu(Menu);

	glutAddMenuEntry("Wyjscie", EXIT1); //Dodanie opcji do menu podrecznego

	// okreœlenie przycisku myszki obs³uguj¹cej menu podrêczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// podczas zadnej akcji w peli bedzie wykonywana funkcja 'bezczynnosc'
	glutIdleFunc(bezczynnosc);

	// wprowadzenie programu do obs³ugi pêtli komunikatów
	glutMainLoop();

	return 0;
}