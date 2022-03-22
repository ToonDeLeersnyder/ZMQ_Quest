#include <iostream>
#include <string>
#include <zmq.hpp>

int main( void )
{
    try
    {
        zmq::context_t context(1);
        std::string topic( "ToonSpecialService>CooleLiefdesMeter!>" );
        std::string sendtpic( "ToonSpecialService>CooleLiefdesMeter?>Start");

        //Incoming messages come in here



        zmq::socket_t pusher( context, ZMQ_PUSH );
        zmq::socket_t subscriber( context, ZMQ_SUB );

        pusher.connect( "tcp://benternet.pxl-ea-ict.be:24041" );
        subscriber.connect( "tcp://benternet.pxl-ea-ict.be:24042" );

        subscriber.setsockopt( ZMQ_SUBSCRIBE, topic.c_str(), topic.length()  );

        zmq::message_t * msg = new zmq::message_t();



       // pusher.send( "example>quest?>Toon De Leersnyder>", 38 );
        pusher.send(sendtpic.c_str(), sendtpic.length());


        while( subscriber.connected() )
        {

            subscriber.recv( msg );

            std::cout << "Subscribed : [" << std::string( (char*) msg->data(), msg->size() ) << "]" << std::endl;
            printf("yeet3");
        }
    }
    catch( zmq::error_t & ex )
    {
        std::cerr << "Caught an exception : " << ex.what();
    }

    return 0;
}
