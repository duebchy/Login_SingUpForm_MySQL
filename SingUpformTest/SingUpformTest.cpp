#include "pch.h"
#include "CppUnitTest.h"
class User {



private:
	int id = -1;
	int Score = 0;
	std::string Name;
	std::string password;
	std::string email;
public:
	//simple getters
	std::string getPassword() {
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

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SingUpformTest
{
	TEST_CLASS(SingUpformTest)
	{
	public:
		
		TEST_METHOD(TestMethodGetName)
		{
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			Assert::IsTrue(user.getName() == "admin");
		}
		TEST_METHOD(TestMethodGetPassword)
		{
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			Assert::IsTrue(user.getPassword() == "123456");
		}
		TEST_METHOD(TestMethodGetEmail) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			Assert::IsTrue(user.getEmail() == "test@admin.com");
		}
		TEST_METHOD(TestMethodGetScore) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			Assert::IsTrue(user.getScore() == 228);

		}



		TEST_METHOD(TestMethodSetName) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			user.setName("test@tes.test");
			Assert::IsTrue(user.getName() == "test@tes.test");
		}
		TEST_METHOD(TestMethodSetPassword) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			user.setPassword("111");
			Assert::IsTrue(user.getPassword() == "111");
		}
		TEST_METHOD(TestMethodSetEmail) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			user.setEmail("test@test.test");
			Assert::IsTrue(user.getEmail() == "test@test.test");
		}
		TEST_METHOD(TestMethodSetScore) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228);
			user.setScore(1);
			Assert::IsTrue(user.getScore() == 1);

		}
	};
}
