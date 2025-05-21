#include<iostream>
#include<string> 
using namespace std;

class Car{
  public: 
      virtual void startEngine() = 0;
      virtual void shiftGear(int gear) = 0;
      virtual void accelerate(int speed) = 0;
      virtual void brake() = 0;
      virtual void stopEngine() = 0;
      virtual ~Car() {}
      //Virtual is a keyboard so you can only declear a function not
      //add a functionalty 
};

class  SportsCar : public Car {
 public:
      string brand;
      string model;
      bool isEngineOn;
      int currentSpeed;
      int currentGear;
      
      SportsCar (string b, string a){
          this->brand = b;
          this->model = a;
          isEngineOn = false;
          currentSpeed = 0;
          currentGear = 0;
      }

      void startEngine() {
        isEngineOn = true;
        cout<< brand << " " << model << " Engine starts with a road!"<<endl;
      }

      void shiftGear(int gear){
        if(!isEngineOn){
             cout<< brand << " " << model << "First start your engine"<<endl;
             return;
        }
        cout<<"current gear is " << gear<<endl;
      }

      void accelerate(int speed) {
        currentSpeed = speed;
         if(!isEngineOn){
             cout<< brand << " " << model << "First start your engine"<<endl;
        }

        cout<<"Current Speed :"<< speed <<endl;
      }


      void brake() {
        currentSpeed -= 20;

         if(!isEngineOn){
             cout<< brand << " " << model << "First start your engine"<<endl;
        }

        cout<<"current speed after brake : " << currentSpeed << endl;

      }

      void stopEngine(){
        isEngineOn = false;
        currentGear =  0;
        currentSpeed = 0;
        cout<< brand << " " << model << " Engine is truned off" << endl;
      }
};


int main(){

    Car* myCar = new SportsCar("Ford","Mustang");
    myCar->startEngine();
    myCar-> shiftGear(2);
    myCar->accelerate(20);
    myCar->brake();

    return 0;
}