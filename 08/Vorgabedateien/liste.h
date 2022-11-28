// Datei: liste.h

#pragma once

#include <string>

struct TListenKnoten
{
    int data;
    TListenKnoten *next;
};

std::string liste_als_string(TListenKnoten* anker);

void hinten_anfuegen(TListenKnoten*& anker, const int wert);
