cmake_minimum_required(VERSION 3.21)
project(2_AmbulanzApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2_AmbulanzApp
        Ambulanz.cpp
        Ambulanz.h
        AmbulanzApp.cpp
        AmbulanzUI.cpp
        AmbulanzUI.h
        Arzt.h
        Patient.h
        PatientenAdmin.cpp
        PatientenAdmin.h
        Person.cpp
        Person.h Patient.cpp Arzt.cpp AerzteAdmin.cpp AerzteAdmin.h)
