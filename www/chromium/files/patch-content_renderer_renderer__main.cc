--- content/renderer/renderer_main.cc.orig	2016-08-08 11:46:46.508540000 -0400
+++ content/renderer/renderer_main.cc	2016-08-08 11:52:49.150637000 -0400
@@ -172,7 +172,7 @@
 #endif
 
   {
-#if defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
     // TODO(markus): Check if it is OK to unconditionally move this
     // instruction down.
     RenderProcessImpl render_process;
@@ -182,7 +182,7 @@
     bool run_loop = true;
     if (!no_sandbox)
       run_loop = platform.EnableSandbox();
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
     RenderProcessImpl render_process;
     RenderThreadImpl::Create(std::move(main_message_loop),
                              std::move(renderer_scheduler));
