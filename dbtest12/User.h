#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "var.h"
#include "cppconn/prepared_statement.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
class User {
	
	

private:
	int Score = 0;
	std::string Name;
	std::string password;
	std::string email;
public:
	//simple getters
	std::string Gpassword(){
		return password;

	}
	std::string Gemail() {
		return email;
	}
	std::string getName() {
		return Name;
	}
	int getScore() {
		return Score;
	}
	void login(std::string _name, std::string _password, std::string _email, int _score) {
		Name = _name;
		password = _password;
		email = _email;
		Score = _score;
	}
public:
	
	std::string setName(std::string s) {
		if (s.empty()) return "Name empty!";
		Name = s;
		
	}
	
	//getters------------------------------------------------------------------------------------------------------------------------
	std::string setScore(int n) {
		if (n < 0) return "Score out of range: score < 0";
		Score = n;
	}
	//...hzhz------------------------------------------------------------------------------------------------------------------------
	std::string setEmail(std::string s) {
		email = s;
	}
	std::string setPassword(std::string s) {
		password = s;
	}

};


struct table {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	
};
