// These two includes are necessary to read
// the LIS3MDL (magnetometer)
# include <Wire.h>
# include <LIS3MDL.h>


// LIS3MDL is a class.  We create an instance
// of this class called "mag".  We will then
// use mag to access the device by method
// functions and variables inside the class.
#define BUTTON 30


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
  int count_time = 0;  

  int mx1=0;
  int my1=0;
  int mz1=0;
  
  int flag = 1;

  float sum_x=0;
  float sum_y=0;
  float sum_z=0;

  float a_x=0;
  float a_y=0;  
  float a_z=0;

  float standard_x=0;
  float standard_y=0;  
  float standard_z=0;

  float xi[50];
  float yi[50];
  float zi[50];


void setup() {

  // Start the wire library for i2c.
  // Note: do not add this command into
  // a class constructor. It must occur
  // (or be called) from setup().
  Wire.begin();
  pinMode(BUTTON,INPUT);
  pinMode(13,OUTPUT);


  

  // Serial for debug output
  Serial.begin(9600);
  Serial.println("***RESET***");
  delay(2000);
  Serial.println("Start test");

  // Check we have intialised commmuncation
  if (!mag.init() ) { 

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



} 


// Short loop to report magnetometer readings
// over Serial.
void loop() {

if(flag == 1) //get standard_value
{
  mag.read();//frist
  mx0=mag.m.x;

  delay(50);


  mag.read();//second
  mx1=mag.m.x;

  delay(50);

  // Calling this function from our instance
  // of the LIS3MDL class gets the latest
  // readings of the sensor.
  


  //取均值并进行数据转换 average
  x=(mx0+mx1)/2 * 0.00092;


  sum_x = sum_x + x;



  if(n==49)
  {
    standard_x = sum_x / 50;
 

    sum_x = 0;

    
    Serial.println("Get the standard value");
    Serial.println(" ");
    Serial.print(standard_x);
    Serial.println(" ");
    Serial.println("Press butten to get data");
    Serial.println(" ");
    flag = 0;
  }
  n++;//loop_count
}


if(flag == 0)
{

  delay(10000);
  delay(10000);
  delay(10000);
  delay(10000);
  delay(10000);
  delay(10000);

  n=0;
  flag = 2;
  if(  count_time == 10)
  {
    flag = 5;
  }
  count_time++;
    
  
}

if(flag == 2)
{


  mag.read();//Frist
  mx0=mag.m.x;

  delay(50);


  mag.read();//Second
  mx1=mag.m.x;

  delay(50);

    xi[n]=(mx0+mx1)/2 * 0.00092 - standard_x;
//    Serial.print(xi[n]);
//    Serial.print(" ");
  
    if(n==49)
  { 
    Serial.println(" ");
    Serial.println("Processing the data value");
    Serial.println(" ");
    delay(5);
    Serial.print(" = [");
    for(int i = 0; i<50 ; i++)
    {
      Serial.print(xi[i]);
      Serial.print(" ");
    }
    Serial.print("];");
    Serial.println(" ");
    
    for(int i = 0; i<50; i++)
    {
      xi[i]=0;
    }

    Serial.println("Press butten to get next data");
    Serial.println(" ");    
    flag = 0;
    n = 0;  
  }

  n++;//loop_count
 
}

if(flag == 5)
{
  if(digitalRead(BUTTON) == 0 )
  { digitalWrite(13,HIGH);
    delay(10);
    digitalWrite(13,LOW);
    if(digitalRead(BUTTON) == 0)
    {
    n=0;
    flag = 0;
    count_time = 0;
    }
    
  }
}

} 

