/* soapUplinkBindingProxy.h
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

#ifndef soapUplinkBindingProxy_H
#define soapUplinkBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC UplinkBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        bool soap_own; ///< flag indicating that this context is owned by this proxy when context is shared
        /// Endpoint URL of service 'UplinkBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in onvif.h, if any
        /// Construct a proxy with new managing context
        UplinkBindingProxy();
        /// Copy constructor
        UplinkBindingProxy(const UplinkBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        UplinkBindingProxy(struct soap*);
        /// Constructor taking an endpoint URL
        UplinkBindingProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        UplinkBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        UplinkBindingProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        UplinkBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~UplinkBindingProxy();
        /// Initializer used by constructors
        virtual void UplinkBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual UplinkBindingProxy *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        UplinkBindingProxy& operator=(const UplinkBindingProxy&);
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
        virtual int GetServiceCapabilities(_ns12__GetServiceCapabilities *ns12__GetServiceCapabilities, _ns12__GetServiceCapabilitiesResponse &ns12__GetServiceCapabilitiesResponse)
        { return this->GetServiceCapabilities(NULL, NULL, ns12__GetServiceCapabilities, ns12__GetServiceCapabilitiesResponse); }
        virtual int GetServiceCapabilities(const char *soap_endpoint, const char *soap_action, _ns12__GetServiceCapabilities *ns12__GetServiceCapabilities, _ns12__GetServiceCapabilitiesResponse &ns12__GetServiceCapabilitiesResponse);
        /// Web service operation 'GetUplinks' (returns SOAP_OK or error code)
        virtual int GetUplinks(_ns12__GetUplinks *ns12__GetUplinks, _ns12__GetUplinksResponse &ns12__GetUplinksResponse)
        { return this->GetUplinks(NULL, NULL, ns12__GetUplinks, ns12__GetUplinksResponse); }
        virtual int GetUplinks(const char *soap_endpoint, const char *soap_action, _ns12__GetUplinks *ns12__GetUplinks, _ns12__GetUplinksResponse &ns12__GetUplinksResponse);
        /// Web service operation 'SetUplink' (returns SOAP_OK or error code)
        virtual int SetUplink(_ns12__SetUplink *ns12__SetUplink, _ns12__SetUplinkResponse &ns12__SetUplinkResponse)
        { return this->SetUplink(NULL, NULL, ns12__SetUplink, ns12__SetUplinkResponse); }
        virtual int SetUplink(const char *soap_endpoint, const char *soap_action, _ns12__SetUplink *ns12__SetUplink, _ns12__SetUplinkResponse &ns12__SetUplinkResponse);
        /// Web service operation 'DeleteUplink' (returns SOAP_OK or error code)
        virtual int DeleteUplink(_ns12__DeleteUplink *ns12__DeleteUplink, _ns12__DeleteUplinkResponse &ns12__DeleteUplinkResponse)
        { return this->DeleteUplink(NULL, NULL, ns12__DeleteUplink, ns12__DeleteUplinkResponse); }
        virtual int DeleteUplink(const char *soap_endpoint, const char *soap_action, _ns12__DeleteUplink *ns12__DeleteUplink, _ns12__DeleteUplinkResponse &ns12__DeleteUplinkResponse);
    };
#endif
