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

Klasse Person

Allgemeine Basisklasse fuer Personendaten in der Applikation
In einem Person-Objekt werden Name, Vorname ... eines
Patienten gespeichert.

Da die bisherigen Methoden nur Minimalfunktionalit�t aufweisen,
sind sie direkt im .h-File implementiert. Sie koennen dann ggfls.
durch den Compiler z.B. als inline-Funktionen optimiert werden

In der initialen Fassung ist im cpp Modul nur die Klassenvariable
geschlechtMap implementiert. Die Klassenvariable dient als Lookup-
Table, um Elemente der Enumeration Geschlecht in strings umzuwandeln.
Die Funktionalitaet ist deshalb nicht an ein Objekt gebunden. Sie wird
von der Klasse zur Verfuegung gestellt.

Klassen- und Membervariablen koennen in C++ nicht bei der Deklaration 
initialisiert werden. Die Initialisierung einer Klassenvariablen im 
Konstruktor einer Methode macht keinen Sinn. Deshalb muss sie in der
cpp-Datei initialisiert werden.

Die Variable geschlechtMap ist in der Header-Datei nicht als Pointer
auf eine Map definiert worden sondern nur als Map, d.h. man muss sie
nicht mit new erzeugen (koennte man, wird hier aber nicht getan).
Der Wert der Map (die Schluessel-Werte-Paare), werden der Map direkt
zugewiesen.


Maintenance Info:
2017-09-25 R. Bendl
Modul erstellt

*/

#include <string>
#include <map>

using namespace std;
#include "Person.h"

std::map<Person::Geschlecht, std::string> Person::geschlechtMap =  {
    {Person::Geschlecht::M, "maenlich"},
    {Person::Geschlecht::W, "weiblich"},
    {Person::Geschlecht::U, "unbekannt"}};

const std::string &Person::getName() const {
    return name;
}

const std::string &Person::getVorname() const {
    return vorname;
}

const std::string &Person::getGeburtstag() const {
    return Geburtstag;
}
  
