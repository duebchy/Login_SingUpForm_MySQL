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
void help() {
	std::cout << "/sing - set up a new account" << std::endl;
	std::cout << "/login - login in a existing account (/login example@email.com password)" << std::endl;
	std::cout << "/cp - change password, login in acoount (/cp newpassword)" << std::endl;
	std::cout << "/cn - change name, login in account(/cn newname)" << std::endl;
	std::cout << "/exit - exit application" << std::endl;
	std::cout << "/show - show data of logged user" << std::endl;
	std::cout << "/help - show list of commands" << std::endl;
}


std::string changeName(std::string s) {
	query = "UPDATE users SET username = '" + s + "' WHERE username = '" + user.getName() + "'";
	ConnCheck();
	if (!qstate) {
		user.setName(s);
		return "";
	}
	else {
		return "error";
	}
}
std::string changePassword(std::string s) {
	query = "UPDATE users SET password = '" + s + "' WHERE username = '" + user.getName() + "'";
	ConnCheck();
	if (!qstate) {
		user.setPassword(s);
		return "";
	}
	else {
		return "error";
	}
}

int addData(std::string name, int score, std::string password, std::string email, User user) {
	query = "INSERT INTO users (name, score, password, email) VALUES ('" + user.getName() + "', '" + std::to_string(user.getScore()) + "', '"+ +"', '"+ +"')";
	ConnCheck();

		if (!qstate) {
			std::cout << "������ ������� ���������." << std::endl;
		}
		else {
			std::cout << "������ ��� ���������� ������: " << mysql_error(t.conn) << std::endl;
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
		return "";
	}
	
	return "error";
	
	

}
void showdata() {
	
	std::cout << "Name: " << user.getName() << ", Score: " << user.getScore() << ", Email: " << user.getEmail() << ", Password: " << user.getPassword() << std::endl;
	
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
	else if (command[0] == '/' && command[1] == 's' && command[2] == 'h', command[3] == 'o') {
		showdata();
	}
	else if (command[0] == '/' && command[1] == 'c' && command[2] == 'p') {
		int cnt = 4;
			while (cnt < command.length()) {
				
				val1 += command[cnt];
				cnt++;
		}
		return changePassword(val1);
	}
	else if (command[0] == '/' && command[1] == 'h' && command[2] == 'e' && command[3] == 'l' && command[4] == 'p') {
		help();
	}
	else if (command[0] == '/' && command[1] == 'c' && command[2] == 'n') {
		int cnt = 4;
		while (cnt < command.length()) {
			val1 += command[cnt];
			cnt++;
		}
		changeName(val1);
	}
	else if(command != "") {
		return "unknown command";
	}
	return "";
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

		help();
		
		while (true) {
			
			std::getline(std::cin, command);
			if (command == "/exit") {
				break;
			}
			err = parse(command);

			
			
			
			std::cout << err << std::endl;
			
			
		}
		mysql_close(t.conn);
		

		
	}
	else {
		puts("connection fail!");
	}
	
	return 0;

}