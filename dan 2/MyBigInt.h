#ifndef _MY_BIG_INT_
#define _MY_BIG_INT_

#include <cstdint>
#include <iostream>
#include <cstring>

struct MyBigInt {

	friend MyBigInt operator+(const MyBigInt& lhs, const MyBigInt& rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyBigInt& mbi);

	friend bool operator<(const MyBigInt& lhs, const MyBigInt&rhs);
	friend bool operator<=(const MyBigInt& lhs, const MyBigInt&rhs);
	friend bool operator>(const MyBigInt& lhs, const MyBigInt&rhs);
	friend bool operator>=(const MyBigInt& lhs, const MyBigInt&rhs);
	friend bool operator==(const MyBigInt& lhs, const MyBigInt&rhs);
	friend bool operator!=(const MyBigInt& lhs, const MyBigInt&rhs);
	friend MyBigInt operator""_mbi(const char * str);

	MyBigInt(long long num = 0);
	// MyBigInt(const char* str);
	MyBigInt(const MyBigInt& other);
	MyBigInt& operator=(const MyBigInt& other);
	MyBigInt(MyBigInt&& other) noexcept;
	MyBigInt& operator=(MyBigInt&& other) noexcept;
	
	~MyBigInt(){ if(digits!=nullptr)delete[]digits;}
private:
	int_least8_t* digits = nullptr;
	int size = 0;
};



#endif
