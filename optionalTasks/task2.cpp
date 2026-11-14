#include <iostream>
#include <vector>

class Motor{
    private:
        int putere;
};


class Roata{
    public:
        static int id;
};

int Roata::id = 0;

class Masina{
    public:

    private:
        Motor motor;
        std::vector<Roata> roti = std::vector<Roata>(4);
};

int main(){

    return 0;
}