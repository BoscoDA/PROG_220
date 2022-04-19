#include <memory>
#include <vector>
#include <iostream>

// Karl's rules for pointers
// If your functions returns an array or a complex object, return a pointer.
// If your function takes in an array or complex object, use a pointer.
// If your data has a longer lifecycle than the function that created it, use a pointer
//

// All the copies behind the scenes when pointers are not used
// struct B
// {
//     int i;
//     B(const int i) { this->i = i; }
//     B(const B &b)
//     {
//         std::cout << "Copied" << std::endl;
//     }
// };
// struct A
// {
//     std::vector<B> b_vector;
// };

// A foo(int n)
// {
//     A a = A();

//     for (int i = 0; i < n; i++)
//     {
//         a.b_vector.push_back(B(i));
//     }

//     return a;
// }

// CPP 98 fix to lots of copies
// mutable
// heap allocated - lots of management
struct B
{
    int i;
    B(const int i) { this->i = i; }
    B(const B &b)
    {
        std::cout << "Copied" << std::endl;
    }
};
struct A
{
    std::vector<B *> b_vector;

    ~A()
    {
        for (auto b : b_vector)
        {
            std::cout << "deleted" << std::endl;
            delete b;
        }
    }
};

A *foo(const int n)
{
    A *a = new A();

    for (int i = 0; i < n; i++)
    {
        a->b_vector.push_back(new B(i));
    }

    return a;
}

// foo2 and bar demonstrate dangers of pointers
void foo2(int *x)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << x[i] << std::endl;
    }
}

void bar()
{
    int x = 0;
    foo2(&x);

    int *y = new int[10];
    foo2(y);

    delete y;
}

// CPP 11
//  - unquie pointers
//    - use in any place you would use a raw pointer
//    - live in the memory namespace
//    - has a concept of ownership
//    - only one thing can point to it at a time
//    - same size as a raw pointer
//  - shared pointers
//    - double the size of a raw pointer
//    - holds a reference count
//    -
//  -

void baz(std::unique_ptr<A> a_ptr)
{
}

int main()
{
    // A *a = foo(1000);
    // delete a;

    std::unique_ptr<A> a = std::make_unique<A>();
    // moved instead of copied
    baz(std::move(a));

    std::shared_ptr<A> a_shared = std::make_shared<A>();
}