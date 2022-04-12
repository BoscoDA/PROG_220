#include <iostream>
#include <string>
#include <vector>

struct Animal
{
    virtual void make_noise() = 0;

protected:
    int age;
    std::string name;
};

enum DogBreed
{
    Dachshund,
    Lab,
    GeldenRetreiver
};

struct Dog : public Animal
{
    DogBreed breed;
};

void foo(Animal *a_ptr)
{
    // Lose all dog funcionality this way
    a_ptr->make_noise();
    // a_ptr->age = 10;
    // a_ptr->name = "Animal";
}

struct Entity
{
    int id;
    long lasd_modified_timestamp;
    std::string last_modified_user;
};

struct LOB : public Entity
{
};

struct HasAge
{
    int age;
};

struct HasName
{
    std::string name;
};

struct MakesNoise
{
    virtual void make_noise() = 0;
};

// supports multiple inheiritance. no interfaces.
struct Dog2 : HasAge, HasName, MakesNoise
{
};

void noise_handler(MakesNoise *ptr)
{
    ptr->make_noise();
}

// design patterns

// Singleton - used for things that are big and you only want one of them.
//          i.e: data structures,
struct Singleton
{
    static Singleton *GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }

private:
    static Singleton *instance;
    Singleton()
    {
    }
};

// Factory
struct ComplexObject
{
    int a, b, c, d;

    // constructore = initialization and/through  allocation
    ComplexObject(int a, int b, int c, int d)
    {
        this->a;
        this->b;
        this->c;
        this->d;
    }

    // factories are a way to split initialization and allocation
    static ComplexObject *Create(int z)
    {
        return new ComplexObject(1, 2, 3, z * 5);
    }

    static ComplexObject *Default()
    {
        return new ComplexObject(0, 0, 0, 0);
    }
};

// template is completely compile time
template <class T> // can return any type that has a open constructor
struct Factory
{
    static T *Create() { return new T(); }
};

class A
{
public:
    int z;
    A();
    ~A();

    static void Init(A *a)
    {
        a->z = 10;
    }
};

int main()
{
    Singleton *s = Singleton::GetInstance();
    A *a = Factory<A>::Create();

    A::Init(a);

    // vectors use templates
    // std::vector<A>;
}