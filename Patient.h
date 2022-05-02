#pragma once

#include <string>
#include "Person.h"

class Patient : public Person {
public:
    // es ist effizienter, die Datenelemente in einer Initialisierungsliste
    // zu initialisieren (nach dem Doppelpunkt) als im Rumpf der Methode
    // 
    Patient(int id, std::string name, std::string vorname, Person::Geschlecht geschlecht, std::string geburtstag,
            std::string krankenkasse)
            : Person(name, vorname, geschlecht, geburtstag) {
        ID = letzeID;
        letzeID++;
        this->krankenkasse = krankenkasse;
    }

    Patient(const Patient &p) {
        ID = p.ID;
        arzt = p.arzt;
        krankenkasse = p.krankenkasse;
    }

    ~ Patient() {};

    Patient() {};

    int getID() { return ID; }

    const std::string &getKrankenkasse() const;

    void setKrankenkasse(const std::string &krankenkasse);


private:
    int ID;
    Person arzt;
    std::string krankenkasse;
    static int letzeID;
};
