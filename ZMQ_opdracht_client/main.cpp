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
        //std::string sendtpic( "4 op een rij!>play>");

        //Incoming messages come in here



        zmq::socket_t pusher( context, ZMQ_PUSH );
        zmq::socket_t subscriber( context, ZMQ_SUB );

        pusher.connect( "tcp://benternet.pxl-ea-ict.be:24041" );
        subscriber.connect( "tcp://benternet.pxl-ea-ict.be:24042" );

        subscriber.setsockopt( ZMQ_SUBSCRIBE, topic.c_str(), topic.length()  );

        zmq::message_t * msg = new zmq::message_t();



       // pusher.send( "example>quest?>Toon De Leersnyder>", 38 );


        char service[101];
        char keuze[101];
        char naam1[101];
        char naam2[101];
        char date1[101];
        char date2[101];


        while( subscriber.connected() )
        {
            char service[101];
            printf("what service do you want?\n\r");
            scanf("%100s", service);

            if (!strcmp(service, "liefdesmeter"))
            {

                printf("want to compare names or dates?\n\r");
                scanf("%100s", keuze);
                if (!strcmp(keuze, "names"))
                {
                    printf("give 2 names in 2 seperate enters\n\r");
                    scanf("%100s \n\r", naam1);
                    scanf("%100s", naam2);
                    sendtpic = "ToonSpecialService>CooleLiefdesMeter?>Names>";
                    std::string var = sendtpic + naam1 + ">>" + naam2;
                    std::cout << "Follow this command: " << var;
                    pusher.send(sendtpic.c_str(), sendtpic.length());

                }
                else if (!strcmp(keuze, "dates"))
                {
                    printf("give 2 dates in 2 seperate enters\n\r");
                    scanf("%100s \n\r", date1);
                    scanf("%100s", date2);
                    sendtpic = "ToonSpecialService>CooleLiefdesMeter?>Dates>";
                    pusher.send(sendtpic.c_str(), sendtpic.length());

                }
           }

           else if (!strcmp(service, "rekenmachine"))
            {



            }

           // pusher.send(sendtpic.c_str(), sendtpic.length());
            subscriber.recv( msg );

            std::cout << "Subscribed : [" << std::string( (char*) msg->data(), msg->size() ) << "]" << std::endl;

        }
    }
    catch( zmq::error_t & ex )
    {
        std::cerr << "Caught an exception : " << ex.what();
    }

    return 0;
}
