#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <mutex>
#include <memory>
#include <string>
#include "../inc/imprumut.hpp"

class Imprumut;

class Patrulater
{
protected:
    float lungime; // lungimiile sunt egale
    float latime; // latimile sunt egale
    std::string *descriere; // o descriere a formei geometrice
    std::unique_ptr<Imprumut> imprumutat = std::make_unique<Imprumut>(this); //pointerul pentru a stii daca e sau nu imprumutat
public:
    bool esteImprumutat = false;
    Patrulater() = delete;
    Patrulater(const Patrulater &p);
    Patrulater(const Patrulater &&p);
    Patrulater(float L, float l);
    Patrulater(float L, float l, std::string des);
    Patrulater(float latura);
    Patrulater(float latura, std::string des);
    virtual ~Patrulater();

    virtual void arie() = 0;
    virtual void perimetru() = 0;
    virtual void descriere_forma() = 0;
    void imprumutaForma();

};