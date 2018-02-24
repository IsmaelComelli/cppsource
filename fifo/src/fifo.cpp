#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#define FIFO_PATH "/tmp/fifo.txt"

int main()
    {
    int fd;
    char arr1[80], arr2[80];
    
    mkfifo(FIFO_PATH, 0666);
    
    while (1)
        {
        fd = open(FIFO_PATH, O_WRONLY);
        printf("Digite até 80 caracteres: ");
        fgets(arr2, 80, stdin);
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
        
        fd = open(FIFO_PATH, O_RDONLY);
        read(fd, arr1, sizeof(arr1));
        printf("Lido do arquivo: %s", arr1);
        close(fd);
        }
    
    return 0;
    } 

