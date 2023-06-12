#include <iostream>
#include <string>

#include "Credits.h"

using namespace std;

Credits::Credits() {}

Credits::~Credits() {}

void Credits::showCredits() {
    cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
    cout << " Nume si prenume: Mihalache Vlad" << endl;
    cout << " Universitatea: \"Stefan cel Mare\", Suceava" << endl;
    cout << " Facultatea: Inginerie Electrica si Stiinta Calculatoarelor" << endl;
    cout << " Specializarea: Calculatoare" << endl;
    cout << " Anul: II" << endl;
}