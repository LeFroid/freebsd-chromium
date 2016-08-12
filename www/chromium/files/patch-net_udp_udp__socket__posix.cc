--- net/udp/udp_socket_posix.cc.orig	2016-08-08 11:00:25.522436000 -0400
+++ net/udp/udp_socket_posix.cc	2016-08-08 11:01:07.115453000 -0400
@@ -45,7 +45,7 @@
 const int kPortStart = 1024;
 const int kPortEnd = 65535;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Returns IPv4 address in network order.
 int GetIPv4AddressFromIndex(int socket, uint32_t index, uint32_t* address) {
@@ -603,7 +603,7 @@
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
         ip_mreqn mreq;
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
@@ -678,7 +678,7 @@
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       ip_mreqn mreq;
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = htonl(INADDR_ANY);
