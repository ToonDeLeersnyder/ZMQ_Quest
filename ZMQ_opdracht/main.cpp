#include <stdio.h>
#include "server.h"
#include <iostream>
#include <string.h>
#include <ctime>
#include <zmq.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int main( void )
{


    Server * s1 = new Server();
    s1->serverStart();

}
