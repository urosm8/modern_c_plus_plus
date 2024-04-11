#include "MyBigInt.h"

#include <iostream>

MyBigInt operator+(const MyBigInt& lhs, const MyBigInt& rhs)
{
	MyBigInt ret;
	const MyBigInt& longerArg = (lhs.size < rhs.size) ? rhs : lhs;
	const MyBigInt& shorterArg = (lhs.size < rhs.size) ? lhs : rhs;
	ret.digits = new int_least8_t[longerArg.size + 1];
	int_least8_t reminder = 0;
	for (int i = 0; i < shorterArg.size; i++) {
		int_least8_t tempSum = longerArg.digits[i] + shorterArg.digits[i] + reminder;
		ret.digits[i] = (tempSum > 9) ? tempSum - 10 : tempSum;
		reminder = (tempSum > 9) ? 1 : 0;
	}
	for (int i = shorterArg.size; i < longerArg.size; i++) {
		int_least8_t tempSum = longerArg.digits[i] + reminder;
		ret.digits[i] = (tempSum > 9) ? tempSum - 10 : tempSum;
		reminder = (tempSum > 9) ? 1 : 0;
	}
	if (reminder == 0) {
		ret.size = longerArg.size;
	} else {
		ret.size = longerArg.size + 1;
	}
	ret.digits[longerArg.size] = reminder;
	return ret;
}

// Овде написати следећу функцију:
MyBigInt fibo(int n){
	if(n==0) return std::move(MyBigInt(0));
	if(n==1) return std::move(MyBigInt(1));


	MyBigInt f0{0},f1{1};

	for (int i = 2; i <= n; i++)
	{
		MyBigInt temp = f1;
		f1= f1 + f0;
		f0= std::move(temp);
		
	}

	return std::move(f1);
	
}

MyBigInt operator""_mbi(const char * str){
	MyBigInt mbi;
	mbi.size=std::strlen(str);
	mbi.digits = new int_least8_t[mbi.size];
	for (auto i = 0; i < mbi.size; i++)
	{
		mbi.digits[i]= static_cast<int_least8_t>(int(str[mbi.size-1-i]-'0'));
	}
	
	return std::move(mbi);
}

int main()
{
	MyBigInt k{123};
	std::cout << k << std::endl;
	k = fibo(9);
	std::cout << k << std::endl;
	k = k + 5;
	std::cout << k << std::endl;
	k = 7 + fibo(11);
	std::cout << k << std::endl;
	MyBigInt l = fibo(300);
	if (l != 222232244629420445529739893461909967206666939096499764990979600_mbi) {
		std::cout << "Greska!" << std::endl;
		return 1;
	}
	std::cout << l << std::endl;
	{
		MyBigInt m = l;
		std::cout << m << std::endl;
	}
	std::cout << l << std::endl;
	{
		MyBigInt n = std::move(l);
		std::cout << n << std::endl;
	}
	return 0;
}
