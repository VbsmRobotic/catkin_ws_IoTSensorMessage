/*
*Author : VAHID BEHTAJI
*Pub_Sub App for IoT sensor custom message
*/

#include<iostream>
#include<cmath>

#include "ros/ros.h"
#include "iotsensormessage/IoTSensor.h"      // name of packge is iotsensormessage


using namespace  std ;

ros::Publisher IoTSensor_pub ;
ros::Subscriber IoTSensor_sub ; 



void iot_sensor_callback(const iotsensormessage::IoTSensor msg)
{
    float temp = msg.temperature ;
    float hum  = msg.humidity ;
    ROS_INFO("New IoT sensor data received %f and %f ", temp, hum);
}
    

//main loop
int main(int argc, char **argv) 
    {
        //Initializes ROS, and sets up a node
        ros::init(argc, argv, "iot_sensor_node") ;

        /**
         * NodeHandle is the main access point to communications with the ROS system.
         * The first NodeHandle constructed will fully initialize this node, and the last
         * NodeHandle destructed will close down the node.
         */
        ros::NodeHandle n ;

        /**
         * The advertise() function is how you tell ROS that you want to
         * publish on a given topic name. This invokes a call to the ROS
         * master node, which keeps a registry of who is publishing and who
         * is subscribing. After this advertise() call is made, the master
         * node will notify anyone who is trying to subscribe to this topic name,
         * and they will in turn negotiate a peer-to-peer connection with this
         * node.  advertise() returns a Publisher object which allows you to
         * publish messages on that topic through a call to publish().  Once
         * all copies of the returned Publisher object are destroyed, the topic
         * will be automatically unadvertised.
         * 
         * data type is 
         * package name::folder.msg
         *  iotsensormessage::IoTSensor
         * 
         * The second parameter to advertise() is the size of the message queue
         * used for publishing messages.  If messages are published more quickly
         * than we can send them, the number here specifies how many messages to
         * buffer up before throwing some away.
         */
        
        IoTSensor_pub = n.advertise<iotsensormessage::IoTSensor>("IoTSensorData", 100);

        // Create a subscriber to the same topic 
        IoTSensor_sub = n.subscribe("IoTsensorData_New", 100, iot_sensor_callback);

        ros::Rate rate(1);   // 1 message per second





        // Run code in a loop till node is shutdown

        while(ros::ok())
        {
            /* initialize random seed: */
            srand (time(NULL));
            //Create message
            iotsensormessage::IoTSensor msgs ;

            // Load in message components
            msgs.id  = 1 ;
            msgs.name = "VAHID_CUSTOM_SENSOR" ;
            msgs.temperature = 36.85 + (rand()% 6);
            msgs.humidity =  8.65 + (rand() % 5) ;


            //TEST 
            ROS_INFO("%s", msgs.name.c_str());           
            ROS_INFO("%s", msgs.name.c_str());
            ROS_INFO("%f", msgs.temperature);
            ROS_INFO("%f", msgs.humidity);
      
            //Publish the message  publisher object is IoTSensor_pub
            IoTSensor_pub.publish(msgs) ;    //put it in buffer
            

            // Sleep to fix loop rate
            rate.sleep() ;

        }
    }








 