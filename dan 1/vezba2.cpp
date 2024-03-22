#include <iostream>
// Овде написати следећу функцију:
constexpr int fibo(int n) noexcept{ // OPTIMALNIJA IMPLEMENTACIJE JE PREKO MATRICNOG MNOZENJA
	if(n==0)return 0; // ILI PREKO SPECIJALNIH FORMULA
	if(n==1)return 1;
	int  f0 = 0;
	int  f1 = 1;

	for (int i = 2; i <= n; i++)
	{
		f1+=f0;
		f0=f1-f0;
	}

	return f1;
}


int main()
{
	static_assert(fibo(7) == 13, "Greska!");
	const int k = fibo(9);
	const int k1 = fibo(10);
	const int k2 = fibo(11);
	std::cout << k << std::endl;
	std::cout << k1 << std::endl;
	std::cout << k2 << std::endl;
	// constexpr int l = fibo(300); // 300. Фибоначијев број је превелик за int
	// ukoliko ukljucimo komentar iznad, vec sam IDE podvlaci i upozorava da se prevazilazi opseg za INT
}
