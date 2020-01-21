#include "header.h"
#include <iostream>
#include <stdlib.h>

/*
  Carlos Enrique Hurtado Puente
  22929504
*/

int main(){

  Client client;
  CashRegister *garzon = new CashRegister();
  ProductStore garzonStore;
  app(&garzonStore, garzon, &client);
  delete garzon;
}
  