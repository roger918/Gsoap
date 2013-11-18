#include "soapwsHttpWellthServiceProxy.h"
#include "wsHttpWellthService.nsmap"
#include "soapStub.h"
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
#if 1 
/*Added by shan*/
struct soap soap;
soap_init(&soap);
soap.recv_timeout = 60;
#endif

/***
soap_ssl_init();
if (soap_ssl_client_context(pSoap, SOAP_SSL_NO_AUTHENTICATION, NULL,NULL,NULL,NULL,NULL) == SOAP_OK)
  std::cout << "Client COntext set OK " << std::endl;
***/
soap_ssl_init(); /* init OpenSSL (just once) */



#if 1
if (soap_ssl_client_context(pSoap,
   SOAP_SSL_DEFAULT /*SOAP_SSL_NO_AUTHENTICATION | SOAP_SSL_NO_DEFAULT_CA_PATH*/,
  "client.pem", /* keyfile: required only when client must authenticate to server (see SSL docs on how to obtain this file) */
   "Wellth!", /* password to read the key file (not used with GNUTLS) */
   "cacert.pem", /* cacert file to store trusted certificates (needed to verify server) */    "/home/wellth/wellth1/wellth/Try_01", /* capath to directory with trusted certificates */
   NULL /* if randfile!=NULL: use a file with random data to seed randomness */ 
) /*== SOAP_OK*/)
{
   soap_print_fault(pSoap, stderr);
   exit(1);
}
#endif

/***
strcpy(request,"dileeptp@gmail.com");
soapRequest.emailID = (std::string *)&request;
***/

#if 1
pSoap->ssl_flags = SOAP_SSL_NO_AUTHENTICATION | SOAP_SSL_NO_DEFAULT_CA_PATH;
soapRequest.emailID = &request;
soapRequest.soap = pSoap;
#endif


// if (service.GetNameByEmailID((_ns3__GetNameByEmailID*)request,(_ns3__GetNameByEmailIDResponse*)response) == SOAP_OK)
//	soap_call___ns1__GetNameByEmailID(pSoap,NULL,NULL,&soapRequest,&soapResponse);
#if 1
if (service.GetNameByEmailID(&soapRequest,&soapResponse) == SOAP_OK)
  std::cout << "The response is " << response << std::endl;
else
  service.soap_stream_fault(std::cerr); 
  service.destroy(); // delete data and release memory 
#endif

}
