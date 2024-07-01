#pragma once
#include <mysql.h>
#include <string>
std::string query; //require to database
struct table {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

};