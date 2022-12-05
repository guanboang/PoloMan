// These two includes are necessary to read
// the LIS3MDL (magnetometer)
# include <Wire.h>
# include <LIS3MDL.h>
# include "motors.h"

// LIS3MDL is a class.  We create an instance
// of this class called "mag".  We will then
// use mag to access the device by method
// functions and variables inside the class.
#define BUTTON 14
#define LED_PIN 13
#define LED_RED 17

#define maxdistance 0.4
Motors_c motor; // motor class 电机类


LIS3MDL mag;
  float x=0;
  float y=0;
  float z=0;
  bool b=0;

  float x1=0;
  float y1=0;
  float z1=0;

  float xc=0;
  float yc=0;
  float zc=0;
  

  int mx0=0;
  int my0=0;
  int mz0=0;


  int  n =0;
  int Mul=100;
    

  int mx1=0;
  int my1=0;
  int mz1=0;

  float sum_x=0;
  float sum_y=0;
  float sum_z=0;

  float mag_x=0;


  bool get_mag= 0;
  int motoset = 0;

 


void setup() {

  // Start the wire library for i2c.
  // Note: do not add this command into
  // a class constructor. It must occur
  // (or be called) from setup().
  Wire.begin();
  pinMode(BUTTON,INPUT);
    pinMode( LED_PIN, OUTPUT );
    pinMode(LED_RED, OUTPUT);


  // Set initial state of the LED
  

  

  // Serial for debug output
  Serial.begin(9600);
  Serial.println("***RESET***");
  delay(5000);
  Serial.println("Start test");
  
  // Check we have intialised commmuncation
  if (!mag.init() ) {  // no..? :(

    // Since we failed to communicate with the
    // magnetometer, we put the robot into an infinite
    // while loop and report the error.
    while(1) {
      Serial.println("Failed to detect and initialize magnetometer!");
      delay(1000);
    }
  }

  // Initialisation was ok.
  // Set to default settings.
  mag.enableDefault();
  
  // Initializing the motor
  // 初始化电机
  motor.initialise();

  for ( int which = 0; which< 50;which ++ ){
    mag.read();//读一次
    mx0=mag.m.x;
    my0=mag.m.y;
    mz0=mag.m.z;
    delay(20);
    digitalWrite(LED_PIN, LOW);


    mag.read();//读第二次
    mx1=mag.m.x;
    my1=mag.m.y;
    mz1=mag.m.z;
    delay(20);

        digitalWrite(LED_PIN, HIGH);
    // Calling this function from our instance
    // of the LIS3MDL class gets the latest
    // readings of the sensor.
    

    // Print the readings over serial.
    // m.x = x axis, etc.
    //mx1=mx1<<8;


    //取均值并进行数据转换
    x=(mx0+mx1)/2* 0.00092;
    //my1=my1<<8;
    y=(my0+my1)/2 * 0.00092;
    //mz1=mz1<<8;
    z=(mz0+mz1)/2 * 0.00092;

    sum_x= x+sum_x;

    sum_y= y+sum_y;
    sum_z= z+sum_z;
  }
    sum_x= sum_x/50;
    sum_y= sum_y/50;
    sum_z= sum_z/50;

Serial.println("Init finish");
Serial.println(sum_x);

digitalWrite(LED_PIN, HIGH);
digitalWrite(LED_RED, LOW);

} // end of setup()


// Short loop to report magnetometer readings
// over Serial.
void loop() {
  n++;//循环计数器

  mag.read();//读一次
  mx0=mag.m.x;
  my0=mag.m.y;
  mz0=mag.m.z;
  delay(20);


  mag.read();//读第二次
  mx1=mag.m.x;
  my1=mag.m.y;
  mz1=mag.m.z;
  delay(20);
  // Calling this function from our instance
  // of the LIS3MDL class gets the latest
  // readings of the sensor.
  

  // Print the readings over serial.
  // m.x = x axis, etc.
  //mx1=mx1<<8;


  //取均值并进行数据转换
  x=(mx0+mx1)/2* 0.00092;
  //my1=my1<<8;
  y=(my0+my1)/2 * 0.00092;
  //mz1=mz1<<8;
  z=(mz0+mz1)/2 * 0.00092;

  float change_x=0;

  change_x = sum_x-x;

  if (get_mag == 0){
    Serial.println("Wait mag");

  }

  if (change_x > 0.4 && get_mag==0){

    Serial.println("Wait mag");
    mag_x = x;
    get_mag=1;
    Serial.println("-");
    

    motoset = ((mag_x - x)*20 );
  }


  if(get_mag==1){



  int moto_speed=0;
    int moto_now=0;
  moto_now=(mag_x-x)*20;
  moto_speed=motoset-moto_now;
  moto_speed=moto_speed*2.5;

  if (moto_speed>50||moto_speed<-50){
    moto_speed =0;
  }



  motor.setMottors(moto_speed, moto_speed);

  digitalWrite(LED_RED, HIGH);
  Serial.println(moto_speed);



  }



  xc=(x-x1)*Mul;
  yc=(y-y1)*Mul;
  zc=(z-z1)*Mul;




  x1=x;
  y1=y;
  z1=z;
  // x = mag.m.x * 0.00092;
  // y = mag.m.y* 0.00092;
  // z = mag.m.z* 0.00092;



/*  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(z);
  //Serial.print("//");
  if (n==50){
    Serial.println("get 50 data");
    Serial.println("when want next 50, press butten");

    
    while (1){
      b=digitalRead(BUTTON);

        if (b==1){
          n=0;
          b=0;
          break;
        }

    }
  }


  */

// delay(500);
//  

//   int Xc = mag.m.x - x;
//     int Yc = mag.m.y - y;
//       int Zc = mag.m.z - z;

  // Serial.print(Xc);
  // Serial.print(",")
  // Serial.print(Yc);
  //   Serial.print(",");
  // Serial.println(Zc);



  // Short delay to keep things
  // slow enough to observe.
  // There is a limit to how fast you
  // can make i2c readings.
  //delay(500);

} // end of loop()