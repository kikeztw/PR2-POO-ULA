#ifndef _HEADER_H_
#define _HEADER_H_
#include <stack>
#include <iostream> 
#include <bits/stdc++.h> 

struct Product 
{
  float price;
  char name[20];
  int quantity = 1;
};

struct Client
{
  char name[10];
  char lastName[10];
  bool isPartner;
};

class CashRegister 
{
    std::stack <Product> store;
    Client currentClient;
    float discount;

    public:
      CashRegister();
      CashRegister(const CashRegister &);
      ~CashRegister(){};

      float getShoppingCartPrice();
      int getQuantityProduct();
      std::stack<Product> getShoppingCarList();
      Client getCurrentClient();
      float getDiscount(float);


      bool setProductCart(Product);
      void setClient(Client);

};


class ProductStore 
{
   Product store[5];
   int storeSize;

   public:
    ProductStore();
    ProductStore(const ProductStore &);
    ~ProductStore(){};

    Product* getStore();
    Product getProductFromTheStore(int);
    int getStoreSize();
};



//  ------------- app ------------------------
void app(ProductStore *, CashRegister *, Client *);
void appMenu(ProductStore *, CashRegister *, Client *);
void appClientData(CashRegister *, Client*, ProductStore *);
void appShoppingCar(ProductStore *, CashRegister *, Client *);
void appBuyProducts(ProductStore *, CashRegister *);
void appClientData(CashRegister *);

void registerClient(Client *, CashRegister *);
void getClientData(Client *);

void selectProductFromList(ProductStore *, CashRegister *, Client *);

void printfCarShoppingList (std::stack <Product>);
void printfStoreInProductStore(Product *, int);
#endif
