#include <string.h>

enum EGameAPIUserResult
{
  success = 1,
  timeout = 2
};

struct gameAPIReturnValue
{
  EGameAPIUserResult result;
  unsigned long reactionTime;
};

struct gameAPIParameter
{
  int ledNumber;
  int pushButtonNumber;
  int delay;
  bool blocking;
};
//---------------------------------------

const int myGameSize = 3;

gameAPIParameter f[myGameSize] ;
//---------------------------------------

void setup() {
  Serial.begin(9600);

}
int i = 0 ;
int incomingByte = 0; // for incoming serial data

void loop() {
  Serial.println(String(i++) + ": Waiting for command...");
  if (Serial.available() > 0) {
    String s = Serial.readString();
    Serial.print("I received: " + s + "\n");

    // Returns first token
    char* token = strtok((char*)s.c_str(), ",");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
      Serial.print("token: "+ String(token) + "\n");
      token = strtok(NULL, ",");
    }
  }
  delay(1000);

}
