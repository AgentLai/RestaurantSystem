#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <conio.h>

#define SST 0.06 //Sales and Service Tax
#define PRICE_1 0.50 //Chinese Teh & Air suam
#define PRICE_2 2.50 //Kopi O & Nescafe
#define PRICE_3 3.00 //Milo
#define PRICE_4 4.50 //Nasi Lemak
#define PRICE_5 7.00 //Nasi Goreng Ayam, Nasi Goreng Mamak, Nasi Goreng Kampung
#define PRICE_6 8.00 //Nasi Goreng Pattaya

using namespace std;

//Declaration of variables and initialization of prices
int user_choice; 

//This is the original input from the user
int order_quantity;

//These are to store the original input from the user
int order_quantity_1, order_quantity_2, order_quantity_3, order_quantity_4, order_quantity_5; 
int order_quantity_6, order_quantity_7, order_quantity_8, order_quantity_9, order_quantity_10;

//These are to store the total prices for each meal to be totaled
double order_price_1, order_price_2, order_price_3, order_price_4, order_price_5;
double order_price_6, order_price_7, order_price_8, order_price_9, order_price_10;

//These are the sales amount for foods, drinks and the total of both of them
double food_sales, drink_sales, pre_tax_sales, post_tax_sales;

//The total SST amount collected by the restaurant
double sales_and_service_tax;

//The amount the user pays
double payment, payment_2, change;

//The cost of the food the user chose incl SST
double price_of_item;
/**
 * This function sets the precision and forces it to 2 decimal places (0.00) then gets the amount 
 * @param price The price is to be converted to string
 * @return The price in string format with the prefix in RM
 */
string get_price_str(double price) {
	ostringstream stream;
	stream << fixed << setprecision(2) << price;
	string price_str = stream.str();
	price_str = "RM" + price_str;

	return price_str;
}

//This function serves to clear the display of the program to keep things clean and tidy
void clear_screen() {

	system("cls");
}

void print_food_logo() {
 cout << "_____ ___   ___  ____       _    _   _ ____                 \n";
 cout << "|  ___/ _ \\ / _ \\|  _ \\     / \\  | \\ | |  _ \\                \n";
 cout << "| |_ | | | | | | | | | |   / _ \\ |  \\| | | | |               \n";
 cout << "|  _|| |_| | |_| | |_| |  / ___ \\| |\\  | |_| |               \n";
 cout << "|_|__ \\___/ \\___/|____/_ /_/___\\_\\_|_\\_|____/___ _   _ _   _ \n";
 cout << "|  _ \\|  _ \\|_ _| \\ | | |/ / ___|  |  \\/  | ____| \\ | | | | |\n";
 cout << "| | | | |_) || ||  \\| | ' /\\___ \\  | |\\/| |  _| |  \\| | | | |\n";
 cout << "| |_| |  _ < | || |\\  | . \\ ___) | | |  | | |___| |\\  | |_| |\n";
 cout << "|____/|_| \\_\\___|_| \\_|_|\\_\\____/  |_|  |_|_____|_| \\_|\\___/ \n";
                                                              
}

void print_main_menu_logo() {
 cout <<" __  __       _         __  __                  \n";
 cout <<"|  \\/  |     (_)       |  \\/  |                 \n";
 cout <<"| \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _ \n";
 cout <<"| |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |\n";
 cout <<"| |  | | (_| | | | | | | |  | |  __/ | | | |_| |\n";
 cout << "|_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|\n";                                               
}

void print_restaurant_logo() {

  cout <<"    __          __    _                                _                     \n";
  cout <<"    \\ \\        / /   | |                              | |                    \n";
  cout <<"     \\ \\  /\\  / /___ | |  ___  ___   _ __ ___    ___  | |_  ___              \n";
  cout <<"      \\ \\/  \\/ // _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\ | __|/ _ \\             \n";
  cout <<"       \\  /\\  /|  __/| || (__| (_) || | | | | ||  __/ | |_| (_) |            \n";
  cout <<"        \\/  \\/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|  \\__|\\___/             \n";
  cout <<" _    _   _____   _____             _                                    _   \n";
  cout <<"| |  | | / ____| |  __ \\           | |                                  | |  \n";
  cout <<"| |__| || (___   | |__) | ___  ___ | |_  __ _  _   _  _ __  __ _  _ __  | |_ \n";
  cout <<"|  __  | \\___ \\  |  _  / / _ \\/ __|| __|/ _` || | | || '__|/ _` || '_ \\ | __|\n";
  cout <<"| |  | | ____) | | | \\ \\|  __/\\__ \\| |_| (_| || |_| || |  | (_| || | | || |_ \n";
  cout <<"|_|  |_||_____/  |_|  \\_\\\___||___/ \\__|\\__,_| \\__,_||_|   \\__,_||_| |_| \\__|\n";
  cout <<"      _    _                                                                 \n";
  cout <<"     | |  | |                                                                \n";
  cout <<"     | |__| |  ___ __      __  _ __ ___    __ _  _   _  __      __ ___       \n";
  cout <<"     |  __  | / _ \\\ \\ /\\ / / | '_ ` _ \\  / _` || | | | \\ \\ /\\ / // _ \\      \n";
  cout <<"     | |  | || (_) |\\ V  V /  | | | | | || (_| || |_| |  \\ V  V /|  __/      \n";
  cout <<"     |_|  |_| \\___/  \\_/\\_/   |_| |_| |_| \\__,_| \\__, |   \\_/\\_/  \\___|      \n";
  cout <<"     _                     __                     __/ | _            ___     \n";
  cout <<"    | |                   / _|                   |___/ (_)          |__ \\    \n";
  cout <<"    | |__    ___    ___  | |_   ___   ___  _ __ __   __ _   ___  ___   ) |   \n";
  cout <<"    | '_ \\  / _ \\  / _ \\ |  _| / __| / _ \\| '__|\\ \\ / /| | / __|/ _ \\ / /    \n";
  cout <<"    | |_) ||  __/ | (_) || |   \\__ \\|  __/| |    \\ V / | || (__|  __/|_|     \n";
  cout <<"    |_.__/  \\___|  \\___/ |_|   |___/ \\___||_|     \\_/  |_| \\___|\\___|(_)     \n";
                                                                               
}

void print_sales_report_logo() {
 cout << " _____          _____ _  __     __        _____         _      ______  _____  \n";
 cout << "|  __ \\   /\\   |_   _| | \\ \\   / /       / ____|  /\\   | |    |  ____|/ ____| \n";
 cout << "| |  | | /  \\    | | | |  \\ \\_/ /       | (___   /  \\  | |    | |__  | (___   \n";
 cout << "| |  | |/ /\\ \\   | | | |   \\   /         \\___ \\ / /\\ \\ | |    |  __|  \\___ \\  \n";
 cout << "| |__| / ____ \\ _| |_| |____| |          ____) / ____ \\| |____| |____ ____) | \n";
 cout << "|_____/_/    \\_\\_____|______|_|___   ___|_____/_/____\\_\\______|______|_____/  \n";
 cout << "              |  __ \\|  ____|  __ \\ / __ \\|  __ \\__   __|                     \n";
 cout << "              | |__) | |__  | |__) | |  | | |__) | | |                        \n";
 cout << "              |  _  /|  __| |  ___/| |  | |  _  /  | |                        \n";
 cout << "              | | \\ \\| |____| |    | |__| | | \\ \\  | |                        \n";
 cout << "              |_|  \\_\\______|_|     \\____/|_|  \\_\\ |_|                        \n";                                                                             
}

void print_ending_screen_logo() {
	
	clear_screen();
	cout<<" _____  _  _    _    _  _  _  __     __   __ ___   _   _                 \n";
	cout<<"|_   _|| || |  /_\\  | \\| || |/ /     \\ \\ / // _ \\ | | | |                \n";
	cout<<"  | |  | __ | / _ \\ | .` || ' <       \\ V /| (_) || |_| |                \n";
	cout<<"  |_|  |_||_|/_/ \\_\\|_|\\_||_|\\_\\       |_|  \\___/  \\___/                 \n";
	cout<<" ___  ___   ___       _   _  ___  ___  _  _   ___                        \n";
	cout<<"| __|/ _ \\ | _ \\     | | | |/ __||_ _|| \\| | / __|                       \n";
	cout<<"| _|| (_) ||   /     | |_| |\\__ \\ | | | .` || (_ |                       \n";
	cout<<"|_|  \\___/ |_|_\\      \\___/ |___/|___||_|\\_| \\___|                       \n";
	cout<<"  ___   _   _  ___      ___   ___   ___  _____ __      __ _    ___  ___ \n";
	cout<<" / _ \\ | | | || _ \\    / __| / _ \\ | __||_   _|\\ \\    / //_\\  | _ \\| __|\n";
	cout<<"| (_) || |_| ||   /    \\__ \\| (_) || _|   | |   \\ \\/\\/ // _ \\ |   /| _| \n";
	cout << " \\___/  \\___/ |_|_\\    |___/ \\___/ |_|    |_|    \\_/\\_//_/ \\_\\|_|_\\|___|\n";
                                                                      
}

void food_drinks_menu() {
	clear_screen();
	print_food_logo();
	cout << "\n";
	cout << "1 Nasi Lemak\t\t\t" << get_price_str(PRICE_4) << "\n";
	cout << "2 Nasi Goreng Ayam\t\t" << get_price_str(PRICE_5) << "\n";
	cout << "3 Nasi Goreng Pattaya\t\t" << get_price_str(PRICE_6) << "\n";
	cout << "4 Nasi Goreng Mamak\t\t" << get_price_str(PRICE_5) << "\n";
	cout << "5 Nasi Goreng Kampung\t\t" << get_price_str(PRICE_5) << "\n";
	cout << "6 Air Suam\t\t\t" << get_price_str(PRICE_1) << "\n";
	cout << "7 Chinese Teh\t\t\t" << get_price_str(PRICE_1) << "\n";
	cout << "8 Kopi O\t\t\t" << get_price_str(PRICE_2) << "\n";
	cout << "9 Milo\t\t\t\t" << get_price_str(PRICE_3) << "\n";
	cout << "10 Nescafe\t\t\t" << get_price_str(PRICE_2) << "\n";

}

/**
 * This function serves to check if the user input is a valid option
 * @param min The minimum integer the user inputs 
 * @param max The maximum integer the user inputs
 * @param choice The choice the user actually enters
 * @return choice This will return the user's choice to the other blocks of code without changing the value
 * @return -1 This will return -1 to the other blocks of code which will trigger the condition for the do while loop
 *			  and not allow the user to proceed
 */
int validate_choice(int min, int max, int choice) {
	if (choice >= min && choice <= max) {
		return choice;
	}
	else {
		cout << "\n";
		cout << "Invalid input. Please enter again.\n\n\n";
		return -1;
	}
}

/**
 * This function serves to get the user's choice for the menu
 * @param message 
 * @return The price in string format with the prefix in RM
 */
int get_menu_choice(int min, int max, string message) {
	cout << "\n"; 
	cout << message;
	int user_choice;
	cin >> user_choice;
	return validate_choice(min, max, user_choice);
}

int prompt_user_order() {
	food_drinks_menu();
	cout << "\n";
	cout << "What would you like to order? ";
	cout << "Enter 0 to return to the main menu\n";
	int user_choice = get_menu_choice(0, 10, "Food code: "); //Minimum input to receive is 0 and maximum input to receive is 10

	switch (user_choice) {
	case 1:
		cout << "\n";
		cout << "Food: Nasi Lemak\n";
		cout << "Price: " << get_price_str(PRICE_4) << "\n";
		cout << "Quantity : ";
		cin >> order_quantity;
		order_quantity_1 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_4 * order_quantity) * SST) + PRICE_4 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_4) << " * " << order_quantity << " = " << "RM" << PRICE_4 * order_quantity;
		cout << " + 6% SST = RM" << price_of_item;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <= 0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
		}
		if (payment >= price_of_item)
		 {
			cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}
		cout << "\n\n\n";
		system("pause");
		break;

	case 2:
		cout << "\n";
		cout << "Food: Nasi Goreng Ayam\n";
		cout << "Price: " << get_price_str(PRICE_5) << "\n";
		cout << "Quantity: "; 
		cin >> order_quantity;
		order_quantity_2 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_5 * order_quantity) * SST) + PRICE_5 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_5) << " * " << order_quantity << " = " << "RM" << PRICE_5 * order_quantity;
		cout << " + 6% SST = RM" << price_of_item;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 3:
		cout << "\n";
		cout << "Food: Nasi Goreng Pattaya\n";
		cout << "Price: " << get_price_str(PRICE_6) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_3 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_6 * order_quantity) * SST) + PRICE_6 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_6) << " * " << order_quantity << " = " << "RM" << PRICE_6 * order_quantity;
		cout << " + 6% SST = RM" << price_of_item;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 4:
		cout << "\n";
		cout << "Food: Nasi Goreng Mamak\n";
		cout << "Price: " << get_price_str(PRICE_5) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_4 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_5 * order_quantity) * SST) + PRICE_5 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_5) << " * " << order_quantity << " = " << "RM" << PRICE_5 * order_quantity;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 5:
		cout << "\n";
		cout << "Food: Nasi Goreng Kampung\n";
		cout << "Price: " << get_price_str(PRICE_5) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_5 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_5 * order_quantity) * SST) + PRICE_5 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_5) << " * " << order_quantity << " = " << "RM" << PRICE_5 * order_quantity;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 6:
		cout << "\n";
		cout << "Drink: Air Suam\n";
		cout << "Price: " << get_price_str(PRICE_1) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_6 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_1 * order_quantity) * SST) + PRICE_1 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_1) << " * " << order_quantity << " = " << "RM" << PRICE_1 * order_quantity;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 7:
		cout << "\n";
		cout << "Drink: Chinese Teh\n";
		cout << "Price: " << get_price_str(PRICE_1) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_7 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_1 * order_quantity) * SST) + PRICE_1 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_1) << " * " << order_quantity << " = " << "RM" << PRICE_1 * order_quantity;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 8:
		cout << "\n";
		cout << "Drink: Kopi O\n";
		cout << "Price: " << get_price_str(PRICE_2) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_8 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_2 * order_quantity) * SST) + PRICE_2 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_2) << " * " << order_quantity << " = " << "RM" << PRICE_2 * order_quantity;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 9:
		cout << "\n";
		cout << "Drink: Milo\n";
		cout << "Price: " << get_price_str(PRICE_3) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_9 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_3 * order_quantity) * SST) + PRICE_3 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_3) << " * " << order_quantity << " = " << "RM" << PRICE_3 * order_quantity;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	case 10:
		cout << "\n";
		cout << "Drink: Nescafe\n";
		cout << "Price: " << get_price_str(PRICE_2) << "\n";
		cout << "Quantity: ";
		cin >> order_quantity;
		order_quantity_10 += order_quantity;
		cout << fixed << setprecision(2) << endl;
		price_of_item = ((PRICE_2 * order_quantity) * SST) + PRICE_2 * order_quantity;
		cout << "Summary: " << get_price_str(PRICE_2) << " * " << order_quantity << " = " << "RM" << PRICE_2 * order_quantity;
		cout << endl;
		cout << "Please make payment of RM" << price_of_item << "\n";
		cout << "RM";
		cin >> payment;
		cout << endl;
		while (payment <=0) {
			cout << "Invalid amount! Please enter a valid amount: RM";
			cin >> payment;
			}
		if (payment >= price_of_item)
		 {
		cout << "Your change is RM" << payment - (price_of_item);
		}
		else {
			cout << "Your payment is incomplete, you still owe RM" << (price_of_item) - payment << endl;
			cout << "Payment: RM";
			cin >> payment_2;
			while (payment_2 < (price_of_item - payment)) {
				cout << "Please make full payment: RM";
				cin >> payment_2;
			}
			cout << "Your change is RM" << payment_2 - (price_of_item - payment);
			}

		cout << "\n\n\n";
		system("pause");
		break;

	default:
		return -1;
		break;
	}

	return user_choice;

}

int main_menu() { 
	cout << "\n";
	print_main_menu_logo();
	cout << "\n";
	cout << "1. Take order\n";
	cout << "2. Generate Daily Sales Report\n";
	cout << "0. Exit the program\n";
	return get_menu_choice(0, 2, "Enter a number: "); //This serves to ensure the user does not input a number less than 0 or greater than 2
}

int daily_sales_report() {
	print_sales_report_logo();

	//To make the program set all the prices to be RMx.00 rather than RMx
	cout << "\n" << fixed << setprecision(2);

	//Initializing all the prices to be kept in the order_price_x variable to be used later
	order_price_1 = order_quantity_1 * PRICE_4;
	order_price_2 = order_quantity_2 * PRICE_5;
	order_price_3 = order_quantity_3 * PRICE_6;
	order_price_4 = order_quantity_4 * PRICE_5;
	order_price_5 = order_quantity_5 * PRICE_5;
	order_price_6 = order_quantity_6 * PRICE_1;
	order_price_7 = order_quantity_7 * PRICE_1;
	order_price_8 = order_quantity_8 * PRICE_2;
	order_price_9 = order_quantity_9 * PRICE_3;
	order_price_10 = order_quantity_10 * PRICE_2;

	cout << "Sales per meal type\n\n";
	cout << "Nasi Lemak" << "\t\t" << order_quantity_1 << " * " << get_price_str(PRICE_4);
	cout << "\t";
	cout << " = \tRM" << order_price_1  << "\n";

	cout << "Nasi Goreng Ayam" << "\t" << order_quantity_2 << " * " << get_price_str(PRICE_5);
	cout << "\t";
	cout << " = \tRM" << order_price_2 << "\n";

	cout << "Nasi Goreng Pattaya" << "\t" << order_quantity_3 << " * " << get_price_str(PRICE_6);
	cout << "\t"; 
	cout << " = \tRM" << order_price_3 << "\n";

	cout << "Nasi Goreng Mamak" << "\t" << order_quantity_4 << " * " << get_price_str(PRICE_5);
	cout << "\t"; 
	cout << " = \tRM" << order_price_4 << "\n";

	cout << "Nasi Goreng Kampung" << "\t" << order_quantity_5 << " * " << get_price_str(PRICE_5);
	cout << "\t"; 
	cout << " = \tRM" << order_price_5 << "\n";

	cout << "Air Suam" << "\t\t" << order_quantity_6 << " * " << get_price_str(PRICE_1);
	cout << "\t"; 
	cout << " = \tRM" << order_price_6 << "\n";

	cout << "Chinese Teh" << "\t\t" << order_quantity_7 << " * " << get_price_str(PRICE_1);
	cout << "\t"; 
	cout << " = \tRM" << order_price_7 << "\n";

	cout << "Kopi O" << "\t\t\t" << order_quantity_8 << " * " << get_price_str(PRICE_2);
	cout << "\t"; 
	cout << " = \tRM" << order_price_8 << "\n";

	cout << "Milo" << "\t\t\t" << order_quantity_9 << " * " << get_price_str(PRICE_3);
	cout << "\t";
	cout << " = \tRM" << order_price_9 << "\n";

	cout << "Nescafe" << "\t\t\t" << order_quantity_10 << " * " << get_price_str(PRICE_2);
	cout << "\t";
	cout << " = \tRM" << order_price_10 << "\n\n";

	//Initialization of all the variables to be used for the final report
	food_sales = order_price_1 + order_price_2 + order_price_3 + order_price_4 + order_price_5;
	drink_sales = order_price_6 + order_price_7 + order_price_8 + order_price_9 + order_price_10;
	pre_tax_sales = food_sales + drink_sales;
	sales_and_service_tax = pre_tax_sales * SST;
	post_tax_sales = pre_tax_sales + sales_and_service_tax;

	//Final report
	cout << "Food Sales:  " << right << setw(37) << "RM" << food_sales << "\n";
	cout << "Drink Sales: " << right << setw(37) << "RM" << drink_sales << "\n";
	cout << "Total Sales: " << right << setw(37) << "RM" << pre_tax_sales << "\n";
	cout << "Total Sales: " << right << setw(37) << "RM" << pre_tax_sales << "\n";
	cout << "Sales and Service charge: " << right << setw(24) << "RM" << sales_and_service_tax << "\n";
	cout << "Total cash collected:     " << right << setw(24) << "RM" << post_tax_sales << "\n\n";
	cout << "Enter 0 to return to main menu: ";
	return get_menu_choice(0, 0, "Action:  ");
}

int main() 

{
	print_restaurant_logo();
	cout << "\n\n";
	system("pause");
	//This do while loop serves to keep the user in the program until the user chooses to close the program
	do
	{
		clear_screen(); 
		user_choice = main_menu();
		switch (user_choice) {

			case 1:
				do {
					clear_screen();
				} while (prompt_user_order() != -1);
				break;

			case 2:
				do {
					clear_screen();
				} while (daily_sales_report() != 0);
				break;

			case 0:
				print_ending_screen_logo();
				break;
			default: 
				break;
		
		}

	} while (user_choice == -1 || user_choice != 0); 

	return 0;
}
