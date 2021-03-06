/* soapDeviceIOBindingProxy.h
   Generated by gSOAP 2.8.45 for onvif.h

gSOAP XML Web services tools
Copyright (C) 2000-2017, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef soapDeviceIOBindingProxy_H
#define soapDeviceIOBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC DeviceIOBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        bool soap_own; ///< flag indicating that this context is owned by this proxy when context is shared
        /// Endpoint URL of service 'DeviceIOBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in onvif.h, if any
        /// Construct a proxy with new managing context
        DeviceIOBindingProxy();
        /// Copy constructor
        DeviceIOBindingProxy(const DeviceIOBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        DeviceIOBindingProxy(struct soap*);
        /// Constructor taking an endpoint URL
        DeviceIOBindingProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        DeviceIOBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        DeviceIOBindingProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        DeviceIOBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~DeviceIOBindingProxy();
        /// Initializer used by constructors
        virtual void DeviceIOBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual DeviceIOBindingProxy *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        DeviceIOBindingProxy& operator=(const DeviceIOBindingProxy&);
        /// Delete all deserialized data (uses soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to default
        virtual void reset();
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Add SOAP Header to message
        virtual void soap_header(char *wsa__MessageID, struct wsa__Relationship *wsa__RelatesTo, struct wsa__EndpointReferenceType *wsa__From, struct wsa__EndpointReferenceType *wsa__ReplyTo, struct wsa__EndpointReferenceType *wsa__FaultTo, char *wsa__To, char *wsa__Action, struct wsdd__AppSequenceType *wsdd__AppSequence, char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance, struct _wsse__Security *wsse__Security);
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
        /// Get SOAP Fault structure (i.e. soap->fault, which is NULL when absent)
        virtual ::SOAP_ENV__Fault *soap_fault();
        /// Get SOAP Fault string (NULL when absent)
        virtual const char *soap_fault_string();
        /// Get SOAP Fault detail as string (NULL when absent)
        virtual const char *soap_fault_detail();
        /// Close connection (normally automatic, except for send_X ops)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        /// Web service operation 'GetServiceCapabilities' (returns SOAP_OK or error code)
        virtual int GetServiceCapabilities(_tmd__GetServiceCapabilities *tmd__GetServiceCapabilities, _tmd__GetServiceCapabilitiesResponse &tmd__GetServiceCapabilitiesResponse)
        { return this->GetServiceCapabilities(NULL, NULL, tmd__GetServiceCapabilities, tmd__GetServiceCapabilitiesResponse); }
        virtual int GetServiceCapabilities(const char *soap_endpoint, const char *soap_action, _tmd__GetServiceCapabilities *tmd__GetServiceCapabilities, _tmd__GetServiceCapabilitiesResponse &tmd__GetServiceCapabilitiesResponse);
        /// Web service operation 'GetRelayOutputOptions' (returns SOAP_OK or error code)
        virtual int GetRelayOutputOptions(_tmd__GetRelayOutputOptions *tmd__GetRelayOutputOptions, _tmd__GetRelayOutputOptionsResponse &tmd__GetRelayOutputOptionsResponse)
        { return this->GetRelayOutputOptions(NULL, NULL, tmd__GetRelayOutputOptions, tmd__GetRelayOutputOptionsResponse); }
        virtual int GetRelayOutputOptions(const char *soap_endpoint, const char *soap_action, _tmd__GetRelayOutputOptions *tmd__GetRelayOutputOptions, _tmd__GetRelayOutputOptionsResponse &tmd__GetRelayOutputOptionsResponse);
        /// Web service operation 'GetAudioSources' (returns SOAP_OK or error code)
        virtual int GetAudioSources(tmd__Get *tmd__GetAudioSources, tmd__GetResponse &tmd__GetAudioSourcesResponse)
        { return this->GetAudioSources(NULL, NULL, tmd__GetAudioSources, tmd__GetAudioSourcesResponse); }
        virtual int GetAudioSources(const char *soap_endpoint, const char *soap_action, tmd__Get *tmd__GetAudioSources, tmd__GetResponse &tmd__GetAudioSourcesResponse);
        /// Web service operation 'GetAudioOutputs' (returns SOAP_OK or error code)
        virtual int GetAudioOutputs(tmd__Get *tmd__GetAudioOutputs, tmd__GetResponse &tmd__GetAudioOutputsResponse)
        { return this->GetAudioOutputs(NULL, NULL, tmd__GetAudioOutputs, tmd__GetAudioOutputsResponse); }
        virtual int GetAudioOutputs(const char *soap_endpoint, const char *soap_action, tmd__Get *tmd__GetAudioOutputs, tmd__GetResponse &tmd__GetAudioOutputsResponse);
        /// Web service operation 'GetVideoSources' (returns SOAP_OK or error code)
        virtual int GetVideoSources(tmd__Get *tmd__GetVideoSources, tmd__GetResponse &tmd__GetVideoSourcesResponse)
        { return this->GetVideoSources(NULL, NULL, tmd__GetVideoSources, tmd__GetVideoSourcesResponse); }
        virtual int GetVideoSources(const char *soap_endpoint, const char *soap_action, tmd__Get *tmd__GetVideoSources, tmd__GetResponse &tmd__GetVideoSourcesResponse);
        /// Web service operation 'GetVideoOutputs' (returns SOAP_OK or error code)
        virtual int GetVideoOutputs(_tmd__GetVideoOutputs *tmd__GetVideoOutputs, _tmd__GetVideoOutputsResponse &tmd__GetVideoOutputsResponse)
        { return this->GetVideoOutputs(NULL, NULL, tmd__GetVideoOutputs, tmd__GetVideoOutputsResponse); }
        virtual int GetVideoOutputs(const char *soap_endpoint, const char *soap_action, _tmd__GetVideoOutputs *tmd__GetVideoOutputs, _tmd__GetVideoOutputsResponse &tmd__GetVideoOutputsResponse);
        /// Web service operation 'GetVideoSourceConfiguration' (returns SOAP_OK or error code)
        virtual int GetVideoSourceConfiguration(_tmd__GetVideoSourceConfiguration *tmd__GetVideoSourceConfiguration, _tmd__GetVideoSourceConfigurationResponse &tmd__GetVideoSourceConfigurationResponse)
        { return this->GetVideoSourceConfiguration(NULL, NULL, tmd__GetVideoSourceConfiguration, tmd__GetVideoSourceConfigurationResponse); }
        virtual int GetVideoSourceConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__GetVideoSourceConfiguration *tmd__GetVideoSourceConfiguration, _tmd__GetVideoSourceConfigurationResponse &tmd__GetVideoSourceConfigurationResponse);
        /// Web service operation 'GetVideoOutputConfiguration' (returns SOAP_OK or error code)
        virtual int GetVideoOutputConfiguration(_tmd__GetVideoOutputConfiguration *tmd__GetVideoOutputConfiguration, _tmd__GetVideoOutputConfigurationResponse &tmd__GetVideoOutputConfigurationResponse)
        { return this->GetVideoOutputConfiguration(NULL, NULL, tmd__GetVideoOutputConfiguration, tmd__GetVideoOutputConfigurationResponse); }
        virtual int GetVideoOutputConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__GetVideoOutputConfiguration *tmd__GetVideoOutputConfiguration, _tmd__GetVideoOutputConfigurationResponse &tmd__GetVideoOutputConfigurationResponse);
        /// Web service operation 'GetAudioSourceConfiguration' (returns SOAP_OK or error code)
        virtual int GetAudioSourceConfiguration(_tmd__GetAudioSourceConfiguration *tmd__GetAudioSourceConfiguration, _tmd__GetAudioSourceConfigurationResponse &tmd__GetAudioSourceConfigurationResponse)
        { return this->GetAudioSourceConfiguration(NULL, NULL, tmd__GetAudioSourceConfiguration, tmd__GetAudioSourceConfigurationResponse); }
        virtual int GetAudioSourceConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__GetAudioSourceConfiguration *tmd__GetAudioSourceConfiguration, _tmd__GetAudioSourceConfigurationResponse &tmd__GetAudioSourceConfigurationResponse);
        /// Web service operation 'GetAudioOutputConfiguration' (returns SOAP_OK or error code)
        virtual int GetAudioOutputConfiguration(_tmd__GetAudioOutputConfiguration *tmd__GetAudioOutputConfiguration, _tmd__GetAudioOutputConfigurationResponse &tmd__GetAudioOutputConfigurationResponse)
        { return this->GetAudioOutputConfiguration(NULL, NULL, tmd__GetAudioOutputConfiguration, tmd__GetAudioOutputConfigurationResponse); }
        virtual int GetAudioOutputConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__GetAudioOutputConfiguration *tmd__GetAudioOutputConfiguration, _tmd__GetAudioOutputConfigurationResponse &tmd__GetAudioOutputConfigurationResponse);
        /// Web service operation 'SetVideoSourceConfiguration' (returns SOAP_OK or error code)
        virtual int SetVideoSourceConfiguration(_tmd__SetVideoSourceConfiguration *tmd__SetVideoSourceConfiguration, _tmd__SetVideoSourceConfigurationResponse &tmd__SetVideoSourceConfigurationResponse)
        { return this->SetVideoSourceConfiguration(NULL, NULL, tmd__SetVideoSourceConfiguration, tmd__SetVideoSourceConfigurationResponse); }
        virtual int SetVideoSourceConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__SetVideoSourceConfiguration *tmd__SetVideoSourceConfiguration, _tmd__SetVideoSourceConfigurationResponse &tmd__SetVideoSourceConfigurationResponse);
        /// Web service operation 'SetVideoOutputConfiguration' (returns SOAP_OK or error code)
        virtual int SetVideoOutputConfiguration(_tmd__SetVideoOutputConfiguration *tmd__SetVideoOutputConfiguration, _tmd__SetVideoOutputConfigurationResponse &tmd__SetVideoOutputConfigurationResponse)
        { return this->SetVideoOutputConfiguration(NULL, NULL, tmd__SetVideoOutputConfiguration, tmd__SetVideoOutputConfigurationResponse); }
        virtual int SetVideoOutputConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__SetVideoOutputConfiguration *tmd__SetVideoOutputConfiguration, _tmd__SetVideoOutputConfigurationResponse &tmd__SetVideoOutputConfigurationResponse);
        /// Web service operation 'SetAudioSourceConfiguration' (returns SOAP_OK or error code)
        virtual int SetAudioSourceConfiguration(_tmd__SetAudioSourceConfiguration *tmd__SetAudioSourceConfiguration, _tmd__SetAudioSourceConfigurationResponse &tmd__SetAudioSourceConfigurationResponse)
        { return this->SetAudioSourceConfiguration(NULL, NULL, tmd__SetAudioSourceConfiguration, tmd__SetAudioSourceConfigurationResponse); }
        virtual int SetAudioSourceConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__SetAudioSourceConfiguration *tmd__SetAudioSourceConfiguration, _tmd__SetAudioSourceConfigurationResponse &tmd__SetAudioSourceConfigurationResponse);
        /// Web service operation 'SetAudioOutputConfiguration' (returns SOAP_OK or error code)
        virtual int SetAudioOutputConfiguration(_tmd__SetAudioOutputConfiguration *tmd__SetAudioOutputConfiguration, _tmd__SetAudioOutputConfigurationResponse &tmd__SetAudioOutputConfigurationResponse)
        { return this->SetAudioOutputConfiguration(NULL, NULL, tmd__SetAudioOutputConfiguration, tmd__SetAudioOutputConfigurationResponse); }
        virtual int SetAudioOutputConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__SetAudioOutputConfiguration *tmd__SetAudioOutputConfiguration, _tmd__SetAudioOutputConfigurationResponse &tmd__SetAudioOutputConfigurationResponse);
        /// Web service operation 'GetVideoSourceConfigurationOptions' (returns SOAP_OK or error code)
        virtual int GetVideoSourceConfigurationOptions(_tmd__GetVideoSourceConfigurationOptions *tmd__GetVideoSourceConfigurationOptions, _tmd__GetVideoSourceConfigurationOptionsResponse &tmd__GetVideoSourceConfigurationOptionsResponse)
        { return this->GetVideoSourceConfigurationOptions(NULL, NULL, tmd__GetVideoSourceConfigurationOptions, tmd__GetVideoSourceConfigurationOptionsResponse); }
        virtual int GetVideoSourceConfigurationOptions(const char *soap_endpoint, const char *soap_action, _tmd__GetVideoSourceConfigurationOptions *tmd__GetVideoSourceConfigurationOptions, _tmd__GetVideoSourceConfigurationOptionsResponse &tmd__GetVideoSourceConfigurationOptionsResponse);
        /// Web service operation 'GetVideoOutputConfigurationOptions' (returns SOAP_OK or error code)
        virtual int GetVideoOutputConfigurationOptions(_tmd__GetVideoOutputConfigurationOptions *tmd__GetVideoOutputConfigurationOptions, _tmd__GetVideoOutputConfigurationOptionsResponse &tmd__GetVideoOutputConfigurationOptionsResponse)
        { return this->GetVideoOutputConfigurationOptions(NULL, NULL, tmd__GetVideoOutputConfigurationOptions, tmd__GetVideoOutputConfigurationOptionsResponse); }
        virtual int GetVideoOutputConfigurationOptions(const char *soap_endpoint, const char *soap_action, _tmd__GetVideoOutputConfigurationOptions *tmd__GetVideoOutputConfigurationOptions, _tmd__GetVideoOutputConfigurationOptionsResponse &tmd__GetVideoOutputConfigurationOptionsResponse);
        /// Web service operation 'GetAudioSourceConfigurationOptions' (returns SOAP_OK or error code)
        virtual int GetAudioSourceConfigurationOptions(_tmd__GetAudioSourceConfigurationOptions *tmd__GetAudioSourceConfigurationOptions, _tmd__GetAudioSourceConfigurationOptionsResponse &tmd__GetAudioSourceConfigurationOptionsResponse)
        { return this->GetAudioSourceConfigurationOptions(NULL, NULL, tmd__GetAudioSourceConfigurationOptions, tmd__GetAudioSourceConfigurationOptionsResponse); }
        virtual int GetAudioSourceConfigurationOptions(const char *soap_endpoint, const char *soap_action, _tmd__GetAudioSourceConfigurationOptions *tmd__GetAudioSourceConfigurationOptions, _tmd__GetAudioSourceConfigurationOptionsResponse &tmd__GetAudioSourceConfigurationOptionsResponse);
        /// Web service operation 'GetAudioOutputConfigurationOptions' (returns SOAP_OK or error code)
        virtual int GetAudioOutputConfigurationOptions(_tmd__GetAudioOutputConfigurationOptions *tmd__GetAudioOutputConfigurationOptions, _tmd__GetAudioOutputConfigurationOptionsResponse &tmd__GetAudioOutputConfigurationOptionsResponse)
        { return this->GetAudioOutputConfigurationOptions(NULL, NULL, tmd__GetAudioOutputConfigurationOptions, tmd__GetAudioOutputConfigurationOptionsResponse); }
        virtual int GetAudioOutputConfigurationOptions(const char *soap_endpoint, const char *soap_action, _tmd__GetAudioOutputConfigurationOptions *tmd__GetAudioOutputConfigurationOptions, _tmd__GetAudioOutputConfigurationOptionsResponse &tmd__GetAudioOutputConfigurationOptionsResponse);
        /// Web service operation 'GetRelayOutputs' (returns SOAP_OK or error code)
        virtual int GetRelayOutputs(_tds__GetRelayOutputs *tds__GetRelayOutputs, _tds__GetRelayOutputsResponse &tds__GetRelayOutputsResponse)
        { return this->GetRelayOutputs(NULL, NULL, tds__GetRelayOutputs, tds__GetRelayOutputsResponse); }
        virtual int GetRelayOutputs(const char *soap_endpoint, const char *soap_action, _tds__GetRelayOutputs *tds__GetRelayOutputs, _tds__GetRelayOutputsResponse &tds__GetRelayOutputsResponse);
        /// Web service operation 'SetRelayOutputSettings' (returns SOAP_OK or error code)
        virtual int SetRelayOutputSettings(_tmd__SetRelayOutputSettings *tmd__SetRelayOutputSettings, _tmd__SetRelayOutputSettingsResponse &tmd__SetRelayOutputSettingsResponse)
        { return this->SetRelayOutputSettings(NULL, NULL, tmd__SetRelayOutputSettings, tmd__SetRelayOutputSettingsResponse); }
        virtual int SetRelayOutputSettings(const char *soap_endpoint, const char *soap_action, _tmd__SetRelayOutputSettings *tmd__SetRelayOutputSettings, _tmd__SetRelayOutputSettingsResponse &tmd__SetRelayOutputSettingsResponse);
        /// Web service operation 'SetRelayOutputState' (returns SOAP_OK or error code)
        virtual int SetRelayOutputState(_tds__SetRelayOutputState *tds__SetRelayOutputState, _tds__SetRelayOutputStateResponse &tds__SetRelayOutputStateResponse)
        { return this->SetRelayOutputState(NULL, NULL, tds__SetRelayOutputState, tds__SetRelayOutputStateResponse); }
        virtual int SetRelayOutputState(const char *soap_endpoint, const char *soap_action, _tds__SetRelayOutputState *tds__SetRelayOutputState, _tds__SetRelayOutputStateResponse &tds__SetRelayOutputStateResponse);
        /// Web service operation 'GetDigitalInputs' (returns SOAP_OK or error code)
        virtual int GetDigitalInputs(_tmd__GetDigitalInputs *tmd__GetDigitalInputs, _tmd__GetDigitalInputsResponse &tmd__GetDigitalInputsResponse)
        { return this->GetDigitalInputs(NULL, NULL, tmd__GetDigitalInputs, tmd__GetDigitalInputsResponse); }
        virtual int GetDigitalInputs(const char *soap_endpoint, const char *soap_action, _tmd__GetDigitalInputs *tmd__GetDigitalInputs, _tmd__GetDigitalInputsResponse &tmd__GetDigitalInputsResponse);
        /// Web service operation 'GetDigitalInputConfigurationOptions' (returns SOAP_OK or error code)
        virtual int GetDigitalInputConfigurationOptions(_tmd__GetDigitalInputConfigurationOptions *tmd__GetDigitalInputConfigurationOptions, _tmd__GetDigitalInputConfigurationOptionsResponse &tmd__GetDigitalInputConfigurationOptionsResponse)
        { return this->GetDigitalInputConfigurationOptions(NULL, NULL, tmd__GetDigitalInputConfigurationOptions, tmd__GetDigitalInputConfigurationOptionsResponse); }
        virtual int GetDigitalInputConfigurationOptions(const char *soap_endpoint, const char *soap_action, _tmd__GetDigitalInputConfigurationOptions *tmd__GetDigitalInputConfigurationOptions, _tmd__GetDigitalInputConfigurationOptionsResponse &tmd__GetDigitalInputConfigurationOptionsResponse);
        /// Web service operation 'SetDigitalInputConfigurations' (returns SOAP_OK or error code)
        virtual int SetDigitalInputConfigurations(_tmd__SetDigitalInputConfigurations *tmd__SetDigitalInputConfigurations, _tmd__SetDigitalInputConfigurationsResponse &tmd__SetDigitalInputConfigurationsResponse)
        { return this->SetDigitalInputConfigurations(NULL, NULL, tmd__SetDigitalInputConfigurations, tmd__SetDigitalInputConfigurationsResponse); }
        virtual int SetDigitalInputConfigurations(const char *soap_endpoint, const char *soap_action, _tmd__SetDigitalInputConfigurations *tmd__SetDigitalInputConfigurations, _tmd__SetDigitalInputConfigurationsResponse &tmd__SetDigitalInputConfigurationsResponse);
        /// Web service operation 'GetSerialPorts' (returns SOAP_OK or error code)
        virtual int GetSerialPorts(_tmd__GetSerialPorts *tmd__GetSerialPorts, _tmd__GetSerialPortsResponse &tmd__GetSerialPortsResponse)
        { return this->GetSerialPorts(NULL, NULL, tmd__GetSerialPorts, tmd__GetSerialPortsResponse); }
        virtual int GetSerialPorts(const char *soap_endpoint, const char *soap_action, _tmd__GetSerialPorts *tmd__GetSerialPorts, _tmd__GetSerialPortsResponse &tmd__GetSerialPortsResponse);
        /// Web service operation 'GetSerialPortConfiguration' (returns SOAP_OK or error code)
        virtual int GetSerialPortConfiguration(_tmd__GetSerialPortConfiguration *tmd__GetSerialPortConfiguration, _tmd__GetSerialPortConfigurationResponse &tmd__GetSerialPortConfigurationResponse)
        { return this->GetSerialPortConfiguration(NULL, NULL, tmd__GetSerialPortConfiguration, tmd__GetSerialPortConfigurationResponse); }
        virtual int GetSerialPortConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__GetSerialPortConfiguration *tmd__GetSerialPortConfiguration, _tmd__GetSerialPortConfigurationResponse &tmd__GetSerialPortConfigurationResponse);
        /// Web service operation 'SetSerialPortConfiguration' (returns SOAP_OK or error code)
        virtual int SetSerialPortConfiguration(_tmd__SetSerialPortConfiguration *tmd__SetSerialPortConfiguration, _tmd__SetSerialPortConfigurationResponse &tmd__SetSerialPortConfigurationResponse)
        { return this->SetSerialPortConfiguration(NULL, NULL, tmd__SetSerialPortConfiguration, tmd__SetSerialPortConfigurationResponse); }
        virtual int SetSerialPortConfiguration(const char *soap_endpoint, const char *soap_action, _tmd__SetSerialPortConfiguration *tmd__SetSerialPortConfiguration, _tmd__SetSerialPortConfigurationResponse &tmd__SetSerialPortConfigurationResponse);
        /// Web service operation 'GetSerialPortConfigurationOptions' (returns SOAP_OK or error code)
        virtual int GetSerialPortConfigurationOptions(_tmd__GetSerialPortConfigurationOptions *tmd__GetSerialPortConfigurationOptions, _tmd__GetSerialPortConfigurationOptionsResponse &tmd__GetSerialPortConfigurationOptionsResponse)
        { return this->GetSerialPortConfigurationOptions(NULL, NULL, tmd__GetSerialPortConfigurationOptions, tmd__GetSerialPortConfigurationOptionsResponse); }
        virtual int GetSerialPortConfigurationOptions(const char *soap_endpoint, const char *soap_action, _tmd__GetSerialPortConfigurationOptions *tmd__GetSerialPortConfigurationOptions, _tmd__GetSerialPortConfigurationOptionsResponse &tmd__GetSerialPortConfigurationOptionsResponse);
        /// Web service operation 'SendReceiveSerialCommand' (returns SOAP_OK or error code)
        virtual int SendReceiveSerialCommand(_tmd__SendReceiveSerialCommand *tmd__SendReceiveSerialCommand, _tmd__SendReceiveSerialCommandResponse &tmd__SendReceiveSerialCommandResponse)
        { return this->SendReceiveSerialCommand(NULL, NULL, tmd__SendReceiveSerialCommand, tmd__SendReceiveSerialCommandResponse); }
        virtual int SendReceiveSerialCommand(const char *soap_endpoint, const char *soap_action, _tmd__SendReceiveSerialCommand *tmd__SendReceiveSerialCommand, _tmd__SendReceiveSerialCommandResponse &tmd__SendReceiveSerialCommandResponse);
    };
#endif
