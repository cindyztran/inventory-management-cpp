#include <iostream>
#include <string>
#include "Inventory/Inventory.h"
#include "UIFunctions/UIFunctions.h"

int main()
{
    Inventory inventory;
    int choice;
    bool running = true;
    std::string filename;
    std::string searchTerm;
    bool shouldSort;

    while (running)
    {
        std::cout << "Inventory Management System" << std::endl;
        std::cout << "1. Add Product" << std::endl;
        std::cout << "2. Remove Product" << std::endl;
        std::cout << "3. List Products" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "5. Save to file" << std::endl;
        std::cout << "6. Load from file" << std::endl;
        std::cout << "7. Search for a product" << std::endl;
        std::cout << "8. Sort products" << std::endl;
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
        case 5:
            std::cout << "Enter the filename to save: ";
            std::cin >> filename;
            inventory.saveToFile(filename);
            break;
        case 6:
            std::cout << "Enter the filename to load: ";
            std::cin >> filename;
            inventory.loadFromFile(filename);
            break;
        case 7:
            std::cout << "Enter the search term: ";
            std::cin >> searchTerm;
            inventory.searchProduct(searchTerm);
            break;
        case 8:
            std::cout << "Enter true if you want to sort by name, false if you want to sort by ID: ";
            std::cin >> std::boolalpha >> shouldSort;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter true or false." << std::endl;
            }
            else
            {
                inventory.sortProducts(shouldSort);
            }
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

    return 0;
}