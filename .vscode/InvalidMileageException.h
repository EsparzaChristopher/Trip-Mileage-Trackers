#include <exception>
#include <iostream>

using namespace std;

class InvalidMileageException : public exception {
public: 
    InvalidMileageException()
    {
        message = "Invalid Mileage Input!";
    }
    InvalidMileageException(string str){
        message = str;
    }
    string what(){
        return message;
    }

private:
    string message;
};