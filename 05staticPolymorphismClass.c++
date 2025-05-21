#include <bits/stdc++.h>
#include <vector>
using namespace std;
class ManualCar{
    private:
        string brand;
        string model;
        int currentSpeed;
        int currentGear;
        bool isEngineOn;
    
    public :
        ManualCar (string b, string m){
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

        void accelerate(int speed) {
            if(!isEngineOn){
                 cout<<brand << " " << model << "Engine is OFF" << endl;
            }
            currentSpeed += speed;
            cout<<brand << " " << model << " current speed "<< currentSpeed <<endl;
        }

        void brake(){
            currentSpeed -= currentSpeed;
            if(currentSpeed < 0 ) currentSpeed =  0;
            cout<<brand << " " << model<<" "<<"stop the car after breck " << endl;
        }

 };
int main(){

    ManualCar* myManualCar = new ManualCar("suzuki", "mangiR");

    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate(30);
    myManualCar->ShiftGear(3);
    myManualCar->brake();
    myManualCar->stopEngine();
    
    return 0;
}