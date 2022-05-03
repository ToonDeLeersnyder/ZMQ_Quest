#ifndef SERVER_H
#define SERVER_H
#include <string.h>
#include <stdio.h>
#include <iostream>

class Server
{
public:
    Server();
    void serverStart();
    void liefdesmeterNames(std::string var, std::string var2);
    void liefdesmeterDates(std::string date1 , std::string date2);
    bool checkDates(std::string date);
    bool isLeap(int year);
    void parseDates (std::string date1 ,  int* d , int* m , int* y);


    std::string sendtpic;
    std::string USERID;
    std::string topic = ( "ToonSpecialService>CooleLiefdesMeter?>" );

};

#endif // SERVER_H
