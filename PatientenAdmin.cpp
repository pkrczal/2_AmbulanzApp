// Standard Includes
#include <iostream>

using namespace std;

// Eigene Includes
#include "PatientenAdmin.h"

void PatientenAdmin::start() {
    if (!initialisiert) {
        // anlegen Patienten-Array oder andere sinnvolle Verwaltungsstrukturen
        initialisiert = true;
        patienten = new Patient *[arrayIncrement]();
        laengePatientenArray = arrayIncrement;
    }
    // weitere Initialisierungen
    // z.B. Einlesen exisitierender Patienten aus externem Speicher ...
}

void PatientenAdmin::aufnehmenPatient(std::string name, std::string vorname, Person::Geschlecht geschlecht) {
    if (!initialisiert) start();
    if (anzahlPatienten < laengePatientenArray) {
        int id = 0;
        Patient *pat = new Patient(id, name, vorname, geschlecht, "Test");
        patienten[anzahlPatienten] = pat;
        anzahlPatienten++;
    } else {
        patienten = erweitereArray();
        int id = 0;
        Patient *pat = new Patient(id, name, vorname, geschlecht, "Test");
        patienten[anzahlPatienten] = pat;
        anzahlPatienten++;
    }
}

Patient **PatientenAdmin::erweitereArrayNew() {
    arrayIncrement++;
    Patient **buffer;
    buffer = patienten;
    Patient **neueListe = new Patient *[arrayIncrement]();
    for (int i = 0; i < arrayIncrement; i++) {
        neueListe[i] = (*buffer);
        buffer++;
    }
    delete[] patienten;
    laengePatientenArray++;
    return neueListe;
}

Patient **PatientenAdmin::erweitereArray() {
    arrayIncrement++;
    Patient **buffer;
    buffer = new Patient *[arrayIncrement]();
    for (int i = 0; i < laengePatientenArray; i++) {
        buffer[i] = patienten[i];
    }
    delete[] patienten;
    laengePatientenArray = arrayIncrement;
    return buffer;
}

void PatientenAdmin::zeigePatienten() {
    cout << "Patienten:" << endl;
    cout << "Name" << "\t\t\t" << "Vorname" << "\t\t\t" << "Geschlecht" << "\t\t\t" << "ID" << endl;

    for (int i = 0; i < anzahlPatienten; i++) {
        Patient *pat = patienten[i];
        cout << pat->getName()
        << "\t\t\t"
        << pat->getVorname()
        << "\t\t\t"
        << pat->getGeschlecht()
        << "\t\t\t"
        << pat->getID()
        << endl;
    }
}

