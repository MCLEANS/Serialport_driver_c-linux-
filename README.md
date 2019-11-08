# Serialport_driver_c-linux-
A driver to help communication between a linux computer and an external serial device

## Getting data from serial port
The constructor of the class takes in the "serial_port name" e.g /dev/ttyS90

    #include <iostream>
    #include <serial_com.hpp>
    
    char port[] = "/dev/ttyS90";
    Serial_com serial(port);
    
    
    using namespace std;
    int main(){
      
      //get the serial data and save into a string
      std::string serial_data = serial.read_serial();
      std::cout<<serial_data<<std::endl;
      return 0;
    }

As indicated above to get the data after making an object of the Serial_com class we use the read_serial() method which returns a string of the data received

The serial port connection is automatically closed in the destructor when the object goes out of scope
