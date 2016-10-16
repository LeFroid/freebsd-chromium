--- content/browser/renderer_host/media/video_capture_device_client.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/browser/renderer_host/media/video_capture_device_client.cc	2016-08-18 02:29:10.788160000 +0300
@@ -181,7 +181,7 @@
       // see http://linuxtv.org/downloads/v4l-dvb-apis/packed-rgb.html.
       // Windows RGB24 defines blue at lowest byte,
       // see https://msdn.microsoft.com/en-us/library/windows/desktop/dd407253
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       origin_colorspace = libyuv::FOURCC_RAW;
 #elif defined(OS_WIN)
       origin_colorspace = libyuv::FOURCC_24BG;
