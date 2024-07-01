#pragma once

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
	int getId() {
		return id;
	}
	void login(std::string _name, std::string _password, std::string _email, int _score, int _id) {
		Name = _name;
		password = _password;
		email = _email;
		Score = _score;
		id = _id;
	}
public:
	void setId(int id_) {
		id = id_;
	}
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



