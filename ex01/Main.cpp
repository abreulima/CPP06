#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

/*
    This exercise isn't really about data serialization.
    It is more about casting.
*/

std::ostream& operator<<(std::ostream& os, const Data& d) 
{
    os << "Player:\t" << d.name << std::endl;
    os << "HP: " << d.hp << " " "\tSP: " << d.sp << std::endl;
    os << "X: " << d.x << " " "\tY: " << d.y << std::endl;
    return os;
}

int main()
{

    Data data = {"Ivan", 100, 50, 43, 43};
    
    std::cout << data << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);
    std::cout << "0x" << std::hex << ptr << std::endl;

    Data* dt = Serializer::deserialize(ptr);
    std::cout << dt << std::endl;

    if (Serializer::deserialize(Serializer::serialize(&data)) == &data)
    {
        std::cout << "Sucess!" << std::endl;
    }
    else
    {
        std::cout << "Failure!" << std::endl;
    }

    std::cout << std::endl;

    std::cout << *dt;
    return 0;
}
