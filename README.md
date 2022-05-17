# Liefdesmeter

The zmq server calculates love percentage of 2 names or 2 dates that are provided by the python client and sends thel back to the python client.

- [Liefdesmeter](#liefdesmeter)
  - [How to Build](#how-to-build)
    - [ZMQ server](#zmq-server)
    - [python ZMQ client](#python-zmq-client)
  - [Commands](#commands)
    - [Python client](#python-client)
    - [ZMQ server](#zmq-server)
     

## How To Build
build manual for files used in this project.

### ZMQ server
 
needed files.

* mingw64 GCC compiler
 
* Build [libzmq](https://github.com/zeromq/libzmq) with cmake. This does an out of source build and installs the build files.
  *  download and unzip the lib, cd to directory
  *  mkdir build
  *  cd build
  *  cmake ..
  *  sudo make -j4 install
  
* Build [cppzmq](https://github.com/zeromq/cppzmq) with cmake. This does an out of source build and installs the build files

  * download and unzip the lib, cd to directory
  * mkdir build
  * cd build
  * cmake ..
  * sudo make -j4 install 

* c++ coding program (i used qt) 
  * open cmakelist file in the "zmq_opdracht" folder to open the program.



### python ZMQ client

 * download python 3.8 and put python as path variable
 * open cmd 
 * type "pip install pyzmq"
 * type "pip install secrets"
 * open the python file under ZMQ_opdracht_PyClient in IDLE python
 * build and run
 
## Commands

![image](https://user-images.githubusercontent.com/79915408/168831229-ef7a7f5a-48c5-412b-9aea-b5e6b5157ddc.png)


 ### python client
 
 the client listens to "ToonSpecialService>CooleLiefdesMeter!>USER:[client id 8 char long]:" as zmq topic
 
 pusher is connected to "tcp://benternet.pxl-ea-ict.be:24041"

 subscriber is connected to "tcp://benternet.pxl-ea-ict.be:24042"
 

 * sends:
 
   * "ToonSpecialService>CooleLiefdesMeter?>Names>[client id 8 char long]>[naam1]>>[naam2]"
      * client id is a random 8 character string generated in the python client.
      * naam1 and naam2 are user input.
 
   * "ToonSpecialService>CooleLiefdesMeter?>Dates>[client id 8 char long]>[date1]>>[date2]"
      * client id is a random 8 character string generated in the python client.
      * date1 and date2 are user input.
      
 * recieves: 
 
   * "ToonSpecialService>CooleLiefdesMeter!>USER:[client id 8 char long]:[variable]
     *  client id is a random 8 character string generated in the python client.
     *  variable can be the love percentage, "InvalidDates" if the dates send were invalid, "ServiceNotInUse" if the wrong service was called.
       
 ### zmq server 
 
 The server listens to "ToonSpecialService>CooleLiefdesMeter?>" as zmq topic and does different tasks if different variables are used .
 * example1 : if message recieved is "ToonSpecialService>CooleLiefdesMeter?>Names>..." it parses the variables after Names> ( client id , names etc) send by the client
 * example2 : if message recieved is "ToonSpecialService>CooleLiefdesMeter?>Dates>..." it parses the variables after Dates> ( client id , dates etc) send by the client


