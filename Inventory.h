#pragma once
#include "Product.h"
#include <vector>
#include <optional>

class Inventory
{
private:
  std::vector<Product> products;

public:
  void addProduct(const Product &product);
  void removeProduct(int productId);
  std::optional<Product> getProduct(int productId) const;
  void listProducts() const;
};