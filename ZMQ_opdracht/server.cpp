#include "server.h"
#include <ctime>
#include <iostream>
#include <fstream>


Server::Server()
:context(1),pusher(context, ZMQ_PUSH),subscriber(context,ZMQ_SUB)
{


}

void Server::serverStart()
{
    try
    {

        csvread();
        sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER::AAAAAAAAAAAAp");


        pusher.connect( "tcp://benternet.pxl-ea-ict.be:24041" );
        //pusher.connect( "tcp://0.0.0.0:24041" );

        subscriber.connect( "tcp://benternet.pxl-ea-ict.be:24042" );
        //subscriber.connect( "tcp://0.0.0.0:24042" );



        subscriber.setsockopt( ZMQ_SUBSCRIBE, topic.c_str(), topic.length()  );

        zmq::message_t * msg = new zmq::message_t();





        while( subscriber.connected() )
        {

            subscriber.recv( msg );

            if (strcmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Start") == 0)
            {

              sendtpic =  "ToonSpecialService>CooleLiefdesMeter!>Send ur 2 Names like jef etc  or 2 birth dates like (21/1/1999) to ToonSpecialService>CooleLiefdesMeter?>Names>[client id 8 char long]>[naam1]>>[naam2] or ToonSpecialService>CooleLiefdesMeter?>dates>[client id 8 char long]>[date1]>>[date2]  you will get a love percentage as return.";
              pusher.send(sendtpic.c_str(), sendtpic.length());

            }
            else if (strncmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Names>", 44) == 0)
            {
              std::string text;
              std::string textParsed;
              std::string variable1;
              std::string variable2;
              std::string temp;
              int love = 0;

              text =  std::string( (char*) msg->data(),msg->size() );
              textParsed = text.substr(text.find("?>Names") + 8);
              USERID = textParsed.substr(0, textParsed.find(">"));
              if ((USERID.length() >=9 or USERID.length() <= 7)  and USERID.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") != std::string::npos)
              {
                  USERID = "nicetry!";
                  textParsed = ">Jo>>Mama";
              }
              temp = textParsed.substr(9, textParsed.find(">>"));
              variable1 = temp.substr(0, temp.find(">>"));
              variable2 = textParsed.substr(textParsed.find(">>") + 2);
              std::cout << "got the names " << variable1 << " and " << variable2 <<  " from user " << USERID << "\n";

              love = calculateNameLove(variable1,variable2);

              sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":" + std::to_string(love)  );
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

              if ((USERID.length() >=9 or USERID.length() <= 7)  and USERID.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") != std::string::npos)
              {
                  USERID = "nicetry!";
                  textParsed = ">1/12/2002>>01/12/2002";
              }

              temp = textParsed.substr(9, textParsed.find(">>"));
              variable1 = temp.substr(0, temp.find(">>"));
              variable2 = textParsed.substr(textParsed.find(">>") + 2);
              std::cout << "got the dates " << variable1 << " and " << variable2 << " from user " << USERID << "\n";

              if (checkDates(variable1) && checkDates(variable2))
              {
                  int love = 0;
                  std::cout << "dates are valid, continue\n";

                  if (Agecheck( variable1, variable2))
                  {
                      sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":This is kind of sus, please check https://www.ejustice.just.fgov.be/cgi_loi/change_lg.pl?language=nl&la=N&cn=2022032101&table_name=wet");
                      pusher.send(sendtpic.c_str(), sendtpic.length());



                  }
                  else
                  {
                      love = calculateDateLove(variable1 , variable2);
                      sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":" + std::to_string(love));
                      pusher.send(sendtpic.c_str(), sendtpic.length());



                  }



              }
              else{

                  std::cout << "1 or 2 dates are invalid\n";
                  sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":InvalidDates");
                  pusher.send(sendtpic.c_str(), sendtpic.length());
              }
            }
            /* more else if clauses */

            else if (strncmp((char*) msg->data(), "ToonSpecialService>CooleLiefdesMeter?>Register>", 47) == 0)
            {
                std::string text;
                std::string textParsed;
                std::string variable1;
                std::string variable2;
                std::string temp;
                std::string tempName;
                std::string tempDate;
                int love = 0;
                int love1 = 0;
                int love2 = 0;

                text =  std::string( (char*) msg->data(),msg->size() );
                textParsed = text.substr(text.find("?>Register") + 11);
                USERID = textParsed.substr(0, textParsed.find(">"));
                if ((USERID.length() >=9 or USERID.length() <= 7)  and USERID.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") != std::string::npos)
                {
                    USERID = "nicetry!";
                    textParsed = ">Jo>>Mama";
                }
                temp = textParsed.substr(9, textParsed.find(">>"));
                variable1 = temp.substr(0, temp.find(">>"));
                variable2 = textParsed.substr(textParsed.find(">>") + 2);
                std::cout << "got the name " << variable1 << " and date " << variable2 <<  " from user " << USERID << "\n";

                std::fstream fout;
                fout.open("register.csv", std::ios::out | std::ios::app);
                fout << variable1 << ", "
                     << variable2
                     << "\n";
                fout.close();

                for(int i=0;i<content.size();i++)
                {

                    for(int j=0;j<content[i].size();j++)
                    {
                        std::cout<<content[i][j]<<" ";
                        love1 = calculateNameLove(variable1, content[i][0]);
                        if (!Agecheck( variable2, content[i][1]))
                        {
                            love2 = calculateDateLove(variable1 , content[i][1]);
                        }

                        if ((love1 > love) and (!Agecheck( variable2, content[i][1])))
                        {
                            love = love1;
                            tempName = content[i][0];
                            tempDate = content[i][1];

                        }
                        if ((love2 > love) and (!Agecheck( variable2, content[i][1])))
                        {
                            love = love2;
                            tempName = content[i][0];
                            tempDate = content[i][1];

                        }
                    }

                }
                if (love == 0)
                {

                    sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":geen geschikte kandidaat");
                    //pusher.send(sendtpic.c_str(), sendtpic.length());

                }
                else
                {
                    sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":REG" + tempName + ":" + tempDate + ":" + std::to_string(love));
                    //pusher.send(sendtpic.c_str(), sendtpic.length()); PUSH NOG NIET WANT CLIENT WERKT NIET OP RECIEVE VAN DIT TYPE




                }

                std::cout << "got the name " << tempName << " and date " << tempDate <<  " from user " << love << "\n";


            }
            else /* default: */
            {
                sendtpic = ( "ToonSpecialService>CooleLiefdesMeter!>USER:" + USERID + ":ServiceNotInUse");
                pusher.send(sendtpic.c_str(), sendtpic.length());
            }


            std::cout << "Subscribed : [" << std::string( (char*) msg->data(), msg->size() ) << "]" << std::endl;

        }
    }
    catch( zmq::error_t & ex )
    {
        std::cerr << "Caught an exception : " << ex.what();
    }

}



int Server::calculateDateLove(std::string date1 , std::string date2)
{

    int d1;
    int d2;
    int m1;
    int m2;
    int y1;
    int y2;
    parseDates(date1 ,  &d1 ,  &m1 ,  &y1);
    parseDates(date2 ,  &d2 ,  &m2 ,  &y2);

    int love;
    love = d1 + d2 + m1 + m2 + Sum_of_Digits(y1) + Sum_of_Digits(y2);
    if (love > 100)
    {
        love = 100;

    }
    return love;



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
    std::size_t found = date1.find("/");
    if (found==std::string::npos)
    {
    date1 = "01/01/2000";

    }

    variable1 = date1.substr(0, date1.find("/"));
    variable2 = date1.substr(date1.find("/") + 1);
    variable3 = variable2.substr(0, variable2.find("/"));
    variable4 = variable2.substr(variable2.find("/")+ 1);



     *d = std::stoi( variable1 );
     *m = std::stoi( variable3 );
     *y = std::stoi( variable4 );
}


int Server::Sum_of_Digits(int waarde)
    {
       int sum =0;
       while(waarde > 0)
          {
              sum +=(waarde%10);
              waarde/=10;
          }
       return sum;
}

bool Server::Agecheck(std::string date1, std::string date2)
{
    const int MAXLEN = 80;
    char Yeartoday[MAXLEN];
    time_t t = time(0);
    strftime(Yeartoday, MAXLEN, "%Y", localtime(&t));
    std::cout << Yeartoday << '\n';

    int d1;
    int d2;
    int m1;
    int m2;
    int y1;
    int y2;

    parseDates(date1 ,  &d1 ,  &m1 ,  &y1);
    parseDates(date2 ,  &d2 ,  &m2 ,  &y2);

    int calculated_year1 = atoi( Yeartoday) - y1;
    int calculated_year2 = atoi( Yeartoday) - y2;

    if ((calculated_year1 >= 18 and calculated_year2 <= 16) or (calculated_year2 >= 18 and calculated_year1 <= 16))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Server::csvread()
{
    std::fstream file;



    std::vector<std::string> row;
    std::string line, word;

    file.open("register.csv", std::ios::in );
    if(file.is_open())
    {
    while(getline(file, line))
    {
    row.clear();

    std::stringstream str(line);

    while(getline(str, word, ','))
    row.push_back(word);
    content.push_back(row);
    }
    }
    else
    std::cout<<"Could not open the file\n";

    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            std::cout<<content[i][j]<<" ";
        }
    std::cout<<"\n";
    }



}

int Server::calculateNameLove( std::string naam1, std::string  naam2  )
{
    int ns= 0 ,ps = 0,love_percentage = 0,love=54;


             for(int i =0; i<naam1.length(); i++)
                {
                   ns += (std::tolower(naam1.at(i))-96);
                }

             for(int j = 0; j < naam2.length(); j++)
                {

                 ps+=(std::tolower(naam2.at(j))-96);
                }

              love_percentage = (Sum_of_Digits(ns)+Sum_of_Digits(ps)+love);




    return love_percentage;
}




