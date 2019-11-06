#include "serial_com.hpp"

Serial_comm::Serial_comm(char *port){

    

    serial_port = open(port,
                        O_RDWR, //channel is open for both reading and writing
                        O_NOCTTY //no terminal will control the process opening the serial port
                        );
    if(serial_port == -1){
        cout<<"could not make Serial connecton"<<endl;
        
    }
    else{
       
    }
}

void Serial_comm::set_serial_config(){
    tcgetattr(serial_port,&serial_port_settings); //get current serial port settings and store in struct

    //set the speed for both reading and writing
    cfsetispeed(&serial_port_settings,B9600);
    cfsetospeed(&serial_port_settings,B9600);

    //clear parity bit...no parity bit
    //clear parity bit PARENB
    serial_port_settings.c_cflag &= ~PARENB;
    //number of stop bits
    //clear the CSTOPB bit
    serial_port_settings.c_cflag &= ~CSTOPB;
    //set the number of data bits to 8
    serial_port_settings.c_cflag &= ~CSIZE; //clears the mask
    serial_port_settings.c_cflag |= CS8; //set the data bits = 8
    //turn on hardware based flow control(RTS/CTS)
    serial_port_settings.c_cflag &= ~CRTSCTS;
    //turn on the receiver of the serial port(CREAD)
    serial_port_settings.c_cflag |= CREAD | CLOCAL;
    //Turn off software based flow control(XON/XOFF)
    serial_port_settings.c_cflag &= ~(IXON|IXOFF|IXANY);
    //set the comminication mode to Non cannonical
    serial_port_settings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    //commit the changes made
    tcsetattr(serial_port,TCSANOW,&serial_port_settings);

    //set to read data mode
    tcgetattr(serial_port, &serial_port_settings);                           
                                                              
    //Configure Baudrate()
    //Configure data bits()                                         
                                                                
    serial_port_settings.c_cflag |= CREAD | CLOCAL;//enable receiver
                                                                
    /* Setting Time outs */                                       
    serial_port_settings.c_cc[VMIN]  = 8; /* Read 10 characters */  
    serial_port_settings.c_cc[VTIME] = 0;  /* Wait indefinitely   */

                                                
    tcsetattr(serial_port,TCSANOW,&serial_port_settings); 
}

string Serial_comm::read_serial(){
    char read_buffer[22];                
    int  bytes_read = 0;
    string received_data;               
                                
    bytes_read = read(serial_port,&read_buffer,32);
    received_data = read_buffer;
    return received_data;
   }

Serial_comm::~Serial_comm(){
    close(serial_port);
}