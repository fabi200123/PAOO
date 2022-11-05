#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Patrulater
{
protected:
    float lungime; // lungimiile sunt egale
    float latime; // latimile sunt egale
public:
    Patrulater() = delete;
    Patrulater(const Patrulater &p) = delete;
    Patrulater(const Patrulater &&p) = delete;
    Patrulater(float L, float l){
        latime = l;
        lungime = L;
        cout << "Un obiect de tip Patrulater a fost creat cu succes!\n";
    }
    Patrulater(float latura){
        lungime = latura;
        latime = latura;
        cout << "Un obiect de tip Patrulater cu laturile egale a fost creat cu succes!\n";
    }
    virtual ~Patrulater(){
        cout << "Obiectul de tip Patrulater a fost sters cu succes!\n";
    }

    virtual void arie() = 0;
    virtual void perimetru() = 0;
};

class Dreptunghi : public Patrulater
{
public:
    Dreptunghi() = delete;
    Dreptunghi(const Dreptunghi &d) : Patrulater(d.lungime, d.latime){
        cout << "S-a apelat Copy constructor din Dreptunghi!\n";
    }
    Dreptunghi(const Dreptunghi &&d) = delete;
    Dreptunghi(float L, float l) : Patrulater(L, l) {
        cout << "Un obiect de tip Dreptunghi a fost creat cu succes!\n";
    }
    ~Dreptunghi(){
        cout << "Obiectul de tip Dreptunghi a fost sters cu succes!\n";
    }

    void arie() {
        cout << "Aria dreptunghiului este: " << lungime * latime << "\n";
    }
    void perimetru(){
        cout << "Perimentrul dreptunghiului este: " << (2 * (lungime + latime)) << "\n";
    }

};

class Patrat : public Dreptunghi
{
public:
    Patrat() = delete;
    Patrat(const Patrat &p) = delete;
    Patrat(const Patrat &&p) : Dreptunghi(p.latime, p.lungime){
        p.~Patrat();
        cout << "S-a apelat Move Constructor din Patrat!\n";
    }
    Patrat(float latura) : Dreptunghi(latura, latura){
        cout << "Un obiect de tip Patrat a fost creat cu succes!\n";
    }
    ~Patrat(){
        cout << "Obiectul de tip Patrat a fost sters cu succes!\n";
    }

    void arie() {
        cout << "Aria patratului este: " << lungime * latime << "\n";
    }
    void perimetru(){
        cout << "Perimentrul patratului este: " << 4 * lungime << "\n";
    }
};

class Romb : public Patrulater
{
    float unghi;
public:
    Romb() = delete;
    Romb(const Romb &r) : Patrulater(r.latime){
        unghi = r.unghi;
        cout << "S-a apelat Copy Constructor din Romb!\n";
    }
    Romb(const Romb &&r) : Patrulater(r.latime){
        unghi = r.unghi;
        r.~Romb();
        cout << "S-a apelat Move Constructor din Romb!\n";
    }
    Romb(float latura, int alpha) : Patrulater(latura){
        unghi = alpha;
        cout << "Un obiect de tip Romb a fost creat cu succes!\n";
    }
    ~Romb(){
        cout << "Obiectul de tip Romb a fost sters cu succes!\n";
    }

    void arie() {
        cout << "Aria rombului este: " << lungime * lungime * sin(unghi) << "\n";
    }
    void perimetru() {
        cout << "Perimetrul rombului este: " << 4 * lungime << "\n";
    }
};

int main(){
    cout << "Dreptunghi *d = new Dreptunghi(10.0, 5.0);\n\n"; 
    Dreptunghi *d = new Dreptunghi(10.0, 5.0);
    d->perimetru();
    d->arie();
    delete d;
    cout << "\n";
    
    cout << "Patrat *s = new Patrat(12.0);\n\n";
    Patrat *s = new Patrat(12.0);
    s->perimetru();
    s->arie();
    delete s;
    cout << "\n";
    
    cout << "Romb *r = new Romb(10.0, 1);\n\n";
    Romb *r = new Romb(10.0, 1);
    r->perimetru();
    r->arie();
    delete r;
    cout << "\n";
    
    cout << "Patrulater *p = new Patrat(10.0);\n\n";
    Patrulater *p = new Patrat(10.0);
    p->perimetru();
    p->arie();
    delete p;
    cout << "\n";
    
    cout << "Romb *r1 = new Romb(10.0, 0.5);\nRomb *rombi = new Romb(r1);\n\n";
    Romb *r1 = new Romb(10.0, 1);
    Romb *rombi = new Romb(*r1);
    rombi->perimetru();
    rombi->arie();
    delete r1;
    delete rombi;
    cout << "\n";

    // Move constructor Patrat
    vector<Patrat> patrick;
    patrick.push_back(Patrat(6.1));
    cout << "\n";

    cout << "\n";
    cout << "Dreptunghi *d1 = new Dreptunghi(6, 8);\nDreptunghi *drept = new Dreptunghi(d1);\n\n";
    Dreptunghi *d1 = new Dreptunghi(6, 8);
    Dreptunghi *drept = new Dreptunghi(*d1);
    drept->perimetru();
    drept->arie();
    delete d1;
    delete drept;
    cout << "\n";

    // Move Constructor Romb
    vector<Romb> vecti;
    vecti.push_back(Romb(12, 0.25));

    return 0;
}