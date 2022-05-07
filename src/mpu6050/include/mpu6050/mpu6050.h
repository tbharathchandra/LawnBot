#ifndef MPU6050_H
#define MPU6050_H

#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_broadcaster.h>

#include "imu_msgs/Angle.h"
#include "mpu6050/ResetIMU.h"

#include <sensor_msgs/Imu.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>

#include <cmath>

#define ADDRESS_AD0_LOW     0x68
#define ADDRESS_AD0_HIGH    0x69

#define SELF_TEST_X 0x0D
#define SELF_TEST_Y 0x0E
#define SELF_TEST_Z 0x0F
#define SELF_TEST_A 0x10
#define SMPLRT_DIV       0x19
#define CONFIG           0x1A
#define GYRO_CONFIG      0x1B
#define ACCEL_CONFIG     0x1C
#define FIFO_EN          0x23
#define I2C_MST_CTRL     0x24
#define I2C_SLV0_ADDR    0x25
#define I2C_SLV0_REG     0x26
#define I2C_SLV0_CTRL    0x27
#define I2C_SLV1_ADDR    0x28
#define I2C_SLV1_REG     0x29
#define I2C_SLV1_CTRL    0x2A
#define I2C_SLV2_ADDR    0x2B
#define I2C_SLV2_REG     0x2C
#define I2C_SLV2_CTRL    0x2D
#define I2C_SLV3_ADDR    0x2E
#define I2C_SLV3_REG     0x2F
#define I2C_SLV3_CTRL    0x30
#define I2C_SLV4_ADDR    0x31
#define I2C_SLV4_REG     0x32
#define I2C_SLV4_DO      0x33
#define I2C_SLV4_CTRL    0x34
#define I2C_SLV4_DI      0x35
#define I2C_MST_STATUS   0x36
#define INT_PIN_CFG      0x37
#define INT_ENABLE       0x38
#define DMP_INT_STATUS   0x39
#define INT_STATUS       0x3A
#define ACCEL_XOUT_H     0x3B
#define ACCEL_XOUT_L     0x3C
#define ACCEL_YOUT_H     0x3D
#define ACCEL_YOUT_L     0x3E
#define ACCEL_ZOUT_H     0x3F
#define ACCEL_ZOUT_L     0x40
#define TEMP_OUT_H       0x41
#define TEMP_OUT_L       0x42
#define GYRO_XOUT_H      0x43
#define GYRO_XOUT_L      0x44
#define GYRO_YOUT_H      0x45
#define GYRO_YOUT_L      0x46
#define GYRO_ZOUT_H      0x47
#define GYRO_ZOUT_L      0x48
#define EXT_SENS_DATA_00 0x49
#define EXT_SENS_DATA_01 0x4A
#define EXT_SENS_DATA_02 0x4B
#define EXT_SENS_DATA_03 0x4C
#define EXT_SENS_DATA_04 0x4D
#define EXT_SENS_DATA_05 0x4E
#define EXT_SENS_DATA_06 0x4F
#define EXT_SENS_DATA_07 0x50
#define EXT_SENS_DATA_08 0x51
#define EXT_SENS_DATA_09 0x52
#define EXT_SENS_DATA_10 0x53
#define EXT_SENS_DATA_11 0x54
#define EXT_SENS_DATA_12 0x55
#define EXT_SENS_DATA_13 0x56
#define EXT_SENS_DATA_14 0x57
#define EXT_SENS_DATA_15 0x58
#define EXT_SENS_DATA_16 0x59
#define EXT_SENS_DATA_17 0x5A
#define EXT_SENS_DATA_18 0x5B
#define EXT_SENS_DATA_19 0x5C
#define EXT_SENS_DATA_20 0x5D
#define EXT_SENS_DATA_21 0x5E
#define EXT_SENS_DATA_22 0x5F
#define EXT_SENS_DATA_23 0x60
#define I2C_SLV0_DO      0x63
#define I2C_SLV1_DO      0x64
#define I2C_SLV2_DO      0x65
#define I2C_SLV3_DO      0x66
#define I2C_MST_DELAY_CTRL   0x67
#define SIGNAL_PATH_RESET    0x68
#define USER_CTRL        0x6A
#define PWR_MGMT_1       0x6B
#define PWR_MGMT_2       0x6C
#define FIFO_COUNTH      0x72
#define FIFO_COUNTL      0x73
#define FIFO_R_W         0x74
#define WHO_AM_I         0x75

class Mpu6050
{
public:
    Mpu6050(ros::NodeHandle &n)
        : publisher_imu_(n.advertise<sensor_msgs::Imu>("imu/data",1000)),
          publisher_rpy_(n.advertise<imu_msgs::Angle>("imu/angle",1000)),
          service_server_reset_imu_(n.advertiseService("reset_imu", &Mpu6050::ResetIMUServiceCallback, this))
       {
          GetROSParam();
          SetUp();
          InitSensor();
          Reset();
       }
       ~Mpu6050()
       {

       }

    bool ResetIMUServiceCallback(mpu6050::ResetIMU::Request &req,
                                     mpu6050::ResetIMU::Response &res);

    double DegreeToRadian(double value);

    double RadianToDegree(double value);

    void CalculationDeltaTime();

    void InitVariable();

    void Reset();

    void InitCalibration(int value);

    void Calibration();

    void GetROSParam();

    void SetUp();

    void InitSensor();

    short ReadRawData(int addr);

    void GetImuData();

    void CalculationQuaternion(double gx, double gy, double gz, double ax, double ay, double az);

    void UpdateImuData();

    void UpdateTF();

    void UpdateAngle();

    void Update();

    void Publisher();

    void Spin();

private:

    int fd_ = ADDRESS_AD0_LOW;
    bool ad0_ = false;
    bool use_tf_ = true;
    bool use_calibration_ = true;
    int calibration_times_ = 2000;
    bool use_filter_ = true;
    double beta_ = 0.031;
    int acceleration_scale_ = 0;
    int gyro_scale_ = 0;
    std::string frame_id_;
    std::string parents_frame_id_;

    double dt_ = 0.0;


    double acceleration_[3];
    double gyro_[3];

    double average_acceleration_[3];
    double average_gyro_[3];

    double calibration_acceleration_[3];
    double calibration_gyro_[3];

    ros::Time time_now_;
    ros::Time time_last_;
    tf::Quaternion orientation_;
    tf::TransformBroadcaster broadcaster_;

    ros::Publisher publisher_imu_;
    ros::Publisher publisher_rpy_;

    ros::ServiceServer service_server_reset_imu_;
    bool reset_swith_ = false;

    sensor_msgs::Imu imu_;
    imu_msgs::Angle angle_;

    double q0_ = 1.0, q1_ = 0.0, q2_ = 0.0, q3_ = 0.0;	// quaternion [w x y z]

};

	
#endif // MPU6050_H
