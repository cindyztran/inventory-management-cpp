#include "../Inventory/Inventory.h"
#include "UIFunctions.h"
#include <iostream>
#include <random>
#include <optional>

int generateRandomId()
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(1000, 9999);
  int randomId = dist(mt);
  std::cout << "Generated ID: " << randomId << std::endl; // Debug output
  return randomId;
}

void addProductToInventory(Inventory &inventory)
{
  int id;
  do
  {
    id = generateRandomId();
  } while (inventory.getProduct(id).has_value());

  std::string name;
  double price;
  int quantity;

  std::cout << "Enter product name: ";
  std::cin.ignore();            // To consume any leftover newline character
  std::getline(std::cin, name); // Use getline to properly read strings with spaces
  std::cout << "Enter product price: ";
  std::cin >> price;
  std::cout << "Enter product quantity: ";
  std::cin >> quantity;

  Product newProduct(id, name, price, quantity);
  inventory.addProduct(newProduct);
  std::cout << "Product added successfully. ID: " << id << std::endl;
}

void removeProductFromInventory(Inventory &inventory)
{
  int id;
  std::cout << "Enter product ID to remove: ";
  std::cin >> id;

  if (inventory.getProduct(id).has_value())
  {
    inventory.removeProduct(id);
    std::cout << "Product removed successfully." << std::endl;
  }
  else
  {
    std::cout << "Product with ID " << id << " does not exist." << std::endl;
  }
}
