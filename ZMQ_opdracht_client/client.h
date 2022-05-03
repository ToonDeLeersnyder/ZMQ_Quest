#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <zmq.hpp>


class client
{
public:
    client();
    void startClient();
    void liefdesmeterNames();
    void liefdesmeterDates();

    char service[101];
    char keuze[101];
    char naam1[101];
    char naam2[101];
    char date1[101];
    char date2[101];

     std::string sendtpic;

};

#endif // CLIENT_H
