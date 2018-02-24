/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fifo2.cpp
 * Author: comelli
 *
 * Created on 10 de Fevereiro de 2018, 17:14
 */

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
    char str1[80], str2[80];
    
    mkfifo(FIFO_PATH, 0666);
    
    while (1)
        {
        fd = open(FIFO_PATH, O_RDONLY);
        read(fd, str1, sizeof(str1));
        printf("Mensagem recebida: %s", str1);
        close(fd);
        
        fd = open(FIFO_PATH, O_WRONLY);
        printf("Digite até 80 caracteres: ");
        fgets(str2, 80, stdin);
        write(fd, str2, sizeof(str2));
        close(fd);        
        }

    return 0;
    }

