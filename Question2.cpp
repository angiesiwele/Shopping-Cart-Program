 #include <iostream>
 #include <fstream>
 #include <string>
 using namespace std;
 const double DISCOUNT_RATE = 0.05; // 10% discount
 const double DISCOUNT_THRESHOLD = 200.00; // Discount applies if bill is over R100
 //Menu Item Prices
 const double COFFEE_PRICE = 15.00;
 const double BREAD_PRICE = 15.00;
 const double CROISSANT_PRICE = 20.00;
 const double CAKE_SLICE_PRICE = 30.00;
 const double DONUT_PRICE = 10.00;
 const double MUFFIN_PRICE = 20.00;
 const double COOKIE_PRICE = 15.00;
 const double ECLAIR_PRICE = 18.00;
 const double CINNAMON_ROLL_PRICE = 20.00;
 int main() {
 string name,surname;
 string answer;
 int item_number, quantity;
 double total = 0.00, final_total = 0.00;
 //Prompt the user to enter their name and surname.(2 marks)
 cout << "Enter your Name: " << endl;
 cin >> name ;
 cout << "Enter your Surname: " << endl;
 cin >> surname ;
 //Display the menu and prompt the user to select up to 8 items.(3 marks)
 cout << "WELCOME TO THE SUGAR AND SPICE BAKERY\n";
 bool isRunning =true;
 while(isRunning == true) {
 for (int n=1;n<=9;n++) {
 cout << "\nMenu:\n"
 << "1. Coffee-R15.00\n"
 << "2. Bread-R15.00\n"
 << "3. Croissant-R20.00\n"
 << "4. Cake Slice-R30.00\n"
 << "5. Muffin-R20.00\n"
 << "6. Donut-R10.00\n"
 << "7. Cookie-R15.00\n"
 << "8. Eclair-R18.00\n"
 << "9. Cinnamon Roll-R20.00\n"
 << "x. Exit" << endl;
 cout << "Select Item Number (1-9) or 'x' to exit program:";
 cin >> item_number ;
 //Get quantity for the selected items
 cout << "Enter quantity for item" << item_number << ": ";
 cin >> quantity;
 //Calculate the total cost based on the selection
switch (item_number) {
 case 1: total += COFFEE_PRICE*quantity; break;
 case 2: total += BREAD_PRICE*quantity; break;
 case 3: total += CROISSANT_PRICE*quantity; break;
 case 4: total += CAKE_SLICE_PRICE*quantity; break;
 case 5: total += MUFFIN_PRICE*quantity; break;
 case 6: total += DONUT_PRICE*quantity; break;
 case 7: total += COOKIE_PRICE*quantity; break;
 case 8: total += ECLAIR_PRICE*quantity; break;
 case 9: total += CINNAMON_ROLL_PRICE*quantity; break;
 default:
 cout << "Exiting selection.\n";
 isRunning=false;
 break;
 }
 }
 //Apply discount if applicable
 if(total>=DISCOUNT_THRESHOLD) {
 final_total = total-total*DISCOUNT_RATE;
 cout << "Total Bill: R" << total << endl;
 cout << "5% Discount Applied." << endl;
 cout << "Final Bill: R" << final_total << endl;
 }
 else if(total>=DISCOUNT_RATE) {
 final_total = total;
 cout << "Total Bill: R" << total << endl;
 cout << "No Discount Applied." << endl;
 cout << "Final Bill: R" << total << endl;
 }
 //Write Bill to text file
 ofstream MyFile("BakeryReciept.txt");
 // Write to the file
 MyFile << "Customer Name: "<< name;
 MyFile << "\nCustomer Surname: " << surname;
 MyFile << "\nTotal Bill (Before Discount): R" << final_total << endl;
 MyFile << "\nDiscount Applied: " << (total >= DISCOUNT_THRESHOLD ? "Yes, 5%" :
 "No") << "\n";
 MyFile << "\nFinal Total Bill: R" << final_total << endl;
 // Close the file
 MyFile.close();
 cout << "The bill saved as a BakeryReciept.txt " << endl;
 break;
 }
 return 0;
 }
