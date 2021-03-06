/* soapPullPointSubscriptionBindingProxy.h
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

#ifndef soapPullPointSubscriptionBindingProxy_H
#define soapPullPointSubscriptionBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC PullPointSubscriptionBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        bool soap_own; ///< flag indicating that this context is owned by this proxy when context is shared
        /// Endpoint URL of service 'PullPointSubscriptionBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in onvif.h, if any
        /// Construct a proxy with new managing context
        PullPointSubscriptionBindingProxy();
        /// Copy constructor
        PullPointSubscriptionBindingProxy(const PullPointSubscriptionBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        PullPointSubscriptionBindingProxy(struct soap*);
        /// Constructor taking an endpoint URL
        PullPointSubscriptionBindingProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        PullPointSubscriptionBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        PullPointSubscriptionBindingProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        PullPointSubscriptionBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~PullPointSubscriptionBindingProxy();
        /// Initializer used by constructors
        virtual void PullPointSubscriptionBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual PullPointSubscriptionBindingProxy *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        PullPointSubscriptionBindingProxy& operator=(const PullPointSubscriptionBindingProxy&);
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
        /// Web service operation 'PullMessages' (returns SOAP_OK or error code)
        virtual int PullMessages(_tev__PullMessages *tev__PullMessages, _tev__PullMessagesResponse &tev__PullMessagesResponse)
        { return this->PullMessages(NULL, NULL, tev__PullMessages, tev__PullMessagesResponse); }
        virtual int PullMessages(const char *soap_endpoint, const char *soap_action, _tev__PullMessages *tev__PullMessages, _tev__PullMessagesResponse &tev__PullMessagesResponse);
        /// Web service operation 'Seek' (returns SOAP_OK or error code)
        virtual int Seek(_tev__Seek *tev__Seek, _tev__SeekResponse &tev__SeekResponse)
        { return this->Seek(NULL, NULL, tev__Seek, tev__SeekResponse); }
        virtual int Seek(const char *soap_endpoint, const char *soap_action, _tev__Seek *tev__Seek, _tev__SeekResponse &tev__SeekResponse);
        /// Web service operation 'SetSynchronizationPoint' (returns SOAP_OK or error code)
        virtual int SetSynchronizationPoint(_tev__SetSynchronizationPoint *tev__SetSynchronizationPoint, _tev__SetSynchronizationPointResponse &tev__SetSynchronizationPointResponse)
        { return this->SetSynchronizationPoint(NULL, NULL, tev__SetSynchronizationPoint, tev__SetSynchronizationPointResponse); }
        virtual int SetSynchronizationPoint(const char *soap_endpoint, const char *soap_action, _tev__SetSynchronizationPoint *tev__SetSynchronizationPoint, _tev__SetSynchronizationPointResponse &tev__SetSynchronizationPointResponse);
        /// Web service operation 'Unsubscribe' (returns SOAP_OK or error code)
        virtual int Unsubscribe(_wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse &wsnt__UnsubscribeResponse)
        { return this->Unsubscribe(NULL, NULL, wsnt__Unsubscribe, wsnt__UnsubscribeResponse); }
        virtual int Unsubscribe(const char *soap_endpoint, const char *soap_action, _wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse &wsnt__UnsubscribeResponse);
        /// Web service operation 'GetServiceCapabilities' (returns SOAP_OK or error code)
        virtual int GetServiceCapabilities(_tev__GetServiceCapabilities *tev__GetServiceCapabilities, _tev__GetServiceCapabilitiesResponse &tev__GetServiceCapabilitiesResponse)
        { return this->GetServiceCapabilities(NULL, NULL, tev__GetServiceCapabilities, tev__GetServiceCapabilitiesResponse); }
        virtual int GetServiceCapabilities(const char *soap_endpoint, const char *soap_action, _tev__GetServiceCapabilities *tev__GetServiceCapabilities, _tev__GetServiceCapabilitiesResponse &tev__GetServiceCapabilitiesResponse);
        /// Web service operation 'CreatePullPointSubscription' (returns SOAP_OK or error code)
        virtual int CreatePullPointSubscription(_tev__CreatePullPointSubscription *tev__CreatePullPointSubscription, _tev__CreatePullPointSubscriptionResponse &tev__CreatePullPointSubscriptionResponse)
        { return this->CreatePullPointSubscription(NULL, NULL, tev__CreatePullPointSubscription, tev__CreatePullPointSubscriptionResponse); }
        virtual int CreatePullPointSubscription(const char *soap_endpoint, const char *soap_action, _tev__CreatePullPointSubscription *tev__CreatePullPointSubscription, _tev__CreatePullPointSubscriptionResponse &tev__CreatePullPointSubscriptionResponse);
        /// Web service operation 'GetEventProperties' (returns SOAP_OK or error code)
        virtual int GetEventProperties(_tev__GetEventProperties *tev__GetEventProperties, _tev__GetEventPropertiesResponse &tev__GetEventPropertiesResponse)
        { return this->GetEventProperties(NULL, NULL, tev__GetEventProperties, tev__GetEventPropertiesResponse); }
        virtual int GetEventProperties(const char *soap_endpoint, const char *soap_action, _tev__GetEventProperties *tev__GetEventProperties, _tev__GetEventPropertiesResponse &tev__GetEventPropertiesResponse);
        /// Web service operation 'Renew' (returns SOAP_OK or error code)
        virtual int Renew(_wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse &wsnt__RenewResponse)
        { return this->Renew(NULL, NULL, wsnt__Renew, wsnt__RenewResponse); }
        virtual int Renew(const char *soap_endpoint, const char *soap_action, _wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse &wsnt__RenewResponse);
        /// Web service operation 'Unsubscribe' (returns SOAP_OK or error code)
        virtual int Unsubscribe_(_wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse &wsnt__UnsubscribeResponse)
        { return this->Unsubscribe_(NULL, NULL, wsnt__Unsubscribe, wsnt__UnsubscribeResponse); }
        virtual int Unsubscribe_(const char *soap_endpoint, const char *soap_action, _wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse &wsnt__UnsubscribeResponse);
        /// Web service operation 'Subscribe' (returns SOAP_OK or error code)
        virtual int Subscribe(_wsnt__Subscribe *wsnt__Subscribe, _wsnt__SubscribeResponse &wsnt__SubscribeResponse)
        { return this->Subscribe(NULL, NULL, wsnt__Subscribe, wsnt__SubscribeResponse); }
        virtual int Subscribe(const char *soap_endpoint, const char *soap_action, _wsnt__Subscribe *wsnt__Subscribe, _wsnt__SubscribeResponse &wsnt__SubscribeResponse);
        /// Web service operation 'GetCurrentMessage' (returns SOAP_OK or error code)
        virtual int GetCurrentMessage(_wsnt__GetCurrentMessage *wsnt__GetCurrentMessage, _wsnt__GetCurrentMessageResponse &wsnt__GetCurrentMessageResponse)
        { return this->GetCurrentMessage(NULL, NULL, wsnt__GetCurrentMessage, wsnt__GetCurrentMessageResponse); }
        virtual int GetCurrentMessage(const char *soap_endpoint, const char *soap_action, _wsnt__GetCurrentMessage *wsnt__GetCurrentMessage, _wsnt__GetCurrentMessageResponse &wsnt__GetCurrentMessageResponse);
        /// Web service one-way send operation 'send_Notify' (returns SOAP_OK or error code)
        virtual int send_Notify(_wsnt__Notify *wsnt__Notify)
        { return this->send_Notify(NULL, NULL, wsnt__Notify); }
        virtual int send_Notify(const char *soap_endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify);
        /// Web service one-way receive operation 'recv_Notify' (returns SOAP_OK or error code);
        virtual int recv_Notify(struct __tev__Notify&);
        /// Web service receive of HTTP Accept acknowledgment for one-way send operation 'send_Notify' (returns SOAP_OK or error code)
        virtual int recv_Notify_empty_response()
        { return soap_recv_empty_response(this->soap); }
        /// Web service one-way synchronous send operation 'Notify' with HTTP Accept/OK response receive (returns SOAP_OK or error code)
        virtual int Notify(_wsnt__Notify *wsnt__Notify)
        { return this->Notify(NULL, NULL, wsnt__Notify); }
        virtual int Notify(const char *soap_endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify)
        {
          if (this->send_Notify(soap_endpoint, soap_action, wsnt__Notify) || soap_recv_empty_response(this->soap))
            return this->soap->error;
            return SOAP_OK;
        }
        /// Web service operation 'GetMessages' (returns SOAP_OK or error code)
        virtual int GetMessages(_wsnt__GetMessages *wsnt__GetMessages, _wsnt__GetMessagesResponse &wsnt__GetMessagesResponse)
        { return this->GetMessages(NULL, NULL, wsnt__GetMessages, wsnt__GetMessagesResponse); }
        virtual int GetMessages(const char *soap_endpoint, const char *soap_action, _wsnt__GetMessages *wsnt__GetMessages, _wsnt__GetMessagesResponse &wsnt__GetMessagesResponse);
        /// Web service operation 'DestroyPullPoint' (returns SOAP_OK or error code)
        virtual int DestroyPullPoint(_wsnt__DestroyPullPoint *wsnt__DestroyPullPoint, _wsnt__DestroyPullPointResponse &wsnt__DestroyPullPointResponse)
        { return this->DestroyPullPoint(NULL, NULL, wsnt__DestroyPullPoint, wsnt__DestroyPullPointResponse); }
        virtual int DestroyPullPoint(const char *soap_endpoint, const char *soap_action, _wsnt__DestroyPullPoint *wsnt__DestroyPullPoint, _wsnt__DestroyPullPointResponse &wsnt__DestroyPullPointResponse);
        /// Web service one-way send operation 'send_Notify' (returns SOAP_OK or error code)
        virtual int send_Notify_(_wsnt__Notify *wsnt__Notify)
        { return this->send_Notify_(NULL, NULL, wsnt__Notify); }
        virtual int send_Notify_(const char *soap_endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify);
        /// Web service one-way receive operation 'recv_Notify' (returns SOAP_OK or error code);
        virtual int recv_Notify_(struct __tev__Notify_&);
        /// Web service receive of HTTP Accept acknowledgment for one-way send operation 'send_Notify' (returns SOAP_OK or error code)
        virtual int recv_Notify__empty_response()
        { return soap_recv_empty_response(this->soap); }
        /// Web service one-way synchronous send operation 'Notify' with HTTP Accept/OK response receive (returns SOAP_OK or error code)
        virtual int Notify_(_wsnt__Notify *wsnt__Notify)
        { return this->Notify_(NULL, NULL, wsnt__Notify); }
        virtual int Notify_(const char *soap_endpoint, const char *soap_action, _wsnt__Notify *wsnt__Notify)
        {
          if (this->send_Notify_(soap_endpoint, soap_action, wsnt__Notify) || soap_recv_empty_response(this->soap))
            return this->soap->error;
            return SOAP_OK;
        }
        /// Web service operation 'CreatePullPoint' (returns SOAP_OK or error code)
        virtual int CreatePullPoint(_wsnt__CreatePullPoint *wsnt__CreatePullPoint, _wsnt__CreatePullPointResponse &wsnt__CreatePullPointResponse)
        { return this->CreatePullPoint(NULL, NULL, wsnt__CreatePullPoint, wsnt__CreatePullPointResponse); }
        virtual int CreatePullPoint(const char *soap_endpoint, const char *soap_action, _wsnt__CreatePullPoint *wsnt__CreatePullPoint, _wsnt__CreatePullPointResponse &wsnt__CreatePullPointResponse);
        /// Web service operation 'Renew' (returns SOAP_OK or error code)
        virtual int Renew_(_wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse &wsnt__RenewResponse)
        { return this->Renew_(NULL, NULL, wsnt__Renew, wsnt__RenewResponse); }
        virtual int Renew_(const char *soap_endpoint, const char *soap_action, _wsnt__Renew *wsnt__Renew, _wsnt__RenewResponse &wsnt__RenewResponse);
        /// Web service operation 'Unsubscribe' (returns SOAP_OK or error code)
        virtual int Unsubscribe__(_wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse &wsnt__UnsubscribeResponse)
        { return this->Unsubscribe__(NULL, NULL, wsnt__Unsubscribe, wsnt__UnsubscribeResponse); }
        virtual int Unsubscribe__(const char *soap_endpoint, const char *soap_action, _wsnt__Unsubscribe *wsnt__Unsubscribe, _wsnt__UnsubscribeResponse &wsnt__UnsubscribeResponse);
        /// Web service operation 'PauseSubscription' (returns SOAP_OK or error code)
        virtual int PauseSubscription(_wsnt__PauseSubscription *wsnt__PauseSubscription, _wsnt__PauseSubscriptionResponse &wsnt__PauseSubscriptionResponse)
        { return this->PauseSubscription(NULL, NULL, wsnt__PauseSubscription, wsnt__PauseSubscriptionResponse); }
        virtual int PauseSubscription(const char *soap_endpoint, const char *soap_action, _wsnt__PauseSubscription *wsnt__PauseSubscription, _wsnt__PauseSubscriptionResponse &wsnt__PauseSubscriptionResponse);
        /// Web service operation 'ResumeSubscription' (returns SOAP_OK or error code)
        virtual int ResumeSubscription(_wsnt__ResumeSubscription *wsnt__ResumeSubscription, _wsnt__ResumeSubscriptionResponse &wsnt__ResumeSubscriptionResponse)
        { return this->ResumeSubscription(NULL, NULL, wsnt__ResumeSubscription, wsnt__ResumeSubscriptionResponse); }
        virtual int ResumeSubscription(const char *soap_endpoint, const char *soap_action, _wsnt__ResumeSubscription *wsnt__ResumeSubscription, _wsnt__ResumeSubscriptionResponse &wsnt__ResumeSubscriptionResponse);
    };
#endif
