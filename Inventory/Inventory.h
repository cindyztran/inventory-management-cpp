#pragma once
#include "../Product/Product.h"
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
  void saveToFile(const std::string &filename);
  void loadFromFile(const std::string &filename);
  std::optional<Product> searchProduct(const std::string &searchTerm) const;
};