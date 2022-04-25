
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

void AmbulanzUI::ioSchnittstelle(Ambulanz *ambu)
 {
  int abbruch = 0;
  int aktion  = 0;
  PatientenAdmin *pAdm = ambu->getPatientAdmin();
  
  for(; abbruch == 0;)
   {
    cout << "Schnittstelle AmbulanzApp " << endl;
    cout << "Patient aufnehmen \t\t\t  1" << endl;
    cout << "Patienten anzeigen \t\t\t  2" << endl;
    cout << "beenden \t\t\t\t -1" << endl;

    aktion = 0;
    cin >> aktion;

    switch(aktion)
     {
      case(1):
       {
        eingabePatientenDaten(ambu);
        break;
       }
      case(2):
        pAdm->zeigePatienten();
        cout << endl;
      break;
      case(-1):
        abbruch = true;
      break;
      
     }
    // loeschen des Eingabepuffers, damit im Fehlerfall keine unendl. Schleife resultiert
    if(cin.fail())
     { 
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
     }
   }
 }

void AmbulanzUI::eingabePatientenDaten (Ambulanz *ambu)
 {
  PatientenAdmin *pAdm = ambu->getPatientAdmin();
  string          name;
  string          vorname;
  char            ok = ' ';
  Patient::Geschlecht geschlecht = Patient::Geschlecht::U;

  cout << "Patient aufnehmen:" << endl;
  cout << "Name:" << endl;
  cin >> name;
  cout << "Vorname:" << endl;
  cin >> vorname;

  while((ok != 'j') && (ok != 'n'))
   {
    cout << "Patient aufnehmen: Name " << name << " Vorname " << vorname
         << " Geschlecht " << Patient::geschlechtToString (geschlecht)
         << endl << "OK? (j/n)" << endl;
    cin >> ok;
    if(ok == 'j') 
      pAdm->aufnehmenPatient(name, vorname, geschlecht);

    // loeschen des Eingabepuffers, damit im Fehlerfall keine unendl. Schleife resultiert
    if(cin.fail())
     { 
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
     }
   }
 }


