/* 
 * File:   main.cpp
 * Author: Dreamszhu
 *
 * Created on October 23, 2014, 11:36 AM
 */

#include <cstdlib>
#include <gtkmm.h>

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

	builder->get_widget_derived("logindialog", loginDialog);

	if (loginDialog) {
		loginDialog->set_title("登錄");
		loginDialog->set_modal(true);

		int ret = loginDialog->run();
		
		if (ret == Gtk::RESPONSE_YES) {
			loginDialog->close();

			builder->add_from_file("ui/main.glade");

			builder->get_widget("mainwindow", mainWindow);
			
			app->run(*mainWindow);
		}
	}

	delete loginDialog;
	delete mainWindow;

	return 0;
}

