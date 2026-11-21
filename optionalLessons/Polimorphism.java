package OOP_LABS.optionalLessons;


class Animal{
    public void sunet(){
        System.out.println("...");
    }
}

class Caine extends Animal{
    public void sunet(){
        System.out.println("ham");
    }
}

public class Polimorphism {
    /*
        2 tipuri pentru fiecare variabila:

        care dintre cele 2 tipuri conteaza aici?

    */

    Animal a = new Caine();

    a.sunet();
}
