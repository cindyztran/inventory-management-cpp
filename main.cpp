#include "Inventory.h"
#include "UIFunctions.h"
#include <iostream>

int main()
{
    Inventory inventory;
    int choice;
    bool running = true;

    while (running)
    {
        std::cout << "Inventory Management System" << std::endl;
        std::cout << "1. Add Product" << std::endl;
        std::cout << "2. Remove Product" << std::endl;
        std::cout << "3. List Products" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addProductToInventory(inventory);
            break;
        case 2:
            removeProductFromInventory(inventory);
            break;
        case 3:
            inventory.listProducts();
            break;
        case 4:
            running = false;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

    return 0;
}