#include "soapwsHttpWellthServiceProxy.h"
#include "wsHttpWellthService.nsmap"

int main()
{
wsHttpWellthServiceProxy service;
//char request[64];
std::string request = "dileeptp@gmail.com";
char response[64];
_ns3__GetNameByEmailID soapRequest;
_ns3__GetNameByEmailIDResponse soapResponse;
struct soap *pSoap = NULL;


pSoap = soap_new();
soap_set_namespaces(pSoap,namespaces);
soap_ssl_init();
if (soap_ssl_client_context(pSoap, SOAP_SSL_NO_AUTHENTICATION, NULL,NULL,NULL,NULL,NULL) == SOAP_OK)
  std::cout << "Client COntext set OK " << std::endl;

/**
strcpy(request,"dileeptp@gmail.com");
soapRequest.emailID = (std::string *)&request;
**/
pSoap->ssl_flags = SOAP_SSL_NO_AUTHENTICATION | SOAP_SSL_NO_DEFAULT_CA_PATH;
soapRequest.emailID = &request;
soapRequest.soap = pSoap;



// if (service.GetNameByEmailID((_ns3__GetNameByEmailID*)request,(_ns3__GetNameByEmailIDResponse*)response) == SOAP_OK)
//soap_call___ns1__GetNameByEmailID(pSoap,NULL,NULL,&soapRequest,&soapResponse);

if (service.GetNameByEmailID(&soapRequest,&soapResponse) == SOAP_OK)
  std::cout << "The response is " << response << std::endl;
else
  service.soap_stream_fault(std::cerr); 
  service.destroy(); // delete data and release memory 


}
