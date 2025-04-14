//Question 2
/* Shopping Cart Program
The system should allow customers to select items and specify quantities, calculate the total cost,
apply a discount if applicable, and write the final bill to a text file for record-keeping.
The store has a policy where a 5% discount is applied if the total cost of the items exceeds R200.
The system will prompt the user to enter their name, select items from the menu, and enter the quantities.
After the total is calculated and any discount applied, the program will output the customer’s final bill
and save the details to a text file.
 */
#include <iostream>
#include <fstream>
using namespace std;
const double DISCOUNT_RATE = 0.05; // 10% discount
const double DISCOUNT_THRESHOLD = 200.00; // Discount applies if bill is over R100

char name,surname,menu;
char answer;
int item_number;
double total, final_total;


int main() {
    //Prompt the user for input.
    //Prompt the user to enter their name and surname.(2 marks)
    cout << "Enter your Name: " << endl;
    cin >> name ;
    cout << "Enter your Surname: " << endl;
    cin >> surname ;
        //Display the menu and prompt the user to select up to 8 items.(3 marks)
    bool isRunning =true;
    while(isRunning == true) {
        for (int n=1;n<=8;n++) {
            cout << "\nMenu:\n"
            << "1. Coffee - R15.00\n"
            << "2. Sandwich - R30.00\n"
            << "3. Salad - R25.00\n"
            << "4. Juice - R10.00\n"
            << "5. Muffin - R20.00\n"
            << "6. Pizza Slice - R35.00\n"
            << "7. Soup - R18.00\n"
            << "8. Burger - R40.00\n"
            << "x. Exit" << endl;
            cout << "Select Item " << n << " (1-8):";
            cin >> item_number ;
            if(item_number==1) {
                total = total + COFFEE_PRICE;
            }
            if(item_number==2) {
                total = total + SANDWICH_PRICE;
            }
            if(item_number==3) {
                total = total + SALAD_PRICE;
            }
            if(item_number==4) {
                total = total + JUICE_PRICE;
            }
            if(item_number==5) {
                total = total + MUFFIN_PRICE;
            }
            if(item_number==6) {
                total = total + PIZZA_PRICE;
            }
            if(item_number==7) {
                total = total + SOUP_PRICE;
            }
            if(item_number==8) {
                total = total + BURGER_PRICE;
            }
            if(item_number=='x') {
                isRunning = false;
                break;
            }
    }

        if(total>=DISCOUNT_THRESHOLD) {
            final_total = total-total*DISCOUNT_RATE;
            cout << "Total Bill: R" << total << endl;
            cout << "10% Discount Applied." << endl;
            cout << "Final Bill: R" << final_total << endl;
        }
        else if(total>=DISCOUNT_RATE) {
            final_total = total;
            cout << "Total Bill: R" << total << endl;
            cout << "No Discount Applied." << endl;
            cout << "Final Bill: R" << total << endl;
        }
        // Create and open a text file
        ofstream MyFile("CafeteriaBill.txt");
        // Write to the file
        MyFile << "Customer Name: "<< name << "\nCustomer Surname: " << surname<< "\nFinal Total Bill: R" << final_total << endl;
        // Close the file
        MyFile.close();
        cout << "The bill has been written to CafeteriaBill.txt :" << endl;
        break;

    }
    //Handle item selection and quantity input
    //Calculate the total cost and apply the discount if applicable.
    //Write the final output to a text file


    return 0;
}


