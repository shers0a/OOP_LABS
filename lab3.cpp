#include <iostream>

/*
    struct urile si class ele ambele pot avea functii.
    e mai ok sa folosim clase deoarece ne ofera cocneptul de incapsulare si se salveaza pe heap, nu pe stack
        => eficientizam memoria.
*/

union DummyUnion{
    int dummyInt;
    char dummyChar;
};

struct DummyStruct{
    int dummyInt;
    float dummyFloat;

    void dummyPrint(){
        std::cout << "dummy\n";
    }
};

class DummyClass{
    public:
        void dummyPrint(){
            std::cout << "dummy\n";
        }

        //la this se foloseste "->" deoarece te referi la instanta unei clase deci dereferentiaza
        //asta e un constructor
        
        DummyClass(int dummyInt, float dummyFloat){
            this -> dummyInt = dummyInt;
            this -> dummyFloat = dummyFloat;
        }
    private:
        int dummyInt;
        float dummyFloat;
};

int main(int argc, char** args){
    
    return 0;
}