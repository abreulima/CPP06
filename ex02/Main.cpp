#include <iostream>
#include <ctime>
#include <exception>

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void)
{
    // Xorshift
    unsigned int static state = static_cast<unsigned int>(std::time(NULL));
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;

    switch (state % 3)
    {
        case 0:     return new A();
        case 1:     return new B();
        default:    return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
        return ;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
        return ;     
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
        return ;
    }
    else
    {
        std::cout << "Unkown" << std::endl;
        return ;
    }

}

void identify(Base& p)
{
    try 
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception& e) { }
    try 
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception& e) { }
    try 
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::exception& e) { }
    std::cout << "Unkown" << std::endl;
}

int main()
{

    std::cout << "Tests" << std::endl;
    
    {
        // used as ref. in the func. call
        A a = A();
        B b = B();
        C c = C();

        identify(a);
        identify(b);
        identify(c);
    }

    {
        // as pointers in the func. call
        A* a = new A();
        B* b = new B();
        C* c = new C();

        identify(a);
        identify(b);
        identify(c);

        delete a;
        delete b;
        delete c;
    }

    std::cout << "Using pointers and random." << std::endl;
    for (int i = 0; i < 12; i++)
    {
        Base* base = generate();
        identify(base);
        delete base;
    }

    std::cout << "Using references  and random." << std::endl;
    for (int i = 0; i < 10; i++)
    {
        Base& base = *generate();
        identify(base);
        delete &base; 
    }

}