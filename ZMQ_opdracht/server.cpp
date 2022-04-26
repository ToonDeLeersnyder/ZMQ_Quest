#include "server.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <zmq.hpp>

server::server()
{
    try
    {
        zmq::context_t context(1);
        std::string topic( "ToonSpecialService>CooleLiefdesMeter?>" );
        std::string sendtpic( "ToonSpecialService>CooleLiefdesMeter!>AAAAAAAAAAAAp");






        zmq::socket_t pusher( context, ZMQ_PUSH );
        zmq::socket_t subscriber( context, ZMQ_SUB );

        pusher.connect( "tcp://benternet.pxl-ea-ict.be:24041" );
        //pusher.connect( "tcp://localhost:24041" );

        subscriber.connect( "tcp://benternet.pxl-ea-ict.be:24042" );
        //subscriber.connect( "tcp://localhost::24042" );


        subscriber.setsockopt( ZMQ_SUBSCRIBE, topic.c_str(), topic.length()  );

        zmq::message_t * msg = new zmq::message_t();





        while( subscriber.connected() )
        {

            subscriber.recv( msg );

            if (strcmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Start") == 0)
            {
              sendtpic =  "ToonSpecialService>CooleLiefdesMeter!>Send ur 2 Names or 2 birth dates like (21/01/1999) to ToonSpecialService>CooleLiefdesMeter?>Names or Dates";
              pusher.send(sendtpic.c_str(), sendtpic.length());


            }
            else if (strncmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Names>", 44) == 0)
            {
              printf("got the names");

              pusher.send(sendtpic.c_str(), sendtpic.length());

            }
            else if (strncmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Dates>", 44) == 0)
            {
              printf("got the dates");
              pusher.send(sendtpic.c_str(), sendtpic.length());
            }
            /* more else if clauses */
            else /* default: */
            {

            }


            std::cout << "Subscribed : [" << std::string( (char*) msg->data(), msg->size() ) << "]" << std::endl;

        }
    }
    catch( zmq::error_t & ex )
    {
        std::cerr << "Caught an exception : " << ex.what();
    }


}




