--- chrome/browser/ui/browser_command_controller.cc.orig	2016-10-06 04:02:13.000000000 +0300
+++ chrome/browser/ui/browser_command_controller.cc	2016-10-13 05:57:01.306342000 +0300
@@ -76,7 +76,7 @@
 #include "chrome/browser/ui/browser_commands_chromeos.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
 
@@ -216,7 +216,7 @@
   if (window()->IsFullscreen() && command_id == IDC_FULLSCREEN)
     return true;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
@@ -419,7 +419,7 @@
       break;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     case IDC_USE_SYSTEM_TITLE_BAR: {
       PrefService* prefs = browser_->profile()->GetPrefs();
       prefs->SetBoolean(prefs::kUseCustomChromeFrame,
@@ -812,7 +812,7 @@
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_2, true);
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_3, true);
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   command_updater_.UpdateCommandEnabled(IDC_USE_SYSTEM_TITLE_BAR, true);
 #endif
 
