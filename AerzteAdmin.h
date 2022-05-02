//
// Created by Paul Krczal on 02.05.22.
//

#ifndef INC_2_AMBULANZAPP_AERZTEADMIN_H
#define INC_2_AMBULANZAPP_AERZTEADMIN_H

#include "Arzt.h"
#include "vector"

#pragma once

class AerzteAdmin {

public:
    AerzteAdmin() {
        anzahlAerzte = 0;
    }

    ~AerzteAdmin() {
        for (Arzt *a: aerzte) {
            delete a;
        }
    }

    AerzteAdmin(AerzteAdmin &a) : anzahlAerzte(a.anzahlAerzte) {}

    void aufnehmenArzt(std::string titel, std::string name, std::string vorname, Person::Geschlecht geschlecht,
                       std::string Geburtstag, std::string fach, std::string telefonNummer);

    Arzt *getArztMitId(int id);

    void zeigeAerzte();

private:
    std::vector<Arzt *> aerzte;
    int anzahlAerzte;
};


#endif //INC_2_AMBULANZAPP_AERZTEADMIN_H
