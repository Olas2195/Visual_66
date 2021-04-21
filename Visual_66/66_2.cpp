#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

public class Trojki {
    ifstream plik;
    vector <int> liczby;

public:
    string wynik="";

    Trojki(string name) {
        plik.open(name);
    }

    void wczytaj() {
        int x;
        while(!plik.eof()) {
            for(int i = 0; i <= 2; i++) {
                plik >> x;
                liczby.push_back(x);
            }
            this->sprawdzanie();
            liczby.clear();
        }
    }

    void sprawdzanie() {
        bool pierwsze  = true;

        for(int i=0; i<=1; i++) {
            for(int j=2; j<liczby[i]; j++) {
                if(liczby[i]%j == 0) {
                    pierwsze = false;
                }
            }
        }
        if(pierwsze) {
            if(liczby[0]*liczby[1] == liczby[2]) {
                for(int i=0; i<=2; i++) {
                    wynik += to_string(liczby[i]) + " ";
                }
                wynik += "\n";
            }
        }
    }

    string wypisz() {
        return wynik;
    }

    ~Trojki() {
        plik.close();
    }
};