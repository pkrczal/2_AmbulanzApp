//
// Created by Paul Krczal on 25.04.22.
//
#include "Patient.h"

int Patient::letzeID = 0;

const std::string &Patient::getKrankenkasse() const {
    return krankenkasse;
}

void Patient::setKrankenkasse(const std::string &krankenkasse) {
    Patient::krankenkasse = krankenkasse;
}

