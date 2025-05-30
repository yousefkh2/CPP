#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"  
#include "Cat.hpp" 

int main() {
    std::cout << "--- SIMPLE CONSTRUCTION/DELETION ---\n";
    const Animal* d = new Dog();      // animal => brain => dog
    const Animal* c = new Cat();
    delete d;                          // the other way around
    delete c;

    std::cout << "\n--- DEEP COPY TEST ---\n";
    Dog original;
    original.getBrain()->setIdea(0, "Chase this man!");
    Dog copy = original;
    std::cout << "Original idea[0]: "
              << original.getBrain()->getIdea(0) << "\n";
    std::cout << "Copy     idea[0]: "
              << copy.getBrain()->getIdea(0) << "\n";
    // now i will change original:
    original.getBrain()->setIdea(0, "Lie down!");
    std::cout << "After change, copy idea[0]: "
              << copy.getBrain()->getIdea(0) << "\n";  // must still be "Chase this man!"

    std::cout << "\n--- ARRAY OF ANIMALS ---\n";
    const int N = 4;
    Animal* zoo[N];
    for (int i = 0; i < N; ++i) {
        if (i < N/2)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }
    for (int i = 0; i < N; ++i)
        delete zoo[i];

    return 0;
}
