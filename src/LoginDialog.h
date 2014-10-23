/* 
 * File:   LoginDialog.h
 * Author: Dreamszhu
 *
 * Created on October 23, 2014, 9:53 AM
 */

#ifndef LOGINDIALOG_H
#define	LOGINDIALOG_H

#include <gtkmm/builder.h>
#include <gtkmm/dialog.h>

class LoginDialog : public Gtk::Dialog {
public:
	LoginDialog();
	LoginDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
	virtual ~LoginDialog();

protected:
	void onLoginButtonClick();

	Glib::RefPtr<Gtk::Builder> m_builder;
	Gtk::Button* m_loginButton;
private:

};

#endif	/* LOGINDIALOG_H */

