//Compilator/Intepritator
//By SimaKyr
#include <SPI.h>//SPI for SD library
#include <SD.h>//SD library

File logF;//Creating var for SD card module
int com = 0;//Command for command()
int arglenght = 2;//Arguments lenght(only using for reading from sd card code)
int varor = 0;//Boolean :D, using for VarG() - this detector var or text-digits
int arg = 0;//For VarG
String arg1, arg2, arg3, arg4, arg5, namel, temp1, temp2, text;//Arg, this Argument, namel, name list


void logsd() {logF = SD.open("log.txt", FILE_WRITE);if(logF){logF.println(text);logF.close();}}//This logger, using for minimilize code and talking information
void command() {//Player command THIS CODE IN DEVELOPING     |
text = String("Command-" + com);logsd();//Talking SD card)) \ /
if(com == 1){//                                              *
  temp1 = arg1.toInt();
  if(temp1 == arg1){
  digitalWrite(arg1.toInt(), arg1.toInt());}
  else{
  digitalWrite(arg1.toInt(), "A" + arg1.toInt());
  }
  
  }
  
if(com == 2){int arg1;}
if(com == 3){Serial.println(arg1);}
if(com == 4){Serial.print(arg1);}
if(com == 5){arg = 1;varg();arg1.replace("'", "");arg1.replace("'", "");if(varor == 0){delay(arg1.toInt());}else{delay(1000);}}//Delay simulator
}

void newlist() {//This don't work, using for creating list
text = String("Creating list-" + namel);logsd();//This code logger
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
}

void setup() {//Starting 
  Serial.begin(9600);//This for set speed Uart port
  if(!SD.begin(4)) {//Detector
    Serial.println("Connect SD CARD! ):");//Connect SD CARD!!
    return;//Exit 
  }
  Serial.println("SD CARD work! (:");//Talk if sd card work
  text = String("SD card work!");logsd();//Test work sd card
  text = String("--Compilator logger--");logsd();//This text
  text = String("Version:Alpha 0.2");logsd();//This the code version
  text = String("By SimaKyr");logsd();//GNU License
  text = String("Starting compilator...");logsd();//Starting compilator text
}
  
void loop() {//This example using code
  com = 2;
  arg1 = String("1 = '105'");
  command();
  com = 3;
  arg1 = 1;
  command();
  com = 5;
  arg1 = String("'10000'");
  command();
}
