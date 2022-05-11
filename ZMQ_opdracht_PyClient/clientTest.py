import time
import zmq
import string
import random
import secrets


context = zmq.Context()
def id_generator(N=6):
    return ''.join(secrets.choice(string.ascii_uppercase + string.digits) for _ in range(N))
def producer():   
    
    pusher= context.socket(zmq.PUSH)
    pusher.connect("tcp://benternet.pxl-ea-ict.be:24041")
    # pusher.connect( "tcp://0.0.0.0:24041" );

    subscriber = context.socket(zmq.SUB)
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042")
     
    # subscriber.connect( "tcp://0.0.0.0:24042" );
    
    clientID = id_generator(8)
    print (clientID)
    invalid = 0
    
    subscriber.setsockopt_string( zmq.SUBSCRIBE, "ToonSpecialService>CooleLiefdesMeter!>USER:" + clientID + ":")
    
    
    while True:        
        
        service = input("what service do you want? (type liefdesmeter) \n\r") 
        if service == "liefdesmeter":
            invalid = 0;
            keuze = input("want to compare names or dates? type 'names' or 'dates'\n\r")
            if keuze == "names":
                naam1 = input("geef naam 1 in (vb: jef) en enter:")
                naam2 = input("geef naam 2 in (vb: jef) en enter:")
                sendtpic = ("ToonSpecialService>CooleLiefdesMeter?>Names>" + clientID + ">")
                var = sendtpic + naam1 + ">>" + naam2
                pusher.send_string(var)
            elif keuze == "dates":
                datum1 = input("geef datum 1 in (vb: 31/12/2002) en enter:")
                datum2 = input("geef datum 2 in (vb: 31/12/2002) en enter:")
                sendtpic = ("ToonSpecialService>CooleLiefdesMeter?>Dates>" + clientID + ">")
                var = sendtpic + datum1 + ">>" + datum2
                pusher.send_string(var)
            else:
                print("invalid compare type")
                invalid = 1
        
        else:
            
            print("invalid service")
            invalid = 1
            
            
            
        if (not invalid):
            

            
            msg = subscriber.recv()
            if msg == "b'ToonSpecialService>CooleLiefdesMeter!>USER:" + clientID + ":InvalidDates'":
                print ("1 or 2 dates are invalid, try again! \n\r")
                print ("\n\r")
                print ("\n\r")
                print ("\n\r")
            elif msg == "b'ToonSpecialService>CooleLiefdesMeter!>USER:" + clientID + ":ServiceNotInUse'":
                print ("service not in use")
                print ("\n\r")
                print ("\n\r")
                print ("\n\r")
            else:
                
                msg = msg.decode()
                splitblah = msg.split(":" + clientID + ":")
                
                print ("\n\r")
                print ("\n\r")
                print ("\n\r")
                if int(splitblah[1]) <= 20:
                    print("Aw man this aint true love, ur love percentage is only " + splitblah[1] + "% \n\r")
                elif int(splitblah[1]) >20 and int(splitblah[1]) <=60:
                    print(" I see some sparks between you! love percentage is " + splitblah[1] + "% \n\r")
                elif int(splitblah[1]) >60 and int(splitblah[1]) <=80:
                    print(" Damn almost true love! love percentage is " + splitblah[1] + "% \n\r")
                elif int(splitblah[1]) >80 :
                    print(" True love! Thats what i like to see :) " + splitblah[1] + "% \n\r")
                print ( "<<<<<<<<love>>>>>>>>:"  + splitblah[1] )
                
                print ("\n\r")
                print ("\n\r")
                print ("\n\r")
            
            
           
        
        
        
producer()
