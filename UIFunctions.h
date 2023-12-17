#ifndef UIFUNCTIONS_H
#define UIFUNCTIONS_H

#include "Inventory.h"

void addProductToInventory(Inventory &inventory);
void removeProductFromInventory(Inventory &inventory);
void listAllProducts(const Inventory &inventory);

#endif