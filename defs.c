#include "getbno080.h"
//a file i made up coz the fucking program didn't want to compile with the fucking version of fucking gcc i fuckin had :))))))
//made every one of these extern in getbno080.h

// I2C file descriptor
int i2cfd;

// Each packet has a header of 4 bytes
uint8_t shtpHeader[4];
// The data array for read and write operations
uint8_t shtpData[MAX_PACKET_SIZE];
// 6 SHTP channels. Each channel has its own seqnum
uint8_t sequence[6];
// Commands sequence number inside the command packet
uint8_t cmdsequence;
// > 10 words in a metadata, but we'll stop at Q point 3
unsigned int metaData[MAX_METADATA_SIZE];
//These are the raw sensor values pulled from the user requested Input Report
uint16_t rawAccelX, rawAccelY, rawAccelZ, accelAccuracy;
uint16_t rawLinAccelX, rawLinAccelY, rawLinAccelZ, accelLinAccuracy;
uint16_t rawGyroX, rawGyroY, rawGyroZ, gyroAccuracy;
uint16_t rawMagX, rawMagY, rawMagZ, magAccuracy;
uint16_t rawQuatI, rawQuatJ, rawQuatK, rawQuatReal, rawQuatRadianAccuracy, quatAccuracy;
uint16_t stepCount;
uint8_t stabilityClassifier;
uint8_t activityClassifier;
uint8_t *_activityConfidences; //Array that store the confidences of the 9 possible activities
uint8_t calibrationStatus; //Byte R0 of ME Calibration Response
//These Q values are defined in the datasheet but can also be obtained by querying the meta data records
//See the read metadata example for more info
int16_t rotationVector_Q1;
int16_t accelerometer_Q1;
int16_t linear_accelerometer_Q1;
int16_t gyro_Q1;
int16_t magnetometer_Q1;
