/#include <iostream>      
#include <vector>        
#include <string>        
using namespace std;     
// Structure which store information about each item 
struct Item { 
    string name;        // Name of the product 
    double price;       // Price of the item 
    int stock;          // Number of product available in vending machine 
}; 
int main() { 
    // this Create a list of product available in the vending machine 
    vector<Item> items = { 
        {"Coke", 1.50, 4}, 
        {"Water", 1.00, 5}, 
        {"Coffee", 2.00, 4}, 
        {"Tea", 1.80, 7}, 
        {"Chocolate Bar", 1.20, 2}, 
        {"Biscuits", 1.00, 5} 

    }; 
    // Variable to store the money inserted by the user 
    double money = 0.0; 
    // this code display welcome message 
    cout << "==== Welcome to the Vending Machine ====\n"; 
    // this code ask individual to insert currency 
    cout << "Insert money to start (£): "; 
    cin >> money; 
    // Main loop keeps running until the user chooses to quit 

    while (true) { 
        //the vending machine menu 
        cout << "\n------ Menu ------\n"; 

        for (size_t i = 0; i < items.size(); ++i) { 

            cout << i + 1 << ". " << items[i].name 

                 << " £" << items[i].price 

                 << " (Stock: " << items[i].stock << ")\n"; 
        } 
        // Variable to store the user's choice 
        int choice; 
        // Ask the individual to choose a item to buy 
        cout << "\nSelect item number (0 to quit): "; 
        cin >> choice; 
        // If the user enters 0, this causes to leave vending machine 
        if (choice == 0) 
            break; 
        // this check if selected item is valid  
        if (choice < 1 || choice > static_cast<int>(items.size())) { 
            cout << "Invalid choice.\n"; 
            continue;   // if its valid restart the loop 
        } 
        // Reference the selected item from the list 
        Item &it = items[choice - 1]; 
        // this check if selected item is out of stock 
        if (it.stock <= 0) { 
            cout << "Sorry, out of stock.\n"; 
            continue; 
        } 
        // Check if the individual has correct amount money 
        if (money < it.price) { 
            cout << "Not enough money.\n"; 
            continue; 
        } 
        // Process the purchase and Deduct the price from the user's balance 
        money -= it.price; 
        // this reduce stock of selected item 
        it.stock--; 
        // tells individual item is dispensing  
        cout << "Dispensing " << it.name << "...\n"; 
        // this show the remaining balance 
        cout << "Remaining balance: £" << money << "\n"; 
        // this code suggest you to buy biscuits if you buy hot drink such as coffee or tea 
        if (it.name == "Coffee" || it.name == "Tea") { 
            cout << "How about some biscuits with your drink?\n"; 
        } 
    } 
    // Return any remaining change to individual 
    cout << "\nReturning change: £" << money << "\n"; 
    cout << "Thank you for using the vending machine!\n"; 

    // End of program 
    return 0; 
} 
