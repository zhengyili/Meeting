/* 
 * File:   main.cpp
 * Author: Dreamszhu
 *
 * Created on October 23, 2014, 11:36 AM
 */

#include <cstdlib>
#include <gtkmm.h>
#include <webkit/webkit.h>

#include "LoginDialog.h"

/*
 * 
 */
int main(int argc, char** argv) {
	
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.myleft.meeting");
	
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();

	builder->add_from_file("ui/login.glade");

	LoginDialog* loginDialog = NULL;
	Gtk::ApplicationWindow* mainWindow = NULL;
	Gtk::ScrolledWindow* webScrolledWindow = NULL;
	WebKitWebView *webView = NULL;

	builder->get_widget_derived("logindialog", loginDialog);

	if (loginDialog) {
		loginDialog->set_title("登錄");
		loginDialog->set_modal(true);

		int ret = loginDialog->run();
		
		if (ret == Gtk::RESPONSE_YES) {
			loginDialog->close();

			builder->add_from_file("ui/main.glade");

			builder->get_widget("mainwindow", mainWindow);
			
			if (mainWindow) {
				builder->get_widget("webscrolledwindow", webScrolledWindow);
				if (webScrolledWindow) {
					webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
					g_object_set(webkit_web_view_get_settings(webView), "auto-resize-window", TRUE, NULL);
					webScrolledWindow->add(*(Glib::wrap(GTK_WIDGET(webView))));
					
					webkit_web_view_load_uri(webView, "https://github.com/dreamsxin/Meeting");
					webScrolledWindow->show_all();
					
				}
				app->run(*mainWindow);
			}
		}
	}

	return 0;
}

