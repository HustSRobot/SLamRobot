#ifndef _SERIALPORT_H
#define _SERIALPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

using namespace std;

int uart_send(int fd, char *data, int datalen);
int uart_recv(int fd, char *data, int datalen);
int init_serial(void);

extern int serial_fd;
#endif// !_SERIALPORT_H

