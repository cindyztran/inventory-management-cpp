#include "Inventory.h"
#include <iostream>
#include <algorithm>

void Inventory::addProduct(const Product &product)
{
  products.push_back(product);
}

void Inventory::removeProduct(int productId)
{
  products.erase(
      std::remove_if(products.begin(), products.end(),
                     [productId](const Product &product)
                     {
                       return product.getId() == productId;
                     }),
      products.end());
}

#include <optional>

std::optional<Product> Inventory::getProduct(int productId) const
{
  for (const auto &product : products)
  {
    if (product.getId() == productId)
    {
      return product;
    }
  }
  return std::nullopt;
}

void Inventory::listProducts() const
{
  for (const auto &product : products)
  {
    std::cout << "ID: " << product.getId() << ", Name: " << product.getName() << ", Price: " << product.getPrice() << ", Quantity: " << product.getQuantity() << std::endl;
  }
}
std::optional<Product> Inventory::searchProduct(const std::string &searchTerm) const
{
  std::cout << "Searching for " << searchTerm << std::endl;
  std::cout << "ID\tName\tPrice\tQuantity" << std::endl;
  for (const auto &product : products)
  {
    if (product.getName() == searchTerm || std::to_string(product.getId()) == searchTerm)
    {
      std::cout << product.getId() << "\t" << product.getName() << "\t" << product.getPrice() << "\t" << product.getQuantity() << std::endl;
      return product;
    }
  }
  return std::nullopt;
}

void Inventory::sortProducts(bool byName)
{
  std::sort(products.begin(), products.end(),
            [byName](const Product &product1, const Product &product2)
            {
              if (byName)
              {
                std::cout << "Sorting by name" << std::endl;
                return product1.getName() < product2.getName();
              }
              else
              {
                std::cout << "Sorting by id" << std::endl;
                return product1.getId() < product2.getId();
              }
            });
}