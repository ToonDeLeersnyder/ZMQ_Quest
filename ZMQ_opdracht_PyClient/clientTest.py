import time
import zmq
import string
import random
import secrets
import PySimpleGUI as sg


# Define the window's contents
layout = [[sg.Text("what service do you want? (type liefdesmeter)")],
          [sg.Input(key='-INPUT1-')],
          [sg.Text("want to compare names or dates? click 'names' or 'dates'")],
          [sg.Checkbox('Names:', default=True, key="-NamesCheck-"),
           sg.Checkbox('Dates:', default=False, key="-DatesCheck-")],
          [sg.Text("geef naam 1 of datum 1 in in (vb: jef of dd/mm/yyyy)")],
          [sg.Input(key='-INPUT3-')],
          [sg.Text("geef naam 2 of datum 2 in in (vb: jef of dd/mm/yyyy)")],
          [sg.Input(key='-INPUT4-')],
          [sg.Text(size=(40,1), key='-OUTPUT-')],
          [sg.Button('Ok'), sg.Button('Quit')]]

# Create the window
window = sg.Window('ToonSpecialService', layout)


    
    









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
        event, values = window.read()
        #    See if user wants to quit or window was closed
        if event == sg.WINDOW_CLOSED or event == 'Quit':
            break
         
        if values['-INPUT1-'] == "liefdesmeter":
            invalid = 0
            if values['-NamesCheck-']:
                naam1 = values['-INPUT3-']
                naam2 = values['-INPUT4-']
                sendtpic = ("ToonSpecialService>CooleLiefdesMeter?>Names>" + clientID + ">")
                var = sendtpic + naam1 + ">>" + naam2
                pusher.send_string(var)
            elif values['-DatesCheck-']:
                datum1 = values['-INPUT3-']
                datum2 = values['-INPUT4-']
                sendtpic = ("ToonSpecialService>CooleLiefdesMeter?>Dates>" + clientID + ">")
                var = sendtpic + datum1 + ">>" + datum2
                pusher.send_string(var)
            else:
                window['-OUTPUT-'].update("invalid compare type")
                
                invalid = 1
        
        else:
            
            window['-OUTPUT-'].update("invalid service")
            invalid = 1
            
            
            
        if (not invalid):
            

            
            msg = subscriber.recv()
            if msg == "b'ToonSpecialService>CooleLiefdesMeter!>USER:" + clientID + ":InvalidDates'":
                
                window['-OUTPUT-'].update("1 or 2 dates are invalid, try again!")
                
            elif msg == "b'ToonSpecialService>CooleLiefdesMeter!>USER:" + clientID + ":ServiceNotInUse'":
                window['-OUTPUT-'].update("service not in use")
                
            else:
                
                msg = msg.decode()
                splitblah = msg.split(":" + clientID + ":")
                if splitblah[1] == "InvalidDates":
                    
                   window['-OUTPUT-'].update("1 or 2 dates are invalid, try again!")
                elif int(splitblah[1]) <= 20:
                    window['-OUTPUT-'].update("Aw man this aint true love, ur love percentage is only " + splitblah[1] + "%")
                elif int(splitblah[1]) >20 and int(splitblah[1]) <=60:
                    window['-OUTPUT-'].update(" I see some sparks between you! love percentage is " + splitblah[1] + "%")
                    
                elif int(splitblah[1]) >60 and int(splitblah[1]) <=80:
                    window['-OUTPUT-'].update(" Damn almost true love! love percentage is " + splitblah[1] + "%")
                    
                elif int(splitblah[1]) >80 :
                    window['-OUTPUT-'].update("  True love! Thats what i like to see :)  " + splitblah[1] + "%")

producer()                
# Finish up by removing from the screen
window.close()                
            
            
           
        
        
        

