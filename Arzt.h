#pragma once

#include "Person.h"

class Arzt : public Person {
public:
    Arzt(std::string titel, std::string name, std::string vorname, Person::Geschlecht geschlecht,
         std::string Geburtstag, std::string fach, std::string telefonNummer) : Person(name,
                                                                                       vorname,
                                                                                       geschlecht,
                                                                                       Geburtstag), titel(titel),
                                                                                fach(fach), telefon(telefonNummer) {};

    ~Arzt() {};

    const std::string &getTitel() const {
        return titel;
    }

    const std::string &getFach() const {
        return fach;
    }

    const std::string &getTelefon() const {
        return telefon;
    }

private:
    std::string titel;
    std::string fach;
    std::string telefon;

    Arzt() {}
};
