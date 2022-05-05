#include "server.h"


Server::Server()
:context(1),pusher(context, ZMQ_PUSH),subscriber(context,ZMQ_SUB)
{


}

void Server::serverStart()
{
    try
    {


        sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER::AAAAAAAAAAAAp");


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

              sendtpic =  "ToonSpecialService>CooleLiefdesMeter!>Send ur 2 Names or 2 birth dates like (21/1/1999) to ToonSpecialService>CooleLiefdesMeter?>Names or Dates";
              pusher.send(sendtpic.c_str(), sendtpic.length());

            }
            else if (strncmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Names>", 44) == 0)
            {
              std::string text;
              std::string textParsed;
              std::string variable1;
              std::string variable2;
              std::string temp;

              text =  std::string( (char*) msg->data(),msg->size() );
              textParsed = text.substr(text.find("?>Names") + 8);
              USERID = textParsed.substr(0, textParsed.find(">"));
              temp = textParsed.substr(9, textParsed.find(">>"));
              variable1 = temp.substr(0, temp.find(">>"));
              variable2 = textParsed.substr(textParsed.find(">>") + 2);
              std::cout << "got the names " << variable1 << " and " << variable2 <<  " from user " << USERID << "\n";
              sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":AAAAAAAAAAAAp");
              pusher.send(sendtpic.c_str(), sendtpic.length());

            }
            else if (strncmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Dates>", 44) == 0)
            {
              std::string text;
              std::string textParsed;
              std::string variable1;
              std::string variable2;
              std::string temp;

              text =  std::string( (char*) msg->data(),msg->size() );
              textParsed = text.substr(text.find("?>Dates") + 8);
              USERID = textParsed.substr(0, textParsed.find(">"));
              temp = textParsed.substr(9, textParsed.find(">>"));
              variable1 = temp.substr(0, temp.find(">>"));
              variable2 = textParsed.substr(textParsed.find(">>") + 2);
              std::cout << "got the dates " << variable1 << " and " << variable2 << " from user " << USERID << "\n";
              sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":AAAAAAAAAAAAp");
              pusher.send(sendtpic.c_str(), sendtpic.length());
              if (checkDates(variable1) && checkDates(variable2))
              {
                  std::cout << "dates are valid\n";

              }
              else{

                  std::cout << "1 or 2 dates are invalid\n";
              }
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

void Server::liefdesmeterNames(std::string name , std::string name2)
{




}

void Server::liefdesmeterDates(std::string date1 , std::string date2)
{

    int d1;
    int d2;
    int m1;
    int m2;
    int y1;
    int y2;
    parseDates(date1 ,  &d1 ,  &m1 ,  &y1);
    parseDates(date2 ,  &d2 ,  &m2 ,  &y2);



}

bool Server::checkDates(std::string date)
{


    int d;
    int m;
    int y;
    parseDates(date ,  &d ,  &m ,  &y);
    std::cout << "got the dates " << d<<  " and " << m << " and " << y  << "\n";

    const int MAX_VALID_YR = 2300;
    const int MIN_VALID_YR = 1800;



        if (y > MAX_VALID_YR ||
            y < MIN_VALID_YR)
        return false;
        if (m < 1 || m > 12)
        return false;
        if (d < 1 || d > 31)
        return false;

        // Handle February month
        // with leap year
        if (m == 2)
        {
            if (isLeap(y))
            return (d <= 29);
            else
            return (d <= 28);
        }

        // Months of April, June,
        // Sept and Nov must have
        // number of days less than
        // or equal to 30.
        if (m == 4 || m == 6 ||
            m == 9 || m == 11)
            return (d <= 30);

        return true;

}

bool Server::isLeap(int year)
{
   return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
             (year % 400 == 0));
}

void Server::parseDates(std::string date1 , int* d , int* m , int* y)
{
    std::string variable1;
    std::string variable2;
    std::string variable3;
    std::string variable4;


    variable1 = date1.substr(0, date1.find("/"));
    variable2 = date1.substr(date1.find("/") + 1);
    variable3 = variable2.substr(0, variable2.find("/"));
    variable4 = variable2.substr(variable2.find("/")+ 1);

    std::cout << "got the dates " << variable1 <<  " and " << variable3 << " and " << variable4  << "\n";

     *d = std::stoi( variable1 );
     *m = std::stoi( variable3 );
     *y = std::stoi( variable4 );
}




