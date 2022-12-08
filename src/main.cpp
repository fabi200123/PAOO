#include <iostream>
#include <cmath>
#include <vector>
#include <mutex>
#include <memory>
#include "../inc/imprumut.hpp"
#include "../inc/patrulater.hpp"

using namespace std;

Patrulater::Patrulater(const Patrulater &p) : Patrulater(p.lungime, p.latime, *p.descriere){
    cout << "S-a apelat Copy constructor din Patrulater!\n";
}
Patrulater::Patrulater(const Patrulater &&p){
    descriere = new string;
    *descriere = *p.descriere;
    latime = p.latime;
    lungime = p.lungime;
    cout << "S-a apelat Move constructor din Patrulater!\n";
}
Patrulater::Patrulater(float L, float l){
    latime = l;
    lungime = L;
    descriere = new string("TO BE SET!");
    cout << "Un obiect de tip Patrulater a fost creat cu succes!\n";
}
Patrulater::Patrulater(float L, float l, string des){
    latime = l;
    lungime = L;
    descriere = new string(des);
    cout << "Un obiect de tip Patrulater cu descriere a fost creat cu succes!\n";
}
Patrulater::Patrulater(float latura){
    lungime = latura;
    latime = latura;
    descriere = new string("TO BE SET!");
    cout << "Un obiect de tip Patrulater cu laturile egale a fost creat cu succes!\n";
}
Patrulater::Patrulater(float latura, string des){
    lungime = latura;
    latime = latura;
    descriere = new string(des);
    cout << "Un obiect de tip Patrulater cu laturile egale si cu descriere a fost creat cu succes!\n";
}
Patrulater::~Patrulater(){
    delete descriere;
    cout << "Obiectul de tip Patrulater a fost sters cu succes!\n";
}
void Patrulater::imprumutaForma(){
    if(!esteImprumutat){
        imprumutat->lock();
        cout << "Forma cu lungimea " << lungime << " si latimea " << latime <<" a fost imprumutata!\n";
        imprumutat->unlock();
    }
}

class Dreptunghi : public Patrulater
{
public:
    Dreptunghi() = delete;
    Dreptunghi(const Dreptunghi &d) : Patrulater(d.lungime, d.latime, *d.descriere){
        cout << "S-a apelat Copy constructor din Dreptunghi!\n";
    }
    Dreptunghi(const Dreptunghi &&d) : Patrulater(move(d)){
        cout << "S-a apelat Move constructor din Dreptunghi!\n";
    }
    Dreptunghi(float L, float l) : Patrulater(L, l) {
        cout << "Un obiect de tip Dreptunghi a fost creat cu succes!\n";
    }
    Dreptunghi(float L, float l, string des) : Patrulater(L, l, des) {
        cout << "Un obiect de tip Dreptunghi cu descriere a fost creat cu succes!\n";
    }
    Dreptunghi& operator=(Dreptunghi const& F){
        if(this != &F){
            delete descriere;
            descriere = new string(*F.descriere);
            this->latime = F.latime;
            this->lungime = F.lungime;
            cout << "Copy assigment in Dreptunghi!\n";
            return *this;
        }
        cout << "Self assigment in Dreptunghi!\n";
        return *this;
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
    void descriere_forma() {
        cout << "Descrierea este: " << *descriere << "\n";
    }

};

class Patrat : public Dreptunghi
{
public:
    Patrat() = delete;
    Patrat(const Patrat &p) = delete;
    Patrat(const Patrat &&p) : Dreptunghi(move(p)){
        cout << "S-a apelat Move Constructor din Patrat!\n";
    }
    Patrat(float latura) : Dreptunghi(latura, latura){
        cout << "Un obiect de tip Patrat a fost creat cu succes!\n";
    }
    Patrat(float latura, string des) : Dreptunghi(latura, latura, des){
        cout << "Un obiect de tip Patrat cu descriere a fost creat cu succes!\n";
    }
    Patrat& operator=(Patrat const& F){
        if(this != &F){
            delete descriere;
            descriere = new string(*F.descriere);
            this->latime = F.latime;
            this->lungime = F.lungime;
            cout << "Copy assigment in Patrat!\n";
            return *this;
            
        }
        cout << "Self assigment in Patrat!\n";
        return *this;
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
    void descriere_forma() {
        cout << "Descrierea este: " << *descriere << "\n";
    }
};

class Romb : public Patrulater
{
    float unghi;
public:
    Romb() = delete;
    Romb(const Romb &r) : Patrulater(r.latime, *r.descriere){
        unghi = r.unghi;
        cout << "S-a apelat Copy Constructor din Romb!\n";
    }
    Romb(const Romb &&r) : Patrulater(move(r)){
        unghi = r.unghi;
        cout << "S-a apelat Move Constructor din Romb!\n";
    }
    Romb(float latura, int alpha) : Patrulater(latura){
        unghi = alpha;
        cout << "Un obiect de tip Romb a fost creat cu succes!\n";
    }
    Romb(float latura, int alpha, string des) : Patrulater(latura, des){
        unghi = alpha;
        cout << "Un obiect de tip Romb cu descriere a fost creat cu succes!\n";
    }
    Romb& operator=(Romb const& F){
        if(this != &F){
            delete descriere;
            descriere = new string(*F.descriere);
            this->latime = F.latime;
            this->lungime = F.lungime;
            this->unghi = F.unghi;
            cout << "Copy assigment in Romb!\n";
            return *this;
            
        }
        cout << "Self assigment in Romb!\n";
        return *this;
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
    void descriere_forma() {
        cout << "Descrierea este: " << *descriere << "\n";
    }
};

/*------------------tema-6---------------------*/
Imprumut::Imprumut(Patrulater *p){
    patrulater = p;
    mutex_pointer = make_unique<mutex>();
    mutex_pointer->unlock();
}
Imprumut::~Imprumut(){
    unlock();
}
void Imprumut::lock(){
    if(!patrulater->esteImprumutat){
        mutex_pointer->lock();
        cout << "S-a imprumutat forma!\n";
        patrulater->esteImprumutat = true;
    }
}
void Imprumut::unlock(){
    if(patrulater->esteImprumutat){
        mutex_pointer->unlock();
        cout << "S-a returnat forma!\n";
        patrulater->esteImprumutat = false;
    }
}

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
    
    cout << "Romb *r1 = new Romb(10.0, 1);\nRomb *rombi = new Romb(r1);\n\n";
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

    cout <<"\n-------------------------------------------------------------------------------------------------------------------------\n";

    Dreptunghi drept_1(10, 15, "Un dreptunghi cu laturile de 10 si 15 cm");
    Dreptunghi nou_d1(10, 10, "Descriere"), nou_d2(10, 12, "Ceva ceva");
    //copy assigment
    nou_d1 = nou_d2 = drept_1;
    nou_d1.arie();
    nou_d1.descriere_forma();
    //self assigment
    drept_1 = drept_1;
    nou_d1.arie();

    Patrat patri(10, "Un patrat cu lungimea 10"), patrat_identic(10, "Ceva descriere"), nou_patrat(11, "Descriere patrat nou");
    //copy assigment
    patrat_identic = nou_patrat = patri;
    patrat_identic.arie();
    patrat_identic.descriere_forma();
    //self assigment
    patri = patri;

    Romb rombulet(10, 1, "Romb cu latura de 10 cm si unghi de 1"), nou_romb(12, 5, "Romb cu latura de 12 si unghi de 5");
    //copy assigment
    nou_romb = rombulet;
    nou_romb.arie();
    nou_romb.descriere_forma();
    //self assigment
    nou_romb = nou_romb;

    cout <<"\n-------------------------------------------------------------------------------------------------------------------------\n";

    shared_ptr<Patrat> shared_patrat = make_shared<Patrat>(20, "Patrat de latura 20");
    shared_patrat->descriere_forma();

    shared_ptr<Dreptunghi> shared_dreptunghi = make_shared<Dreptunghi>(20, 40, "Dreptunghi de 20 si 40!");
    shared_dreptunghi->descriere_forma();

    shared_ptr<Patrulater> shared_patrulater = shared_dreptunghi;
    shared_patrulater->descriere_forma();

    shared_ptr<Dreptunghi> dreptunghi_imprumut = make_shared<Dreptunghi>(10, 20, "Dreptunghi cu laturile de 10 si 20!");
    shared_ptr<Dreptunghi> profesor1(dreptunghi_imprumut);
    shared_ptr<Dreptunghi> profesor2(dreptunghi_imprumut);
    profesor1->descriere_forma();
    profesor2->descriere_forma();
    
    profesor1->imprumutaForma();
    profesor2->imprumutaForma();
    return 0;
}