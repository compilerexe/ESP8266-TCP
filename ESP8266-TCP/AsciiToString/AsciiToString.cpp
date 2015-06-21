#include "AsciiToString.h"

AsciiToString::AsciiToString() {

}

void AsciiToString::getString(int ascii) {

	switch (ascii) {

        case 13 : this->message = word; 
                  this->word = ""; 

                break;
        case 32 : this->word += " "; break;
        case 33 : this->word += "!"; break;
        case 34 : this->word += '"'; break;
        case 35 : this->word += "#"; break;
        case 36 : this->word += "$"; break;
        case 37 : this->word += "%"; break;
        case 38 : this->word += "&"; break;
        case 39 : this->word += "'"; break;
        case 40 : this->word += "("; break;
        case 41 : this->word += ")"; break;
        case 42 : this->word += "*"; break;
        case 43 : this->word += "+"; break;
        case 44 : this->word += ","; break;
        case 45 : this->word += "-"; break;
        case 46 : this->word += "."; break;
        case 47 : this->word += "/"; break;

        case 48 : this->word += "0"; break;
        case 49 : this->word += "1"; break;
        case 50 : this->word += "2"; break;
        case 51 : this->word += "3"; break;
        case 52 : this->word += "4"; break;
        case 53 : this->word += "5"; break;
        case 54 : this->word += "6"; break;
        case 55 : this->word += "7"; break;
        case 56 : this->word += "8"; break;
        case 57 : this->word += "9"; break;

        case 58 : this->word += ":"; break;
        case 59 : this->word += ";"; break;
        case 60 : this->word += "<"; break;

        case 61 : this->word += "="; break;
        case 62 : this->word += ">"; break;
        case 63 : this->word += "?"; break;
        case 64 : this->word += "@"; break;

        case 65 : this->word += "A"; break;
        case 66 : this->word += "B"; break;
        case 67 : this->word += "C"; break;
        case 68 : this->word += "D"; break;
        case 69 : this->word += "E"; break;
        case 70 : this->word += "F"; break;
        case 71 : this->word += "G"; break;
        case 72 : this->word += "H"; break;
        case 73 : this->word += "I"; break;
        case 74 : this->word += "J"; break;
        case 75 : this->word += "K"; break;
        case 76 : this->word += "L"; break;
        case 77 : this->word += "M"; break;
        case 78 : this->word += "N"; break;
        case 79 : this->word += "O"; break;
        case 80 : this->word += "P"; break;
        case 81 : this->word += "Q"; break;
        case 82 : this->word += "R"; break;
        case 83 : this->word += "S"; break;
        case 84 : this->word += "T"; break;
        case 85 : this->word += "U"; break;
        case 86 : this->word += "V"; break;
        case 87 : this->word += "W"; break;
        case 88 : this->word += "X"; break;
        case 89 : this->word += "Y"; break;
        case 90 : this->word += "Z"; break;
        
        case 97 : this->word += "a"; break;
        case 98 : this->word += "b"; break;
        case 99 : this->word += "c"; break;
        case 100 : this->word += "d"; break;
        case 101 : this->word += "e"; break;
        case 102 : this->word += "f"; break;
        case 103 : this->word += "g"; break;
        case 104 : this->word += "h"; break;
        case 105 : this->word += "i"; break;
        case 106 : this->word += "j"; break;
        case 107 : this->word += "k"; break;
        case 108 : this->word += "l"; break;
        case 109 : this->word += "m"; break;
        case 110 : this->word += "n"; break;
        case 111 : this->word += "o"; break;
        case 112 : this->word += "p"; break;
        case 113 : this->word += "q"; break;
        case 114 : this->word += "r"; break;
        case 115 : this->word += "s"; break;
        case 116 : this->word += "t"; break;
        case 117 : this->word += "u"; break;
        case 118 : this->word += "v"; break;
        case 119 : this->word += "w"; break;
        case 120 : this->word += "x"; break;
        case 121 : this->word += "y"; break;
        case 122 : this->word += "z"; break;

        case 123 : this->word += "{"; break;
        case 124 : this->word += "|"; break;
        case 125 : this->word += "}"; break;
        case 126 : this->word += "~"; break;
    }
}

void AsciiToString::clear() {
    this->message = "";
}