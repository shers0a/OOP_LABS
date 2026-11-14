# Task-uri POO – Cursurile 3 și 4

Scrii tot de la zero: clasele, `main`-ul și testele. Fiecare task are cerințele și, la final, ce trebuie să demonstreze `main`-ul tău.

Compilare recomandată:
```bash
g++ -Wall -Wextra -fsanitize=address -g task1.cpp -o t1 && ./t1
```
`-fsanitize=address` te prinde imediat dacă ai double free, memory leak sau acces în afara memoriei.

**Reguli generale** (pentru toate task-urile):
- datele membre sunt `private`
- fără `struct` pentru clase
- fără `std::vector` și `std::string` acolo unde scrie „alocat dinamic”, ca să exersezi `new`/`delete`
- fiecare constructor și destructor afișează un mesaj scurt (`"C Fractie"`, `"D Fractie"`) **doar la task-urile marcate cu 🔍**, ca să vezi ordinea apelurilor

---

## Task 1 – `Punct` (încălzire)
Material exersat: constructori, `this`, inline, funcții prieten.

- `Punct` cu coordonatele `x` și `y` (`double`)
- un singur constructor, cu valori implicite, care să acopere `Punct()`, `Punct(3)` și `Punct(3, 4)`
- getteri și setteri, definiți **inline implicit** (în clasă)
- funcția membru `distantaOrigine()`, definită **explicit inline**, în afara clasei
- funcția **prieten** `double distanta(Punct a, Punct b)`
- funcția **prieten** `Punct mijloc(Punct a, Punct b)`

**`main` trebuie să arate:** creare în toate cele 3 moduri, distanța dintre două puncte și mijlocul lor.

---

## Task 2 – 🔍 Ordinea constructorilor și destructorilor
Material exersat: ordinea apelurilor, obiecte membre, obiecte globale, transmitere prin valoare și prin referință.

- clasa `Motor`, cu un `int putere`
- clasa `Roata`, cu un `int id`
- clasa `Masina`, care conține **un `Motor` și 4 obiecte `Roata`** (un tablou)
- toate clasele afișează mesaje din constructori, constructorul de copiere și destructor
- o `Masina` globală
- funcțiile `void inspectieValoare(Masina m)` și `void inspectieReferinta(Masina& m)`

**`main` trebuie să arate:** creezi o mașină, apelezi ambele funcții și compari ordinea mesajelor. Scrie în comentariu, **înainte să rulezi**, ce crezi că se afișează, apoi verifică.

---

## Task 3 – `Fractie`
Material exersat: supraîncărcarea operatorilor (membru și prieten), prefix/postfix, membri statici.

- numărătorul și numitorul se simplifică automat (cu cmmdc); numitorul e mereu pozitiv, iar numitorul 0 e interzis (afișezi o eroare)
- constructori: `Fractie()` = 0/1, `Fractie(int)` = n/1, `Fractie(int, int)`
- `+ - * /` și `== != <` ca funcții **prieten**, ca să meargă și `2 + f`, și `f + 2`
- `+= -= *= /=` ca funcții **membru**, care întorc `*this`
- `++` și `--` în formă prefix și postfix
- un membru **static** `nrObiecte`, care arată câte fracții există **acum** în memorie, și o funcție statică care îl întoarce
- `operator<<` pentru afișare (`cout << f;`)

**`main` trebuie să arate:**
- toate operațiile, inclusiv `int + Fractie`
- diferența dintre `f++` și `++f`
- `nrObiecte` înainte de un bloc `{ }`, în interiorul lui (după ce creezi fracții acolo) și după el

---

## Task 4 – 🔍 `Sir` (string propriu)
Material exersat: memorie dinamică, constructor de copiere, `operator=`, destructor, `operator[]`.

- membrii: `char* s` și `int lungime`
- constructori: `Sir()` (șir gol), `Sir(const char*)`, constructor de copiere (**copie profundă**)
- destructor
- `operator=`, care tratează auto-atribuirea `a = a;`
- `operator[]` care întoarce `char&`, cu verificare de limite
- `operator+` (concatenare), `operator+=`, `operator==`
- `operator<<` și `operator>>`

**`main` trebuie să arate:**
- copierea: modifici copia, iar originalul rămâne neschimbat
- transmiterea unui `Sir` prin valoare unei funcții, fără crash
- o funcție care **întoarce** un `Sir` prin valoare
- `a = a;` fără probleme
- rularea cu `-fsanitize=address` fără erori

---

## Task 5 – `Matrice` alocată dinamic
Material exersat: memorie dinamică 2D, operatorii `()` și `[]`, regula celor 3.

- membrii: `int** a`, `int linii`, `int coloane`
- constructor `Matrice(int l, int c, int val = 0)`, constructor de copiere, `operator=`, destructor
- `operator()(int i, int j)`, care întoarce `int&` (`m(1, 2) = 5;`), cu verificare de limite
- `operator+`; dacă dimensiunile nu se potrivesc, afișezi o eroare
- `operator*` pentru înmulțirea a două matrice, și `operator*` cu un scalar, în **ambele ordini** (`m * 3` și `3 * m`)
- `operator==`
- funcția membru `transpusa()`, care întoarce o matrice nouă

**`main` trebuie să arate:** toate operațiile, un exemplu de înmulțire cu dimensiuni diferite (de exemplu 2x3 * 3x2) și rularea fără erori de memorie.

---

## Task 6 – `Cont` și `Banca`
Material exersat: clase prieten, funcții membru prietene, forward declaration.

**Varianta A** (într-un fișier):
- `Cont`: titular, IBAN, sold, toate private; **fără** setter pentru sold
- `Banca` este `friend class` pentru `Cont`
- `Banca` are un tablou alocat dinamic de `Cont*`, plus `adaugaCont`, `depune`, `retrage` (fără sold negativ) și `raport()`

**Varianta B** (alt fișier):
- doar `Banca::transfer(Cont&, Cont&, double)` este prietenă cu `Cont`, nu toată clasa `Banca`
- trebuie să-ți dai seama singur ce clasă se declară prima, unde e nevoie de forward declaration și unde definești `transfer`

**`main` trebuie să arate:** operațiile și, într-un comentariu, o linie de tipul `c.sold = 1000;` care **nu** compilează, împreună cu eroarea dată de compilator.

---

## Task 7 – `Angajat` și membri statici
Material exersat: date și funcții statice, inițializarea în afara clasei, `::`.

- `Angajat`: nume, salariu și un `id` unic, generat automat
- membri statici:
  - `nrAngajati` (câți există acum)
  - `urmatorulId` (nu se refolosește, chiar dacă un angajat e distrus)
  - `salariuMinim` (comun tuturor)
- funcții statice: `getNrAngajati()`, `setSalariuMinim(double)` (crește automat la minim salariile mai mici **la crearea** angajaților noi) și `afisStatistici()`
- o variabilă **globală** `int nrAngajati` (da, cu același nume), pe care o folosești în `main` cu `::nrAngajati` ca să vezi diferența

**`main` trebuie să arate:**
- apelul funcțiilor statice **înainte** de a crea vreun obiect
- crearea și distrugerea de obiecte (unele în blocuri `{ }`, unele cu `new`/`delete`)
- că id-urile nu se repetă

---

## Task 8 – Clase locale
Material exersat: clase definite în funcții, restricțiile lor.

- o funcție `void simulare(int n)`, care definește **în interiorul ei** o clasă `Zar`, cu metoda `aruncare()` (folosește `rand()`)
- o variabilă `static` în funcție care numără câte aruncări s-au făcut în total, în toate apelurile lui `simulare`
- `simulare` aruncă de `n` ori și afișează frecvența fiecărei fețe
- **experimente** (le notezi în comentarii, cu eroarea primită):
  1. accesarea din `Zar` a parametrului `n` al funcției
  2. un membru `static int` în `Zar`
  3. definirea unei metode a lui `Zar` în afara clasei
  4. folosirea lui `Zar` în `main`

---

## Task 9 – `Polinom` (task mare, recapitulativ)
Toată materia din cursurile 3 și 4.

- coeficienți `double`, alocați dinamic, și gradul
- constructori: `Polinom()` (polinomul nul), `Polinom(double)` (constantă), `Polinom(int grad, double* coef)`, constructor de copiere
- `operator=` și destructor
- `operator[]`, care întoarce coeficientul lui x^i (`int`→`double&`)
- `operator()(double x)`, care evaluează polinomul în x (`p(2.5)`)
- `+ - *` între polinoame și cu constante, în ambele ordini (`p + 3`, `3 + p`)
- `+= -= *=`
- `==` și `!=`
- `operator<<`, care afișează frumos: `3x^2 - x + 5`, nu `3x^2 + -1x^1 + 5x^0`
- `operator>>`, care citește gradul și coeficienții
- funcția membru `derivata()`
- un contor static al polinoamelor existente
- după operații, gradul trebuie ajustat; de exemplu, `(x^2 + 1) - (x^2)` are gradul 0

**`main` trebuie să arate:** un meniu în consolă (citește două polinoame, alege operația) și rularea fără erori cu `-fsanitize=address`.

---

## Task 10 – Bonus: supraîncărcare `new`/`delete`
- pentru clasa `Fractie` (Task 3), supraîncarci `operator new` și `operator delete` **la nivel de clasă**
- ele afișează câți octeți se alocă și țin un contor static de alocări active
- supraîncarci și varianta **globală** și verifici că `new int` folosește varianta globală, iar `new Fractie` pe cea a clasei

---

## Când termini un task
Trimite-mi codul. Mă uit la:
- corectitudine (memorie, copieri, cazuri limită)
- dacă ai ales corect între funcție membru și prieten
- ce ar întreba profesoara la colocviu despre codul tău
