#ifndef SERVER_H
#define SERVER_H
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <zmq.hpp>

class Server
{
public:
    Server();
    void serverStart();
    void liefdesmeterNames(std::string var, std::string var2);
    int calculateDateLove(std::string date1 , std::string date2);
    bool checkDates(std::string date);
    bool isLeap(int year);
    void parseDates (std::string date1 ,  int* d , int* m , int* y);
    int calculateNameLove( std::string naam1, std::string  naam2  );
    int Sum_of_Digits(int waarde);
    bool Agecheck(std::string date1, std::string date2);
    void csvread();

    std::string sendtpic;
    std::string USERID;
    std::string topic = ( "ToonSpecialService>CooleLiefdesMeter?>" );
    std:: string variable1;
    std:: string variable2;
    std::vector<std::vector<std::string>> content;
private:
    zmq::context_t context;
    zmq::socket_t pusher;
    zmq::socket_t subscriber;


};

#endif // SERVER_H
