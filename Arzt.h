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

Klasse Arzt

In einem Arzt-Objekt werden Name, Vorname, Fach ... eines
Arztes gespeichert.

Maintenance Info:
2017-09-25 R. Bendl
Modul erstellt

*/

#pragma once

#include "Person.h"

class Arzt : public Person
  {
  public:
    Arzt (std::string name, std::string vorname, Person::Geschlecht geschlecht) : Person (name, vorname, geschlecht) {};
    ~Arzt () {};
  private:
    std::string titel;
    std::string fach;
    std::string telefon;
    Arzt () {}
  };
