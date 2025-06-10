#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data d;
    d.value = 42;

    Data*     ptr  = &d;
    uintptr_t raw  = Serializer::serialize(ptr);
    Data*     ptr2 = Serializer::deserialize(raw);

    std::cout << "Original pointer:    " << ptr  << '\n';
    std::cout << "Serialized value:    " << raw  << '\n';
    std::cout << "Deserialized pointer:" << ptr2 << '\n';

    if (ptr == ptr2)
        std::cout << "Success: pointers match\n";
    else
        std::cout << "Error: pointers do not match\n";

    std::cout << "Value via deserialized pointer: " << ptr2->value << '\n';

    return 0;
}
