//g++ -g -o test main.cpp soapC.cpp stdsoap2.cpp duration.c soapDeviceBindingProxy.cpp
//g++ -DWITH_DOM -DWITH_OPENSSL -lssl -lcrypto -g -o test main.cpp soapC.cpp stdsoap2.cpp duration.c
// soapDeviceBindingProxy.cpp wsseapi.cpp mecevp.c smdevp.c dom.cpp wsaapi.c

#include <iostream>
#include <string>

#include "wsseapi.h"
#include "soapDeviceBindingProxy.h"
#include "wsdd.nsmap"

int main(int argc, const char * argv[])
{
	if(argc < 3) {
		std::cerr << "./test addr username passwd"<<std::endl;
		return 0;
	}
	
	int result = SOAP_ERR;
	//std::string endpoint = "http://192.168.201.96/onvif/device_service";
    //std::string username = "admin";
    //std::string password = "hik12345";
    std::string endpoint = argv[1];
    std::string username = argv[2];
    std::string password = argv[3];

    // GetDeviceInformation函数Access Class: READ_SYSTEM需要鉴权
	DeviceBindingProxy *dproxy = new DeviceBindingProxy();

    result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if(SOAP_OK !=result) {
	    std::cerr << "Authentication failed, retcode " << result << std::endl;;
		return 0;
	}
	
	_tds__GetDeviceInformation tds__GetDeviceInformation;
    _tds__GetDeviceInformationResponse tds__GetDeviceInformationResponse;
	 
    result = dproxy->GetDeviceInformation(endpoint.c_str(), NULL,
      &tds__GetDeviceInformation, tds__GetDeviceInformationResponse );
	  
    if (SOAP_OK !=result) {
        dproxy->soap_stream_fault(std::cerr);
	} else {
		std::cout << "Mfr: " << tds__GetDeviceInformationResponse.Manufacturer << std::endl;
        std::cout << "Model: " << tds__GetDeviceInformationResponse.Model << std::endl;
        std::cout << "F/W version: " << tds__GetDeviceInformationResponse.FirmwareVersion << std::endl;
    }

    dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
	
    return 0;
}