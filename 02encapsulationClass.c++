#include<iostream>
#include<string> 
using namespace std;


class  SportsCar {
 private:
      string brand;
      string model;
      bool isEngineOn;
      int currentSpeed;
      int currentGear;
 public:      
      SportsCar (string b, string a){
          this->brand = b;
          this->model = a;
          isEngineOn = false;
          currentSpeed = 0;
          currentGear = 0;
      }

      int getCurrenSpeed() {
        return this->currentSpeed; // this is keyword 'esi class ke sabhi vriable ka access hain this ke paas"
      }

      int setCurrentSpeed(int speed){
        currentSpeed = speed;
        return currentSpeed;
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

    SportsCar* mySportCar = new SportsCar("Ford","Mustang");
    mySportCar->startEngine();
    mySportCar-> shiftGear(2);
    mySportCar->accelerate(20);
    mySportCar->brake();
    cout<<"Get current speed "<<mySportCar->getCurrenSpeed()<<endl;
    cout<<"Set current speed "<<mySportCar->setCurrentSpeed(400)<<endl;
    

    // mySportCar->currentSpeed = 500;
    // cout<<"Current Speed of my car is set to : "<<mySportCar->currentSpeed << endl;


    delete mySportCar;

    return 0;
}