/* soapRuleEngineBindingProxy.h
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

#ifndef soapRuleEngineBindingProxy_H
#define soapRuleEngineBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC RuleEngineBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        bool soap_own; ///< flag indicating that this context is owned by this proxy when context is shared
        /// Endpoint URL of service 'RuleEngineBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in onvif.h, if any
        /// Construct a proxy with new managing context
        RuleEngineBindingProxy();
        /// Copy constructor
        RuleEngineBindingProxy(const RuleEngineBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        RuleEngineBindingProxy(struct soap*);
        /// Constructor taking an endpoint URL
        RuleEngineBindingProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        RuleEngineBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        RuleEngineBindingProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        RuleEngineBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~RuleEngineBindingProxy();
        /// Initializer used by constructors
        virtual void RuleEngineBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual RuleEngineBindingProxy *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        RuleEngineBindingProxy& operator=(const RuleEngineBindingProxy&);
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
        /// Web service operation 'GetSupportedRules' (returns SOAP_OK or error code)
        virtual int GetSupportedRules(_tan__GetSupportedRules *tan__GetSupportedRules, _tan__GetSupportedRulesResponse &tan__GetSupportedRulesResponse)
        { return this->GetSupportedRules(NULL, NULL, tan__GetSupportedRules, tan__GetSupportedRulesResponse); }
        virtual int GetSupportedRules(const char *soap_endpoint, const char *soap_action, _tan__GetSupportedRules *tan__GetSupportedRules, _tan__GetSupportedRulesResponse &tan__GetSupportedRulesResponse);
        /// Web service operation 'CreateRules' (returns SOAP_OK or error code)
        virtual int CreateRules(_tan__CreateRules *tan__CreateRules, _tan__CreateRulesResponse &tan__CreateRulesResponse)
        { return this->CreateRules(NULL, NULL, tan__CreateRules, tan__CreateRulesResponse); }
        virtual int CreateRules(const char *soap_endpoint, const char *soap_action, _tan__CreateRules *tan__CreateRules, _tan__CreateRulesResponse &tan__CreateRulesResponse);
        /// Web service operation 'DeleteRules' (returns SOAP_OK or error code)
        virtual int DeleteRules(_tan__DeleteRules *tan__DeleteRules, _tan__DeleteRulesResponse &tan__DeleteRulesResponse)
        { return this->DeleteRules(NULL, NULL, tan__DeleteRules, tan__DeleteRulesResponse); }
        virtual int DeleteRules(const char *soap_endpoint, const char *soap_action, _tan__DeleteRules *tan__DeleteRules, _tan__DeleteRulesResponse &tan__DeleteRulesResponse);
        /// Web service operation 'GetRules' (returns SOAP_OK or error code)
        virtual int GetRules(_tan__GetRules *tan__GetRules, _tan__GetRulesResponse &tan__GetRulesResponse)
        { return this->GetRules(NULL, NULL, tan__GetRules, tan__GetRulesResponse); }
        virtual int GetRules(const char *soap_endpoint, const char *soap_action, _tan__GetRules *tan__GetRules, _tan__GetRulesResponse &tan__GetRulesResponse);
        /// Web service operation 'GetRuleOptions' (returns SOAP_OK or error code)
        virtual int GetRuleOptions(_tan__GetRuleOptions *tan__GetRuleOptions, _tan__GetRuleOptionsResponse &tan__GetRuleOptionsResponse)
        { return this->GetRuleOptions(NULL, NULL, tan__GetRuleOptions, tan__GetRuleOptionsResponse); }
        virtual int GetRuleOptions(const char *soap_endpoint, const char *soap_action, _tan__GetRuleOptions *tan__GetRuleOptions, _tan__GetRuleOptionsResponse &tan__GetRuleOptionsResponse);
        /// Web service operation 'ModifyRules' (returns SOAP_OK or error code)
        virtual int ModifyRules(_tan__ModifyRules *tan__ModifyRules, _tan__ModifyRulesResponse &tan__ModifyRulesResponse)
        { return this->ModifyRules(NULL, NULL, tan__ModifyRules, tan__ModifyRulesResponse); }
        virtual int ModifyRules(const char *soap_endpoint, const char *soap_action, _tan__ModifyRules *tan__ModifyRules, _tan__ModifyRulesResponse &tan__ModifyRulesResponse);
        /// Web service operation 'GetServiceCapabilities' (returns SOAP_OK or error code)
        virtual int GetServiceCapabilities(_tan__GetServiceCapabilities *tan__GetServiceCapabilities, _tan__GetServiceCapabilitiesResponse &tan__GetServiceCapabilitiesResponse)
        { return this->GetServiceCapabilities(NULL, NULL, tan__GetServiceCapabilities, tan__GetServiceCapabilitiesResponse); }
        virtual int GetServiceCapabilities(const char *soap_endpoint, const char *soap_action, _tan__GetServiceCapabilities *tan__GetServiceCapabilities, _tan__GetServiceCapabilitiesResponse &tan__GetServiceCapabilitiesResponse);
        /// Web service operation 'GetSupportedAnalyticsModules' (returns SOAP_OK or error code)
        virtual int GetSupportedAnalyticsModules(_tan__GetSupportedAnalyticsModules *tan__GetSupportedAnalyticsModules, _tan__GetSupportedAnalyticsModulesResponse &tan__GetSupportedAnalyticsModulesResponse)
        { return this->GetSupportedAnalyticsModules(NULL, NULL, tan__GetSupportedAnalyticsModules, tan__GetSupportedAnalyticsModulesResponse); }
        virtual int GetSupportedAnalyticsModules(const char *soap_endpoint, const char *soap_action, _tan__GetSupportedAnalyticsModules *tan__GetSupportedAnalyticsModules, _tan__GetSupportedAnalyticsModulesResponse &tan__GetSupportedAnalyticsModulesResponse);
        /// Web service operation 'CreateAnalyticsModules' (returns SOAP_OK or error code)
        virtual int CreateAnalyticsModules(_tan__CreateAnalyticsModules *tan__CreateAnalyticsModules, _tan__CreateAnalyticsModulesResponse &tan__CreateAnalyticsModulesResponse)
        { return this->CreateAnalyticsModules(NULL, NULL, tan__CreateAnalyticsModules, tan__CreateAnalyticsModulesResponse); }
        virtual int CreateAnalyticsModules(const char *soap_endpoint, const char *soap_action, _tan__CreateAnalyticsModules *tan__CreateAnalyticsModules, _tan__CreateAnalyticsModulesResponse &tan__CreateAnalyticsModulesResponse);
        /// Web service operation 'DeleteAnalyticsModules' (returns SOAP_OK or error code)
        virtual int DeleteAnalyticsModules(_tan__DeleteAnalyticsModules *tan__DeleteAnalyticsModules, _tan__DeleteAnalyticsModulesResponse &tan__DeleteAnalyticsModulesResponse)
        { return this->DeleteAnalyticsModules(NULL, NULL, tan__DeleteAnalyticsModules, tan__DeleteAnalyticsModulesResponse); }
        virtual int DeleteAnalyticsModules(const char *soap_endpoint, const char *soap_action, _tan__DeleteAnalyticsModules *tan__DeleteAnalyticsModules, _tan__DeleteAnalyticsModulesResponse &tan__DeleteAnalyticsModulesResponse);
        /// Web service operation 'GetAnalyticsModules' (returns SOAP_OK or error code)
        virtual int GetAnalyticsModules(_tan__GetAnalyticsModules *tan__GetAnalyticsModules, _tan__GetAnalyticsModulesResponse &tan__GetAnalyticsModulesResponse)
        { return this->GetAnalyticsModules(NULL, NULL, tan__GetAnalyticsModules, tan__GetAnalyticsModulesResponse); }
        virtual int GetAnalyticsModules(const char *soap_endpoint, const char *soap_action, _tan__GetAnalyticsModules *tan__GetAnalyticsModules, _tan__GetAnalyticsModulesResponse &tan__GetAnalyticsModulesResponse);
        /// Web service operation 'GetAnalyticsModuleOptions' (returns SOAP_OK or error code)
        virtual int GetAnalyticsModuleOptions(_tan__GetAnalyticsModuleOptions *tan__GetAnalyticsModuleOptions, _tan__GetAnalyticsModuleOptionsResponse &tan__GetAnalyticsModuleOptionsResponse)
        { return this->GetAnalyticsModuleOptions(NULL, NULL, tan__GetAnalyticsModuleOptions, tan__GetAnalyticsModuleOptionsResponse); }
        virtual int GetAnalyticsModuleOptions(const char *soap_endpoint, const char *soap_action, _tan__GetAnalyticsModuleOptions *tan__GetAnalyticsModuleOptions, _tan__GetAnalyticsModuleOptionsResponse &tan__GetAnalyticsModuleOptionsResponse);
        /// Web service operation 'ModifyAnalyticsModules' (returns SOAP_OK or error code)
        virtual int ModifyAnalyticsModules(_tan__ModifyAnalyticsModules *tan__ModifyAnalyticsModules, _tan__ModifyAnalyticsModulesResponse &tan__ModifyAnalyticsModulesResponse)
        { return this->ModifyAnalyticsModules(NULL, NULL, tan__ModifyAnalyticsModules, tan__ModifyAnalyticsModulesResponse); }
        virtual int ModifyAnalyticsModules(const char *soap_endpoint, const char *soap_action, _tan__ModifyAnalyticsModules *tan__ModifyAnalyticsModules, _tan__ModifyAnalyticsModulesResponse &tan__ModifyAnalyticsModulesResponse);
        /// Web service operation 'GetSupportedMetadata' (returns SOAP_OK or error code)
        virtual int GetSupportedMetadata(_tan__GetSupportedMetadata *tan__GetSupportedMetadata, _tan__GetSupportedMetadataResponse &tan__GetSupportedMetadataResponse)
        { return this->GetSupportedMetadata(NULL, NULL, tan__GetSupportedMetadata, tan__GetSupportedMetadataResponse); }
        virtual int GetSupportedMetadata(const char *soap_endpoint, const char *soap_action, _tan__GetSupportedMetadata *tan__GetSupportedMetadata, _tan__GetSupportedMetadataResponse &tan__GetSupportedMetadataResponse);
    };
#endif
