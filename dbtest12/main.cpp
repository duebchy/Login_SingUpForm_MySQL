#include <mysql.h>
#include <iostream>
#include <string>
#include "User.h"
#include "var.h"
#include "cppconn/prepared_statement.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
User user;

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
std::string logQuery(std::string email_, std::string password_) {
	query = "SELECT * FROM users WHERE email = '" + email_ + "' AND password = " + password_ + "'";
	
	
	ConnCheck();
	
	
	int Score = -1;
	std::string Name = "";
	std::string password = "";
	std::string email = "";
	if (!qstate) {
		t.res = mysql_store_result(t.conn);
		while (t.row = mysql_fetch_row(t.res)) {
			
			email = t.row[1];
			Name = t.row[2];
			password = t.row[3];
			Score = atoi(t.row[4]);
		}
		
	}
	
	else {
		std::cout << "Query failed" << mysql_error(t.conn) << std::endl;
	}
	if (Name == "") {
		return "User doesn't exist";
	}
	mysql_close(t.conn);
	query.clear();
	user.login(Name, password, email, Score);
	return "";
}
User& initClass() {
	User user;
	return user;
}
std::string parse(std::string& command) {//['/', 'l', 'o', 'g', 'i', 'n', ' ', ]
	std::string val1 = "";
	std::string val2 = "";							//  0    1    2    3    4    5    6   7
	if (command[0] == '/' && command[1] == 'l' && command[2] == 'o' && command[3] == 'g') {
		
		
		int cnt = 7;
		while (command[cnt] != ' ') {
			val1 += command[cnt];
			cnt++;
		}
		while (cnt < command.length()) {
			cnt++;
			val2 += command[cnt];
		}

		return logQuery(val1, val2);
	}
}



int main() {
	std::string email_ = "";
	std::string pass = "";
	std::string name = "";
	int score = 0;
	std::string err = "";
	setlocale(LC_ALL, "RU");
	std::string command = "";
	
	
	if (t.conn) {
		
		int Score = 0;
		std::string Name = "";
		std::string password = "";
		std::string email = "";

		
		
		while (command != "/exit") {
			std::getline(std::cin, command);
			err = parse(command);

			
			if (err.empty()) {
				std::cout << "Name: " << user.getName() << ", Score: " << user.getScore() << ", Email: " << user.Gemail() << ", Password: " << user.Gpassword() << std::endl;
			}
			else {
				std::cout << err << std::endl;
			}
		}
		
		

		
	}
	else {
		puts("connection fail!");
	}
	
	return 0;

}