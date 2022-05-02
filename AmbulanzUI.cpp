
/**
(c) Hochschule Heilbronn
Fakultaet fuer Informatik 
Prof. Dr. R. Bendl


Einfuehrung in C++ (Medizinische Informatik Bachelor)

Rudimentaere Rumpfimplementierung einer Applikation
zur Demonstration grundlegender C++ Moeglichkeiten. 

Aus didaktischen Gruenden (reduzierte Komplexitaet
fuer Einsteiger) wurden nicht alle Features optimal 
implementiert. Die Module koennen sukzessive von Studierenden
erweitert und verbessert werden


Realisiert ein Console basiertes Interface

Maintenance Info:
2017-09-25 R. Bendl
Modul erstellt

*/

#include <iostream>
#include <string>

using namespace std;

#include "AmbulanzUI.h"

void AmbulanzUI::ioSchnittstelle(Ambulanz *ambu) {
    int abbruch = 0;
    int aktion = 0;
    PatientenAdmin *pAdm = ambu->getPatientAdmin();

    for (; abbruch == 0;) {
        cout << "Schnittstelle AmbulanzApp " << endl;
        cout << "Patient aufnehmen \t\t\t  1" << endl;
        cout << "Patienten anzeigen \t\t\t  2" << endl;
        cout << "Patient bearbeiten \t\t\t  3" << endl;
        cout << "beenden \t\t\t\t -1" << endl;

        aktion = 0;
        cin >> aktion;

        switch (aktion) {
            case (1): {
                eingabePatientenDaten(ambu);
                break;
            }
            case (2):
                pAdm->zeigePatienten();
                cout << endl;
                break;
            case (3):
                bearbeitePatientenDaten(ambu);
                break;
            case (-1):
                abbruch = true;
                break;

        }
        // loeschen des Eingabepuffers, damit im Fehlerfall keine unendl. Schleife resultiert
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }
}

void AmbulanzUI::eingabePatientenDaten(Ambulanz *ambu) {
    PatientenAdmin *pAdm = ambu->getPatientAdmin();
    string name;
    string vorname;
    std::string Geburtstag = "-";
    std::string Krankenkasse = "-";
    char ok = ' ';
    char buff[100] = "";
    Patient::Geschlecht geschlecht = Patient::Geschlecht::U;

    clearCin();
    cout << "Patient aufnehmen:" << endl;
    cout << "Name:" << endl;
    cin.getline(buff, sizeof(buff), '\n');
    name = buff;
    cout << "Vorname:" << endl;
    cin.getline(buff, sizeof(buff), '\n');
    vorname = buff;

    while ((ok != 'j') && (ok != 'n')) {
        cout << "Patient aufnehmen: \n Name " << name << "\n"
             << " Vorname " << vorname << "\n"
             << " Geschlecht " << Patient::geschlechtToString(geschlecht) << "\n"
             << " Geburtstag " << Geburtstag << "\n"
             << " Krankenkasse " << Krankenkasse << "\n"
             << endl << "OK? (j/n)" << endl;
        cin >> ok;
        if (ok == 'j')
            pAdm->aufnehmenPatient(name, vorname, geschlecht, Geburtstag, Krankenkasse);

        // loeschen des Eingabepuffers, damit im Fehlerfall keine unendl. Schleife resultiert
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }
}

void AmbulanzUI::clearCin() {
    cin.clear();
    cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void AmbulanzUI::bearbeitePatientenDaten(Ambulanz *ambu) {
    PatientenAdmin *pAdmin = ambu->getPatientAdmin();
    Patient *patient;
    char buff[100] = "";
    int id;

    cout << "Geben sie die ID des gewünschten Patienten ein:" << endl;
    cin >> id;

    if (id < 0) {
        cout << "Ungueltige ID!";
        return;
    }

    if (pAdmin->getPatientMitId(id) == nullptr) {
        cout << "Ungueltige ID!";
        return;
    } else {
        patient = pAdmin->getPatientMitId(id);
    }

    bool abbruch = false;
    while (abbruch == false) {
        cout << "Geburtsdatum: \t\t  1" << endl;
        cout << "Krankenkasse: \t\t  2" << endl;
        cout << "Beenden: \t\t   -1" << endl;

        int input = 0;
        cin >> input;

        switch (input) {
            case (1):
                clearCin();
                cout << "Geburtstag: " << endl;
                cin.getline(buff, sizeof(buff), '\n');
                patient->setGeburtstag(buff);
                break;
            case (2):
                clearCin();
                cout << "Krankenkasse: " << endl;
                cin.getline(buff, sizeof(buff), '\n');
                patient->setKrankenkasse(buff);
                break;
            case (-1):
                abbruch = true;
                return;
        }
    }
}





