
#include <iostream>
#include <vector>

#include "libfreenect.h"

struct KinectPair {
  std::string serial;
  int id;
};

int main(int argc, char **argv) {

  freenect_context *kinectContext;

  if ( freenect_init(&kinectContext, NULL) < 0 )
    throw std::runtime_error("Cannot initialize freenect library");

  std::vector<KinectPair> deviceList;
  freenect_device_attributes * devAttrib; 
  
  int numDevices = freenect_list_device_attributes(kinectContext, &devAttrib);

  for(int i = 0; i < numDevices; i++) {
    KinectPair kp;
    kp.id = i;
    kp.serial = (std::string) devAttrib->camera_serial; 
    deviceList.push_back(kp);
    devAttrib = devAttrib->next;
  }

  for ( auto i = deviceList.begin(); i != deviceList.end(); i++ ) {
    std::cout << "DEVICE ID: " << i->id << std::endl;
    std::cout << "DEVICE SERIAL: " << i->serial << std::endl;
  }

  return 0;

}