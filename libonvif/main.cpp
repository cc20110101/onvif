//g++ -g -o test main.cpp -L/usr/local/onvif/lib -lonvif -lssl -lcrypto

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>

#include "wsaapi.h"
#include "wsseapi.h"
#include "wsddnsmap.h"
#include "soapwsddProxy.h"
#include "soapDeviceBindingProxy.h"
#include "soapDeviceIOBindingProxy.h"
#include "soapMediaBindingProxy.h"
#include "soapSearchBindingProxy.h"
#include "soapRecordingBindingProxy.h"
#include "soapReplayBindingProxy.h"
#include "soapPTZBindingProxy.h"
#include "soapPullPointSubscriptionBindingProxy.h"
#include "soapProvisioningBindingProxy.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ZOOMIN 4
#define ZOOMOUT 5
#define speed 5

using std::string;
using std::endl;

class DeviceInfo {
  public:
	std::string ip;
	std::string port;
	std::string addr;

  public:
	void init() {
		ip.clear();
		port.clear();
		addr.clear();
	}
};


class onviflib {

  public:

	void WSDiscovery();

	void getDateTime(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                 std::string username = "test",
	                 std::string password = "test12345");

	void getOSDs(std::string endpoint = "http://49.235.201.95/onvif/device_service",
	             std::string username = "test",
	             std::string password = "test");

	void getDevInfo(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                std::string username = "test",
	                std::string password = "test12345");

	void getVideoOutputInfo(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                        std::string username = "test",
	                        std::string password = "test12345");

	void getVideoSourceInfo(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                        std::string username = "test",
	                        std::string password = "test12345");

	void getStreamUri(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                  std::string username = "test",
	                  std::string password = "test12345");

	void systemReboot(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                  std::string username = "test",
	                  std::string password = "test12345");

	void getCapabilitieInfo(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                        std::string username = "test",
	                        std::string password = "test12345");

	// endpoint为getCapabilitieInfo获得的"http://49.235.201.96/onvif/Media"地址也可以，效果一样
	void getProfileInfo(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                    std::string username = "test",
	                    std::string password = "test12345");

	void getRecordTokenInfo(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                        std::string username = "test",
	                        std::string password = "test12345");

	void getAllRecordTokenInfo(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                           std::string username = "test",
	                           std::string password = "test12345");

	void getReplayUri(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                  std::string username = "test",
	                  std::string password = "test12345");

	void getRecordingConfiguration(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                               std::string username = "test",
	                               std::string password = "test12345");

	void getRecordingInformation(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                             std::string username = "test",
	                             std::string password = "test12345");

	void getMediaAttributes(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                        std::string username = "test",
	                        std::string password = "test12345");

	void PtzContinuousMove(int command = LEFT, std::string username = "test", std::string password = "test12345");

	void ProvisioningMove(std::string endpoint = "http://49.235.201.44/onvif/device_service",
	                      std::string username = "test",
	                      std::string password = "test12345");

	// "http://49.235.201.96/onvif/PTZ" 或 "http://49.235.201.96/onvif/device_service" 都可
	void getNodes(std::string endpoint = "http://49.235.201.96/onvif/PTZ",
	              std::string username = "test",
	              std::string password = "test12345");

	void getConfigurations(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                       std::string username = "test",
	                       std::string password = "test12345");

	void getPresets(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                std::string username = "test",
	                std::string password = "test12345");

	void setPreset(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	               std::string username = "test",
	               std::string password = "test12345");

	void gotoPreset(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                std::string username = "test",
	                std::string password = "test12345");

	void getEventProperties(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                        std::string username = "test",
	                        std::string password = "test12345");

	void createPullPointSubscription(std::string endpoint = "http://49.235.201.96/onvif/device_service",
	                                 std::string username = "test",
	                                 std::string password = "test12345");

	void getSnapshotUri(std::string endpoint = "http://49.235.201.130/onvif/device_service",
	                    std::string username = "test",
	                    std::string password = "test12345");

  private:

	time_t string2time_t(const std::string string_time);
	std::string time_t2string(const time_t time_t_time);
	DeviceInfo deviceInfo;
	std::vector<DeviceInfo> vDeviceInfo;
};

void onviflib::getSnapshotUri(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	MediaBindingProxy *dproxy = new MediaBindingProxy(SOAP_C_UTFSTRING);

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_trt__GetSnapshotUri trt__GetSnapshotUri;
	trt__GetSnapshotUri.ProfileToken = "Profile_101";
	_trt__GetSnapshotUriResponse trt__GetSnapshotUriResponse;
	result = dproxy->GetSnapshotUri(endpoint.c_str(), NULL, &trt__GetSnapshotUri, trt__GetSnapshotUriResponse);
	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		std::cerr << trt__GetSnapshotUriResponse.MediaUri->Uri << std::endl;
	}

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::getDateTime(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	DeviceBindingProxy *dproxy = new DeviceBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
		return;
	}

	_tds__GetSystemDateAndTime tds__GetSystemDateAndTime;
	_tds__GetSystemDateAndTimeResponse tds__GetSystemDateAndTimeResponse;
	result = dproxy->GetSystemDateAndTime(endpoint.c_str(), NULL,
	                                      &tds__GetSystemDateAndTime,
	                                      tds__GetSystemDateAndTimeResponse);

	if (SOAP_OK != result) {
		std::cerr << "error1=" << dproxy->soap_fault_string() << std::endl;
	} else {
		std::cout << tds__GetSystemDateAndTimeResponse.SystemDateAndTime->TimeZone->TZ << std::endl;

		tt__DateTime *tt = tds__GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime;
		std::cout << tt->Date->Year << "-" << tt->Date->Month << "-" << tt->Date->Day << " " <<
		          tt->Time->Hour << ":" << tt->Time->Minute << ":" << tt->Time->Second << std::endl;

		tt = tds__GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime;
		std::cout << tt->Date->Year << "-" << tt->Date->Month << "-" << tt->Date->Day << " " <<
		          tt->Time->Hour << ":" << tt->Time->Minute << ":" << tt->Time->Second << std::endl;
		/*
		<tds:GetSystemDateAndTimeResponse>
		<tds:SystemDateAndTime>
		<tt:DateTimeType>Manual</tt:DateTimeType>
		<tt:DaylightSavings>false</tt:DaylightSavings>
		<tt:TimeZone><tt:TZ>CST-8:00:00</tt:TZ>
		</tt:TimeZone>
		<tt:UTCDateTime><tt:Time><tt:Hour>7</tt:Hour>
		<tt:Minute>25</tt:Minute>
		<tt:Second>17</tt:Second>
		</tt:Time>
		<tt:Date><tt:Year>2020</tt:Year>
		<tt:Month>4</tt:Month>
		<tt:Day>29</tt:Day>
		</tt:Date>
		</tt:UTCDateTime>
		<tt:LocalDateTime><tt:Time><tt:Hour>15</tt:Hour>
		<tt:Minute>25</tt:Minute>
		<tt:Second>17</tt:Second>
		</tt:Time>
		<tt:Date><tt:Year>2020</tt:Year>
		<tt:Month>4</tt:Month>
		<tt:Day>29</tt:Day>
		</tt:Date>
		</tt:LocalDateTime>
		</tds:SystemDateAndTime>
		</tds:GetSystemDateAndTimeResponse>
		*/
	}

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
		return;
	}

	tt__TimeZone tz;
	tz.TZ = "CST-08:00:00";

	tt__Date da;
	da.Year = 2020;
	da.Month = 4;
	da.Day = 29;

	tt__Time ti;
	ti.Hour = 2;
	ti.Minute = 20;
	ti.Second = 35;

	tt__DateTime dt;
	dt.Date = &da;
	dt.Time = &ti;

	_tds__SetSystemDateAndTime tds__SetSystemDateAndTime;
	tds__SetSystemDateAndTime.DateTimeType = tt__SetDateTimeType__Manual; //手工或NTP
	tds__SetSystemDateAndTime.DaylightSavings = false; //夏令时打开或者关闭
	tds__SetSystemDateAndTime.UTCDateTime = &dt;
	tds__SetSystemDateAndTime.TimeZone = &tz;

	_tds__SetSystemDateAndTimeResponse tds__SetSystemDateAndTimeResponse;
	result = dproxy->SetSystemDateAndTime(endpoint.c_str(), NULL,
	                                      &tds__SetSystemDateAndTime,
	                                      tds__SetSystemDateAndTimeResponse);

	if (SOAP_OK != result) {
		std::cerr << "error1=" << dproxy->soap_fault_string() << std::endl;
	} else {}


	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::getOSDs(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	MediaBindingProxy *dproxy = new MediaBindingProxy(SOAP_C_UTFSTRING);

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_trt__GetOSDs trt__GetOSDs;
	_trt__GetOSDsResponse trt__GetOSDsResponse;
	result = dproxy->GetOSDs(endpoint.c_str(), NULL, &trt__GetOSDs, trt__GetOSDsResponse);
	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		std::string *str;
		for (int i = 0; i < trt__GetOSDsResponse.OSDs.size(); ++i) {
			std::cerr << trt__GetOSDsResponse.OSDs[i]->VideoSourceConfigurationToken->__item << std::endl;
			if (trt__GetOSDsResponse.OSDs[i]->TextString->PlainText)
				std::cerr << *trt__GetOSDsResponse.OSDs[i]->TextString->PlainText << std::endl;
			//else
			//  continue;

			for (int j = 0; j < trt__GetOSDsResponse.OSDs[i]->TextString->Extension->__any.size(); ++j) {
				if (strncmp(trt__GetOSDsResponse.OSDs[i]->TextString->Extension->__any[j],
				            "<tt:ChannelName>true", 20) == 0)
					std::cerr << trt__GetOSDsResponse.OSDs[i]->TextString->Extension->__any[j] << std::endl;
			}
		}
	}


	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::WSDiscovery() {


	char wsaTo[128] = {"urn:schemas-xmlsoap-org:ws:2005:04:discovery"};
	char wsaAction[128] = {"http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe"};
	char McastAddr[128] = {"soap.udp://239.255.255.250:3702"};
	char item[10] = {0};
	char types[64] = {"dn:NetworkVideoTransmitter"};

	wsddProxy *wsdd = new wsddProxy();

	wsdd->soap->recv_timeout = 3;  //3s
	wsdd->soap->send_timeout = 3;
	wsdd->soap->connect_timeout = 3;

	struct SOAP_ENV__Header header;
	soap_default_SOAP_ENV__Header(wsdd->soap, &header);

	header.wsa__MessageID = (char *)soap_wsa_rand_uuid(wsdd->soap);
	header.wsa__To = wsaTo;
	header.wsa__Action = wsaAction;
	wsdd->soap->header = &header;

	wsdd__ScopesType sScope;
	soap_default_wsdd__ScopesType(wsdd->soap, &sScope);       //跟soap_default_SOAP_ENV__Header类似
	//sScope.__item = item;
	wsdd__ProbeType req;
	soap_default_wsdd__ProbeType(wsdd->soap, &req);
	req.Scopes = &sScope;
	req.Types = types;

	int result = wsdd->send_Probe(McastAddr, NULL, &req);
	if (SOAP_OK != result) {
		std::cerr << "send_Probe error";
		return;
	}

	vDeviceInfo.clear();
	std::string strXAddr;
	struct __wsdd__ProbeMatches resp;
	while (result == SOAP_OK) {
		memset(&resp, 0x00, sizeof(resp));
		result = wsdd->recv_ProbeMatches(resp);
		if (result == SOAP_OK && !(wsdd->soap->error)) {
			for (int i = 0; i < resp.wsdd__ProbeMatches->__sizeProbeMatch; ++i) {
				strXAddr = resp.wsdd__ProbeMatches->ProbeMatch->XAddrs;
				//"http://49.235.201.105:80/onvif/device_service http://49.235.2.64:80/onvif/device_service"
				//"http://49.235.201.130/onvif/device_service http://[fe80::869a:40ff:fe80:c41d]/onvif/device_service"
				//"http://49.235.201.95:80/onvif/device_service"

				//std::cerr << "__sizeProbeMatch        :" << resp.wsdd__ProbeMatches->__sizeProbeMatch << std::endl;
				//std::cerr << "Target EP Address       :" << resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.Address << std::endl;
				//std::cerr << "Target Type             :" << resp.wsdd__ProbeMatches->ProbeMatch->Types << std::endl;
				//std::cerr << "Target Service Address  :" << resp.wsdd__ProbeMatches->ProbeMatch->XAddrs << std::endl;
				//std::cerr << "Target Metadata Version :" << resp.wsdd__ProbeMatches->ProbeMatch->MetadataVersion << std::endl;
				//std::cerr << std::endl;

				//deviceInfo
				std::string strSingleAddr;
				string::size_type pos1;
				string::size_type pos = strXAddr.find(' ');
				while (string::npos != pos) {

					deviceInfo.init();
					strSingleAddr = strXAddr.substr(0, pos);
					strXAddr = strXAddr.substr(pos + 1);
					pos = strXAddr.find(' ');

					deviceInfo.addr = strSingleAddr;

					pos1 = strSingleAddr.find("//", 0);
					if (string::npos != pos1) {
						strSingleAddr = strSingleAddr.substr(pos1 + 2);
						pos1 = strSingleAddr.find('/', 0);
						if (string::npos != pos1) {
							strSingleAddr = strSingleAddr.substr(0, pos1);
							pos1 = strSingleAddr.find(']', 0);
							if (string::npos != pos1) {
								deviceInfo.ip = strSingleAddr.substr(0, pos1 + 1);
								strSingleAddr = strSingleAddr.substr(pos1 + 1);
								if (strSingleAddr.empty())
									deviceInfo.port = "80";
								else
									deviceInfo.port = strSingleAddr.substr(1);
							} else {
								pos1 = strSingleAddr.find(':', 0);
								if (string::npos != pos1) {
									deviceInfo.ip = strSingleAddr.substr(0, pos1);
									deviceInfo.port = strSingleAddr.substr(pos1 + 1);
								} else {
									deviceInfo.ip = strSingleAddr;
									deviceInfo.port = "80";
								}
							}
						} else {
							continue;
						}
					} else {
						continue;
					}

					vDeviceInfo.push_back(deviceInfo);
				}

				deviceInfo.init();
				deviceInfo.addr = strXAddr;
				strSingleAddr = strXAddr;
				pos1 = strSingleAddr.find("//", 0);
				if (string::npos != pos1) {
					strSingleAddr = strSingleAddr.substr(pos1 + 2);
					pos1 = strSingleAddr.find('/', 0);
					if (string::npos != pos1) {
						strSingleAddr = strSingleAddr.substr(0, pos1);
						pos1 = strSingleAddr.find(']', 0);
						if (string::npos != pos1) {
							deviceInfo.ip = strSingleAddr.substr(0, pos1 + 1);
							strSingleAddr = strSingleAddr.substr(pos1 + 1);
							if (strSingleAddr.empty())
								deviceInfo.port = "80";
							else
								deviceInfo.port = strSingleAddr.substr(1);
						} else {
							pos1 = strSingleAddr.find(':', 0);
							if (string::npos != pos1) {
								deviceInfo.ip = strSingleAddr.substr(0, pos1);
								deviceInfo.port = strSingleAddr.substr(pos1 + 1);
							} else {
								deviceInfo.ip = strSingleAddr;
								deviceInfo.port = "80";
							}
						}
					} else {
						continue;
					}
				} else {
					continue;
				}

				vDeviceInfo.push_back(deviceInfo);
			}
		} else {
			break;
		}
	}

	for (int i = 0; i < vDeviceInfo.size(); ++i) {
		std::cerr << vDeviceInfo[i].addr << std::endl;
		std::cerr << vDeviceInfo[i].ip << std::endl;
		std::cerr << vDeviceInfo[i].port << std::endl;
		std::cerr << std::endl;
	}

}

void onviflib::createPullPointSubscription(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	PullPointSubscriptionBindingProxy *psub = new PullPointSubscriptionBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(psub->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}


	_tev__CreatePullPointSubscription tev__CreatePullPointSubscription;

	std::string initialTerminationTime = "PT180S";
	tev__CreatePullPointSubscription.InitialTerminationTime = &initialTerminationTime;

	wsnt__FilterType *filter = soap_new_wsnt__FilterType(psub->soap, -1);
	tev__CreatePullPointSubscription.Filter = filter;

	wsnt__TopicExpressionType *topicExpressionType = soap_new_wsnt__TopicExpressionType(psub->soap, -1);
	filter->TopicExpression = topicExpressionType; //可以加过滤主题条件
	topicExpressionType->Dialect = "http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet";
	//char topic[100] = {"tns1:Monitoring/ProcessorUsage|tns1:VideoSource//"};
	char topic[100] = {""};
	topicExpressionType->__mixed = topic;

	_tev__CreatePullPointSubscriptionResponse tev__CreatePullPointSubscriptionResponse;
	result = psub->CreatePullPointSubscription(endpoint.c_str(), NULL,
	         &tev__CreatePullPointSubscription,
	         tev__CreatePullPointSubscriptionResponse);

	if (SOAP_OK != result) {
		psub->soap_stream_fault(std::cerr);
		return;
	}

	/*
	<tev:CreatePullPointSubscriptionResponse>
	<tev:SubscriptionReference>
	<wsa:Address>http://49.235.201.96/onvif/Events/PullSubManager_20200414T032252Z_0</wsa:Address>
	</tev:SubscriptionReference>
	<wsnt:CurrentTime>2020-04-14T03:22:52Z</wsnt:CurrentTime>
	<wsnt:TerminationTime>2020-04-14T03:23:52Z</wsnt:TerminationTime>
	</tev:CreatePullPointSubscriptionResponse>
	*/

	char *address = tev__CreatePullPointSubscriptionResponse.SubscriptionReference.Address;
	std::cerr << "地址：" << address << std::endl;
	std::cerr << "结束时间：" << time_t2string(tev__CreatePullPointSubscriptionResponse.wsnt__TerminationTime) << std::endl << std::endl; //20200428104706
	//std::cerr << "结束时间：" << tev__CreatePullPointSubscriptionResponse.wsnt__TerminationTime << std::endl;  //1588042026

	for (int i = 0; i < 10000; ++i) {
		std::cerr << "----------" << std::endl;
		psub = new PullPointSubscriptionBindingProxy(); //这里重新创建也可以

		result = soap_wsse_add_UsernameTokenDigest(psub->soap, NULL, username.c_str(), password.c_str());
		if (SOAP_OK != result) {
			std::cerr << "Authentication failed, retcode " << result << std::endl;
			return;
		}

		std::string terminationTime = "PT1M";
		_wsnt__Renew wsnt__Renew;
		wsnt__Renew.TerminationTime = &terminationTime;
		_wsnt__RenewResponse wsnt__RenewResponse;
		result = psub->Renew(address, NULL, &wsnt__Renew, wsnt__RenewResponse);
		if (SOAP_OK != result) {
			std::cerr << "Renew failed, retcode " << result << std::endl;
			return;
		}

		result = soap_wsse_add_UsernameTokenDigest(psub->soap, NULL, username.c_str(), password.c_str());
		if (SOAP_OK != result) {
			std::cerr << "Authentication failed, retcode " << result << std::endl;
			return;
		}

		_tev__PullMessages tev__PullMessages;
		tev__PullMessages.Timeout = 5;  //ms  阻塞试,超时时间
		tev__PullMessages.MessageLimit = 1024;
		_tev__PullMessagesResponse tev__PullMessagesResponse;
		result = psub->PullMessages(address, NULL, &tev__PullMessages, tev__PullMessagesResponse);
		if (SOAP_OK != result) {
			std::cerr << "PullMessages failed, retcode " << result << std::endl;
			return;
		}
		std::cerr << time_t2string(tev__PullMessagesResponse.CurrentTime) << "--" << time_t2string(tev__PullMessagesResponse.TerminationTime) << std::endl << std::endl;
		for (int j = 0; j < tev__PullMessagesResponse.wsnt__NotificationMessage.size(); ++j) {

			wsnt__TopicExpressionType *topic = tev__PullMessagesResponse.wsnt__NotificationMessage[j]->Topic;
			if (topic) {
				std::cerr << topic->__any  << std::endl; //主题
				std::cerr << topic->Dialect  << std::endl;
			} else {
				std::cerr << "topic is empty" << std::endl;
			}

			std::cerr << "PropertyOperation:" << *(tev__PullMessagesResponse.wsnt__NotificationMessage[j]->Message.tt__Message->PropertyOperation) << std::endl;

			std::vector<_tt__ItemList_SimpleItem> simpleItem;
			tt__ItemList *itemList = tev__PullMessagesResponse.wsnt__NotificationMessage[j]->Message.tt__Message->Source;
			if (itemList) {
				simpleItem = itemList->SimpleItem;
				for (int k = 0; k < simpleItem.size(); ++ k) {
					std::cerr << simpleItem[k].Name << ":" << simpleItem[k].Value << std::endl;
				}
			}

			itemList = tev__PullMessagesResponse.wsnt__NotificationMessage[j]->Message.tt__Message->Key;
			if (itemList) {
				simpleItem = itemList->SimpleItem;
				for (int k = 0; k < simpleItem.size(); ++ k) {
					std::cerr << simpleItem[k].Name << ":" << simpleItem[k].Value << std::endl;
				}
			}

			itemList = tev__PullMessagesResponse.wsnt__NotificationMessage[j]->Message.tt__Message->Data;
			if (itemList) {
				simpleItem = itemList->SimpleItem;
				for (int k = 0; k < simpleItem.size(); ++ k) {
					std::cerr << simpleItem[k].Name << ":" << simpleItem[k].Value << std::endl;
				}
			}

			std::cerr << std::endl;
		}

		/*
		20200414135259--20200414140359
		tns1:VideoSource/MotionAlarm
		http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet
		<tt:Message UtcTime="2020-04-14T05:52:59Z" PropertyOperation="Initialized">
		<tt:Source><tt:SimpleItem Name="Source" Value="VideoSource_1"/>
		</tt:Source>
		<tt:Data><tt:SimpleItem Name="State" Value="false"/>
		</tt:Data>
		</tt:Message>
		*/
	}

	/*
	<tev:PullMessagesResponse><tev:CurrentTime>2020-04-14T03:25:49Z</tev:CurrentTime>
	<tev:TerminationTime>2020-04-14T03:37:49Z</tev:TerminationTime>
	<wsnt:NotificationMessage>
	<wsnt:Topic Dialect="http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet">tns1:VideoSource/MotionAlarm</wsnt:Topic>
	<wsnt:Message><tt:Message UtcTime="2020-04-14T03:25:49Z" PropertyOperation="Initialized"><tt:Source><tt:SimpleItem Name="Source" Value="VideoSource_1"/>
	</tt:Source>
	<tt:Data><tt:SimpleItem Name="State" Value="false"/>
	</tt:Data>
	</tt:Message>
	</wsnt:Message>
	</wsnt:NotificationMessage>
	.....
	<wsnt:NotificationMessage><wsnt:Topic Dialect="http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet">tns1:Device/Trigger/DigitalInput</wsnt:Topic>
	<wsnt:Message><tt:Message UtcTime="2020-04-14T03:25:49Z" PropertyOperation="Initialized"><tt:Source><tt:SimpleItem Name="InputToken" Value="AlarmIn_2"/>
	</tt:Source>
	<tt:Data><tt:SimpleItem Name="LogicalState" Value="false"/>
	</tt:Data>
	</tt:Message>
	</wsnt:Message>
	</wsnt:NotificationMessage>
	</tev:PullMessagesResponse>
	*/

	result = soap_wsse_add_UsernameTokenDigest(psub->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_wsnt__Unsubscribe wsnt__Unsubscribe;
	_wsnt__UnsubscribeResponse wsnt__UnsubscribeResponse;
	result = psub->Unsubscribe(address, NULL, &wsnt__Unsubscribe, wsnt__UnsubscribeResponse);
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	psub->destroy();
	delete psub;
	psub = NULL;
}

void onviflib::getEventProperties(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	PullPointSubscriptionBindingProxy *psub = new PullPointSubscriptionBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(psub->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tev__GetEventProperties tev__GetEventProperties;
	_tev__GetEventPropertiesResponse tev__GetEventPropertiesResponse;
	result = psub->GetEventProperties(endpoint.c_str(), NULL, &tev__GetEventProperties, tev__GetEventPropertiesResponse);

	if (SOAP_OK != result) {
		psub->soap_stream_fault(std::cerr);
		return;
	}

	for (int i = 0; i < tev__GetEventPropertiesResponse.wstop__TopicSet->__any.size(); ++i) {
		std::cerr << tev__GetEventPropertiesResponse.wstop__TopicSet->__any[i] << std::endl;
	}
	/*
	<tev:GetEventPropertiesResponse>
	<tev:TopicNamespaceLocation>http://www.onvif.org/onvif/ver10/topics/topicns.xml</tev:TopicNamespaceLocation>
	<wsnt:FixedTopicSet>true</wsnt:FixedTopicSet>
	<wstop:TopicSet><tns1:VideoSource wstop:topic="false">
	<MotionAlarm wstop:topic="true">
	<tt:MessageDescription IsProperty="true">
	<tt:Source><tt:SimpleItemDescription Name="Source" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="State" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</MotionAlarm>
	<ImageTooDark wstop:topic="false"><ImagingService wstop:topic="true">
	<tt:MessageDescription IsProperty="true">
	<tt:Source><tt:SimpleItemDescription Name="Source" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="State" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</ImagingService>
	</ImageTooDark>
	</tns1:VideoSource>
	<tns1:Device wstop:topic="false"><Trigger wstop:topic="false"><tnshik:AlarmIn wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="AlarmInToken" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="State" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</tnshik:AlarmIn>
	<DigitalInput wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="InputToken" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="LogicalState" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</DigitalInput>
	<Relay wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="RelayToken" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="LogicalState" Type="tt:RelayLogicalState"/>
	</tt:Data>
	</tt:MessageDescription>
	</Relay>
	</Trigger>
	<HardwareFailure wstop:topic="false"><tnshik:HardDiskFull wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="HardDiskNo" Type="xs:int"/>
	</tt:Source>
	</tt:MessageDescription>
	</tnshik:HardDiskFull>
	<tnshik:HardDiskError wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="HardDiskNo" Type="xs:int"/>
	</tt:Source>
	</tt:MessageDescription>
	</tnshik:HardDiskError>
	<StorageFailure wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="Failed" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</StorageFailure>
	</HardwareFailure>
	<tnshik:Network wstop:topic="false"><tnshik:EthernetBroken wstop:topic="true"/>
	<tnshik:IPAddrConflict wstop:topic="true"/>
	</tnshik:Network>
	</tns1:Device>
	<tns1:UserAlarm wstop:topic="false"><tnshik:IllegalAccess wstop:topic="true"/>
	</tns1:UserAlarm>
	<tns1:RuleEngine wstop:topic="false"><CellMotionDetector wstop:topic="false"><Motion wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="VideoSourceConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="VideoAnalyticsConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="Rule" Type="xs:string"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="IsMotion" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</Motion>
	</CellMotionDetector>
	<LineDetector wstop:topic="false"><Crossed wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="VideoSourceConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="VideoAnalyticsConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="Rule" Type="xs:string"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="ObjectId" Type="xs:integer"/>
	</tt:Data>
	</tt:MessageDescription>
	</Crossed>
	</LineDetector>
	<FieldDetector wstop:topic="false"><ObjectsInside wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="VideoSourceConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="VideoAnalyticsConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="Rule" Type="xs:string"/>
	</tt:Source>
	<tt:Key><tt:SimpleItemDescription Name="ObjectId" Type="xs:integer"/>
	</tt:Key>
	<tt:Data><tt:SimpleItemDescription Name="IsInside" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</ObjectsInside>
	</FieldDetector>
	<TamperDetector wstop:topic="false"><Tamper wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="VideoSourceConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="VideoAnalyticsConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="Rule" Type="xs:string"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="IsTamper" Type="xs:boolean"/>
	</tt:Data>
	</tt:MessageDescription>
	</Tamper>
	</TamperDetector>
	</tns1:RuleEngine>
	<tns1:AudioAnalytics wstop:topic="false"><Audio wstop:topic="false"><DetectedSound wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="AudioSourceConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="AudioAnalyticsConfigurationToken" Type="tt:ReferenceToken"/>
	<tt:SimpleItemDescription Name="Rule" Type="xs:string"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="isSoundDetected" Type="xs:boolean"/>
	<tt:SimpleItemDescription Name="UTCTime" Type="xs:dateTime"/>
	</tt:Data>
	</tt:MessageDescription>
	</DetectedSound>
	</Audio>
	</tns1:AudioAnalytics>
	<tns1:Configuration wstop:topic="false"><Profile wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:Profile"/>
	</tt:Data>
	</tt:MessageDescription>
	</Profile>
	<VideoEncoderConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:VideoEncoderConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</VideoEncoderConfiguration>
	<VideoSourceConfiguration wstop:topic="false"><MediaService wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:VideoSourceConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</MediaService>
	</VideoSourceConfiguration>
	<AudioEncoderConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:AudioEncoderConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</AudioEncoderConfiguration>
	<AudioSourceConfiguration wstop:topic="false"><MediaService wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:AudioSourceConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</MediaService>
	</AudioSourceConfiguration>
	<AudioOutputConfiguration wstop:topic="false"><MediaService wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:AudioOutputConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</MediaService>
	</AudioOutputConfiguration>
	<MetadataConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:MetadataConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</MetadataConfiguration>
	<PTZConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:PTZConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</PTZConfiguration>
	<VideoAnalyticsConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:VideoAnalyticsConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</VideoAnalyticsConfiguration>
	</tns1:Configuration>
	<tns1:RecordingConfig wstop:topic="false" xmlns:xs="http://www.w3.org/2001/XMLSchema"><JobState wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="RecordingJobToken" Type="tt:RecordingJobReference"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="State" Type="xs:string"/>
	<tt:ElementItemDescription Name="Information" Type="tt:RecordingJobStateInformation"/>
	</tt:Data>
	</tt:MessageDescription>
	</JobState>
	<RecordingJobConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="RecordingJobToken" Type="tt:RecordingJobReference"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:RecordingJobConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</RecordingJobConfiguration>
	<RecordingConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="RecordingToken" Type="tt:RecordingReference"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:RecordingConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</RecordingConfiguration>
	<TrackConfiguration wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="RecordingToken" Type="tt:RecordingReference"/>
	<tt:SimpleItemDescription Name="TrackToken" Type="tt:TrackReference"/>
	</tt:Source>
	<tt:Data><tt:ElementItemDescription Name="Configuration" Type="tt:TrackConfiguration"/>
	</tt:Data>
	</tt:MessageDescription>
	</TrackConfiguration>
	</tns1:RecordingConfig>
	<tns1:Monitoring wstop:topic="false"><ProcessorUsage wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="Value" Type="xs:float"/>
	</tt:Data>
	</tt:MessageDescription>
	</ProcessorUsage>
	<OperatingTime wstop:topic="false"><LastReset wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Data><tt:SimpleItemDescription Name="Status" Type="xs:dateTime"/>
	</tt:Data>
	</tt:MessageDescription>
	</LastReset>
	</OperatingTime>
	<OperatingTime wstop:topic="false"><LastReboot wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Data><tt:SimpleItemDescription Name="Status" Type="xs:dateTime"/>
	</tt:Data>
	</tt:MessageDescription>
	</LastReboot>
	</OperatingTime>
	<OperatingTime wstop:topic="false"><LastClockSynchronization wstop:topic="true"><tt:MessageDescription IsProperty="true"><tt:Data><tt:SimpleItemDescription Name="Status" Type="xs:dateTime"/>
	</tt:Data>
	</tt:MessageDescription>
	</LastClockSynchronization>
	</OperatingTime>
	</tns1:Monitoring>
	<tns1:Media wstop:topic="false"><ProfileChanged wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Data><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Data>
	</tt:MessageDescription>
	</ProfileChanged>
	<ConfigurationChanged wstop:topic="true"><tt:MessageDescription IsProperty="false"><tt:Source><tt:SimpleItemDescription Name="Token" Type="tt:ReferenceToken"/>
	</tt:Source>
	<tt:Data><tt:SimpleItemDescription Name="Type" Type="xs:string"/>
	</tt:Data>
	</tt:MessageDescription>
	</ConfigurationChanged>
	</tns1:Media>
	</wstop:TopicSet>
	<wsnt:TopicExpressionDialect>http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet</wsnt:TopicExpressionDialect>
	<wsnt:TopicExpressionDialect>http://docs.oasis-open.org/wsn/t-1/TopicExpression/Concrete</wsnt:TopicExpressionDialect>
	<tev:MessageContentFilterDialect>http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter</tev:MessageContentFilterDialect>
	<tev:MessageContentSchemaLocation>http://www.onvif.org/onvif/ver10/schema/onvif.xsd</tev:MessageContentSchemaLocation>
	</tev:GetEventPropertiesResponse>



	设备报警   设备离线
	           硬盘故障    tns1:Device:HardwareFailure

	视频通道报警
	        通道离线
	        移动侦测
	        快速移动
	        入侵检测
	        物品遗漏
	        徘徊检测
	        绊线检测

	tns1:VideoSource:MotionAlarm
	tns1:VideoSource:ImageTooDark:ImagingService

	tns1:Device:Trigger:tnshik:AlarmIn
	tns1:Device:Trigger:DigitalInput
	tns1:Device:Trigger:Trigger:Relay
	tns1:Device:HardwareFailure:tnshik:HardDiskFull
	tns1:Device:HardwareFailure:tnshik:HardDiskError
	tns1:Device:HardwareFailure:StorageFailure
	tns1:Device:tnshik:Network:tnshik:EthernetBroken
	tns1:Device:tnshik:Network:tnshik:IPAddrConflict

	tns1:UserAlarm:tnshik:IllegalAccess

	tns1:RuleEngine:CellMotionDetector:Motion
	tns1:RuleEngine:LineDetector:Crossed
	tns1:RuleEngine:FieldDetector:ObjectsInside
	tns1:RuleEngine:TamperDetector:Tamper    遮挡报警

	tns1:AudioAnalytics:Audio:DetectedSound

	tns1:Configuration:Profile
	tns1:Configuration:VideoEncoderConfiguration
	tns1:Configuration:VideoSourceConfiguration:MediaService
	tns1:Configuration:AudioEncoderConfiguration
	tns1:Configuration:AudioSourceConfiguration:AudioSourceConfiguration
	tns1:Configuration:AudioOutputConfiguration:MediaService
	tns1:Configuration:MetadataConfiguration
	tns1:Configuration:PTZConfiguration
	tns1:Configuration:VideoAnalyticsConfiguration

	tns1:RecordingConfig:JobState
	tns1:RecordingConfig:RecordingJobConfiguration
	tns1:RecordingConfig:RecordingConfiguration
	tns1:RecordingConfig:TrackConfiguration

	tns1:Monitoring:ProcessorUsage
	tns1:Monitoring:OperatingTime:LastReset
	tns1:Monitoring:OperatingTime:LastReboot
	tns1:Monitoring:OperatingTime:LastClockSynchronization

	tns1:Media:ProfileChanged
	tns1:Media:ConfigurationChanged
	*/
	psub->destroy();
	delete psub;
	psub = NULL;
}

void onviflib::gotoPreset(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	PTZBindingProxy *pPTZ = new PTZBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tptz__GotoPreset tptz__GotoPreset;
	tptz__GotoPreset.ProfileToken = "Profile_1";
	tptz__GotoPreset.PresetToken = "6";
	_tptz__GotoPresetResponse tptz__GotoPresetResponse;
	result = pPTZ->GotoPreset(endpoint.c_str(), NULL, &tptz__GotoPreset, tptz__GotoPresetResponse);

	if (SOAP_OK != result) {
		pPTZ->soap_stream_fault(std::cerr);
		return;
	}

	pPTZ->destroy();
	delete pPTZ;
	pPTZ = NULL;
}

void onviflib::setPreset(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	PTZBindingProxy *pPTZ = new PTZBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	std::string presetToken = "300";
	std::string presetName = "ccPreset2";
	_tptz__SetPreset tptz__SetPreset;
	tptz__SetPreset.ProfileToken = "Profile_1";
	//tptz__SetPreset.PresetToken = &presetToken;
	tptz__SetPreset.PresetName = &presetName;
	_tptz__SetPresetResponse tptz__SetPresetResponse;
	result = pPTZ->SetPreset(endpoint.c_str(), NULL, &tptz__SetPreset, tptz__SetPresetResponse);

	if (SOAP_OK != result) {
		pPTZ->soap_stream_fault(std::cerr);
		return;
	}
	presetToken = tptz__SetPresetResponse.PresetToken;
	// create preset,presetToken=6
	std::cerr << "create preset,presetToken=" << presetToken << std::endl;

	/*
	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
	    std::cerr << "Authentication failed, retcode " << result << std::endl;
	    return;
	}

	std::string presetName = "ccPreset";
	std::string presetToken = "ccPresetToken";
	_tptz__SetPreset tptz__SetPreset;
	tptz__SetPreset.PresetToken = &presetName;
	tptz__SetPreset.ProfileToken = "Profile_1";
	tptz__SetPreset.PresetName = &presetName;

	_tptz__SetPresetResponse tptz__SetPresetResponse;
	result = pPTZ->SetPreset(endpoint.c_str(), NULL, &tptz__SetPreset, tptz__SetPresetResponse);

	if (SOAP_OK != result) {
	    pPTZ->soap_stream_fault(std::cerr);
	    return;
	}
	*/
	pPTZ->destroy();
	delete pPTZ;
	pPTZ = NULL;
}

void onviflib::getPresets(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	PTZBindingProxy *pPTZ = new PTZBindingProxy(SOAP_C_UTFSTRING);

	//soap_set_mode(pPTZ->soap, SOAP_C_UTFSTRING);
	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tptz__GetPresets tptz__GetPresets;
	tptz__GetPresets.ProfileToken = "Profile_1";
	_tptz__GetPresetsResponse tptz__GetPresetsResponse;
	result = pPTZ->GetPresets(endpoint.c_str(), NULL, &tptz__GetPresets, tptz__GetPresetsResponse);

	if (SOAP_OK != result) {
		pPTZ->soap_stream_fault(std::cerr);
		return;
	}

	std::string name;
	std::string token;
	for (int i = 0; i < tptz__GetPresetsResponse.Preset.size(); ++i) {
		std::cerr << *tptz__GetPresetsResponse.Preset[i]->token << " ：";
		std::cerr << *tptz__GetPresetsResponse.Preset[i]->Name << std::endl;
	}

	/*
	<tptz:GetPresetsResponse>
	<tptz:Preset token="1"><tt:Name>杨宁</tt:Name>
	<tt:PTZPosition><tt:PanTilt x="0.142722" y="1.000000"/>
	<tt:Zoom x="0.000000"/>
	</tt:PTZPosition>
	</tptz:Preset>
	<tptz:Preset token="2"><tt:Name>预置点2</tt:Name>
	<tt:PTZPosition><tt:PanTilt x="-0.059833" y="1.000000"/>
	<tt:Zoom x="0.000000"/>
	</tt:PTZPosition>
	</tptz:Preset>
	...
	<tptz:Preset token="300"><tt:Name>é¢ç½®ç¹ 300</tt:Name>
	<tt:PTZPosition><tt:PanTilt x="0.000000" y="0.894737"/>
	<tt:Zoom x="0.000000"/>
	</tt:PTZPosition>
	</tptz:Preset>
	</tptz:GetPresetsResponse>
	*/
	pPTZ->destroy();
	delete pPTZ;
	pPTZ = NULL;
}

void onviflib::getConfigurations(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	PTZBindingProxy *pPTZ = new PTZBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tptz__GetConfigurations tptz__GetConfigurations;
	_tptz__GetConfigurationsResponse tptz__GetConfigurationsResponse;
	result = pPTZ->GetConfigurations(endpoint.c_str(), NULL, &tptz__GetConfigurations, tptz__GetConfigurationsResponse);

	if (SOAP_OK != result) {
		pPTZ->soap_stream_fault(std::cerr);
		return;
	}
	/*
	<tptz:GetConfigurationsResponse><tptz:PTZConfiguration token="PTZToken"><tt:Name>PTZ</tt:Name>
	<tt:UseCount>3</tt:UseCount>
	<tt:NodeToken>PTZNODETOKEN</tt:NodeToken>
	<tt:DefaultAbsolutePantTiltPositionSpace>http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace</tt:DefaultAbsolutePantTiltPositionSpace>
	<tt:DefaultAbsoluteZoomPositionSpace>http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace</tt:DefaultAbsoluteZoomPositionSpace>
	<tt:DefaultRelativePanTiltTranslationSpace>http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace</tt:DefaultRelativePanTiltTranslationSpace>
	<tt:DefaultRelativeZoomTranslationSpace>http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace</tt:DefaultRelativeZoomTranslationSpace>
	<tt:DefaultContinuousPanTiltVelocitySpace>http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace</tt:DefaultContinuousPanTiltVelocitySpace>
	<tt:DefaultContinuousZoomVelocitySpace>http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace</tt:DefaultContinuousZoomVelocitySpace>
	<tt:DefaultPTZSpeed><tt:PanTilt x="0.100000" y="0.100000" space="http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"/>
	<tt:Zoom x="1.000000" space="http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"/>
	</tt:DefaultPTZSpeed>
	<tt:DefaultPTZTimeout>PT300S</tt:DefaultPTZTimeout>
	<tt:PanTiltLimits><tt:Range><tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace</tt:URI>
	<tt:XRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	<tt:YRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:YRange>
	</tt:Range>
	</tt:PanTiltLimits>
	<tt:ZoomLimits><tt:Range><tt:URI>http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace</tt:URI>
	<tt:XRange><tt:Min>0.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	</tt:Range>
	</tt:ZoomLimits>
	</tptz:PTZConfiguration>
	</tptz:GetConfigurationsResponse>
	*/
	pPTZ->destroy();
	delete pPTZ;
	pPTZ = NULL;
}

void onviflib::getNodes(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	PTZBindingProxy *pPTZ = new PTZBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tptz__GetNodes tptz__GetNodes;
	_tptz__GetNodesResponse tptz__GetNodesResponse;
	result = pPTZ->GetNodes(endpoint.c_str(), NULL, &tptz__GetNodes, tptz__GetNodesResponse);

	if (SOAP_OK != result) {
		pPTZ->soap_stream_fault(std::cerr);
		return;
	}
	/*
	<tptz:GetNodesResponse>
	<tptz:PTZNode FixedHomePosition="false" GeoMove="false" token="PTZNODETOKEN"><tt:Name>PTZNODE</tt:Name>
	<tt:SupportedPTZSpaces><tt:AbsolutePanTiltPositionSpace>
	<tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace</tt:URI>
	<tt:XRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	<tt:YRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:YRange>
	</tt:AbsolutePanTiltPositionSpace>
	<tt:AbsoluteZoomPositionSpace><tt:URI>http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace</tt:URI>
	<tt:XRange><tt:Min>0.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	</tt:AbsoluteZoomPositionSpace>
	<tt:RelativePanTiltTranslationSpace><tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace</tt:URI>
	<tt:XRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	<tt:YRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:YRange>
	</tt:RelativePanTiltTranslationSpace>
	<tt:RelativePanTiltTranslationSpace><tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationSpaceFov</tt:URI>
	<tt:XRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	<tt:YRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:YRange>
	</tt:RelativePanTiltTranslationSpace>
	<tt:RelativeZoomTranslationSpace><tt:URI>http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace</tt:URI>
	<tt:XRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	</tt:RelativeZoomTranslationSpace>
	<tt:ContinuousPanTiltVelocitySpace><tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace</tt:URI>
	<tt:XRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	<tt:YRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:YRange>
	</tt:ContinuousPanTiltVelocitySpace>
	<tt:ContinuousPanTiltVelocitySpace><tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocitySpaceFOV</tt:URI>
	<tt:XRange><tt:Min>-7.000000</tt:Min>
	<tt:Max>7.000000</tt:Max>
	</tt:XRange>
	<tt:YRange><tt:Min>-7.000000</tt:Min>
	<tt:Max>7.000000</tt:Max>
	</tt:YRange>
	</tt:ContinuousPanTiltVelocitySpace>
	<tt:ContinuousZoomVelocitySpace><tt:URI>http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace</tt:URI>
	<tt:XRange><tt:Min>-1.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	</tt:ContinuousZoomVelocitySpace>
	<tt:ContinuousZoomVelocitySpace><tt:URI>http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocitySpaceMillimeter</tt:URI>
	<tt:XRange><tt:Min>-7.000000</tt:Min>
	<tt:Max>7.000000</tt:Max>
	</tt:XRange>
	</tt:ContinuousZoomVelocitySpace>
	<tt:PanTiltSpeedSpace><tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace</tt:URI>
	<tt:XRange><tt:Min>0.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	</tt:PanTiltSpeedSpace>
	<tt:ZoomSpeedSpace><tt:URI>http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace</tt:URI>
	<tt:XRange><tt:Min>0.000000</tt:Min>
	<tt:Max>1.000000</tt:Max>
	</tt:XRange>
	</tt:ZoomSpeedSpace>
	</tt:SupportedPTZSpaces>
	<tt:MaximumNumberOfPresets>300</tt:MaximumNumberOfPresets>
	<tt:HomeSupported>true</tt:HomeSupported>
	<tt:Extension><tt:SupportedPresetTour><tt:MaximumNumberOfPresetTours>8</tt:MaximumNumberOfPresetTours>
	<tt:PTZPresetTourOperation>Start</tt:PTZPresetTourOperation>
	<tt:PTZPresetTourOperation>Stop</tt:PTZPresetTourOperation>
	</tt:SupportedPresetTour>
	</tt:Extension>
	</tptz:PTZNode>
	</tptz:GetNodesResponse>
	*/
	pPTZ->destroy();
	delete pPTZ;
	pPTZ = NULL;
}

void onviflib::ProvisioningMove(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	ProvisioningBindingProxy *rproxy = new ProvisioningBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(rproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	LONG64 time_out = 2000;
	_ns9__PanMove ns9__PanMove;
	ns9__PanMove.VideoSource = "VideoSource_1";
	ns9__PanMove.Timeout = &time_out;
	ns9__PanMove.Direction = ns9__PanDirection__Left;

	_ns9__PanMoveResponse ns9__PanMoveResponse;

	result = rproxy->PanMove(endpoint.c_str(), NULL, &ns9__PanMove, ns9__PanMoveResponse);

	if (SOAP_OK != result) {
		rproxy->soap_stream_fault(std::cerr);
	}

	sleep(3);

	result = soap_wsse_add_UsernameTokenDigest(rproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	time_out = 1000;
	_ns9__FocusMove ns9__FocusMove;
	ns9__FocusMove.VideoSource = "VideoSource_1";
	ns9__FocusMove.Timeout = &time_out;
	ns9__FocusMove.Direction = ns9__FocusDirection__Near;
	_ns9__FocusMoveResponse ns9__FocusMoveResponse;

	result = rproxy->FocusMove(endpoint.c_str(), NULL, &ns9__FocusMove, ns9__FocusMoveResponse);

	if (SOAP_OK != result) {
		rproxy->soap_stream_fault(std::cerr);
		return;
	}

	rproxy->destroy();
	delete rproxy;
	rproxy = NULL;
}

void onviflib::PtzContinuousMove(int command, std::string username, std::string password) {
	int result = 0;
	std::string strMediaAddr = "http://49.235.201.96/onvif/Media";      //getCapabilitieInfo
	std::string strProfileToken = "Profile_1";                           //getProfileInfo
	std::string strPTZAddr = "http://49.235.201.96/onvif/PTZ";          //getCapabilitieInfo
	strPTZAddr = "http://49.235.201.96/onvif/device_service";

	PTZBindingProxy *pPTZ = new PTZBindingProxy();
	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "soap_wsse_add_UsernameTokenDigest error" << std::endl;
		return;
	}

	_tptz__ContinuousMove continuous_req;
	_tptz__ContinuousMoveResponse continuous_rep;

	LONG64 time = 20LL;
	continuous_req.Timeout = &time;  // 超时时间
	continuous_req.ProfileToken = strProfileToken;  // 标志

	tt__PTZSpeed *velocity = soap_new_tt__PTZSpeed(pPTZ->soap, -1);
	continuous_req.Velocity = velocity; // 方位与速率参数

	tt__Vector2D *panTilt = soap_new_tt__Vector2D(pPTZ->soap, -1);
	continuous_req.Velocity->PanTilt = panTilt; //水平

	std::string  str = "http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace";
	continuous_req.Velocity->PanTilt->space = &str;

	tt__Vector1D *zoom = soap_new_tt__Vector1D(pPTZ->soap, -1);
	continuous_req.Velocity->Zoom = zoom;  //聚焦

	switch (command) {
	case LEFT:
		continuous_req.Velocity->PanTilt->x = -((float)speed / 10);  //向左转并且速度为0.5
		continuous_req.Velocity->PanTilt->y = 0;
		break;
	case RIGHT:
		continuous_req.Velocity->PanTilt->x = ((float)speed / 10);
		continuous_req.Velocity->PanTilt->y = 0;
		break;
	case UP:
		continuous_req.Velocity->PanTilt->x = 0;
		continuous_req.Velocity->PanTilt->y = ((float)speed / 10);
		break;
	case DOWN:
		continuous_req.Velocity->PanTilt->x = 0;
		continuous_req.Velocity->PanTilt->y = -((float)speed / 10);
		break;
	case ZOOMIN:
		continuous_req.Velocity->Zoom->x = ((float)speed / 10);
		break;
	case ZOOMOUT:
		continuous_req.Velocity->Zoom->x = -((float)speed / 10);
		break;
	default:
		break;
	}

	result = pPTZ->ContinuousMove(strPTZAddr.c_str(), NULL, &continuous_req, continuous_rep);
	if (result == SOAP_OK) {
		std::cerr << "转动成功" << std::endl;
	} else {
		std::cerr << "转动失败" << std::endl;
		pPTZ->soap_stream_fault(std::cerr);
	}

	sleep(3); //3s

	result = soap_wsse_add_UsernameTokenDigest(pPTZ->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "soap_wsse_add_UsernameTokenDigest error" << std::endl;
		return;
	}

	_tptz__Stop tptz__Stop;
	tptz__Stop.ProfileToken = strProfileToken;
	_tptz__StopResponse tptz__StopResponse;
	result = pPTZ->Stop(strPTZAddr.c_str(), NULL, &tptz__Stop, tptz__StopResponse);
	if (result == SOAP_OK) {
		std::cerr << "停止成功" << std::endl;
	} else {
		std::cerr << "停止失败" << std::endl;
		pPTZ->soap_stream_fault(std::cerr);
	}

	pPTZ->destroy();
	delete pPTZ;
	pPTZ = NULL;
}

void onviflib::getMediaAttributes(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	SearchBindingProxy *rproxy = new SearchBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(rproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	time_t curr = string2time_t("20200411090300");
	_tse__GetMediaAttributes tse__GetMediaAttributes;
	tse__GetMediaAttributes.RecordingTokens.push_back("OnvifRecordingToken_1");
	tse__GetMediaAttributes.Time = curr;
	_tse__GetMediaAttributesResponse tse__GetMediaAttributesResponse;

	result = rproxy->GetMediaAttributes(endpoint.c_str(), NULL,
	                                    &tse__GetMediaAttributes, tse__GetMediaAttributesResponse);

	if (SOAP_OK != result) {
		rproxy->soap_stream_fault(std::cerr);
		return;
	}

	for (int i = 0 ; i < tse__GetMediaAttributesResponse.MediaAttributes.size(); ++i) {

		std::cerr << tse__GetMediaAttributesResponse.MediaAttributes[i]->RecordingToken << "  ";

		char szBuf[64] = {0};

		tm sttm = *localtime(&tse__GetMediaAttributesResponse.MediaAttributes[i]->From);
		strftime(szBuf, 64, "%Y-%m-%d %H:%M:%S", &sttm);
		std::cerr << szBuf;

		memset(szBuf, 0, sizeof(szBuf));
		sttm = *localtime(&tse__GetMediaAttributesResponse.MediaAttributes[i]->Until);
		strftime(szBuf, 64, "%Y-%m-%d %H:%M:%S", &sttm);
		std::cerr << "  " << szBuf << std::endl;
	}


	/*
	<tse:GetMediaAttributesResponse><tse:MediaAttributes>
	<tt:RecordingToken>OnvifRecordingToken_1</tt:RecordingToken>
	<tt:From>2020-04-10T06:23:34Z</tt:From>
	<tt:Until>2020-04-10T06:51:39Z</tt:Until>
	</tse:MediaAttributes>
	</tse:GetMediaAttributesResponse>
	*/
	rproxy->destroy();
	delete rproxy;
	rproxy = NULL;

}

void onviflib::getRecordingInformation(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	SearchBindingProxy *rproxy = new SearchBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(rproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tse__GetRecordingInformation tse__GetRecordingInformation;
	tse__GetRecordingInformation.RecordingToken = "OnvifRecordingToken_1";
	_tse__GetRecordingInformationResponse tse__GetRecordingInformationResponse;

	result = rproxy->GetRecordingInformation(endpoint.c_str(), NULL,
	         &tse__GetRecordingInformation, tse__GetRecordingInformationResponse);

	if (SOAP_OK != result) {
		rproxy->soap_stream_fault(std::cerr);
		return;
	}
	/*
	<tse:GetRecordingInformationResponse>
	<tse:RecordingInformation><tt:RecordingToken>OnvifRecordingToken_1</tt:RecordingToken>
	<tt:Source><tt:SourceId>SourceId_1</tt:SourceId>
	<tt:Name>IpCamera_1</tt:Name>
	<tt:Location>Location</tt:Location>
	<tt:Description>Description of source</tt:Description>
	<tt:Address>http://www.onvif.org/ver10/schema/Profile</tt:Address>
	</tt:Source>
	<tt:EarliestRecording>2020-04-09T18:43:04Z</tt:EarliestRecording>
	<tt:LatestRecording>2020-04-10T06:33:29Z</tt:LatestRecording>
	<tt:Content>RecordContent</tt:Content>
	<tt:Track><tt:TrackToken>videotracktoken_1</tt:TrackToken>
	<tt:TrackType>Video</tt:TrackType>
	<tt:Description>VideoTrack</tt:Description>
	<tt:DataFrom>2020-04-09T18:43:04Z</tt:DataFrom>
	<tt:DataTo>2020-04-10T06:33:29Z</tt:DataTo>
	</tt:Track>
	<tt:Track><tt:TrackToken>audiotracktoken_1</tt:TrackToken>
	<tt:TrackType>Audio</tt:TrackType>
	<tt:Description>AudioTrack</tt:Description>
	<tt:DataFrom>2020-04-09T18:43:04Z</tt:DataFrom>
	<tt:DataTo>2020-04-10T06:33:29Z</tt:DataTo>
	</tt:Track>
	<tt:Track><tt:TrackToken>metadatatracktoken_1</tt:TrackToken>
	<tt:TrackType>Metadata</tt:TrackType>
	<tt:Description>MetadataTrack</tt:Description>
	<tt:DataFrom>2020-04-09T18:43:04Z</tt:DataFrom>
	<tt:DataTo>2020-04-10T06:33:29Z</tt:DataTo>
	</tt:Track>
	<tt:RecordingStatus>Recording</tt:RecordingStatus>
	</tse:RecordingInformation>
	</tse:GetRecordingInformationResponse>
	*/
	rproxy->destroy();
	delete rproxy;
	rproxy = NULL;

}

void onviflib::getRecordingConfiguration(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	RecordingBindingProxy *rproxy = new RecordingBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(rproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_trc__GetRecordingConfiguration trc__GetRecordingConfiguration;
	trc__GetRecordingConfiguration.RecordingToken = "OnvifRecordingToken_1";
	_trc__GetRecordingConfigurationResponse trc__GetRecordingConfigurationResponse;

	result = rproxy->GetRecordingConfiguration(endpoint.c_str(), NULL,
	         &trc__GetRecordingConfiguration, trc__GetRecordingConfigurationResponse);

	if (SOAP_OK != result) {
		rproxy->soap_stream_fault(std::cerr);
		return;
	}
	/*
	<trc:GetRecordingConfigurationResponse>
	<trc:RecordingConfiguration><tt:Source><tt:SourceId>SourceId_1</tt:SourceId>
	<tt:Name>IpCamera_1</tt:Name>
	<tt:Location>Location</tt:Location>
	<tt:Description>Description of source</tt:Description>
	<tt:Address>http://www.onvif.org/ver10/schema/Profile</tt:Address>
	</tt:Source>
	<tt:Content>RecordContent</tt:Content>
	<tt:MaximumRetentionTime>PT0S</tt:MaximumRetentionTime>
	</trc:RecordingConfiguration>
	</trc:GetRecordingConfigurationResponse>
	*/
	rproxy->destroy();
	delete rproxy;
	rproxy = NULL;

}

void onviflib::getReplayUri(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	ReplayBindingProxy *rproxy = new ReplayBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(rproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}


	tt__Transport transport;
	transport.Protocol = tt__TransportProtocol__RTSP; // udp、tcp、RTSP、HTTP
	transport.Tunnel = NULL;

	tt__StreamSetup streamSetup;
	streamSetup.Transport = &transport;
	streamSetup.Stream = tt__StreamType__RTP_Unicast; // 单播

	_trp__GetReplayUri trp__GetReplayUri;
	trp__GetReplayUri.StreamSetup = &streamSetup;
	trp__GetReplayUri.RecordingToken = "OnvifRecordingToken_1";

	_trp__GetReplayUriResponse trp__GetReplayUriResponse;

	result = rproxy->GetReplayUri(endpoint.c_str(), NULL,
	                              &trp__GetReplayUri, trp__GetReplayUriResponse);

	if (SOAP_OK != result) {
		rproxy->soap_stream_fault(std::cerr);
		return;
	}
	std::cerr << trp__GetReplayUriResponse.Uri << std::endl;
	/*
	<env:Body><trp:GetReplayUriResponse>
	<trp:Uri>rtsp://49.235.201.96:554/Streaming/Tracks/101?transportmode=unicast&amp;replaymode=onvifreplay</trp:Uri>
	</trp:GetReplayUriResponse>
	</env:Body>
	*/
	// 可限制时间点，注意减8小时
	// rtsp://test:test12345@49.235.201.96:554/Streaming/Tracks/101?transportmode=unicast&replaymode=onvifreplay&starttime=20200410T220000Z
	rproxy->destroy();
	delete rproxy;
	rproxy = NULL;

}

void onviflib::getAllRecordTokenInfo(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	DeviceBindingProxy *dproxy = new DeviceBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tds__GetCapabilities tds__GetCapabilities;
	_tds__GetCapabilitiesResponse _tds__GetCapabilitiesResponse;

	result = dproxy->GetCapabilities(endpoint.c_str(), NULL,
	                                 &tds__GetCapabilities, _tds__GetCapabilitiesResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
		return;
	}

	if (_tds__GetCapabilitiesResponse.Capabilities->Extension->Recording->XAddr.empty()) {
		std::cerr << "无法获取Recording Address" << std::endl;
		return;
	}
	std::string recordAddr = _tds__GetCapabilitiesResponse.Capabilities->Extension->Recording->XAddr;
	std::cerr << "Recording Address= " << recordAddr << std::endl;

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;


	RecordingBindingProxy *pRecord = new RecordingBindingProxy();
	result = soap_wsse_add_UsernameTokenDigest(pRecord->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_trc__GetRecordings GetRecordings_req;
	_trc__GetRecordingsResponse GetRecordings_rep;
	result = pRecord->GetRecordings(recordAddr.c_str(), NULL, &GetRecordings_req, GetRecordings_rep);
	if (result != SOAP_OK) {
		pRecord->soap_stream_fault(std::cerr);
		return ;
	}

	for (int i = 0; i < GetRecordings_rep.RecordingItem.size(); ++i) {
		std::cerr << "RecordingToken= " << GetRecordings_rep.RecordingItem[i]->RecordingToken << std::endl;
	}
	/*
	<env:Body><trc:GetRecordingsResponse>
	<trc:RecordingItem><tt:RecordingToken>OnvifRecordingToken_1</tt:RecordingToken>
	<tt:Configuration><tt:Source><tt:SourceId>SourceId_1</tt:SourceId>
	<tt:Name>IpCamera_1</tt:Name>
	<tt:Location>Location</tt:Location>
	<tt:Description>Description of source</tt:Description>
	<tt:Address>http://www.onvif.org/ver10/schema/Profile</tt:Address>
	</tt:Source>
	<tt:Content>RecordContent</tt:Content>
	<tt:MaximumRetentionTime>PT0S</tt:MaximumRetentionTime>
	</tt:Configuration>
	<tt:Tracks><tt:Track><tt:TrackToken>videotracktoken_1</tt:TrackToken>
	<tt:Configuration><tt:TrackType>Video</tt:TrackType>
	<tt:Description>VideoTrack</tt:Description>
	</tt:Configuration>
	</tt:Track>
	<tt:Track><tt:TrackToken>audiotracktoken_1</tt:TrackToken>
	<tt:Configuration><tt:TrackType>Audio</tt:TrackType>
	<tt:Description>AudioTrack</tt:Description>
	</tt:Configuration>
	</tt:Track>
	<tt:Track><tt:TrackToken>metadatatracktoken_1</tt:TrackToken>
	<tt:Configuration><tt:TrackType>Metadata</tt:TrackType>
	<tt:Description>MetadataTrack</tt:Description>
	</tt:Configuration>
	</tt:Track>
	</tt:Tracks>
	</trc:RecordingItem>
	</trc:GetRecordingsResponse>
	</env:Body>
	*/
	delete pRecord;
	return ;

}

void onviflib::getRecordTokenInfo(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	DeviceBindingProxy *dproxy = new DeviceBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tds__GetCapabilities tds__GetCapabilities;
	_tds__GetCapabilitiesResponse _tds__GetCapabilitiesResponse;

	result = dproxy->GetCapabilities(endpoint.c_str(), NULL,
	                                 &tds__GetCapabilities, _tds__GetCapabilitiesResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
		return;
	}

	if (_tds__GetCapabilitiesResponse.Capabilities->Extension->Search == NULL) {
		std::cerr << "无法获取Search info" << std::endl;
		return;
	}
	std::string seachAddr = _tds__GetCapabilitiesResponse.Capabilities->Extension->Search->XAddr;
	if (_tds__GetCapabilitiesResponse.Capabilities->Extension->Recording->XAddr.empty()) {
		std::cerr << "无法获取Search Address" << std::endl;
		return;
	}

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;


	SearchBindingProxy *searchProxy = new SearchBindingProxy();
	result = soap_wsse_add_UsernameTokenDigest(searchProxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}
	_tse__GetRecordingSummary getRecordingSummary_req;
	_tse__GetRecordingSummaryResponse getRecordingSummary_rep;

	result = searchProxy->GetRecordingSummary(seachAddr.c_str(), NULL, &getRecordingSummary_req, getRecordingSummary_rep);
	if (result == SOAP_OK) {

		/*
		<env:Body><tse:GetRecordingSummaryResponse>
		<tse:Summary>
		<tt:DataFrom>2020-04-08T19:52:54Z</tt:DataFrom>
		<tt:DataUntil>2020-04-09T07:58:11Z</tt:DataUntil>
		<tt:NumberRecordings>1</tt:NumberRecordings>
		</tse:Summary>
		</tse:GetRecordingSummaryResponse>
		</env:Body>
		*/

		tt__RecordingSummary *summary = getRecordingSummary_rep.Summary;

		std::cerr << "录像数量：" << summary->NumberRecordings << std::endl;
		//DataFrom 在设备上有记录数据的最早时间点。
		//DataUntil 在设备上记录数据的最新时间点。
		if (summary->DataFrom > 0 && summary->DataUntil > 0) {
			char szBuf[64] = {0};

			tm sttm = *localtime(&summary->DataFrom);
			strftime(szBuf, 64, "%Y-%m-%d %H:%M:%S", &sttm);
			std::cerr << "日期范围从：" << szBuf;

			memset(szBuf, 0, sizeof(szBuf));
			sttm = *localtime(&summary->DataUntil);
			strftime(szBuf, 64, "%Y-%m-%d %H:%M:%S", &sttm);
			std::cerr << "到" << szBuf << std::endl;
		} else {
			std::cerr << "录像不存在？" << std::endl;
		}
	} else {
		searchProxy->soap_stream_fault(std::cerr);
		return;
	}


	result = soap_wsse_add_UsernameTokenDigest(searchProxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}


	int maxMatches = 1000;
	LONG64 maxTime = 120000;
	tt__SearchScope searchScope;

	_tse__FindRecordings findRecordings_req;
	findRecordings_req.MaxMatches = &maxMatches;  // 最大查找数
	findRecordings_req.KeepAliveTime = maxTime;  //ms超时时间
	findRecordings_req.Scope = &searchScope;
	_tse__FindRecordingsResponse findRecordings_rep;

	result = searchProxy->FindRecordings(seachAddr.c_str(), NULL, &findRecordings_req, findRecordings_rep);
	if (result == SOAP_OK) {
		/*
		<env:Body><tse:FindRecordingsResponse>
		<tse:SearchToken>RecordingSearchToken_1</tse:SearchToken>
		</tse:FindRecordingsResponse>
		</env:Body>
		*/
		result = soap_wsse_add_UsernameTokenDigest(searchProxy->soap, NULL, username.c_str(), password.c_str());
		if (SOAP_OK != result) {
			std::cerr << "Authentication failed, retcode " << result << std::endl;
			return;
		}

		std::string searchToken = findRecordings_rep.SearchToken;

		_tse__GetRecordingSearchResults getRecordingSearchResults_req;
		_tse__GetRecordingSearchResultsResponse getRecordingSearchResults_rep;
		getRecordingSearchResults_req.SearchToken = searchToken;
		//这是几毫秒？
		getRecordingSearchResults_req.WaitTime = &maxTime;

		result = searchProxy->GetRecordingSearchResults(seachAddr.c_str(), NULL, &getRecordingSearchResults_req, getRecordingSearchResults_rep);
		if (result == SOAP_OK) {

			/*
			<env:Body><tse:GetRecordingSearchResultsResponse>
			<tse:ResultList><tt:SearchState>Completed</tt:SearchState>
			<tt:RecordingInformation><tt:RecordingToken>OnvifRecordingToken_1</tt:RecordingToken>
			<tt:Source><tt:SourceId>SourceId_1</tt:SourceId>
			<tt:Name>IpCamera_1</tt:Name>
			<tt:Location>Location</tt:Location>
			<tt:Description>Description of source</tt:Description>
			<tt:Address>http://www.onvif.org/ver10/schema/Profile</tt:Address>
			</tt:Source>
			<tt:EarliestRecording>2020-04-08T21:19:39Z</tt:EarliestRecording>
			<tt:LatestRecording>2020-04-09T09:23:01Z</tt:LatestRecording>
			<tt:Content>RecordContent</tt:Content>
			<tt:Track><tt:TrackToken>videotracktoken_1</tt:TrackToken>
			<tt:TrackType>Video</tt:TrackType>
			<tt:Description>VideoTrack</tt:Description>
			<tt:DataFrom>2020-04-08T21:19:39Z</tt:DataFrom>
			<tt:DataTo>2020-04-09T09:23:01Z</tt:DataTo>
			</tt:Track>
			<tt:Track><tt:TrackToken>audiotracktoken_1</tt:TrackToken>
			<tt:TrackType>Audio</tt:TrackType>
			<tt:Description>AudioTrack</tt:Description>
			<tt:DataFrom>2020-04-08T21:19:39Z</tt:DataFrom>
			<tt:DataTo>2020-04-09T09:23:01Z</tt:DataTo>
			</tt:Track>
			<tt:Track><tt:TrackToken>metadatatracktoken_1</tt:TrackToken>
			<tt:TrackType>Metadata</tt:TrackType>
			<tt:Description>MetadataTrack</tt:Description>
			<tt:DataFrom>2020-04-08T21:19:39Z</tt:DataFrom>
			<tt:DataTo>2020-04-09T09:23:01Z</tt:DataTo>
			</tt:Track>
			<tt:RecordingStatus>Recording</tt:RecordingStatus>
			</tt:RecordingInformation>
			</tse:ResultList>
			</tse:GetRecordingSearchResultsResponse>
			</env:Body>
			*/

			std::string recordingToken;
			tt__FindRecordingResultList *summary = getRecordingSearchResults_rep.ResultList;
			std::vector <tt__RecordingInformation *> v = summary->RecordingInformation;
			for (unsigned int i = 0; i < v.size(); i++) {
				tt__RecordingInformation *info = v.at(i);
				std::cerr << "录制标记：" << info->RecordingToken << std::endl;
				recordingToken = info->RecordingToken;
			}
			//此处只取第一个Recording Token
			recordingToken = v.at(0)->RecordingToken;
		} else {
			searchProxy->soap_stream_fault(std::cerr);
			return ;
		}
	} else {
		searchProxy->soap_stream_fault(std::cerr);
		return ;
	}
	delete searchProxy;
	return ;

}

void onviflib::getProfileInfo(std::string endpoint,
                              std::string username,
                              std::string password) {
	int result = SOAP_ERR;

	MediaBindingProxy *dproxy = new MediaBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_trt__GetProfiles trt__GetProfiles;
	_trt__GetProfilesResponse trt__GetProfilesResponse;

	result = dproxy->GetProfiles(endpoint.c_str(), NULL,
	                             &trt__GetProfiles, trt__GetProfilesResponse);
	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		/*
		96获取所有，其中Profile_1 Profile_2 Profile_3，
		每个Profile_1具体信息同如下单个查找
		*/

		std::cerr << trt__GetProfilesResponse.Profiles[0]->Name << std::endl;
		std::cerr << trt__GetProfilesResponse.Profiles[0]->token << std::endl;
		std::cerr << trt__GetProfilesResponse.Profiles[0]->VideoSourceConfiguration->SourceToken << std::endl;
		std::cerr << trt__GetProfilesResponse.Profiles[0]->VideoSourceConfiguration->Name << std::endl;
		std::cerr << trt__GetProfilesResponse.Profiles[0]->VideoSourceConfiguration->token << std::endl;
	}


	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_trt__GetProfile trt__GetProfile;
	trt__GetProfile.ProfileToken = "Profile_101"; //130的Profile_101
	_trt__GetProfileResponse trt__GetProfileResponse;

	result = dproxy->GetProfile(endpoint.c_str(), NULL,
	                            &trt__GetProfile, trt__GetProfileResponse);
	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		/*

		<trt:GetProfileResponse><trt:Profile token="Profile_1" fixed="true"><tt:Name>mainStream</tt:Name>
		<tt:VideoSourceConfiguration token="VideoSourceToken"><tt:Name>VideoSourceConfig</tt:Name>
		<tt:UseCount>3</tt:UseCount>
		<tt:SourceToken>VideoSource_1</tt:SourceToken>
		<tt:Bounds x="0" y="0" width="1920" height="1080"></tt:Bounds>
		</tt:VideoSourceConfiguration>
		<tt:AudioSourceConfiguration token="AudioSourceConfigToken"><tt:Name>AudioSourceConfig</tt:Name>
		<tt:UseCount>3</tt:UseCount>
		<tt:SourceToken>AudioSourceChannel</tt:SourceToken>
		</tt:AudioSourceConfiguration>
		<tt:VideoEncoderConfiguration token="VideoEncoderToken_1"><tt:Name>VideoEncoder_1</tt:Name>
		<tt:UseCount>1</tt:UseCount>
		<tt:Encoding>H264</tt:Encoding>
		<tt:Resolution><tt:Width>1280</tt:Width>
		<tt:Height>720</tt:Height>
		</tt:Resolution>
		<tt:Quality>3.000000</tt:Quality>
		<tt:RateControl><tt:FrameRateLimit>25</tt:FrameRateLimit>
		<tt:EncodingInterval>1</tt:EncodingInterval>
		<tt:BitrateLimit>2048</tt:BitrateLimit>
		</tt:RateControl>
		<tt:H264><tt:GovLength>50</tt:GovLength>
		<tt:H264Profile>Main</tt:H264Profile>
		</tt:H264>
		<tt:Multicast><tt:Address><tt:Type>IPv4</tt:Type>
		<tt:IPv4Address>0.0.0.0</tt:IPv4Address>
		</tt:Address>
		<tt:Port>8860</tt:Port>
		<tt:TTL>128</tt:TTL>
		<tt:AutoStart>false</tt:AutoStart>
		</tt:Multicast>
		<tt:SessionTimeout>PT5S</tt:SessionTimeout>
		</tt:VideoEncoderConfiguration>
		<tt:AudioEncoderConfiguration token="MainAudioEncoderToken"><tt:Name>AudioEncoderConfig</tt:Name>
		<tt:UseCount>3</tt:UseCount>
		<tt:Encoding>G711</tt:Encoding>
		<tt:Bitrate>64</tt:Bitrate>
		<tt:SampleRate>8</tt:SampleRate>
		<tt:Multicast><tt:Address><tt:Type>IPv4</tt:Type>
		<tt:IPv4Address>0.0.0.0</tt:IPv4Address>
		</tt:Address>
		<tt:Port>8862</tt:Port>
		<tt:TTL>128</tt:TTL>
		<tt:AutoStart>false</tt:AutoStart>
		</tt:Multicast>
		<tt:SessionTimeout>PT5S</tt:SessionTimeout>
		</tt:AudioEncoderConfiguration>
		<tt:VideoAnalyticsConfiguration token="VideoAnalyticsToken"><tt:Name>VideoAnalyticsName</tt:Name>
		<tt:UseCount>3</tt:UseCount>
		<tt:AnalyticsEngineConfiguration><tt:AnalyticsModule Name="MyCellMotionModule" Type="tt:CellMotionEngine"><tt:Parameters><tt:SimpleItem Name="Sensitivity" Value="100"/>
		<tt:ElementItem Name="Layout"><tt:CellLayout Columns="22" Rows="18"><tt:Transformation><tt:Translate x="-1.000000" y="-1.000000"/>
		<tt:Scale x="0.090909" y="0.111111"/>
		</tt:Transformation>
		</tt:CellLayout>
		</tt:ElementItem>
		</tt:Parameters>
		</tt:AnalyticsModule>
		<tt:AnalyticsModule Name="MyLineDetectorModule" Type="tt:LineDetectorEngine"><tt:Parameters><tt:SimpleItem Name="Sensitivity" Value="1"/>
		<tt:ElementItem Name="Layout"><tt:Transformation><tt:Translate x="-1.000000" y="-1.000000"/>
		<tt:Scale x="0.002000" y="0.002000"/>
		</tt:Transformation>
		</tt:ElementItem>
		<tt:ElementItem Name="Field"><tt:PolygonConfiguration><tt:Polygon><tt:Point x="0" y="0"/>
		<tt:Point x="0" y="1000"/>
		<tt:Point x="1000" y="1000"/>
		<tt:Point x="1000" y="0"/>
		</tt:Polygon>
		</tt:PolygonConfiguration>
		</tt:ElementItem>
		</tt:Parameters>
		</tt:AnalyticsModule>
		<tt:AnalyticsModule Name="MyFieldDetectorModule" Type="tt:FieldDetectorEngine"><tt:Parameters><tt:SimpleItem Name="Sensitivity" Value="1"/>
		<tt:ElementItem Name="Layout"><tt:Transformation><tt:Translate x="-1.000000" y="-1.000000"/>
		<tt:Scale x="0.002000" y="0.002000"/>
		</tt:Transformation>
		</tt:ElementItem>
		<tt:ElementItem Name="Field"><tt:PolygonConfiguration><tt:Polygon><tt:Point x="0" y="0"/>
		<tt:Point x="0" y="1000"/>
		<tt:Point x="1000" y="1000"/>
		<tt:Point x="1000" y="0"/>
		</tt:Polygon>
		</tt:PolygonConfiguration>
		</tt:ElementItem>
		</tt:Parameters>
		</tt:AnalyticsModule>
		<tt:AnalyticsModule Name="MyTamperDetecModule" Type="hikxsd:TamperEngine"><tt:Parameters><tt:SimpleItem Name="Sensitivity" Value="0"/>
		<tt:ElementItem Name="Transformation"><tt:Transformation><tt:Translate x="-1.000000" y="-1.000000"/>
		<tt:Scale x="0.002841" y="0.003472"/>
		</tt:Transformation>
		</tt:ElementItem>
		<tt:ElementItem Name="Field"><tt:PolygonConfiguration><tt:Polygon><tt:Point x="0" y="0"/>
		<tt:Point x="0" y="576"/>
		<tt:Point x="704" y="576"/>
		<tt:Point x="704" y="0"/>
		</tt:Polygon>
		</tt:PolygonConfiguration>
		</tt:ElementItem>
		</tt:Parameters>
		</tt:AnalyticsModule>
		</tt:AnalyticsEngineConfiguration>
		<tt:RuleEngineConfiguration><tt:Rule Name="MyMotionDetectorRule" Type="tt:CellMotionDetector"><tt:Parameters><tt:SimpleItem Name="MinCount" Value="5"/>
		<tt:SimpleItem Name="AlarmOnDelay" Value="1000"/>
		<tt:SimpleItem Name="AlarmOffDelay" Value="1000"/>
		<tt:SimpleItem Name="ActiveCells" Value="0P8A8A=="/>
		</tt:Parameters>
		</tt:Rule>
		<tt:Rule Name="MyTamperDetectorRule" Type="hikxsd:TamperDetector"><tt:Parameters><tt:ElementItem Name="Field"><tt:PolygonConfiguration><tt:Polygon><tt:Point x="0" y="0"/>
		<tt:Point x="0" y="0"/>
		<tt:Point x="0" y="0"/>
		<tt:Point x="0" y="0"/>
		</tt:Polygon>
		</tt:PolygonConfiguration>
		</tt:ElementItem>
		</tt:Parameters>
		</tt:Rule>
		</tt:RuleEngineConfiguration>
		</tt:VideoAnalyticsConfiguration>
		<tt:PTZConfiguration token="PTZToken"><tt:Name>PTZ</tt:Name>
		<tt:UseCount>3</tt:UseCount>
		<tt:NodeToken>PTZNODETOKEN</tt:NodeToken>
		<tt:DefaultAbsolutePantTiltPositionSpace>http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace</tt:DefaultAbsolutePantTiltPositionSpace>
		<tt:DefaultAbsoluteZoomPositionSpace>http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace</tt:DefaultAbsoluteZoomPositionSpace>
		<tt:DefaultRelativePanTiltTranslationSpace>http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace</tt:DefaultRelativePanTiltTranslationSpace>
		<tt:DefaultRelativeZoomTranslationSpace>http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace</tt:DefaultRelativeZoomTranslationSpace>
		<tt:DefaultContinuousPanTiltVelocitySpace>http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace</tt:DefaultContinuousPanTiltVelocitySpace>
		<tt:DefaultContinuousZoomVelocitySpace>http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace</tt:DefaultContinuousZoomVelocitySpace>
		<tt:DefaultPTZSpeed><tt:PanTilt x="0.100000" y="0.100000" space="http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"/>
		<tt:Zoom x="1.000000" space="http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"/>
		</tt:DefaultPTZSpeed>
		<tt:DefaultPTZTimeout>PT300S</tt:DefaultPTZTimeout>
		<tt:PanTiltLimits><tt:Range><tt:URI>http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace</tt:URI>
		<tt:XRange><tt:Min>-1.000000</tt:Min>
		<tt:Max>1.000000</tt:Max>
		</tt:XRange>
		<tt:YRange><tt:Min>-1.000000</tt:Min>
		<tt:Max>1.000000</tt:Max>
		</tt:YRange>
		</tt:Range>
		</tt:PanTiltLimits>
		<tt:ZoomLimits><tt:Range><tt:URI>http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace</tt:URI>
		<tt:XRange><tt:Min>0.000000</tt:Min>
		<tt:Max>1.000000</tt:Max>
		</tt:XRange>
		</tt:Range>
		</tt:ZoomLimits>
		</tt:PTZConfiguration>
		<tt:Extension><tt:AudioOutputConfiguration token="AudioOutputConfigToken"><tt:Name>AudioOutputConfigName</tt:Name>
		<tt:UseCount>3</tt:UseCount>
		<tt:OutputToken>AudioOutputToken</tt:OutputToken>
		<tt:SendPrimacy>www.onvif.org/ver20/HalfDuplex/Auto</tt:SendPrimacy>
		<tt:OutputLevel>10</tt:OutputLevel>
		</tt:AudioOutputConfiguration>
		<tt:AudioDecoderConfiguration token="AudioDecoderConfigToken"><tt:Name>AudioDecoderConfig</tt:Name>
		<tt:UseCount>3</tt:UseCount>
		</tt:AudioDecoderConfiguration>
		</tt:Extension>
		</trt:Profile>
		</trt:GetProfileResponse>

		*/
	}

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::getCapabilitieInfo(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	DeviceBindingProxy *dproxy = new DeviceBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tds__GetCapabilities tds__GetCapabilities;
	_tds__GetCapabilitiesResponse _tds__GetCapabilitiesResponse;

	result = dproxy->GetCapabilities(endpoint.c_str(), NULL,
	                                 &tds__GetCapabilities, _tds__GetCapabilitiesResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		std::cerr << _tds__GetCapabilitiesResponse.Capabilities->Media->XAddr << std::endl;
	}
	/*

	<env:Body><tds:GetCapabilitiesResponse><tds:Capabilities>
	<tt:Analytics>
	<tt:XAddr>http://49.235.201.130/onvif/Analytics</tt:XAddr>
	<tt:RuleSupport>true</tt:RuleSupport>
	<tt:AnalyticsModuleSupport>true</tt:AnalyticsModuleSupport>
	</tt:Analytics>
	<tt:Device><tt:XAddr>http://49.235.201.130/onvif/device_service</tt:XAddr>
	<tt:Network>
	<tt:IPFilter>true</tt:IPFilter>
	<tt:ZeroConfiguration>true</tt:ZeroConfiguration>
	<tt:IPVersion6>true</tt:IPVersion6>
	<tt:DynDNS>true</tt:DynDNS>
	<tt:Extension><tt:Dot11Configuration>false</tt:Dot11Configuration>
	<tt:Extension><tt:DHCPv6>true</tt:DHCPv6>
	<tt:Dot1XConfigurations>0</tt:Dot1XConfigurations>
	</tt:Extension>
	</tt:Extension>
	</tt:Network>
	<tt:System><tt:DiscoveryResolve>false</tt:DiscoveryResolve>
	<tt:DiscoveryBye>true</tt:DiscoveryBye>
	<tt:RemoteDiscovery>false</tt:RemoteDiscovery>
	<tt:SystemBackup>false</tt:SystemBackup>
	<tt:SystemLogging>true</tt:SystemLogging>
	<tt:FirmwareUpgrade>true</tt:FirmwareUpgrade>
	<tt:SupportedVersions><tt:Major>16</tt:Major>
	<tt:Minor>12</tt:Minor>
	</tt:SupportedVersions>
	<tt:SupportedVersions><tt:Major>2</tt:Major>
	<tt:Minor>60</tt:Minor>
	</tt:SupportedVersions>
	<tt:SupportedVersions><tt:Major>2</tt:Major>
	<tt:Minor>40</tt:Minor>
	</tt:SupportedVersions>
	<tt:SupportedVersions><tt:Major>2</tt:Major>
	<tt:Minor>20</tt:Minor>
	</tt:SupportedVersions>
	<tt:SupportedVersions><tt:Major>2</tt:Major>
	<tt:Minor>10</tt:Minor>
	</tt:SupportedVersions>
	<tt:SupportedVersions><tt:Major>2</tt:Major>
	<tt:Minor>0</tt:Minor>
	</tt:SupportedVersions>
	<tt:Extension><tt:HttpFirmwareUpgrade>true</tt:HttpFirmwareUpgrade>
	<tt:HttpSystemBackup>false</tt:HttpSystemBackup>
	<tt:HttpSystemLogging>false</tt:HttpSystemLogging>
	<tt:HttpSupportInformation>false</tt:HttpSupportInformation>
	</tt:Extension>
	</tt:System>
	<tt:IO><tt:InputConnectors>1</tt:InputConnectors>
	<tt:RelayOutputs>1</tt:RelayOutputs>
	<tt:Extension><tt:Auxiliary>false</tt:Auxiliary>
	<tt:AuxiliaryCommands>nothing</tt:AuxiliaryCommands>
	<tt:Extension/>
	</tt:Extension>
	</tt:IO>
	<tt:Security><tt:TLS1.1>true</tt:TLS1.1>
	<tt:TLS1.2>true</tt:TLS1.2>
	<tt:OnboardKeyGeneration>false</tt:OnboardKeyGeneration>
	<tt:AccessPolicyConfig>false</tt:AccessPolicyConfig>
	<tt:X.509Token>false</tt:X.509Token>
	<tt:SAMLToken>false</tt:SAMLToken>
	<tt:KerberosToken>false</tt:KerberosToken>
	<tt:RELToken>false</tt:RELToken>
	<tt:Extension><tt:TLS1.0>true</tt:TLS1.0>
	<tt:Extension><tt:Dot1X>false</tt:Dot1X>
	<tt:SupportedEAPMethod>0</tt:SupportedEAPMethod>
	<tt:RemoteUserHandling>false</tt:RemoteUserHandling>
	</tt:Extension>
	</tt:Extension>
	</tt:Security>
	</tt:Device>
	<tt:Events><tt:XAddr>http://49.235.201.130/onvif/Events</tt:XAddr>
	<tt:WSSubscriptionPolicySupport>true</tt:WSSubscriptionPolicySupport>
	<tt:WSPullPointSupport>true</tt:WSPullPointSupport>
	<tt:WSPausableSubscriptionManagerInterfaceSupport>false</tt:WSPausableSubscriptionManagerInterfaceSupport>
	</tt:Events>
	<tt:Imaging><tt:XAddr>http://49.235.201.130/onvif/Imaging</tt:XAddr>
	</tt:Imaging>
	<tt:Media><tt:XAddr>http://49.235.201.130/onvif/Media</tt:XAddr>
	<tt:StreamingCapabilities><tt:RTPMulticast>true</tt:RTPMulticast>
	<tt:RTP_TCP>true</tt:RTP_TCP>
	<tt:RTP_RTSP_TCP>true</tt:RTP_RTSP_TCP>
	</tt:StreamingCapabilities>
	<tt:Extension><tt:ProfileCapabilities><tt:MaximumNumberOfProfiles>15</tt:MaximumNumberOfProfiles>
	</tt:ProfileCapabilities>
	</tt:Extension>
	</tt:Media>
	<tt:PTZ><tt:XAddr>http://49.235.201.130/onvif/PTZ</tt:XAddr>
	</tt:PTZ>
	<tt:Extension><hikxsd:hikCapabilities><hikxsd:XAddr>http://49.235.201.130/onvif/hik_ext</hikxsd:XAddr>
	<hikxsd:IOInputSupport>true</hikxsd:IOInputSupport>
	<hikxsd:PrivacyMaskSupport>true</hikxsd:PrivacyMaskSupport>
	<hikxsd:PTZ3DZoomSupport>true</hikxsd:PTZ3DZoomSupport>
	<hikxsd:PTZPatternSupport>true</hikxsd:PTZPatternSupport>
	<hikxsd:Language>1</hikxsd:Language>
	</hikxsd:hikCapabilities>
	<tt:DeviceIO><tt:XAddr>http://49.235.201.130/onvif/DeviceIO</tt:XAddr>
	<tt:VideoSources>2</tt:VideoSources>
	<tt:VideoOutputs>0</tt:VideoOutputs>
	<tt:AudioSources>1</tt:AudioSources>
	<tt:AudioOutputs>1</tt:AudioOutputs>
	<tt:RelayOutputs>1</tt:RelayOutputs>
	</tt:DeviceIO>
	<tt:Recording><tt:XAddr>http://49.235.201.130/onvif/Recording</tt:XAddr>
	<tt:ReceiverSource>false</tt:ReceiverSource>
	<tt:MediaProfileSource>true</tt:MediaProfileSource>
	<tt:DynamicRecordings>false</tt:DynamicRecordings>
	<tt:DynamicTracks>false</tt:DynamicTracks>
	<tt:MaxStringLength>64</tt:MaxStringLength>
	</tt:Recording>
	<tt:Search><tt:XAddr>http://49.235.201.130/onvif/SearchRecording</tt:XAddr>
	<tt:MetadataSearch>false</tt:MetadataSearch>
	</tt:Search>
	<tt:Replay><tt:XAddr>http://49.235.201.130/onvif/Replay</tt:XAddr>
	</tt:Replay>
	</tt:Extension>
	</tds:Capabilities>
	</tds:GetCapabilitiesResponse>
	</env:Body>

	*/
	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::getStreamUri(std::string endpoint,
                            std::string username,
                            std::string password) {
	int result = SOAP_ERR;

	MediaBindingProxy *dproxy = new MediaBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	tt__Transport transport;
	transport.Protocol = tt__TransportProtocol__RTSP; // udp、tcp、RTSP、HTTP
	transport.Tunnel = NULL;

	tt__StreamSetup streamSetup;
	streamSetup.Transport = &transport;
	streamSetup.Stream = tt__StreamType__RTP_Unicast; // 单播

	_trt__GetStreamUri trt__GetStreamUri;
	trt__GetStreamUri.StreamSetup = &streamSetup;
	trt__GetStreamUri.ProfileToken = "Profile_101"; // 函数getProfileInfo

	_trt__GetStreamUriResponse trt__GetStreamUriResponse;

	result = dproxy->GetStreamUri(endpoint.c_str(), NULL,
	                              &trt__GetStreamUri, trt__GetStreamUriResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		/*
		<env:Body><trt:GetStreamUriResponse><trt:MediaUri>
		<tt:Uri>rtsp://49.235.201.130:554/Streaming/Channels/101?transportmode=unicast&amp;profile=Profile_101</tt:Uri>
		<tt:InvalidAfterConnect>false</tt:InvalidAfterConnect>
		<tt:InvalidAfterReboot>false</tt:InvalidAfterReboot>
		<tt:Timeout>PT60S</tt:Timeout>
		</trt:MediaUri>
		</trt:GetStreamUriResponse>
		</env:Body>
		*/
	}

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::getVideoSourceInfo(std::string endpoint,
                                  std::string username,
                                  std::string password) {
	int result = SOAP_ERR;

	DeviceIOBindingProxy *dproxy = new DeviceIOBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	tmd__Get _tmd__Get;
	tmd__GetResponse _tmd__GetResponse;

	result = dproxy->GetVideoSources(endpoint.c_str(), NULL,
	                                 &_tmd__Get, _tmd__GetResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		for (int i = 0; i < _tmd__GetResponse.Token.size(); ++i )
			std::cout << _tmd__GetResponse.Token[i] << std::endl;

		//VideoSource_1
		//VideoSource_2
	}

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::getVideoOutputInfo(std::string endpoint,
                                  std::string username,
                                  std::string password) {
	int result = SOAP_ERR;

	// GetDeviceInformation函数Access Class: READ_SYSTEM需要鉴权
	DeviceIOBindingProxy *dproxy = new DeviceIOBindingProxy();
	/*
	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result)
	{
	    std::cerr << "Authentication failed, retcode " << result << std::endl;
	    return;
	}
	*/
	_tmd__GetVideoOutputs tmd__GetVideoOutputs;
	_tmd__GetVideoOutputsResponse tmd__GetVideoOutputsResponse;

	result = dproxy->GetVideoOutputs(endpoint.c_str(), NULL,
	                                 &tmd__GetVideoOutputs, tmd__GetVideoOutputsResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
		//std::cerr << "error="<< dproxy->soap_fault_string()<< std::endl;
	} else {
	}

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::getDevInfo(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	// GetDeviceInformation函数Access Class: READ_SYSTEM需要鉴权
	DeviceBindingProxy *dproxy = new DeviceBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
		//std::cerr << "error1="<< dproxy->soap_fault_string()<< std::endl;
		//std::cerr << "error2="<< dproxy->soap_fault_detail()<< std::endl;
		return;
	}

	_tds__GetDeviceInformation tds__GetDeviceInformation;
	_tds__GetDeviceInformationResponse tds__GetDeviceInformationResponse;

	result = dproxy->GetDeviceInformation(endpoint.c_str(), NULL,
	                                      &tds__GetDeviceInformation, tds__GetDeviceInformationResponse);

	if (SOAP_OK != result) {
		//dproxy->soap_stream_fault(std::cerr);
		std::cerr << "error1=" << dproxy->soap_fault_string() << std::endl;
		//std::cerr << "error2="<< dproxy->soap_fault_detail()<< std::endl;
	} else {
		std::cout << "Mfr: " << tds__GetDeviceInformationResponse.Manufacturer << std::endl;
		std::cout << "Model: " << tds__GetDeviceInformationResponse.Model << std::endl;
		std::cout << "F/W version: " << tds__GetDeviceInformationResponse.FirmwareVersion << std::endl;
		/*

		<env:Body>
		<tds:GetDeviceInformationResponse><tds:Manufacturer>HIKVISION</tds:Manufacturer>
		<tds:Model>iDS-2PT91JNLC-CS/CXS</tds:Model>
		<tds:FirmwareVersion>V5.5.23 build 190821</tds:FirmwareVersion>
		<tds:SerialNumber>iDS-2PT91JNLC-CS/CXS20190924CCCHD65746854</tds:SerialNumber>
		<tds:HardwareId>88</tds:HardwareId>
		</tds:GetDeviceInformationResponse>
		</env:Body>

		*/

	}

	_tds__GetHostname tds__GetHostname;
	_tds__GetHostnameResponse tds__GetHostnameResponse;

	result = dproxy->GetHostname(endpoint.c_str(), NULL,
	                             &tds__GetHostname, tds__GetHostnameResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		/*
		<tds:GetHostnameResponse><tds:HostnameInformation>
		<tt:FromDHCP>false</tt:FromDHCP>
		<tt:Name>Hikvision</tt:Name>
		</tds:HostnameInformation>
		</tds:GetHostnameResponse>
		*/
	}


	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

void onviflib::systemReboot(std::string endpoint, std::string username, std::string password) {
	int result = SOAP_ERR;

	DeviceBindingProxy *dproxy = new DeviceBindingProxy();

	result = soap_wsse_add_UsernameTokenDigest(dproxy->soap, NULL, username.c_str(), password.c_str());
	if (SOAP_OK != result) {
		std::cerr << "Authentication failed, retcode " << result << std::endl;
		return;
	}

	_tds__SystemReboot tds__SystemReboot;
	_tds__SystemRebootResponse tds__SystemRebootResponse;

	result = dproxy->SystemReboot(endpoint.c_str(), NULL,
	                              &tds__SystemReboot, tds__SystemRebootResponse);

	if (SOAP_OK != result) {
		dproxy->soap_stream_fault(std::cerr);
	} else {
		/*
		  <env:Body><tds:SystemRebootResponse><tds:Message>Rebooting in 90 seconds</tds:Message>
		  </tds:SystemRebootResponse>
		  </env:Body>
		  */
	}

	dproxy->destroy();
	delete dproxy;
	dproxy = NULL;
}

//string 转换为time_t  时间格式为20140328182526
time_t onviflib::string2time_t(const std::string string_time) {
	struct tm tm1;
	time_t time1;
	sscanf(string_time.c_str(), "%4d%2d%2d%2d%2d%2d",
	       &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday,
	       &tm1.tm_hour, &tm1.tm_min, &tm1.tm_sec);

	tm1.tm_year -= 1900;
	tm1.tm_mon --;
	tm1.tm_isdst = -1;
	time1 = mktime(&tm1);
	return time1;
}

//time_t转换为string  时间格式为20140328182526
std::string onviflib::time_t2string(const time_t time_t_time) {
	char szTime[64] = { 0 };
	struct tm tm1;
	localtime_r(&time_t_time, &tm1 );
	sprintf( szTime, "%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d",
	         tm1.tm_year + 1900, tm1.tm_mon + 1, tm1.tm_mday,
	         tm1.tm_hour, tm1.tm_min, tm1.tm_sec);
	return szTime;
}

int main(int argc, const char *argv[]) {
	onviflib onvif;

	if (argc < 3) {
		std::cerr << "  not run as ./test addr username passwd, will use default config:" << std::endl;
		std::cerr << "    http://49.235.201.96/onvif/device_service  test test12345" << std::endl;
		std::cerr << std::endl;

		// 发现设备
		//onvif.WSDiscovery();

		// 获取OSD
		//onvif.getOSDs();

		// 设备信息
		//onvif.getDevInfo();

		//ActionNotSupporte
		//onvif.getVideoOutputInfo();

		// 获取视频源
		//onvif.getVideoSourceInfo();

		// 获取URI
		//onvif.getStreamUri();

		// 设备重启
		//onvif.systemReboot();

		// 获取设备功能信息
		//onvif.getCapabilitieInfo();

		// 获取设备属性信息
		//onvif.getProfileInfo();

		// 获取录制信息
		//onvif.getRecordTokenInfo();

		//获取录制token信息
		//onvif.getAllRecordTokenInfo();

		// 获取回放地址
		//onvif.getReplayUri();

		// 获取录制配置信息
		//onvif.getRecordingConfiguration();

		// 获取录制信息
		//onvif.getRecordingInformation();

		// 获取媒体信息
		//onvif.getMediaAttributes();

		// PTZ持续移动
		//onvif.PtzContinuousMove();

		// PTZ获取节点
		//onvif.getNodes();

		// 获取PTZ配置
		//onvif.getConfigurations();

		// 设置预置点
		//onvif.setPreset();

		// 获取PTZ预设点配置
		//onvif.getPresets();

		// 转到预设点
		//onvif.gotoPreset();

		// 获取事件属性
		//onvif.getEventProperties();

		// 创建订阅与获取消息
		//onvif.createPullPointSubscription();

		// 获取设备信息
		//onvif.getDateTime();

		// 获取快照
		//onvif.getSnapshotUri();

		// 移动
		onvif.ProvisioningMove();

	} else {
		std::string endpoint = argv[1];
		std::string username = argv[2];
		std::string password = argv[3];

		// 设备信息
		//onvif.getDevInfo(endpoint, username, password);
		//onvif.getVideoOutputInfo(endpoint, username, password);
	}

	return 0;
}
