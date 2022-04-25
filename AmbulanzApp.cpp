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


Erstellt Ambulanz-Objekte und liefert Schnittstelle um Daten 
ein und auszugeben

Maintenance Info:
2017-09-25 R. Bendl
Modul erstellt

*/

#include <iostream>
using namespace std;

#include "Ambulanz.h"
#include "AmbulanzUI.h"

int main (int argc, char**argv)
  {
   Ambulanz *ambu = new Ambulanz();
   AmbulanzUI *ui = new AmbulanzUI();

   ui->ioSchnittstelle(ambu);
   return 0;
  }