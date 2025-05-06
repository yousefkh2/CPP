#include "Zombie.hpp"
#include <iostream>

int main() {
    // create a zombie on the stack
    std::cout << "Creating zombie on the stack:" << std::endl;
    Zombie stackZombie("Stack Zombie");
    stackZombie.announce();
    
    // create a zombie on the heap
    std::cout << "\nCreating zombie on the heap:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    
    // call the randomChump function
    std::cout << "\nCalling randomChump:" << std::endl;
    randomChump("Random Zombie");
    
    std::cout << "\nDeleting heap zombie:" << std::endl;
    delete heapZombie;
    
    std::cout << "\nEnd of main function - stack zombie will be destroyed now" << std::endl;
    return 0;
}
