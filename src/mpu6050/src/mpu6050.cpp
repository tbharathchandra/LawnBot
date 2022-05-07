#include "mpu6050/mpu6050.h"

bool Mpu6050::ResetIMUServiceCallback(mpu6050::ResetIMU::Request &req, mpu6050::ResetIMU::Response &res)
{
  if(req.command == true)
  {
      reset_swith_ = true;
      ROS_INFO("Receive Service Call Reset IMU : True");
      res.message = "Receive success";
      res.result = "true";
  }
  return true;
}

double Mpu6050::DegreeToRadian(double value)
{
  return value * (M_PI/180.0);
}

double Mpu6050::RadianToDegree(double value)
{
  return value * (180.0/M_PI);
}

void Mpu6050::CalculationDeltaTime()
{
  double now = time_now_.sec + (time_now_.nsec) * 0.000000001;
  double last = time_last_.sec + (time_last_.nsec) * 0.000000001;
  dt_ = now - last;
}

void Mpu6050::InitVariable()
{
  ROS_INFO("InitVariable MPU6050");
  for (int i=0;i<=3;i++)
  {
    acceleration_[i] = 0.0;
    gyro_[i] = 0.0;

    average_acceleration_[i] = 0.0;
    average_gyro_[i] = 0.0;

    calibration_acceleration_[i] = 0.0;
    calibration_gyro_[i] = 0.0;
  }
}

void Mpu6050::Reset()
{
  ROS_INFO("Reset MPU6050");
  InitVariable();
  q0_ = 1.0; q1_ = 0.0; q2_ = 0.0; q3_ = 0.0;
  if(use_calibration_ == true) InitCalibration(calibration_times_);
  time_last_ = ros::Time::now();
  reset_swith_ = false;
  ROS_INFO("Start MPU6050");
}

void Mpu6050::InitCalibration(int value)
{
  ROS_INFO("Start Calibrating MPU6050");

  for (int i=0; i <value; i++)
  {
    GetImuData();
    average_acceleration_[0] += acceleration_[0];
    average_acceleration_[1] += acceleration_[1];
    average_acceleration_[2] += acceleration_[2] - 9.80665;
    average_gyro_[0] += gyro_[0];
    average_gyro_[1] += gyro_[1];
    average_gyro_[2] += gyro_[2];
    delay(10);
    ROS_INFO("Calibrating MPU6050 %d / %d", i+1, value);
  }

  average_acceleration_[0] = average_acceleration_[0]/value;
  average_acceleration_[1] = average_acceleration_[1]/value;
  average_acceleration_[2] = average_acceleration_[2]/value;
  average_gyro_[0] = average_gyro_[0]/value;
  average_gyro_[1] = average_gyro_[1]/value;
  average_gyro_[2] = average_gyro_[2]/value;

  ROS_INFO("Finish Calibrating MPU6050");

}

void Mpu6050::Calibration()
{
  calibration_acceleration_[0] = acceleration_[0] - average_acceleration_[0];
  calibration_acceleration_[1] = acceleration_[1] - average_acceleration_[1];
  calibration_acceleration_[2] = acceleration_[2] - average_acceleration_[2];

  calibration_gyro_[0] = DegreeToRadian(gyro_[0] - average_gyro_[0]);
  calibration_gyro_[1] = DegreeToRadian(gyro_[1] - average_gyro_[1]);
  calibration_gyro_[2] = DegreeToRadian(gyro_[2] - average_gyro_[2]);
}

void Mpu6050::GetROSParam()
{
  ros::NodeHandle n("~");
  n.param<bool>("AD0", ad0_, false);
  n.param<bool>("PublishTF", use_tf_, false);
  n.param<bool>("UseCalibration", use_calibration_, true);

  n.param<int>("CalibrationTimes", calibration_times_, 2000);
  if(calibration_times_ <= 0) calibration_times_ = 0;

  n.param<bool>("UseFilter", use_filter_, true);

  n.param<double>("FilterGain", beta_, 0.031);
  if(beta_ <= 0.0) beta_ = 0.031;

  n.param<int>("AccelerationScale", acceleration_scale_, 0);
  if(acceleration_scale_ < 0 | acceleration_scale_ > 3) acceleration_scale_ = 0;

  n.param<int>("GyroScale", gyro_scale_, 0);
  if(gyro_scale_ < 0 | gyro_scale_ > 3) gyro_scale_ = 0;

  n.param<std::string>("FrameID", frame_id_, "imu_link");
  n.param<std::string>("ParentsFrameID", parents_frame_id_, "base_link");

  ROS_INFO("AccelerationScale : %d", acceleration_scale_);
  ROS_INFO("GyroScale : %d", gyro_scale_);
}

void Mpu6050::SetUp()
{
  if(ad0_ == true) fd_ = wiringPiI2CSetup(ADDRESS_AD0_HIGH);
  else fd_ = wiringPiI2CSetup(ADDRESS_AD0_LOW);
}

void Mpu6050::InitSensor()
{
  wiringPiI2CWriteReg8 (fd_, SMPLRT_DIV, 0x07);
  wiringPiI2CWriteReg8 (fd_, PWR_MGMT_1, 0x04);
  wiringPiI2CWriteReg8 (fd_, CONFIG, 0x00);

  if(acceleration_scale_ == 0) wiringPiI2CWriteReg8 (fd_, ACCEL_CONFIG, 0x00);
  else if(acceleration_scale_ == 1) wiringPiI2CWriteReg8 (fd_, ACCEL_CONFIG, 0x08);
  else if(acceleration_scale_ == 2) wiringPiI2CWriteReg8 (fd_, ACCEL_CONFIG, 0x10);
  else if(acceleration_scale_ == 3) wiringPiI2CWriteReg8 (fd_, ACCEL_CONFIG, 0x18);
  else wiringPiI2CWriteReg8 (fd_, ACCEL_CONFIG, 0x00);

  if(gyro_scale_ == 0) wiringPiI2CWriteReg8 (fd_, GYRO_CONFIG, 0x00);
  else if(gyro_scale_ == 1) wiringPiI2CWriteReg8 (fd_, GYRO_CONFIG, 0x08);
  else if(gyro_scale_ == 2) wiringPiI2CWriteReg8 (fd_, GYRO_CONFIG, 0x10);
  else if(gyro_scale_ == 3) wiringPiI2CWriteReg8 (fd_, GYRO_CONFIG, 0x18);
  else wiringPiI2CWriteReg8 (fd_, GYRO_CONFIG, 0x00);

  wiringPiI2CWriteReg8 (fd_, INT_ENABLE, 0x01);
  wiringPiI2CWriteReg8 (fd_, SMPLRT_DIV, 0x07);
}

short Mpu6050::ReadRawData(int addr)
{
  short high_byte,low_byte,value;
  high_byte = wiringPiI2CReadReg8(fd_, addr);
  low_byte = wiringPiI2CReadReg8(fd_, addr+1);
  value = (high_byte << 8) | low_byte;
  return value;
}

void Mpu6050::GetImuData()
{
  acceleration_[0] = (ReadRawData(ACCEL_XOUT_H) / (16384.0 / pow(2, acceleration_scale_))) * 9.80665;
  acceleration_[1] = (ReadRawData(ACCEL_YOUT_H) / (16384.0 / pow(2, acceleration_scale_))) * 9.80665;
  acceleration_[2] = (ReadRawData(ACCEL_ZOUT_H) / (16384.0 / pow(2, acceleration_scale_))) * 9.80665;
  gyro_[0] = ReadRawData(GYRO_XOUT_H) / (131.072 / pow(2, gyro_scale_));
  gyro_[1] = ReadRawData(GYRO_YOUT_H) / (131.072 / pow(2, gyro_scale_));
  gyro_[2] = ReadRawData(GYRO_ZOUT_H) / (131.072 / pow(2, gyro_scale_));
}

void Mpu6050::CalculationQuaternion(double gx, double gy, double gz, double ax, double ay, double az)
{
  double recipNorm;
  double s0, s1, s2, s3;
  double qDot1, qDot2, qDot3, qDot4;
  double _2q0, _2q1, _2q2, _2q3, _4q0, _4q1, _4q2 ,_8q1, _8q2, q0q0, q1q1, q2q2, q3q3;

  // Rate of change of quaternion from gyroscope
  qDot1 = 0.5 * (-q1_ * gx - q2_ * gy - q3_ * gz);
  qDot2 = 0.5 * (q0_ * gx + q2_ * gz - q3_ * gy);
  qDot3 = 0.5 * (q0_ * gy - q1_ * gz + q3_ * gx);
  qDot4 = 0.5 * (q0_ * gz + q1_ * gy - q2_ * gx);

  if(use_filter_ == true)
  {
    // Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
    if(!((ax == 0.0) && (ay == 0.0) && (az == 0.0)))
    {

      // Normalise accelerometer measurement
      recipNorm = sqrt(ax * ax + ay * ay + az * az);
      recipNorm = 1.0/recipNorm;
      ax *= recipNorm;
      ay *= recipNorm;
      az *= recipNorm;

      // Auxiliary variables to avoid repeated arithmetic
      _2q0 = 2.0 * q0_;
      _2q1 = 2.0 * q1_;
      _2q2 = 2.0 * q2_;
      _2q3 = 2.0 * q3_;
      _4q0 = 4.0 * q0_;
      _4q1 = 4.0 * q1_;
      _4q2 = 4.0 * q2_;
      _8q1 = 8.0 * q1_;
      _8q2 = 8.0 * q2_;
      q0q0 = q0_ * q0_;
      q1q1 = q1_ * q1_;
      q2q2 = q2_ * q2_;
      q3q3 = q3_ * q3_;

      // Gradient decent algorithm corrective step
      s0 = _4q0 * q2q2 + _2q2 * ax + _4q0 * q1q1 - _2q1 * ay;
      s1 = _4q1 * q3q3 - _2q3 * ax + 4.0 * q0q0 * q1_ - _2q0 * ay - _4q1 + _8q1 * q1q1 + _8q1 * q2q2 + _4q1 * az;
      s2 = 4.0 * q0q0 * q2_ + _2q0 * ax + _4q2 * q3q3 - _2q3 * ay - _4q2 + _8q2 * q1q1 + _8q2 * q2q2 + _4q2 * az;
      s3 = 4.0 * q1q1 * q3_ - _2q1 * ax + 4.0 * q2q2 * q3_ - _2q2 * ay;
      recipNorm = sqrt(s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3); // normalise step magnitude
      recipNorm = 1.0/recipNorm;
      s0 *= recipNorm;
      s1 *= recipNorm;
      s2 *= recipNorm;
      s3 *= recipNorm;

      // Apply feedback step
      qDot1 -= beta_ * s0;
      qDot2 -= beta_ * s1;
      qDot3 -= beta_ * s2;
      qDot4 -= beta_ * s3;
    }
  }

  // Integrate rate of change of quaternion to yield quaternion
  q0_ += qDot1 * (1.0 * dt_);
  q1_ += qDot2 * (1.0 * dt_);
  q2_ += qDot3 * (1.0 * dt_);
  q3_ += qDot4 * (1.0 * dt_);

  // Normalise quaternion
  recipNorm = sqrt(q0_ * q0_ + q1_ * q1_ + q2_ * q2_ + q3_ * q3_);
  recipNorm = 1.0/recipNorm;
  q0_ *= recipNorm;
  q1_ *= recipNorm;
  q2_ *= recipNorm;
  q3_ *= recipNorm;

}

void Mpu6050::UpdateImuData()
{
  imu_.header.stamp = time_now_;
  imu_.header.frame_id = frame_id_;
  imu_.orientation.x = q1_;
  imu_.orientation.y = q2_;
  imu_.orientation.z = q3_;
  imu_.orientation.w = q0_;
  imu_.linear_acceleration.x = calibration_acceleration_[0];
  imu_.linear_acceleration.y = calibration_acceleration_[1];
  imu_.linear_acceleration.z = calibration_acceleration_[2];
  imu_.angular_velocity.x = calibration_gyro_[0];
  imu_.angular_velocity.y = calibration_gyro_[1];
  imu_.angular_velocity.z = calibration_gyro_[2];
}

void Mpu6050::UpdateTF()
{
  orientation_[0] = q1_;
  orientation_[1] = q2_;
  orientation_[2] = q3_;
  orientation_[3] = q0_;

  if(use_tf_ == true)
  {
    broadcaster_.sendTransform(tf::StampedTransform(tf::Transform(orientation_, tf::Vector3(0.0, 0.0, 0.0)),
                                                    time_now_,
                                                    parents_frame_id_,
                                                    frame_id_));
  }

}

void Mpu6050::UpdateAngle()
{
  tf::Matrix3x3 m(orientation_);
  double roll,pitch,yaw;
  m.getRPY(roll,pitch,yaw);

  angle_.TimeStamp = time_now_;
  angle_.roll = RadianToDegree(roll);
  angle_.pitch = RadianToDegree(pitch);
  angle_.yaw = RadianToDegree(yaw);
}

void Mpu6050::Update()
{
  UpdateImuData();
  UpdateTF();
  UpdateAngle();
}

void Mpu6050::Publisher()
{
  publisher_imu_.publish(imu_);
  publisher_rpy_.publish(angle_);
}

void Mpu6050::Spin()
{
  if(reset_swith_ == true) Reset();
  time_now_ = ros::Time::now();
  CalculationDeltaTime();
  GetImuData();
  Calibration();
  CalculationQuaternion(calibration_gyro_[0],calibration_gyro_[1],calibration_gyro_[2],calibration_acceleration_[0],calibration_acceleration_[1],calibration_acceleration_[2]);
  Update();
  Publisher();
  time_last_ = time_now_;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mpu6050_node");
    ros::NodeHandle n;
    ros::NodeHandle pn("~");

    int hz = 60;

    pn.param<int>("Hz", hz, 60);
    if(hz <= 0) hz = 60;

    ROS_INFO("mpu6050_node Open");

    ros::Rate loop_rate(hz);

    Mpu6050 mpu6050(n);

    while (ros::ok())
    {
      mpu6050.Spin();
      ros::spinOnce();
      loop_rate.sleep();
    }

    ROS_INFO("mpu6050_node Close");

    return 0;
}
