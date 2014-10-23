/* 
 * File:   LoginDialog.cpp
 * Author: Dreamszhu
 * 
 * Created on October 23, 2014, 9:53 AM
 */

#include "LoginDialog.h"

LoginDialog::LoginDialog() {
}

LoginDialog::LoginDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder) :
Gtk::Dialog(cobject),
m_builder(builder),
m_loginButton(NULL) {
	m_builder->get_widget("loginbutton", m_loginButton);
	if (m_loginButton) {
		m_loginButton->signal_clicked().connect(sigc::mem_fun(*this, &LoginDialog::onLoginButtonClick));
	}
}

LoginDialog::~LoginDialog() {
}

void LoginDialog::onLoginButtonClick() {
	this->response(Gtk::RESPONSE_YES);
}

