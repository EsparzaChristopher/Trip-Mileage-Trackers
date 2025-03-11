#include <iostream>
#include <fstream>
#include "InvalidMileageException.h"

using namespace std;



ofstream outfile("ErrorLogs.txt");
void calculateMileage(double i, double f){
    double traveledMiles;
    //Check to make sure initial mileage is less than destination mileage
    if(i > f){
        cout << "Initializing stack unwinding, returning to MileageTracker().\n";
        //If initial mileage is greater than destination, throw an exception
        throw invalid_argument("A starting value of a higher number is not allowed!"); //Beginning of Stack unwinding
    }
    //Calculate total miles traveled
    traveledMiles = f - i;
    

    //Prints out the miles traveled
    cout << "Total miles traveled: " << traveledMiles << endl;
}
//Mileage Tracker
void MileageTracker(){
    double initMileage, destMileage;
    try{
        //Prompt user for starting mileage
    cout << "Please provide a starting mileage value: ";

    //Input the starting mileage
    cin >> initMileage;
    
    //Check to ensure initial mileage is non-negative
    if(initMileage < 0){
        //If initial mileage is negative, throw an exception
        throw InvalidMileageException("A negative mileage value is not allowed!");
    }
    //Prompt user for destination mileage
    cout << "Please provide a destination mileage value: ";

    //Input the destination mileage
    cin >> destMileage;

    //Check to ensure destionation mileage is non-negative 
    if(destMileage < 0){
        //If destination mileage is negative, throw an exception
        throw InvalidMileageException("A negative mileage value is not allowed!");
    }

    //Check to make sure initial mileage is less than destination mileage
   calculateMileage(initMileage, destMileage);
    }
    //Catch exception for invalid arguments
    catch( InvalidMileageException e){
        outfile << "Error: " << e.what() << endl;
        MileageTracker();
    }
    catch(invalid_argument e){
        cout << "Stack Unwinding Achieved!\n";
        outfile << "Error: " << e.what() << endl;
        MileageTracker();
    }
    catch(...){
        cout << "Error: An unexpected error has occurred. Terminating Program.\n";
        outfile << "Error: An unexpected error has occurred. Terminating Program.\n";
        exit(0);
    }
    
} 






int main(){
    MileageTracker();
    return 0;
}