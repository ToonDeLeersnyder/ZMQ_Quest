#include <iostream>
#include <string.h>
#include <stdio.h>
#include <zmq.hpp>

int main( void )
{
    try
    {
        zmq::context_t context(1);
        std::string topic( "ToonSpecialService>CooleLiefdesMeter?>" );
        std::string sendtpic( "ToonSpecialService>CooleLiefdesMeter!>AAAAAAAAAAAAp");






        zmq::socket_t pusher( context, ZMQ_PUSH );
        zmq::socket_t subscriber( context, ZMQ_SUB );

        pusher.connect( "tcp://benternet.pxl-ea-ict.be:24041" );
        subscriber.connect( "tcp://benternet.pxl-ea-ict.be:24042" );

        subscriber.setsockopt( ZMQ_SUBSCRIBE, topic.c_str(), topic.length()  );

        zmq::message_t * msg = new zmq::message_t();



       // pusher.send( "example>quest?>Toon De Leersnyder>", 38 );
        //pusher.send(sendtpic.c_str(), sendtpic.length());


        while( subscriber.connected() )
        {

            subscriber.recv( msg );

            if (strcmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Start") == 0)
            {
              sendtpic =  "ToonSpecialService>CooleLiefdesMeter!>Send ur 2 Names or 2 birth dates to ToonSpecialService>CooleLiefdesMeter?>Names or Dates";
              pusher.send(sendtpic.c_str(), sendtpic.length());




            }
            else if (strcmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Names>") == 0)
            {
              // do something else
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

    return 0;
}
