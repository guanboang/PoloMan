// this #ifndef stops this file
// from being included mored than
// once by the compiler. 
# ifndef _MOTORS_H
# define _MOTORS_H

# define L_PWM_PIN 10
# define L_DIR_PIN 16
# define R_PWM_PIN 9
# define R_DIR_PIN 15

# define FWD LOW
# define REV HIGH

// Class to operate the motor(s).
class Motors_c {
  public:

    // Constructor, must exist.
    Motors_c() {

    } 

    // Use this function to 
    // initialise the pins and 
    // state of your motor(s).
    void initialise() {
      // Configure the PWM pins of Mottor
      pinMode( L_PWM_PIN , OUTPUT );
      pinMode( L_DIR_PIN , OUTPUT );
      pinMode( R_PWM_PIN , OUTPUT );
      pinMode( R_DIR_PIN , OUTPUT );

      // Configure the direction pins of Mottor
      digitalWrite(L_DIR_PIN, FWD);
      digitalWrite(R_DIR_PIN, FWD);
      
      // Stop the motor to ensure the initial state is 0
      analogWrite( L_PWM_PIN, 0 );
      analogWrite( R_PWM_PIN, 0 );
    }

    // Control the speed of the left and right tires,
    // can use symbols to control the direction of motor rotation.
    // Note that the value of PWM should be between 14 and 255.
    void setMottors( float PWM_L , float PWM_R ){
      
      // Contor the left Mottor
      if( PWM_L > 14 ){
        analogWrite( L_PWM_PIN , PWM_L );
        digitalWrite( L_DIR_PIN , FWD );
      }
      if( PWM_L <= 14 &&  PWM_L > 10 ){
        analogWrite( L_PWM_PIN , 14 );
        digitalWrite( L_DIR_PIN , FWD );
      }
      if( PWM_L <= 10 &&  PWM_L >= -10 ){
        analogWrite( L_PWM_PIN , 0 );
      }
      if( PWM_L >= -14 &&  PWM_L < -10 ){
        analogWrite( L_PWM_PIN , 14 );
        digitalWrite( L_DIR_PIN , REV );        
      }
      if( PWM_L < -14 ){
        analogWrite( L_PWM_PIN , -PWM_L );
        digitalWrite( L_DIR_PIN , REV );
      }
      if( PWM_L > 20 ){
        analogWrite( L_PWM_PIN , 20 );
        digitalWrite( L_DIR_PIN , FWD );
        Serial.println("PWM_L is too high");
      }
      if( PWM_L < -20 ){
        analogWrite( L_PWM_PIN , 20 );
        digitalWrite( L_DIR_PIN , REV );
        Serial.println("PWM_L is too high");
      }

      // Contor the left Mottor
      if( PWM_R > 14 ){
        analogWrite( R_PWM_PIN , PWM_R );
        digitalWrite( R_DIR_PIN , FWD );
      }
      if( PWM_R <= 14 &&  PWM_R > 10 ){
        analogWrite( R_PWM_PIN , 14 );
        digitalWrite( R_DIR_PIN , FWD );
      }
      if( PWM_R <= 10 &&  PWM_R >= -10 ){
        analogWrite( R_PWM_PIN , 0 );
      }
      if( PWM_R >= -14 &&  PWM_R < -10 ){
        analogWrite( R_PWM_PIN , 14 );
        digitalWrite( R_DIR_PIN , REV );
      }
      if( PWM_R < -14 ){
        analogWrite( R_PWM_PIN , -PWM_R );
        digitalWrite( R_DIR_PIN , REV );
      }
      if( PWM_R > 20 ){
        analogWrite( R_PWM_PIN , 20 );
        digitalWrite( R_DIR_PIN , FWD );
        Serial.println("PWM_R is too high");
      }
      if( PWM_R < -20 ){
        analogWrite( R_PWM_PIN , 20 );
        digitalWrite( R_DIR_PIN , REV );
        Serial.println("PWM_R is too high");
      }
      
    }
      
};



#endif
