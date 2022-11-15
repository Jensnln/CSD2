#include <iostream>
// using namespace std;

class Woofer
{
public:
  float magnet;
  float coil;
  float product;

  void move(float product)
  {
    coil = product * 0.73;
  }


  void printCoilCollision()
  {
    std::cout << "Coil position: " << coil << std::endl;
  }


};


int main()
{
  Woofer myWoofer;
  for(int i = 0; i < 4; i++)
  {
    float product = i * 0.5;
    myWoofer.move(product);
    myWoofer.printCoilCollision();
  }

  return 0;
}

