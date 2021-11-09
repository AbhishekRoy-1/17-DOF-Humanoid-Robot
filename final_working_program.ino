#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define SERVOMIN 90//the 0 point of servo motor
#define SERVOMAX 610//the 180 point of servo motor

int angle;
int angletopulse(int);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();//creating an instance for the adafruit library

void setup() 
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);//baud rate i.e. bits per second
  pwm.begin();//begins the I2C communication between arduino and motor driver
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  yield();


  //to make robo stand properly
  pwm.setPWM(2,0,angletopulse(72));//locking angle of right waist is 72 degrees
  delay(100);

  pwm.setPWM(3,0,angletopulse(51));//locking angle of left waist is 51 degrees
  delay(100);

  pwm.setPWM(5,0,angletopulse(85));//locking angle of left leg upper motor(85 degrees)
  delay(100);

  pwm.setPWM(4,0,angletopulse(120));//locking angle of right leg upper motor(120 degrees)
  delay(100);

  pwm.setPWM(6,0,angletopulse(115));//locking angle of right leg middle motor(115 degrees)
  delay(100);

  pwm.setPWM(7,0,angletopulse(66));//locking angle of left leg middle motor(66 degrees)
  delay(100);

  pwm.setPWM(8,0,angletopulse(70));//locking angle of right leg lower motor(70 degrees)
  delay(100);

  pwm.setPWM(9,0,angletopulse(100));//locking angle of left leg lower motor(100 degrees)
  delay(100);

  pwm.setPWM(11,0,angletopulse(95));//locking angle of right leg bottom level motor(95 degrees)
  delay(100);

  pwm.setPWM(14,0,angletopulse(157));//locking angle of left leg bottom level motor(157 degrees)
  delay(100);

  pwm.setPWM(13,0,angletopulse(150));
  delay(100);

  pwm.setPWM(12,0,angletopulse(100));
  delay(100);

  pwm.setPWM(0,0,angletopulse(35));
  delay(100);

  pwm.setPWM(1,0,angletopulse(80));
  delay(100);
  
}

  int angletopulse(int ang)
{
  int pulse=map(ang,0,180,SERVOMIN,SERVOMAX);//inbuilt function to change the servo min and servo max to 0 and 180 degree
//  Serial.println("value of angle");
//  Serial.println(ang);
//  Serial.println("value of pulse");
//  Serial.println(pulse);
  return pulse; 
}
void loop() 
{
  if(Serial.available()>0)//to take user input
  {
    char data=Serial.read();//stores taken input into data
    switch(data)
    {
      case 's':           //to stand in robo pose
      {
        pwm.setPWM(2,0,angletopulse(72));//locking angle of right waist is 72 degrees
        delay(100);

        pwm.setPWM(3,0,angletopulse(51));//locking angle of left waist is 51 degrees
        delay(100);

        pwm.setPWM(5,0,angletopulse(85));//locking angle of left leg upper motor(85 degrees)
        delay(100);

        pwm.setPWM(4,0,angletopulse(120));//locking angle of right leg upper motor(120 degrees)
        delay(100);

        pwm.setPWM(6,0,angletopulse(115));//locking angle of right leg middle motor(115 degrees)
        delay(100);

        pwm.setPWM(7,0,angletopulse(66));//locking angle of left leg middle motor(66 degrees)
        delay(100);

        pwm.setPWM(8,0,angletopulse(70));//locking angle of right leg lower motor(70 degrees)
        delay(100);

        pwm.setPWM(9,0,angletopulse(100));//locking angle of left leg lower motor(100 degrees)
        delay(100);

        pwm.setPWM(11,0,angletopulse(95));//locking angle of right leg bottom level motor(95 degrees)
        delay(100);

        pwm.setPWM(14,0,angletopulse(157));//locking angle of left leg bottom level motor(157 degrees)
        delay(100);

        pwm.setPWM(13,0,angletopulse(150));
        delay(100);

        pwm.setPWM(12,0,angletopulse(100));
        delay(100);

        pwm.setPWM(0,0,angletopulse(35));
        delay(100);

        pwm.setPWM(1,0,angletopulse(80));
        delay(100);

        Serial.println("\n STANDING CODE HAS BEEN EXECUTED \n");
        break;
      }

      case 'w':
      { 
        //first robo will posses its standing position 

        pwm.setPWM(2,0,angletopulse(72));//locking angle of right waist is 72 degrees
        delay(100);

        pwm.setPWM(3,0,angletopulse(51));//locking angle of left waist is 51 degrees
        delay(100);

        pwm.setPWM(5,0,angletopulse(85));//locking angle of left leg upper motor(85 degrees)
        delay(100);

        pwm.setPWM(4,0,angletopulse(120));//locking angle of right leg upper motor(120 degrees)
        delay(100);

        pwm.setPWM(6,0,angletopulse(115));//locking angle of right leg middle motor(115 degrees)
        delay(100);

        pwm.setPWM(7,0,angletopulse(66));//locking angle of left leg middle motor(66 degrees)
        delay(100);

        pwm.setPWM(8,0,angletopulse(70));//locking angle of right leg lower motor(70 degrees)
        delay(100);

        pwm.setPWM(9,0,angletopulse(100));//locking angle of left leg lower motor(100 degrees)
        delay(100);

        pwm.setPWM(11,0,angletopulse(95));//locking angle of right leg bottom level motor(95 degrees)
        delay(100);

        pwm.setPWM(14,0,angletopulse(157));//locking angle of left leg bottom level motor(157 degrees)
        delay(100);

        pwm.setPWM(13,0,angletopulse(150));
        delay(100);

        pwm.setPWM(12,0,angletopulse(100));
        delay(100);

        pwm.setPWM(0,0,angletopulse(35));
        delay(100);

        pwm.setPWM(1,0,angletopulse(80));
        delay(100);

        Serial.println("\n ADJUSTING THE WALKING MOTORS............\n");
        
        delay(2000);//after standing, it will wait for 3 seconds

        //now actual walking will start


        for(int i=1;i<=3;i++)           //so that it first takes 3 steps and the case will stop
        {
        //lean on left leg
        
        pwm.setPWM(14,0,angletopulse(157));//here the leaning will start from 157 degrees as it is the locking angle
        delay(200);

        pwm.setPWM(14,0,angletopulse(159));
        delay(200);

        pwm.setPWM(14,0,angletopulse(161));
        delay(200);

        pwm.setPWM(14,0,angletopulse(163));
        delay(200);

        pwm.setPWM(14,0,angletopulse(165));
        delay(200);

        pwm.setPWM(14,0,angletopulse(167));
        delay(200);

       

        


        //movement of right leg upper motor
  
        pwm.setPWM(4,0,angletopulse(120));//for first step in forward direction
        delay(200);

        pwm.setPWM(4,0,angletopulse(118));
        delay(200);

        pwm.setPWM(4,0,angletopulse(116));
        delay(200);

        pwm.setPWM(4,0,angletopulse(114));
        delay(200);

        pwm.setPWM(4,0,angletopulse(112));
        delay(200);

        pwm.setPWM(4,0,angletopulse(110));
        delay(200);


        




       //movement of right leg lower motor

        pwm.setPWM(8,0,angletopulse(70));//for keeping the feet intact with ground after the movement of upper motors 
        delay(200);

        pwm.setPWM(8,0,angletopulse(71));
        delay(200);

        pwm.setPWM(8,0,angletopulse(72));
        delay(200);

        pwm.setPWM(8,0,angletopulse(73));
        delay(200);

        pwm.setPWM(8,0,angletopulse(74));
        delay(200);

        pwm.setPWM(8,0,angletopulse(75));
        delay(200);

        pwm.setPWM(8,0,angletopulse(78));
        delay(200);







        //removal of lean on left leg

        pwm.setPWM(14,0,angletopulse(169));//now getting the motors out of lean position
        delay(200);
      
        pwm.setPWM(14,0,angletopulse(167));
        delay(200);
        
        pwm.setPWM(14,0,angletopulse(165));
        delay(200);

        pwm.setPWM(14,0,angletopulse(163));
        delay(200);

        pwm.setPWM(14,0,angletopulse(161));
        delay(200);

        pwm.setPWM(14,0,angletopulse(159));
        delay(200);

        pwm.setPWM(14,0,angletopulse(157));
        delay(200);

         //lean on right leg

        delay(400);

        
        pwm.setPWM(11,0,angletopulse(95));//now leaning on the opposite motors
        delay(200);

        pwm.setPWM(11,0,angletopulse(93));
        delay(200);

        pwm.setPWM(11,0,angletopulse(91));
        delay(200);

        pwm.setPWM(11,0,angletopulse(89));
        delay(200);

        pwm.setPWM(11,0,angletopulse(87));
        delay(200);

        pwm.setPWM(11,0,angletopulse(85));
        delay(200);

        pwm.setPWM(11,0,angletopulse(83));
        delay(200);

     

       



        //movement of left leg upper motor


        pwm.setPWM(5,0,angletopulse(85));//same movement of motors as the right leg had, to complete the first step
        delay(200);

        pwm.setPWM(5,0,angletopulse(87));
        delay(200);

        pwm.setPWM(5,0,angletopulse(89));
        delay(200);

        pwm.setPWM(5,0,angletopulse(91));
        delay(200);

        pwm.setPWM(5,0,angletopulse(93));
        delay(200);

        pwm.setPWM(5,0,angletopulse(95));
        delay(200);

        pwm.setPWM(5,0,angletopulse(97));
        delay(200);






        //movement of left lower motor

        pwm.setPWM(9,0,angletopulse(100));//to keep the feet intact with ground 
        delay(200);

        pwm.setPWM(9,0,angletopulse(99));
        delay(200);

        pwm.setPWM(9,0,angletopulse(98));
        delay(200);

        pwm.setPWM(9,0,angletopulse(97));
        delay(200);

        pwm.setPWM(9,0,angletopulse(96));
        delay(200);

        pwm.setPWM(9,0,angletopulse(95));
        delay(200);

        





        //removal of lean on right leg

        pwm.setPWM(11,0,angletopulse(83));//lean had to be removed so to complete the forward step
        delay(200);

        pwm.setPWM(11,0,angletopulse(85));
        delay(200);

        pwm.setPWM(11,0,angletopulse(87));
        delay(200);

        pwm.setPWM(11,0,angletopulse(89));
        delay(200);

        pwm.setPWM(11,0,angletopulse(91));
        delay(200);

        pwm.setPWM(11,0,angletopulse(93));
        delay(200);

        pwm.setPWM(11,0,angletopulse(95));
        delay(200);

        pwm.setPWM(11,0,angletopulse(97));
        delay(200);







        //back movement to initial position of right upper and left motor


        pwm.setPWM(4,0,angletopulse(110));//now making the robot stablisd in the new position
        delay(120);

        pwm.setPWM(5,0,angletopulse(97));
        delay(120);

        pwm.setPWM(6,0,angletopulse(115));
        delay(120);

        pwm.setPWM(7,0,angletopulse(66));
        delay(120);

        pwm.setPWM(8,0,angletopulse(75));
        delay(120);

        pwm.setPWM(9,0,angletopulse(95));
        delay(120);






        pwm.setPWM(4,0,angletopulse(112));
        delay(120);

        pwm.setPWM(5,0,angletopulse(95));
        delay(120);

        pwm.setPWM(6,0,angletopulse(113));
        delay(120);

        pwm.setPWM(7,0,angletopulse(68));
        delay(120);

        pwm.setPWM(8,0,angletopulse(74));
        delay(120);

        pwm.setPWM(9,0,angletopulse(96));
        delay(120);





        pwm.setPWM(4,0,angletopulse(114));
        delay(120);

        pwm.setPWM(5,0,angletopulse(93));
        delay(120);

        pwm.setPWM(6,0,angletopulse(111));
        delay(120);

        pwm.setPWM(7,0,angletopulse(70));
        delay(120);

        pwm.setPWM(8,0,angletopulse(73));
        delay(120);

        pwm.setPWM(9,0,angletopulse(97));
        delay(120);





        pwm.setPWM(4,0,angletopulse(116));
        delay(120);

        pwm.setPWM(5,0,angletopulse(91));
        delay(120);

        pwm.setPWM(6,0,angletopulse(109));
        delay(120);

        pwm.setPWM(7,0,angletopulse(72));
        delay(120);

        pwm.setPWM(8,0,angletopulse(72));
        delay(120);

        pwm.setPWM(9,0,angletopulse(98));
        delay(120);





        pwm.setPWM(4,0,angletopulse(118));
        delay(120);

        pwm.setPWM(5,0,angletopulse(89));
        delay(120);

        pwm.setPWM(6,0,angletopulse(107));
        delay(120);

        pwm.setPWM(7,0,angletopulse(74));
        delay(120);

        pwm.setPWM(8,0,angletopulse(71));
        delay(120);

        pwm.setPWM(9,0,angletopulse(99));
        delay(120);





        pwm.setPWM(4,0,angletopulse(120));
        delay(120);

        pwm.setPWM(5,0,angletopulse(87));
        delay(120);

        pwm.setPWM(6,0,angletopulse(105));
        delay(120);

        pwm.setPWM(7,0,angletopulse(76));
        delay(120);

        pwm.setPWM(8,0,angletopulse(70));
        delay(120);

        pwm.setPWM(9,0,angletopulse(100));
        delay(120);






        //backing up

        pwm.setPWM(6,0,angletopulse(105));//keeping its back straight for further more movement  
        delay(120);

        pwm.setPWM(7,0,angletopulse(76));
        delay(120);



        pwm.setPWM(6,0,angletopulse(107));
        delay(120);

        pwm.setPWM(7,0,angletopulse(74));
        delay(120);




        pwm.setPWM(6,0,angletopulse(109));
        delay(120);

        pwm.setPWM(7,0,angletopulse(72));
        delay(120);




        pwm.setPWM(6,0,angletopulse(111));
        delay(120);

        pwm.setPWM(7,0,angletopulse(70));
        delay(120);




        pwm.setPWM(6,0,angletopulse(113));
        delay(120);

        pwm.setPWM(7,0,angletopulse(68));
        delay(120);



        pwm.setPWM(6,0,angletopulse(115));
        delay(120);

        pwm.setPWM(7,0,angletopulse(66));
        delay(120);

        
        Serial.println("THE ROBOT HAS TAKEN ");
        Serial.print(i);
        Serial.print("  STEP");
        delay(2000);
        
      }
      break;
      }
      
      case 'u':     //for up and down of the robot
      { 
        //first robo will take its standing stance
                
        pwm.setPWM(2,0,angletopulse(72));//locking angle of right waist is 72 degrees
        delay(100);

        pwm.setPWM(3,0,angletopulse(51));//locking angle of left waist is 51 degrees
        delay(100);

        pwm.setPWM(5,0,angletopulse(85));//locking angle of left leg upper motor(85 degrees)
        delay(100);

        pwm.setPWM(4,0,angletopulse(120));//locking angle of right leg upper motor(120 degrees)
        delay(100);

        pwm.setPWM(6,0,angletopulse(115));//locking angle of right leg middle motor(115 degrees)
        delay(100);

        pwm.setPWM(7,0,angletopulse(66));//locking angle of left leg middle motor(66 degrees)
        delay(100);

        pwm.setPWM(8,0,angletopulse(70));//locking angle of right leg lower motor(70 degrees)
        delay(100);

        pwm.setPWM(9,0,angletopulse(100));//locking angle of left leg lower motor(100 degrees)
        delay(100);

        pwm.setPWM(11,0,angletopulse(95));//locking angle of right leg bottom level motor(95 degrees)
        delay(100);

        pwm.setPWM(14,0,angletopulse(157));//locking angle of left leg bottom level motor(157 degrees)
        delay(100);

        pwm.setPWM(13,0,angletopulse(150));
        delay(100);

        pwm.setPWM(12,0,angletopulse(100));
        delay(100);

        pwm.setPWM(0,0,angletopulse(35));
        delay(100);

        pwm.setPWM(1,0,angletopulse(80));
        delay(100);

        delay(2000);//after standing it will wait for 2 seconds, after that downward motion starts




        //now downward motion will start
         
        pwm.setPWM(6,0,angletopulse(115));
        delay(100);

        pwm.setPWM(7,0,angletopulse(66));
        delay(100);

        pwm.setPWM(8,0,angletopulse(70));
        delay(100);

        pwm.setPWM(9,0,angletopulse(100));
        delay(100);




  

        pwm.setPWM(6,0,angletopulse(117));
        delay(100);
  
        pwm.setPWM(7,0,angletopulse(64));
        delay(100);
  
        pwm.setPWM(8,0,angletopulse(68));
        delay(100);
  
        pwm.setPWM(9,0,angletopulse(102));
        delay(100);
      
      
      
        
      
        pwm.setPWM(6,0,angletopulse(119));
        delay(100);
    
        pwm.setPWM(7,0,angletopulse(62));
        delay(100);
    
        pwm.setPWM(8,0,angletopulse(66));
        delay(100);

        pwm.setPWM(9,0,angletopulse(104));
        delay(100);
      
      
        
      
      
        pwm.setPWM(6,0,angletopulse(121));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(60));
        delay(100);
        
        pwm.setPWM(8,0,angletopulse(64));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(106));
        delay(100);
      
      
      
        
      
        pwm.setPWM(6,0,angletopulse(123));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(58));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(62));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(108));
        delay(100);
      
      
      
        
      
        pwm.setPWM(6,0,angletopulse(125));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(56));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(60));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(110));
        delay(100);
      
      
      
        
      
        pwm.setPWM(6,0,angletopulse(127));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(54));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(58));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(112));
        delay(100);
      
      
      
      
        
      
        pwm.setPWM(6,0,angletopulse(129));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(52));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(56));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(114));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(131));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(50));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(54));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(116));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(133));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(48));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(52));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(118));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(135));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(46));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(50));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(120));
        delay(100);
      
      
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(137));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(44));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(48));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(122));
        delay(100);
      
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(139));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(42));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(46));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(124));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(141));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(40));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(44));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(126));
        delay(100);
      
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(143));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(38));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(42));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(128));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(145));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(36));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(40));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(130));
        delay(100);
      
      
      
      
      
        //again further lowering to get approx a sitting position to avoid obstacles
      
      
        pwm.setPWM(6,0,angletopulse(147));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(34));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(38));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(132));
        delay(100);
      
        
      
      
      
      
        pwm.setPWM(6,0,angletopulse(149));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(32));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(36));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(134));
        delay(100);
      
        
      
      
      
      
        pwm.setPWM(6,0,angletopulse(151));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(30));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(34));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(136));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(153));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(28));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(32));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(138));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(155));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(26));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(30));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(140));
        delay(100);
      
      
      
      
          //upto here it has attained its maximum lowered position
          
          //now getting up i.e. to its initial position
      
      
        pwm.setPWM(5,0,angletopulse(85));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(120));
        delay(100);
      
      
      
      
      
        pwm.setPWM(5,0,angletopulse(83));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(122));
        delay(100);
      
      
      
      
        pwm.setPWM(5,0,angletopulse(81));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(124));
        delay(100);
      
      
      
      
        pwm.setPWM(5,0,angletopulse(79));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(126));
        delay(100);
      
      
      
      
      
        //again further lowering
      
        pwm.setPWM(6,0,angletopulse(157));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(24));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(28));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(142));
        delay(100);
      
      
      
        pwm.setPWM(6,0,angletopulse(159));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(22));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(26));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(144));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(161));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(20));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(24));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(146));
        delay(100);
      
      
      
      
      
        
        pwm.setPWM(6,0,angletopulse(163));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(18));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(22));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(148));
        delay(100);
      
      
      
        
        pwm.setPWM(6,0,angletopulse(165));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(16));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(20));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(150));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(167));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(14));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(18));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(152));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(169));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(12));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(16));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(154));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(171));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(10));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(14));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(156));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(173));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(8));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(12));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(158));
        delay(100);
      
      
      
      
      
        //now reversing everything
      
      
      
      
        pwm.setPWM(6,0,angletopulse(171));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(10));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(14));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(156));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(169));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(12));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(16));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(154));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(167));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(14));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(16));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(154));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(165));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(16));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(18));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(152));
        delay(100);
        
      
      
      
        pwm.setPWM(6,0,angletopulse(163));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(18));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(20));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(150));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(161));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(20));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(22));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(148));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(159));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(22));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(24));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(146));
        delay(100);
      
        
      
      
         pwm.setPWM(6,0,angletopulse(157));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(24));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(26));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(144));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(155));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(26));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(28));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(142));
        delay(100);
      
      
      
        //getting the waist a stablised position
      
        pwm.setPWM(5,0,angletopulse(79));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(126));
        delay(100);
      
      
      
        pwm.setPWM(5,0,angletopulse(81));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(124));
        delay(100); 
      
      
      
        pwm.setPWM(5,0,angletopulse(83));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(122));
        delay(100);
      
      
      
        pwm.setPWM(5,0,angletopulse(85));
        delay(100);
      
        pwm.setPWM(4,0,angletopulse(120));
        delay(100);
      
      
      
      
      
      
        //in the way of standing up
      
      
      
        pwm.setPWM(6,0,angletopulse(153));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(28));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(32));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(138));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(151));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(30));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(34));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(136));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(149));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(32));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(36));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(134));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(147));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(34));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(38));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(132));
        delay(100);
      
      
      
      
      
        
        pwm.setPWM(6,0,angletopulse(145));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(36));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(40));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(130));
        delay(100);
      
      
      
      
      
         pwm.setPWM(6,0,angletopulse(143));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(38));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(42));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(128));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(141));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(40));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(44));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(126));
        delay(100);
        
      
      
      
        pwm.setPWM(6,0,angletopulse(139));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(42));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(46));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(124));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(137));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(44));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(48));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(122));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(135));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(46));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(50));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(120));
        delay(100);
      
      
      
      
      
        
        pwm.setPWM(6,0,angletopulse(133));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(48));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(52));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(118));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(131));
        delay(100);
        
        pwm.setPWM(7,0,angletopulse(50));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(54));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(116));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(129));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(52));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(56));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(114));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(127));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(54));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(58));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(112));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(125));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(56));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(60));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(110));
        delay(100);
      
      
      
      
      
        pwm.setPWM(6,0,angletopulse(123));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(58));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(62));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(108));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(121));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(60));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(64));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(106));
        delay(100);




        pwm.setPWM(6,0,angletopulse(119));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(62));
        delay(100);
        
        pwm.setPWM(8,0,angletopulse(66));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(104));
        delay(100);





        pwm.setPWM(6,0,angletopulse(117));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(64));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(68));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(102));
        delay(100);
      
      
      
      
        pwm.setPWM(6,0,angletopulse(115));
        delay(100);
      
        pwm.setPWM(7,0,angletopulse(66));
        delay(100);
      
        pwm.setPWM(8,0,angletopulse(70));
        delay(100);
      
        pwm.setPWM(9,0,angletopulse(100));
        delay(100);
      
        Serial.println("UP AND DOWN CODE EXECUTED");
        break;
        
  }

      case 'h'://for movement of hands 

      { 
        //a basic pt drill to check the hands and joints movement.
        
        pwm.setPWM(0,0,angletopulse(35));
        delay(100);

        pwm.setPWM(1,0,angletopulse(80));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(40));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(75));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(45));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(70));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(50));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(65));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(55));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(60));
        delay(100);
    
    
        pwm.setPWM(0,0,angletopulse(60));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(55));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(65));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(50));
        delay(100);
    
    
        pwm.setPWM(0,0,angletopulse(70));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(45));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(75));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(40));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(80));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(35));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(85));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(30));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(90));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(25));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(95));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(20));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(100));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(15));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(105));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(10));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(110));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(5));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(115));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(0));
        delay(100);
    
    
    
    
    
    
    
    
    
        //movement of right and left hand upper motor
    
        pwm.setPWM(12,0,angletopulse(100));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(150));
        delay(100);  
    
    
    
        pwm.setPWM(12,0,angletopulse(95));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(145));
        delay(100);  
    
    
    
    
        pwm.setPWM(12,0,angletopulse(90));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(140));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(85));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(135));
        delay(100);  
    
    
    
    
        pwm.setPWM(12,0,angletopulse(80));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(130));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(75));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(125));
        delay(100);  
    
    
    
    
        pwm.setPWM(12,0,angletopulse(70));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(120));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(65));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(115));
        delay(100);  
    
    
    
    
        pwm.setPWM(12,0,angletopulse(60));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(110));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(55));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(105));
        delay(100);  
    
    
    
    
    
        pwm.setPWM(12,0,angletopulse(50));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(100));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(45));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(95));
        delay(100);  
    
    
    
    
    
        pwm.setPWM(12,0,angletopulse(40));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(90));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(35));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(85));
        delay(100);  
    
    
    
    
    
        pwm.setPWM(12,0,angletopulse(30)); 
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(80));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(25));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(75));
        delay(100);  
    
    
    
        
    
        pwm.setPWM(12,0,angletopulse(20));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(70));
        delay(100);
    
    
      
        //reversing of shoulder part
    
    
    
        
        pwm.setPWM(0,0,angletopulse(115));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(0));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(110));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(5));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(105));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(10));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(100));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(15));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(95));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(20));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(90));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(25));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(85));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(30));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(80));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(35));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(75));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(40));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(70));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(45));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(65));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(50));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(60));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(55));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(55));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(60));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(50));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(65));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(45));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(70));
        delay(100);
    
    
    
        pwm.setPWM(0,0,angletopulse(40));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(75));
        delay(100);
    
    
    
    
        pwm.setPWM(0,0,angletopulse(35));
        delay(100);
    
        pwm.setPWM(1,0,angletopulse(80));
        delay(100);
    
    
    
    
    
    
        //reversing of upper motors in hand
    
    
    
        pwm.setPWM(12,0,angletopulse(20));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(70));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(25));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(75));
        delay(100);
    
    
    
    
        pwm.setPWM(12,0,angletopulse(30));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(80));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(35));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(85));
        delay(100);
    
    
    
    
        pwm.setPWM(12,0,angletopulse(40));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(90));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(45));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(95));
        delay(100);
    
    
    
    
        pwm.setPWM(12,0,angletopulse(50));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(100));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(55));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(105));
        delay(100);
    
    
    
    
        pwm.setPWM(12,0,angletopulse(60));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(110));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(65));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(115));
        delay(100);
    
    
    
    
    
        pwm.setPWM(12,0,angletopulse(70));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(120));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(75));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(125));
        delay(100);
    
    
    
    
    
        pwm.setPWM(12,0,angletopulse(80));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(130));
        delay(100);
    
    
    
    
        pwm.setPWM(12,0,angletopulse(85));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(135));
        delay(100);
    
    
    
    
    
        pwm.setPWM(12,0,angletopulse(90)); 
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(140));
        delay(100);
    
    
    
        pwm.setPWM(12,0,angletopulse(95));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(145));
        delay(100);
    
    
    
        
    
        pwm.setPWM(12,0,angletopulse(100));
        delay(100);
    
        pwm.setPWM(13,0,angletopulse(150));
        delay(100);
    
        Serial.println("HAND MOVEMENT CODE EXECUTED");
        break;
      }


      default :
      break;

      
    }


    delay(100);
   

  }


}
