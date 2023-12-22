#include "../Inventory/Inventory.h"
#include "UIFunctions.h"
#include <iostream>
#include <random>
#include <optional>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

void Inventory::saveToFile(const std::string &filename)
{
  std::ofstream file(filename);
  for (const auto &product : products)
  {
    file << product.getId() << "," << product.getName() << ","
         << product.getPrice() << "," << product.getQuantity() << std::endl;
  }
  file.close();
}

void Inventory::loadFromFile(const std::string &filename)
{
  std::ifstream file(filename);
  std::string line;

  while (std::getline(file, line))
  {
    std::stringstream linestream(line);
    std::string item;
    std::vector<std::string> items;

    while (std::getline(linestream, item, ','))
    {
      items.push_back(item);
    }

    if (items.size() == 4)
    {
      int id = std::stoi(items[0]);
      std::string name = items[1];
      double price = std::stod(items[2]);
      int quantity = std::stoi(items[3]);

      Product product(id, name, price, quantity);
      addProduct(product);
    }
  }
  file.close();
}