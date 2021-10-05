String inputString = "";
boolean stringComplete = false;
String commandString = "";

// Hub 1
int ch1Pin = 22;
int ch2Pin = 24;
int ch3Pin = 26;
int ch4Pin = 28;

// Hub 2
int ch5Pin = 0;
int ch6Pin = 0;
int ch7Pin = 0;
int ch8Pin = 0;

// Hub 3
int ch9Pin = 0;
int ch10Pin = 0;
int ch11Pin = 0;
int ch12Pin = 0;

// Hub 4
int ch13Pin = 0;
int ch14Pin = 0;
int ch15Pin = 0;
int ch16Pin = 0;

boolean isConnected = false;

void setup() {
  
  Serial.begin(9600);
  pinMode(ch1Pin,OUTPUT);
  pinMode(ch2Pin,OUTPUT);
  pinMode(ch3Pin,OUTPUT);
  pinMode(ch4Pin,OUTPUT);
}

void getCommand()
{
  if(inputString.length()>0)
  {
     commandString = inputString.substring(1,4);
     Serial.print(commandString);
  }
}

boolean getLedState()
{
  boolean state = false;
  if(inputString.substring(5,7).equals("ON"))
  {
    state = true;
  }else
  {
    state = false;
  }
  return state;
}

void turnLedOn(int pin)
{
  digitalWrite(pin,HIGH);
}

void turnLedOff(int pin)
{
  digitalWrite(pin,LOW);
}

void loop() {
  if(stringComplete)
  {
    stringComplete = false;
    getCommand();
    
    if(commandString.equals("STAR"))
    {
      turnLedOff(ch1Pin);
      turnLedOff(ch2Pin);
      turnLedOff(ch3Pin);
      turnLedOff(ch4Pin); 
    }
  
    if(commandString.equals("STOP"))
    {
      turnLedOff(ch1Pin);
      turnLedOff(ch2Pin);
      turnLedOff(ch3Pin);
      turnLedOff(ch4Pin); 
    }
    else if(commandString.equals("CHN1"))
    {
      boolean LedState = getLedState();
      if(LedState == true)
      {
        turnLedOn(ch1Pin);
      }else
      {
        turnLedOff(ch1Pin);
      }   
    }
    else if(commandString.equals("CHN2"))
    {
      boolean LedState = getLedState();
      if(LedState == true)
      {
        turnLedOn(ch2Pin);
      }else
      {
        turnLedOff(ch2Pin);
      }   
    }
    else if(commandString.equals("CHN3"))
    {
      boolean LedState = getLedState();
      if(LedState == true)
      {
        turnLedOn(ch3Pin);
      }else
      {
        turnLedOff(ch3Pin);
      }   
    }
    else if(commandString.equals("CHN4"))
    {
      boolean LedState = getLedState();
      if(LedState == true)
      {
        turnLedOn(ch4Pin);
      }else
      {
        turnLedOff(ch4Pin);
      }   
    }

    inputString = "";
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
