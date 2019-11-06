#ifndef _SERIAL_COM_HPP
#define _SERIAL_COM_HPP

#include <iostream>
#include <fcntl.h> //file control definitions
#include <termios.h> //POSIX terminal control definitions
#include <unistd.h> //unix standard definitions
#include <errno.h> //error number definitions
#include <string.h>

using namespace std;

class Serial_comm{
    private:
        char active_serial_port[40];
        int serial_port;
        termios serial_port_settings;
    private:
    public:
    public:
        Serial_comm(char *port);
        ~Serial_comm();
        void set_serial_config();
        string read_serial();
};

#endif //_SERIAL_COM_HPP