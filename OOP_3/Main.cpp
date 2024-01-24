#include <iostream>
#include <string>



class Cassa {
private:
	int money_;

public:
	Cassa() :money_(0) {//при создании объекта по умолчанию заполняем нулем его значение
		money_ = 0;
	}

	int CurrentMoney() {
		return money_; //сколько денег на данный момент в кассе
	}

	void CashIn(int money) {
		this->money_ += money;//закидываем деньги в кассу (оплата пришла)
	}

	void CashOut(int money) {
		if (money > money_) {
			std::cerr << "Недостаточно средств!\n";    //cerr - тоже что и cout, используется для возврвщения ошибок
			return ;
		}
		this->money_ -= money;//money_-мы забрали из кассы, money - остаток в кассе
	}

	int Exchenge(int ticket, int money) {//Exchenge - метод проведения денежного обмена
		if (money < ticket) {
			std::cerr << "Недостаточно средств для покупки. \n";
			return money;//возврат денег покупателю
		}
		if (money_ < money - ticket) {   //ticket - чек стоимости покупки
			std::cerr << "Нет денег для сдачи в кассе. \n";
			return money;
		}
		money_ += ticket;
		return money - ticket;//возвращаем сдачу
	}

};


int main() {
	system("chcp 1251>nul");
	int n;

	Cassa var1;
	Cassa var2;


	var1.CashIn(1000);
	std::cout << "Первая касса имеет " << var1.CurrentMoney() << '\n';
	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';

	var1.CashOut(2000);
	std::cout << "Первая касса выдает " << var1.CurrentMoney() << '\n';
	var1.CashOut(200);
	std::cout << "Первая касса выдает " << var1.CurrentMoney() << '\n';

	var2.CashOut(10);
	std::cout << "Первая касса выдает " << var2.CurrentMoney() << '\n';
	var2.CashOut(0);
	std::cout << "Первая касса выдает " << var2.CurrentMoney() << '\n';

	//проверяем кассу
	int change = 0;//создаем чтобы знать сколько денег нам вернули
	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	change = var2.Exchenge(100, 20);
	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача -> " << change << '\n';

	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	change = var2.Exchenge(100, 120);
	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача -> " << change << '\n';

	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	change = var2.Exchenge(100, 100);
	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача -> " << change << '\n';

	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	change = var2.Exchenge(10, 20);
	std::cout << "Вторая касса имеет " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача -> " << change << '\n';



	return 0;
}

