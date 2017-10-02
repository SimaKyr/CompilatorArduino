/*
Intepritator VERSION ALPHA 0.4
By SimaKyr

* Connecting SD Card MODULE
** MOSI - pin 11 on Arduino
** MISO - pin 12 on Arduino
** CLK/SCL - pin 13 on Arduino
** CS(Selecter device) - pin 4 on Arduino
* 
 */

#include <SPI.h>//SPI for SD library
#include <SD.h>//SD library

File data, ListRam;//Creating var for SD card module
int com = 0;//Command for command()
int arglenght = 2;//Arguments lenght(only using for reading from sd card code)
int varor = 0;//Boolean :D, using for VarG() - this detector var or text-digits
int arg = 0;//For VarG
String arg1, arg2, arg3, arg4, arg5, namel, temp1, temp2, text, line;//Arg, this Argument, namel, name list


void logsd() {data = SD.open("log.txt", FILE_WRITE);if(data){data.println(text);data.close();}}//This logger, using for minimilize code and talking information
void command() {//Player command THIS CODE IN DEVELOPING     |
text = String("Command-" + com);logsd();//Talking SD card)) \ /
if(com == 1){//                                              *
  temp1 = arg1.toInt();
  arg = 2;
  varg();
  if(temp1 == arg1){
    if(varor == 1){digitalWrite(arg1.toInt(), arg2.toInt());}
    if(varor == 0){digitalWrite(arg1.toInt(), 12);}//Enter to this 12 ,value getter
  else{
    if(varor == 1){digitalWrite(arg1.toInt(), "A" + arg2.toInt());}
    if(varor == 0){temp2 = 12;temp2.replace("A","");//Enter to this 12 ,value getter
    digitalWrite(arg1.toInt(),"A" + temp2.toInt());}}}}
  
if(com == 2){setval();}//This work in version ALPHA 0.4+
if(com == 3){arg = 1;varg();if(varor == 1){Serial.println(arg1);}else{Serial.println("Enter value");}}//Serial print in simulator
if(com == 4){arg = 1;varg();if(varor == 1){Serial.print(arg1);}else{Serial.print("Enter value");}}//Serial print simulator
if(com == 5){arg = 1;varg();if(varor == 1){delay(arg1.toInt());}else{delay(1000);}}//Delay simulator
}

void newlist() {//This don't work, using for creating list
text = String("Creating list-" + namel);logsd();//This code logger
}

void setval() {//Set value
  temp1 = "ram/" + arg1;//Economy script
  SD.remove(temp1);//Removing old value
   data = SD.open(temp1, FILE_WRITE);  //Creating file
   data.print(arg2);//Setting value
   data.close();//Closing for save RAM and save file
}

void varg() {//VarG() - this detector var or text-digits
text = String("Var or No? Argument:" + arg1);logsd();//Logger talking :D
if(arg == 1){temp1 = arg1;}//This for....Duplicate arg(num) to temp1
if(arg == 2){temp1 = arg2;}//Duplicate arg(num) to temp1
if(arg == 3){temp1 = arg3;}//Duplicate arg(num) to temp1
if(arg == 4){temp1 = arg4;}//Duplicate arg(num) to temp1
if(arg == 5){temp1 = arg5;}//Duplicate arg(num) to temp1
temp2 = String(temp1);//Duplicate temp 1
temp2.replace("'", "");//Deleting ''
if(temp2 == temp1){varor = 0;text = String("This var");logsd();}//If this value
else{varor = 1;text = String("This not var");logsd();}//If this text, digits
if(arg == 1){arg1.replace("'", "");}//Normal text make
if(arg == 2){arg2.replace("'", "");}
if(arg == 3){arg3.replace("'", "");}
if(arg == 4){arg4.replace("'", "");}
if(arg == 5){arg5.replace("'", "");}

if(arg == 1){arg1.replace("'", "");}
if(arg == 2){arg2.replace("'", "");}
if(arg == 3){arg3.replace("'", "");}
if(arg == 4){arg4.replace("'", "");}
if(arg == 5){arg5.replace("'", "");}
}

void setup() {//Starting 
  SD.mkdir("ram"); 
  Serial.begin(9600);//This for set speed Uart port
  if(!SD.begin(4)) {//Detector
    Serial.println("Connect SD CARD! ):");//Connect SD CARD!!
    return;//Exit 
  }
  SD.remove("log.txt");
  Serial.println("SD CARD work! (:");//Talk if sd card work
  text = String("SD card work!");logsd();//Test work sd card
  text = String("--Compilator logger--");logsd();//This text
  text = String("Version:Alpha 0.4");logsd();//This the code version
  text = String("By SimaKyr");logsd();//GNU License
  text = String("Starting interpreter...");logsd();//Starting compilator text
}
  
void loop() {//This example using code
  com = 2;//name command
  arg1 = String("1 = '105'");//Setting argument
  command();//Start command
  com = 3;
  arg1 = 1;
  command();
  com = 5;
  arg1 = String("'10000'");
  command();
}
