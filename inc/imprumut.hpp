#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <mutex>
#include <memory>
#include <string>
#include "../inc/patrulater.hpp"

using namespace std;
class Patrulater;

class Imprumut{

public:
    Imprumut(Patrulater *p);

    ~Imprumut();

    void lock();
    void unlock();

private:
    Imprumut(const Imprumut &A) = delete;
    Imprumut& operator=(Imprumut &Imprumut) = delete;
    unique_ptr<mutex> mutex_pointer;
    Patrulater *patrulater;
};
