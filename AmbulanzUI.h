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

#pragma once

#include "Ambulanz.h"

class AmbulanzUI {
public:
    AmbulanzUI() {};

    ~AmbulanzUI() {};

    void eingabePatientenDaten(Ambulanz *ambu);

    void ioSchnittstelle(Ambulanz *ambu);

    void bearbeitePatientenDaten(Ambulanz *ambu);

    void clearCin();
};
