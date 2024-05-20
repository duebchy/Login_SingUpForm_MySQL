#include <mysql.h>
#include <iostream>
#include <string>
#include "User.h"
#include "var.h"

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
	
	 
	user.login(Name, password, email, Score);
	return "";
}
//INSERT INTO users (email, username, password, score) VALUES ('example@ex.com', 'name', '123', 123);
std::string singUp() {
	std::string Name = "", password = "", email = "", temp = "jbsafgb23jbksd14asf@kljnsadlkn123gasgag*YSAVNnasja)S(AFknskagfnI@#N";
	int Score = -1;
	std::cout << "enter email: " << std::endl;
	std::cin >> email;
	std::cout << "enter username" << std::endl;
	std::cin >> Name;
	while(temp != password){
		std::cout << "enter password" << std::endl;
		std::cin >> password;
		std::cout << "confirm password" << std::endl;
		std::cin >> temp;
		if (temp != password) {
			std::cout << "passwords do not match" << std::endl;
		}
	}
	std::cout << "enter score: " << std::endl;
	std::cin >> Score;

	query = "INSERT INTO users (email, username, password, score) VALUES ('" + email + "', '" + Name + "', '" + password + "', "+ std::to_string(Score) + ")";
	ConnCheck();
	if (!qstate) {
		user.login(Name, password, email, Score);
	}
	
	return "abasd";
	
	

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
	else if (command[0] == '/' && command[1] == 's' && command[2] == 'i' && command[3] == 'n' && command[4] == 'g') {
		return singUp();
	}
	
	return "unknown command";
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
		mysql_close(t.conn);
		

		
	}
	else {
		puts("connection fail!");
	}
	
	return 0;

}