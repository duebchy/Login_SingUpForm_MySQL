#include "pch.h"
#include "CppUnitTest.h"
#include "../dbtest12/User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SingUpformTest
{
	TEST_CLASS(SingUpformTest)
	{
	public:
		
		TEST_METHOD(TestMethodGetName)
		{
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			Assert::IsTrue(user.getName() == "admin");
		}
		TEST_METHOD(TestMethodGetPassword)
		{
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			Assert::IsTrue(user.getPassword() == "123456");
		}
		TEST_METHOD(TestMethodGetEmail) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			Assert::IsTrue(user.getEmail() == "test@admin.com");
		}
		TEST_METHOD(TestMethodGetScore) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			Assert::IsTrue(user.getScore() == 228);

		}
		TEST_METHOD(TestMethodGetId) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			Assert::IsTrue(user.getId() == 1);
		}


		TEST_METHOD(TestMethodSetName) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			user.setName("test@tes.test");
			Assert::IsTrue(user.getName() == "test@tes.test");
		}
		TEST_METHOD(TestMethodSetPassword) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			user.setPassword("111");
			Assert::IsTrue(user.getPassword() == "111");
		}
		TEST_METHOD(TestMethodSetEmail) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			user.setEmail("test@test.test");
			Assert::IsTrue(user.getEmail() == "test@test.test");
		}
		TEST_METHOD(TestMethodSetScore) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			user.setScore(1);
			Assert::IsTrue(user.getScore() == 1);

		}
		TEST_METHOD(TestMethodSetId) {
			User user;
			user.login("admin", "123456", "test@admin.com", 228, 1);
			user.setId(100);
			Assert::IsTrue(user.getId() == 100);
		}
	};
}
