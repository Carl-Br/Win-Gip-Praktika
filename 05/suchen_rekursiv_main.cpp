// Datei: suchen_rekursiv_main.cpp

#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <string>

using namespace std;

//#include "suchen_rekursiv.h"
//diese Methode sollte eigentlich in einer anderen Datei sein. siehe unten

int zeichenkette_suchen_rekursiv(
string text, string zkette,
size_t text_pos = 0,
size_t text_such_pos = 0,
size_t zkette_such_pos = 0)
{
    //if durchgelaufen oder text von anfang an leer
    if(((text_pos+text_such_pos)>text.length()-1)||text.length()==0){

        return -1;
    }
    //if Zeichen gleich
    if(text.at(text_pos+text_such_pos)==zkette.at(zkette_such_pos)){

        //if letztes zeichen return startzahl
        if(zkette.length()-1==zkette_such_pos){
            return text_pos;
        }
        //else
        return zeichenkette_suchen_rekursiv(text,zkette,text_pos,text_such_pos+1,zkette_such_pos+1);
    }
    //else erhöhe die text_pos um 1
    return zeichenkette_suchen_rekursiv(text,zkette,text_pos+1,0,0);
}

int main()
{
    //Catch::Session().run();
	
    // Ihr Code ab hier ...
    cout<<"Bitte geben Sie den Text ein: ";
    string text;
    getline(cin,text);

    cout<<"Bitte geben Sie die zu suchende Zeichenkette ein: ";
    string zkette;
    getline(cin,zkette);

    int rueckgabe = zeichenkette_suchen_rekursiv(text,zkette);//alle anderen Werte sind default 0

    if(rueckgabe==-1){
        cout<<"Die Zeichenkette '"<<zkette<<"' ist NICHT in dem Text '"<<text<<"' enthalten."<<endl;
    }else{
        cout<<"Die Zeichenkette '"<<zkette<<"' ist in dem Text '"<<text<<"' enthalten."<<endl
        <<"Sie startet ab Zeichen "<<rueckgabe<<" (bei Zaehlung ab 0)."<<endl;
    }

    system("pause");
    return 0;
}

/*
    // Datein suche_rekursiv.cpp
#include <iostream>
using namespace std;

int zeichenkette_suchen_rekursiv(
string text, string zkette,
size_t text_pos = 0,
size_t text_such_pos = 0,
size_t zkette_such_pos = 0
){return -1;}





// Datein suche_rekursiv.h
#pragma once
#include <string>;

int zeichenkette_suchen_rekursiv(
string text="", string zkette="",
size_t text_pos = 0,
size_t text_such_pos = 0,
size_t zkette_such_pos = 0);





// Datei: test_suchen_rekursiv.cpp

#include "catch.h"
#include "suchen_rekursiv.h"

TEST_CASE("Zeichenkette suchen, Text mit Laenge groesser 1, Zeichenkette mit Laenge groesser 1") {
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "cda") == 2);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "de") == 7);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "dex") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "xyz") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "abcdabcd") == 0);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "abcdabcdx") == -1);
}

TEST_CASE("Zeichenkette suchen, Text mit Laenge groesser 1, Zeichenkette mit Laenge 1") {
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "a") == 0);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "c") == 2);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "e") == 8);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "x") == -1);
}

TEST_CASE("Zeichenkette suchen, Text mit Laenge 1") {
	REQUIRE(zeichenkette_suchen_rekursiv("a", "a") == 0);
	REQUIRE(zeichenkette_suchen_rekursiv("a", "c") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("a", "xy") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("a", "aa") == -1);
}

TEST_CASE("Zeichenkette suchen, leerer Text") {
	REQUIRE(zeichenkette_suchen_rekursiv("", "a") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("", "abc") == -1);
}

TEST_CASE("Zeichenkette suchen, Text mit Laenge 20 Zeichen") {
	REQUIRE(zeichenkette_suchen_rekursiv("abcdefghij1234567890", "90") == 18);
	REQUIRE(zeichenkette_suchen_rekursiv("12345678901234567890", "90") == 8);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdefghij1234567890", "9012") == -1);
}

TEST_CASE("Zeichenkette suchen, langer Prefix") {
	REQUIRE(zeichenkette_suchen_rekursiv("aaaaaaabcdef", "aaabcd") == 4);
}


// Vorgegebene Testl�ufe m�ssen selbst als Testcases programmiert werden ...
TEST_CASE("Vorgegebene Testlaeufe") {

	REQUIRE(zeichenkette_suchen_rekursiv("abcdefg","bcd99")==-1);
	REQUIRE(zeichenkette_suchen_rekursiv("xy abc abcdefgh","abcde")==7);
	REQUIRE(zeichenkette_suchen_rekursiv("xyz 123 456 abc","123 4")==4);
	REQUIRE(zeichenkette_suchen_rekursiv("abc defg","abc d")==0);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdefg","efg")==4)

}

*/