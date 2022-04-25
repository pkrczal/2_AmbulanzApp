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

Maintenance Info:
2017-09-25 R. Bendl
Modul erstellt

*/

#pragma once

#include <string>
#include <map>

class Person {
public:
    enum Geschlecht {
        M = 1, W = 2, U = 0
    };

    static std::string geschlechtToString(Geschlecht g) { return geschlechtMap[g]; }

    Person(std::string name, std::string vorname, Geschlecht geschlecht, std::string geburtstag) {
        this->name = name;
        this->vorname = vorname;
        this->geschlecht = geschlecht;
        this->Geburtstag = geburtstag;
    }

    virtual ~Person() {}

    const std::string &getName() const;

    const std::string &getVorname() const;

    const std::string &getGeburtstag() const;

    std::string getGeschlecht() {
        return geschlechtMap[geschlecht];
    }

    Person() {};
private:
    std::string name;
    std::string vorname;
    Geschlecht geschlecht;
    std::string Geburtstag;

    static std::map<Geschlecht, std::string> geschlechtMap;

};
