Create a new ROS message:


Example IoTSensor : -id : int
                                    name : string 
                                    temperature : double
                                    humidity : double

such message is not define in ROS. So, we would like to define it and publish these values in ROS ecosystem and create subscriber that can listen to these values and process them. 


Steps to create a new ROS message :

1- Create a msg folder in your package 

2- Create the message file with file extension “.msg”   
  
3- edit the message file by adding the elements (one per line)
  http://wiki.ros.org/msg

4- Update the dependencies
     4-1.  in package.xml   
4.1.1 : <build_depend>message_generation</build_depend>

4.1.2 :  <exec_depend>message_runtime</exec_depend>

      4-2. in CmakeLists.txt

4.2.1 :  add  message_generation in find package

4.2.2 : ## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   IoTSensor.msg   
 )
4.2.3 :  ## catkin specific configuration ##
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES iotsensormessage
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
  DEPENDS system_lib
)
4.2.4 :  ## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   #actionlib_msgs
 )


5- compile the package using catkin_make

~/catkin_ws_IoTSensorMessage$ catkin_make

[ 14%] Generating Lisp code from iotsensormessage/IoTSensor.msg
[ 28%] Generating EusLisp manifest code for iotsensormessage
[ 57%] Generating Javascript code from iotsensormessage/IoTSensor.msg
[ 57%] Generating C++ code from iotsensormessage/IoTSensor.msg
[ 71%] Generating Python from MSG iotsensormessage/IoTSensor
[ 85%] Generating EusLisp code from iotsensormessage/IoTSensor.msg
[ 85%] Built target iotsensormessage_generate_messages_nodejs
[ 85%] Built target iotsensormessage_generate_messages_lisp
[ 85%] Built target iotsensormessage_generate_messages_cpp
[100%] Generating Python msg __init__.py for iotsensormessage
[100%] Built target iotsensormessage_generate_messages_py
[100%] Built target iotsensormessage_generate_messages_eus
Scanning dependencies of target iotsensormessage_generate_messages
[100%] Built target iotsensormessage_generate_messages


6- make sure that your message is created using rosmsg show

~/catkin_ws_IoTSensorMessage$ source devel/setup.bash
~/catkin_ws_IoTSensorMessage$ rosmsg show IoTSensor
[iotsensormessage/IoTSensor]:
int64 id
string name
float64 temperature
float64 humidity



# IoTSensorCustomMessagePub-SubApp
