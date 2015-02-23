#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Motor
{
public:
  Motor(){
    cout << "Motor constructor" << endl;
    }
  //Motor(){throw 1;}
};

class Car
{
public:
  Car(Motor& oneMotor) {
    cout << "Car motor constructor" << endl;
    motor = oneMotor;
  }

  Car& operator= (Car& oneCar){
    cout << "Car operator=" << endl;
    motor = oneCar.getMotor();
    return *this;
   }

  Car() {
    cout << "Car constructor" << endl;
}

  ~Car() {}

  Motor& getMotor(){
    return motor;
  }
private:
  Motor motor;
};

class Garage
{
public:
  Garage(Car& oneCar) try{
    car = oneCar;
  }
  catch (...){
    throw 1;
  }
  ~Garage(){};
private:
  Car car;
};

int main(int argc, char* argv[])
{
    try{
      cout << "1" << endl;
      Motor motor;
      cout << "2" << endl;
      Car car(motor);
      cout << "3" << endl;
      Garage garage(car);
    }
    catch (int& x){
      cout << "x=" << x << endl;
    }
  return 0;
}
