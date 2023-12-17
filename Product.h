#pragma once
#include <string>

class Product
{
private:
  int id;
  std::string name;
  double price;
  int quantity;

public:
  Product(int id, std::string name, double price, int quantity);

  // Getters and Setters
  int getId() const;
  std::string getName() const;
  int getQuantity() const;
  double getPrice() const;

  void setName(const std::string &name);
  void setPrice(double price);
  void setQuantity(int quantity);
};