g++ -DWITH_OPENSSL soapC.cpp soapwsHttpWellthServiceProxy.cpp ../gsoap-2.8/gsoap/stdsoap2.cpp try_02.cpp -o try_02 -lgsoap++ -lgsoapssl++ -lssl -lcrypto -lz 
#g++ -DWITH_OPENSSL soapC.cpp soapwsHttpWellthServiceProxy.cpp ../gsoap-2.8/gsoap/stdsoap2.cpp try_01.cpp -o try_01 -lgsoap++ -lgsoapssl++ -lssl -lcrypto -lz 
#g++ -DWITH_OPENSSL soapC.cpp soapwsHttpWellthServiceProxy.cpp ../gsoap-2.8/gsoap/stdsoap2.cpp try_01.cpp -o try_01 -lgsoap++ -lgsoapssl++
#g++ soapC.cpp soapwsHttpWellthServiceProxy.cpp try_01.cpp -o try_01 -lgsoap++
