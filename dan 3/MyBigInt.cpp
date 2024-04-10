#include "MyBigInt.h"

std::ostream& operator<<(std::ostream &os, const MyBigInt &mbi)
{   
    int i = mbi.size-1;
    while (i>=0)
    {
        std::cout << static_cast<int>(mbi.digits[i--]);
    }
    return os;
}

MyBigInt::MyBigInt(long long num)
{
    this->size = std::to_string(num).size();
    this->digits = std::make_unique<int_least8_t[]>(this->size);
    for (auto i = 0; i < this->size; ++i)
    {
        this->digits[i] = static_cast<int_least8_t>(num % 10);
        num /= 10;
    }
}

MyBigInt::MyBigInt(const MyBigInt &other) : size(other.size)
{
    this->digits = std::make_unique<int_least8_t[]>(other.size);
    std::copy(other.digits.get(),other.digits.get()+other.size,this->digits.get());
}

MyBigInt& MyBigInt::operator=(const MyBigInt &other)
{
    if (this != &other)
    {
        this->digits.reset();
        this->size = other.size;
        this->digits = std::make_unique<int_least8_t[]>(this->size);
        std::copy(other.digits.get(),other.digits.get()+other.size,this->digits.get());
    }
    return *this;
}

MyBigInt::MyBigInt(MyBigInt &&other) noexcept : size(other.size)
{   
    this->digits = std::move(other.digits);
    other.size = 0;
    other.digits = nullptr;
}

MyBigInt& MyBigInt::operator=(MyBigInt &&other) noexcept
{
    if (this != &other)
    {
        this->digits.reset();
        this->size = other.size;
        this->digits = std::move(other.digits);
        other.size = 0;
        other.digits = nullptr;
    }
    return *this;
}

bool operator==(const MyBigInt &lhs, const MyBigInt &rhs)
{
    if (lhs.size != rhs.size){
        std::cout<<"LHS = "<<lhs.size<<" RHS = "<<rhs.size<<std::endl;
        return false;}

    for (int i = 0; i < lhs.size; ++i)
        if (lhs.digits[i] != rhs.digits[i])
            return false;
    return true;
}

bool operator!=(const MyBigInt &lhs, const MyBigInt &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const MyBigInt &lhs, const MyBigInt &rhs)
{
    if (lhs.size != rhs.size)
        return lhs.digits[0] < rhs.digits[0];

    for (int i = 0; i < lhs.size; i++)
    {
        if (lhs.digits[i] != rhs.digits[i])
            return lhs.digits[i] < rhs.digits[i];
    }
    return false;
}

bool operator>(const MyBigInt &lhs, const MyBigInt &rhs)
{
    return rhs < lhs;
}

bool operator<=(const MyBigInt &lhs, const MyBigInt &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const MyBigInt &lhs, const MyBigInt &rhs)
{
    return !(lhs < rhs);
}

