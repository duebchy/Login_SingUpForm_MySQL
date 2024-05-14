#include <mysql.h>
#include <iostream>
#include <string>
#include "User.h"
#include "var.h"

table init() {
	table t;
	t.conn = mysql_init(0);
	t.conn = mysql_real_connect(t.conn, "localhost", "root", "123456", "testdb", 3307, NULL, 0);

	return t;

}
table t = init();


int ConnCheck() {
	
	q = query.c_str();
	return qstate = mysql_query(t.conn, q);
}


void showData() {
	query = "SELECT * FROM users";
	ConnCheck();
	if (!qstate) {
		t.res = mysql_store_result(t.conn);
		while (t.row = mysql_fetch_row(t.res)) {
			printf("ID: %s, Name: %s, Score: %s\n", t.row[0], t.row[1], t.row[2], t.row[3]);

		}
		mysql_close(t.conn);
	}

	else {
		std::cout << "Query failed" << mysql_error(t.conn) << std::endl;
	}
}



int addData(std::string name, int score, std::string password, std::string email, User user) {
	query = "INSERT INTO users (name, score, password, email) VALUES ('" + user.getName() + "', '" + std::to_string(user.getScore()) + "', '"+ +"', '"+ +"')";
	ConnCheck();

		if (!qstate) {
			std::cout << "Запись успешно добавлена." << std::endl;
		}
		else {
			std::cout << "Ошибка при добавлении записи: " << mysql_error(t.conn) << std::endl;
			return -1;
		}

	return 0;
}

/*std::string login_user(std::string email_, std::string password_, User user) {

	query = "SELECT * FROM users WHERE email = '" + email_ + "' AND password =  '" + password_ + "'";

	
	q = query.c_str();
	mysql_query(t.conn, q);
	if (!qstate) {
		
		
			user.login(t.row[2], t.row[3], t.row[1], atoi(t.row[4]));
			
			mysql_close(t.conn);
			return "";
		
	}
	else {
		return "Query failed";
	}
}

*/





int main() {
	std::string name = "";
	int score = 0;
	User user;
	setlocale(LC_ALL, "RU");
	
	int Score = 0;
	std::string Name = "";
	std::string password = "";
	std::string email = "";

	if (t.conn) {
		
		std::string email_ = "aboba@nub.ru";
		std::string password_ = "2281337";
		
		std::string username = user.getName();
		std::cout << username << std::endl;

		query = "SELECT * FROM users WHERE email = '" + email_ + "' AND password = '" + password_ + "'";
		ConnCheck();
		if (!qstate) {
			t.res = mysql_store_result(t.conn);
			while (t.row = mysql_fetch_row(t.res)) {
				//printf("ID: %s, email: %s, username: %s, password: %s, score %s\n", t.row[0], t.row[1], t.row[2], t.row[3], t.row[4]);
				email = t.row[1];
				Name = t.row[2];
				password = t.row[3];
				Score = atoi(t.row[4]);
			}
			
		}

		else {
			std::cout << "Query failed" << mysql_error(t.conn) << std::endl;
		}
		std::cout << email << std::endl;
		std::cout << Name << std::endl;
		std::cout << password << std::endl;
		std::cout << Score << std::endl;
		/*
		query = "SELECT * FROM users WHERE email = '" + email_ + "' AND password =  '" + password_ + "';";


		q = query.c_str();
		mysql_query(t.conn, q);
		if (!qstate) {


			user.login(t.row[2], t.row[3], t.row[1], atoi(t.row[4]));

			mysql_close(t.conn);
			

		}
		
		*/
		
		

		mysql_close(t.conn);
	}
	else {
		puts("connection fail!");
	}

	return 0;

}