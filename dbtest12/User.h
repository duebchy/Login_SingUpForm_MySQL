#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "var.h"

class User {
	
	

private:
	int id = -1;
	int Score = 0;
	std::string Name;
	std::string password;
	std::string email;
public:
	//simple getters
	std::string getPassword(){
		return password;

	}
	std::string getEmail() {
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
	
	void setName(std::string s) {
		
		Name = s;
		
	}
	
	//getters------------------------------------------------------------------------------------------------------------------------
	void setScore(int n) {
		
		Score = n;
	}
	//...hzhz------------------------------------------------------------------------------------------------------------------------
	void setEmail(std::string s) {
		email = s;
	}
	void setPassword(std::string s) {
		password = s;
	}

};


struct table {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	
};
