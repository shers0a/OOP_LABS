#include <iostream>
#include <cmath>

class Punct{
    public:
        Punct(double x = 0, double y = 0) : x(x), y(y){}
        
        double getX() const{
            return this -> x;
        }

        double getY() const{
            return this -> y;
        }

        void setX(double x){
            this -> x = x;
        }

        void setY(double y){
            this -> y = y;
        }

        inline double distantaOrigine(){
            return sqrt(x * x + y * y);
        }

        friend double distanta(Punct a, Punct b);
        friend Punct* mijloc(Punct a, Punct b);

    private:
        double x, y;

    };
    
double distanta(Punct a, Punct b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Punct* mijloc(Punct a, Punct b){
    return new Punct((a.x + b.x) / 2, (a.y + b.y) / 2);
}
int main(){
    return 0;
}