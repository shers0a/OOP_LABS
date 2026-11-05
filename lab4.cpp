#include <iostream>
#include <vector>
#include <string>
#include <ostream>

/*
    basically ne arata cum sa lucram cu .hpp si .cpp
    stiu asta deja dar tot trebuie explicat:

    pur si simplu:
        in .hpp se afla header ul clasei
        in .cpp se afla toate implementarile metodelor + constructorilor + destructorilor

    in clion se creeaza:
    #ifndef P01_DUMMYCLASS_HPP
    #define P01_DUMMYCLASS_HPP

    #endif //P01_DUMMYCLASS_HPP

    daca n am avea garda asta s ar compila de doua ori acelasi lucru
    e gen pragma once
*/

class DummyClass{
    public:
        DummyClass(){
            std::cout << "DummyClass::DummyClass()" << std::endl;
        }

        DummyClass(int dummyInt, float dummyFloat) : dummyInt(dummyInt), dummyFloat(dummyFloat){}
        
        ~DummyClass(){
            std::cout << "DummyClass::~DummyClass()";
        }

        void printInfo() const{
            std::cout << "DummyClass::printInfo()" << std::endl;
            std::cout << "dummyInt: " << this -> dummyInt << std::endl;
            std::cout << "dummyFloat: " << this -> dummyFloat << std::endl;
        }

    private:
        int dummyInt;
        float dummyFloat;
};


/*
    exercitiu:
    sa se implementeze un catalog pentru clasele de elevi dintr o scoala
    catalogul va stoca 3 medii finale, de la materiile pe care elevii le studiaza
    elevii usnt identificati dupa nr matricol. 
    acestia au nume prenume clasa dar si un field
    setat automat prin care se identifica ciclul de studii curent:
    -PRIMAR
    -GIMNAZIAL
    -LICEAL

    sa se:
        stocheze elevi in catalog
        calculeze media finala a fiecarui elev
        filtreze elevii care apartin unui ciclu de studii dat
            -daca nu exista se va afisa un mesaj coresp
        afiseze datele unui elev dupa un numar matricol dat
            -daca elevul nu exista, se va afisa un mesaj
            -se va afisa si media finala:
                -daca media este sub 5, se afiseaza mesajul REPETENT
                - altfel, se afiseaza mesajul PROMOVAT
*/

class Elev{
    public:
        Elev(const std::string& nume, const std::string& prenume, int clasa, const std::vector<double>& medii) :
            nume(nume), prenume(prenume), clasa(clasa), medii(medii){
                nr_matricol_local = ++nr_matricol;
                
                if(clasa >= 0 && clasa <= 4)
                    ciclu = ciclu_studii::PRIMAR;
                else if( clasa >= 5 && clasa <= 8)
                    ciclu = ciclu_studii::GIMNAZIAL;
                else if( clasa >= 9 && clasa <= 12)
                    ciclu = ciclu_studii::LICEAL;
                else{
                    std::cout << "nu mai e in scoala";
                }
            }

        Elev(){
            nr_matricol_local = ++nr_matricol;
        }            
        
        enum class ciclu_studii{PRIMAR, GIMNAZIAL, LICEAL};
        
        void calcul_medie(){
            if(medii.size() != 3)
                medie = -1;

            double result = 0;
            
            for( auto const& x : medii){
                result += x;
            }

            medie = (result / 3);
        }
        
        ciclu_studii getCiclu() const{
            return ciclu;
        }
        
        int getNrMat() const{
            return nr_matricol_local;
        }

        friend std::ostream& operator<<(std::ostream& os, const Elev& elev){
            os << "ELEV: " << " " <<  elev.nume << " " << elev.prenume << " " << elev.clasa << " " << static_cast<int>(elev.ciclu);
            os << "\n";

            for(auto& medie : elev.medii){
                os << medie << " ";
            }
            
            os << elev.medie << "\n";

            if( elev.medie >= 5 )
                os << "PROMOVAT";
            else
                os << "REPETENT";

            return os;
        }
        
        friend std::istream& operator>>(std::istream& is, Elev& elev ){
            is >> elev.nume >> elev.prenume >> elev.clasa;

            for( int i = 0; i < 3; i++ ){
                double x;
                is >> x;
                elev.medii.push_back(x);
            }

            if(elev.clasa >= 0 && elev.clasa <= 4)
                    elev.ciclu = ciclu_studii::PRIMAR;
                else if( elev.clasa >= 5 && elev.clasa <= 8)
                    elev.ciclu = ciclu_studii::GIMNAZIAL;
                else if( elev.clasa >= 9 && elev.clasa <= 12)
                    elev.ciclu = ciclu_studii::LICEAL;
                else{
                    std::cout << "nu mai e in scoala";
                }

            return is;
        }

    private:
        std::string nume, prenume;
        
        int nr_matricol_local;
        static int nr_matricol;

        ciclu_studii ciclu;

        int clasa;
        double medie;

        std::vector<double> medii;
};

class Catalog{
    public:
        Catalog(const std::vector<Elev>& elevi) : elevi(elevi){}
        
        Catalog() = default;

        friend std::ostream& operator<<(std::ostream& os, const Catalog& cat){
            for( auto const& elev : cat.elevi){
                os << "==========================\n";
                os << elev << "\n";
            }
            
            return os;
        }

        void adauga_elev(const Elev& elev){
            elevi.push_back(elev);
        }

        void citeste_elev(){
            Elev elev;
            std::cin >> elev;

            elevi.push_back(elev);
        }
        
        void calculeaza_medii(){
            for( auto& elev : elevi ){
                elev.calcul_medie();
            }
        }
        
        void filtruCiclu(Elev::ciclu_studii ciclu){
            for(auto const& elev : elevi){
                if(elev.getCiclu() == ciclu){
                    std::cout << elev << "\n";
                }
            }
        }
        
        void afisFiltruNrMat(int nr){
            for( auto const& elev : elevi){
                if( elev.getNrMat() == nr ){
                    std::cout << elev << "\n";
                }
            }
        }
    private:
        std::vector<Elev> elevi;
};

int Elev::nr_matricol = 0;

int main(int argc, char* argv[]){
    
    Catalog catalog;
    catalog.citeste_elev();
    catalog.calculeaza_medii();
    
    catalog.filtruCiclu(Elev::ciclu_studii::PRIMAR);
    catalog.afisFiltruNrMat(2);
    
    return 0;
}