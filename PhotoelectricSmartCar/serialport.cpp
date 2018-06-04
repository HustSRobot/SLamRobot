#include"serialport.h"

using namespace std;

int serial_fd = 0;
#define DEVICE "~/dev/ttyUSB0"

int init_serial(void)
{
    serial_fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (serial_fd < 0) {
        perror("open");
        return -1;
    }


    struct termios options;


    tcgetattr(serial_fd, &options);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag &= ~CRTSCTS;
    options.c_cflag |= CS8;
    options.c_cflag &= ~CSTOPB;
    options.c_iflag |= IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    cfsetospeed(&options, B9600);


    tcflush(serial_fd, TCIFLUSH);
    tcsetattr(serial_fd, TCSANOW, &options);

    return 0;
}


int uart_send(int fd, char *data, int datalen)
{
    int len = 0;
    len = write(fd, data, datalen);
    if(len == datalen) {
        return len;
    } else {
        tcflush(fd, TCOFLUSH);
        return -1;
    }

    return 0;
}


int uart_recv(int fd, char *data, int datalen)
{
    int len=0, ret = 0;
    fd_set fs_read;
    struct timeval tv_timeout;

    FD_ZERO(&fs_read);
    FD_SET(fd, &fs_read);
    tv_timeout.tv_sec  = (10*20/115200+2);
    tv_timeout.tv_usec = 0;

    ret = select(fd+1, &fs_read, NULL, NULL, &tv_timeout);




    if (FD_ISSET(fd, &fs_read)) {
        len = read(fd, data, datalen);

        return len;
    } else {
        perror("select");
        return -1;
    }

    return 0;
}
