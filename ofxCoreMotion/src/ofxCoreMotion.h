

#import "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#import <CoreMotion/CMMotionManager.h>

/*
 ofxCoreMotion created by Trent Brooks.
    - Original DeviceMotion/attitude example by Nardove: http://forum.openframeworks.cc/index.php/topic,11517.0.html - Thanks!
    - Added Gyroscope, accelerometer, & magnetometer.
    - Attitude also has quaternion (used to spin the box in the example)
 
    Dependencies:
    1. add the 'CoreMotion.framework' to your OF xcode project
        - Under TARGETS > ofxCoreMotionExample, under the 'Build Phases' tab, where it says 'Link binary with libraries', click '+' and select the 'CoreMotion.framework'.
 */


#pragma once

class ofxCoreMotion {

public:
    
    ofxCoreMotion();
    virtual ~ofxCoreMotion();

    void setup(bool enableAttitude = true, bool enableAccelerometer = false, bool enableGyro = false, bool enableMagnetometer = false);
    
    void setupGyroscope();
    void setupAccelerometer();
    void setupMagnetometer();
    void setupAttitude(CMAttitudeReferenceFrame type = CMAttitudeReferenceFrameXArbitraryZVertical);
    
    void disableGyroscope();
    void disableAccelerometer();
    void disableMagnetometer();
    void disableAttitude();
    
    void resetAttitude(bool toCurrentReferenceFrame = true);
    
    void setUpdateFrequency(float updateFrequency);    
    void update();    
    
    ofVec3f getAccelerometerData();
    ofVec3f getGyroscopeData();
    ofVec3f getMagnetometerData();
    float getRoll();
    float getPitch();
    float getYaw();
    ofQuaternion getQuaternion();
    ofMatrix4x4 getRotationMatrix();
    //GLfloat* getRotationMatrix();
    ofVec3f getGravity();
    ofVec3f getUserAcceleration();
    ofVec3f getMagneticField();
    
protected:
    
    // core motion
    CMMotionManager* motionManager;
	CMAttitude* referenceAttitude;
    CMAttitudeReferenceFrame referenceFrameType; // 1,2,4,8
    
    float updateFrequency;
    bool enableAttitude, enableGyro, enableAccelerometer, enableMagnetometer;

    ofVec3f accelerometerData;
    ofVec3f gyroscopeData;
    ofVec3f magnetometerData;
    float roll, pitch, yaw;
    ofQuaternion attitudeQuat;
    ofMatrix4x4 rotMatrix;
    //GLfloat	rotMatrix[16];
    ofVec3f gravity;
    ofVec3f userAcceleration;
    ofVec3f magneticField;

};

