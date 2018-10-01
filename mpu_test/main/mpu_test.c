#include "SRA18.h"
#include "MPU.h"
#include "TUNING.h"

int setpoint = 0;
int initial_acce_angle = 0;
float pitch_angle = 0,roll_angle = 0;

void app_main()
{
    uint8_t* acce_rd = (uint8_t*) malloc(BUFF_SIZE);
    uint8_t* gyro_rd = (uint8_t*) malloc(BUFF_SIZE);
    int16_t* acce_raw_value = (int16_t*) malloc(BUFF_SIZE/2);
    int16_t* gyro_raw_value = (int16_t*) malloc(BUFF_SIZE/2);

    i2c_master_init();  //Initialise the I2C interface
    start_mpu();        //Intialise the MPU 
    
    while(1)
    {

          calculate_angle(acce_rd,gyro_rd,acce_raw_value,gyro_raw_value,initial_acce_angle,&roll_angle,&pitch_angle);  //Function to calculate pitch angle based on intial accelerometer angle
          printf("ROLL ANGLE %f\t", roll_angle);
          printf("PITCH ANGLE %f\n",pitch_angle);
       
    }   
}

