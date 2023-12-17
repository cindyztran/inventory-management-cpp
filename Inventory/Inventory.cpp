#include "Inventory.h"
#include <iostream>

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