#include <bits/stdc++.h>
#include <vector>
#include<string>
using namespace std;

class Car
{
protected:
    string brand;
    string model;
    int currentSpeed;
    bool isEngineOn;
public:
    Car(string b,string m){
        this->brand = b;
        this->model = m;
        this->isEngineOn = true;
        this->currentSpeed = 0;
    }

    void startEngine() {
        this->isEngineOn = true;
        cout<<brand<<" "<<model<<" Engine is ON"<<endl;
    }

    void stopEngine(){
        this->isEngineOn = false;
        cout<<brand << " "<< model << "Engine is OFF"<< endl;
    }

    virtual void accelerate() = 0;
    virtual void accelerate(int speed) = 0;
    virtual void brake() = 0;
    virtual ~Car(){};
};

class ManualCar: public Car{
    protected:
        int currentGear;
    
    public:
        ManualCar(string b, string m) : Car(b,m){
            this->currentGear = 0;
        }

        void shiftGear(int gear){
            this->currentGear = gear;
            cout<<brand << " " << model << "Current Gear is " << currentGear;
        }

        void accelerate(){
            if(!isEngineOn){
                cout<<brand << " " <<model << "Engine is OFF"<<endl;
            }

            this->currentSpeed += 20;
            cout<<brand<<" "<<model<<"current speed is" << currentSpeed<<endl;
        }

         void accelerate(int speed){
            if(!isEngineOn){
                cout<<brand << " " <<model << "Engine is OFF"<<endl;
            }

            this->currentSpeed += speed;
            cout<<brand<<" "<<model<<"current speed is" << currentSpeed<<endl;
            
        }

        void brake() {
            if(!isEngineOn){
                cout<<brand << " " <<model << "Engine is OFF"<<endl;
            }
            if(currentSpeed <= 0) currentSpeed = 0;
            this->currentGear = 0; 
            this->currentSpeed = 20;

            cout<<brand<<" "<<model << "Current Gear and Current Speed is "<<currentGear<< " and " << currentSpeed<<endl;
            
        }
        


};

class ElectricCar: public Car{

     protected:
        int betteryLevel;
    
    public:
        ElectricCar(string b, string m) : Car(b,m){
            this->betteryLevel = 100;
        }

        void betteryCharge(int gear){
            this->betteryLevel = 100;
            cout<<brand << " " << model << "Current Gear is " << betteryLevel;
        }

        void accelerate(){
            if(!isEngineOn){
                cout<<brand << " " <<model << "Engine is OFF"<<endl;
            }

            this->currentSpeed += 20;
            cout<<brand<<" "<<model<<"current speed is" << currentSpeed<<endl;
        }

         void accelerate(int speed){
            if(!isEngineOn){
                cout<<brand << " " <<model << "Engine is OFF"<<endl;
            }

            this->currentSpeed += speed;
            cout<<brand<<" "<<model<<"current speed is" << currentSpeed<<endl;
            
        }

        void brake() {
            if(!isEngineOn){
                cout<<brand << " " <<model << "Engine is OFF"<<endl;
            }
            if(currentSpeed <= 0) currentSpeed = 0;
            this->betteryLevel = 0; 
            this->currentSpeed = 20;

            cout<<brand<<" "<<model << "Current Gear and Current Speed is "<<betteryLevel<< " and " << currentSpeed<<endl;
            
        }
};


int main(){

    return 0;
}