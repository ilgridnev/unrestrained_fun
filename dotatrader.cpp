#include <iostream>
 
#include <cstring>

//формат ввода данных: количество типов предметов существующих на рынке
//далее построчно вводятся рецепты для каждого из предметов, записанные в количествах других требуемых предметов
//commision отдельно для каждого рецепта вводятся цены реализации прописанного рецепта
//coin выбор предмета, через который мы будем выражать цены
//выбор предмета, цену которого мы считаем

// 0 0 0 0 0         - coin
// 4 0 0 0 1
// 2 0 0 5 1         - target
// 0 2 0 0 1

// correct ans - 58

using namespace std;

char names [100] [100];

int costs [100] [100];

int commision [100];

int trader(int number_of_item, int x, int coin){
	int y = number_of_item;
	int sum = 0;
	for(int i = 0; i < x; i++){
		if (costs[y][i] != 0 && i != coin){
			int delta = trader(i, x, coin);
			sum = sum + delta*costs[y][i];
		}
		else{
			if (i == coin){
				sum = sum + costs[y][i];
			}
		}
	}
	sum = sum + commision[y];
	return sum;
}

int main(){
	
cout << "How many items?" << '\n';

int x;

cin >> x;

for (int i = 0; i < x; i++){
	cout << "number of item: " << i <<'\n'<< "enter the costs from 0 to " << x << " with spaces" << '\n';
	for (int j = 0; j < x; j ++){
		cin >> costs[i][j];
	}
	cout << "enter the commision "<< '\n';
	cin >> commision[i];
}

cout << "the number of coin? " << '\n';

int coin;

cin >> coin;

cout << "the question is ..." << '\n';

int q;

cin >> q;

cout << "How many coins do you have for me?" << '\n';

int total_coins;

cin >> total_coins;

int cost = trader(q, x, coin);

cout << "the cost is " << cost << " coins" << '\n';

cout << "You can make " << total_coins/cost << " item(s) of this type";

return 0;
 
}