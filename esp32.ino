const int in1 = 4,in2 = 3,in3 = 2,in4 = 1;
const int EN=9;
const int button = 0;
const int button1 = 5;
const int PWM = A0;
void PWMmotor()
{
  int PWMval= analogRead(PWM);
  if(PWMval>0&&PWMval<400)
  {
    analogWrite(EN,50);

  }
  else if(PWMval>400&&PWMval<800)
  {
    analogWrite(EN,220);
  }
  else if(PWMval>850&&PWMval<1000)
  {
    analogWrite(EN,255);
  }
}
void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(EN, OUTPUT);
   pinMode(in3,OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(button,HIGH);
  pinMode(PWM,INPUT);
  pinMode(button1,INPUT);
}
int check = 0;
void tien(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void lui()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void stop()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void trai()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void phai()
{
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
  int checkbutton() {
  if (digitalRead(button) == LOW) {
    delay(20); 

if (digitalRead(button) == LOW) {
      check++;
      if (check > 4) 
      {
        check = 0;
      } 
      while (digitalRead(button) == LOW); 
      delay(20);
      return 1;
    }
  }
  return 0;
}
bool checkbutton2() 
{
  if(digitalRead(button1)==HIGH)
  {
    delay(20);
    if(digitalRead(button1)==HIGH)
    {
       return 1;
    }
  }
  return 0;
}
void loop() {
  checkbutton();
   PWMmotor();
   if(check==0&&checkbutton2())
   {
    stop();
   }else if( check ==1&&checkbutton2())
   {
    tien();
   }else if(check ==2&&checkbutton2())
   {
    lui();
   }else if(check==3&&checkbutton2())
   {
    trai();
   }else if(check==4&&checkbutton2())
   {
    phai();
   }else
   {
    stop();
   }
}
