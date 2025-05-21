#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

class Car {
    protected:
        string brand;
        string model; 
        bool isEngineOn;
        int currentSpeed;
    public: 
       
        Car(string brand, string model){
            this->brand = brand;
            this->model = model;
            this->isEngineOn = false;
            this->currentSpeed = 0;
        }

        void startEngine() {
            isEngineOn = true;
            cout<< brand << " " << model << "Engine is ON" <<endl;
        }

        void stopEngine() {
            isEngineOn = false;
            cout<<brand << " " << model << "Engine is OFF"<<endl;
        }

        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual ~Car() {}
 };

 class ManualCar : public Car{
    private:
        int currentGear;
    
    public :
        ManualCar (string b, string m) : Car(b,m){
            this->currentGear = 0;
        }

        void ShiftGear (int gear) {
            if(!isEngineOn){
                cout<<brand << " " << model << "Engine is OFF" << endl;
            }

            currentGear = gear;
             cout<<brand << " " << model << "Engine is On is " << gear << endl;
        }

        // Overriding accelerate -> Dynamic polumorphism 
        void accelerate() {
            if(!isEngineOn){
                 cout<<brand << " " << model << "Engine is OFF" << endl;
            }
            currentSpeed += 20;
            cout<<brand << " " << model << " current speed "<< currentSpeed <<endl;
        }

        void brake(){
            currentSpeed -= currentSpeed;
            if(currentSpeed < 0 ) currentSpeed =  0;
            cout<<brand << " " << model<<" "<<"stop the car after breck " << endl;
        }

 };


 class ElectricCar : public Car{
    private:
        int batteryLevel;
    
    public :
        ElectricCar (string b, string m) : Car(b,m){
            this->batteryLevel = 100;
        }

        // Overriding accelerate -> Dynamic polumorphism 
        void accelerate() {
            if(!isEngineOn){
                 cout<<brand << " " << model << " Engine is OFF" << endl;
            }
            currentSpeed += 20;
            cout<<brand << " " << model << " "<<endl;
        }

        void brake(){
            currentSpeed -= currentSpeed;
            this->batteryLevel = 0;
            if(currentSpeed < 0 ) currentSpeed =  0;
            cout<<brand << " " << model<<" stop the car after breck " << endl;
        }

        void chargeBattery() {
            if(batteryLevel == 0)
                this->batteryLevel = 100;
            cout<<brand << " " <<model << "battery charged"<<endl;
        }

 };

int main(){
    ManualCar* myManualCar = new ManualCar("suzuki","MaginR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->ShiftGear(2);
    myManualCar->brake();
    myManualCar->stopEngine();
    cout<<"-----------------------------"<<endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla","model 5");

    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->chargeBattery();
    myElectricCar->brake();
    myElectricCar->chargeBattery();
    myElectricCar->stopEngine();
    
    return 0;
}