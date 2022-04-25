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

Klasse PatientenAdmin

Klasse verwaltet die Patientendaten und stellt Funktionen
zur Manipulation der Daten zur Verfuegung

Maintenance Info:
2017-09-25 R. Bendl
Modul erstellt

*/

#pragma once

#include "Patient.h"

class PatientenAdmin
  {
  public:
    PatientenAdmin() 
      {
      patienten            = NULL;
      anzahlPatienten      = 0;
      laengePatientenArray = 0;
      arrayIncrement       = 1;
      initialisiert        = false;
      }
    ~PatientenAdmin() 
      {
      if(patienten) delete[] patienten;
      }
    void start ();
    void aufnehmenPatient (std::string name, std::string vorname, Person::Geschlecht geschlecht);
    void zeigePatienten ();
    Patient** erweitereArray();
    Patient** erweitereArrayNew();

  private:
    int       initialisiert;
    int       anzahlPatienten;
    int       laengePatientenArray;
    int       arrayIncrement;
    Patient** patienten;
  };
