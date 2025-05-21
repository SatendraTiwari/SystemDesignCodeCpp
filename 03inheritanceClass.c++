#include<iostream>
#include<string> 
using namespace std;

class  Car {
 public:
      string brand;
      string model;
      bool isEngineOn;
      int currentSpeed;
 public:      
      Car (string b, string a){
          this->brand = b;
          this->model = a;
          isEngineOn = false;
          currentSpeed = 0;
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

    //   void shiftGear(int gear){
    //     if(!isEngineOn){
    //          cout<< brand << " " << model << "First start your engine"<<endl;
    //          return;
    //     }
    //     cout<<"current gear is " << gear<<endl;
    //   }

      void accelerate(int speed) {
        currentSpeed = speed;
         if(!isEngineOn){
             cout<< brand << " " << model << "First start your engine"<<endl;
        }

        cout<<"Current Speed :"<< speed <<endl;
      }


      void brake() {
        currentSpeed -= currentSpeed;

         if(!isEngineOn){
             cout<< brand << " " << model << "First start your engine"<<endl;
        }

        cout<<"current speed after brake : " << currentSpeed << endl;

      }

      void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout<< brand << " " << model << " Engine is truned off" << endl;
      }
};


class ManualCar : public Car {
  private:
      int currentGear;

  public :
        ManualCar (string b, string m) : Car(b,m) {
            currentGear = 0;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout<< brand << " " <<model << " : shifted to gear " << currentGear<<endl;
        }
};


class ElectricCar : public Car{
  private: 
      int betteryLevel;

  public : 
       ElectricCar(string b, string m) : Car(b,m) {
            betteryLevel = 80;
       }
       void chageBattery() {
        betteryLevel = 100;
        cout<<brand << " "<< model << " : battry fully charged!"<<endl;
       }
};

int main() {
    ManualCar* myManualCar = new ManualCar("Suzuki", "MaginR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate(10);
    myManualCar->brake();
    myManualCar->stopEngine();
    cout<<"-----------------------" <<endl;
    ElectricCar* myElectricCar = new ElectricCar("tesla", "model 5");
    myElectricCar->chageBattery(); // specific to electric car
    myElectricCar->startEngine();
    myElectricCar->accelerate(10); 
    myElectricCar->brake();
    myElectricCar->stopEngine();
}