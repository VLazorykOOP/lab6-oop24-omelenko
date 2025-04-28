#include <iostream>

using namespace std;

// Ієрархія без віртуального успадкування
class Base 
{
public:
    int baseData;
    Base() : baseData(0) {}
};

class I1 : public Base 
{
public:
    int i1;
    I1() : i1(1) {}
};

class I2 : public Base 
{
public:
    int i2;
    I2() : i2(2) {}
};

class I2_1 : public I2
{
public:
    int i2_1;
    I2_1() : i2_1(3) {}
};

class I2_2 : public I2, public I2_1
{
public:
    int i2_2;
    I2_2() : i2_2(4) {}
};

class I122_2 : public I1, public I2, public I2_2
{
public:
    int i122_2;
    I122_2() : i122_2(5) {}
};

// Ієрархія з віртуальним успадкуванням
class BaseVirtual 
{
public:
    int baseVirtualData;
    BaseVirtual() : baseVirtualData(0) {}
};

class I1Virtual: virtual public BaseVirtual 
{
public:
    int i1Virtual;
    I1Virtual() : i1Virtual(1) {}
};

class I2Virtual : virtual public BaseVirtual 
{
public:
    int i2Virtual;
    I2Virtual() : i2Virtual(2) {}
};

class I2_1Virtual : virtual public I2Virtual
{
public:
    int i2_1Virtual;
    I2_1Virtual() : i2_1Virtual(3) {}
};

class I2_2Virtual : virtual public I2Virtual, virtual public I2_1Virtual
{
public:
    int i2_2Virtual;
    I2_2Virtual() : i2_2Virtual(4) {}
};

class I122_2Virtual : virtual public I1Virtual, virtual public I2Virtual, virtual public I2_2Virtual
{
public:
    int i122_2Virtual;
    I122_2Virtual() : i122_2Virtual(5) {}
};

int task1() 
{
    I122_2 objNonVirtual;
    I122_2Virtual objVirtual;

    cout << "Size of I122_2 object (without virtual inheritance): "
        << sizeof(objNonVirtual) << " bytes" << endl;
    cout << "Size of I122_2Virtual object (with virtual inheritance): "
        << sizeof(objVirtual) << " bytes" << endl;

    return 0;
}