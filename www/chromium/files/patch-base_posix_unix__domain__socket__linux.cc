--- base/posix/unix_domain_socket_linux.cc.orig	2016-08-03 15:02:10.000000000 -0400
+++ base/posix/unix_domain_socket_linux.cc	2016-08-08 11:18:08.550899000 -0400
@@ -5,7 +5,10 @@
 #include "base/posix/unix_domain_socket_linux.h"
 
 #include <errno.h>
+#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
+#include <sys/ucred.h>
 #include <unistd.h>
 
 #include <vector>
@@ -23,8 +26,25 @@
 
 namespace base {
 
+#if defined(__FreeBSD__)
+// Port over Linux ucred structure
+struct ucred {
+  pid_t pid; // process ID of the sending process
+  uid_t uid; // user ID of the sending process
+  gid_t gid; // group ID of the sending process
+};
+#endif
+
 const size_t UnixDomainSocket::kMaxFileDescriptors = 16;
 
+#ifndef SCM_CREDENTIALS
+#  define SCM_CREDENTIALS 0x9001
+#endif
+
+#ifndef SO_PASSCRED
+#  define SO_PASSCRED 0x9002
+#endif
+
 #if !defined(OS_NACL_NONSFI)
 // Creates a connected pair of UNIX-domain SOCK_SEQPACKET sockets, and passes
 // ownership of the newly allocated file descriptors to |one| and |two|.
@@ -150,7 +170,11 @@
           cmsg->cmsg_type == SCM_CREDENTIALS) {
         DCHECK_EQ(payload_len, sizeof(struct ucred));
         DCHECK_EQ(pid, -1);
+#if defined(OS_BSD)
+        pid = getpid();
+#else
         pid = reinterpret_cast<struct ucred*>(CMSG_DATA(cmsg))->pid;
+#endif
       }
 #endif
     }
