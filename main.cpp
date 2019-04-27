#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// the structure stores details of each entry
struct entry{
    string acc; //account of the record
    int day; // day of the date of the expense or income
    int month; // month of the date of the expense or income
    int year; // year of the date of the expense or income
    int amount; // amount of the expense or income
    string type; // Type of transcation (Income/Expense)
    string cat; // category that the expense or income belongs to
};
int budget = 0,global_total_expense = 0;

// function: prints the user manual and allows user to select actions
// output: inttemp which indicate the user-chosen action
int menu(){
    int choice;
    cout<<"Menu"<<endl;
    cout<<"1. Create new record\n"
    << "2. Edit or delete\n"
    << "3. Filter and display\n"
    << "4. Show statistical information\n"
    << "5. Budget setting\n"
    << "6. Exit program\n"
    << "Please indicate your choice (1-6): ";
    cin >> choice;
    return choice;
}

int counter = 0; // global variable which is used to count the number of the records

// function: allows user to input and stores user input into the structure entry
// input: entry records[]: array of structure entry, which is being edited
void data_entry(entry records[]){
    int choice;
    cout<<"-----------------------------"<<endl;
    cout<<"You are creating a new record"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"1. Expense\t2. Income"<<endl;
    cout<<"Please indicate your choice (1/2): ";
    cin >> choice ;
    if (choice == 1){
        records[counter].type = "Expense" ;
    }
    else if (choice == 2){
        records[counter].type = "Income" ;
    }
    else{
        cout<<"Invalid input, please re-enter the record"<<endl;
        data_entry(records);
    }
    // above allows user to choose the type of that record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"Please enter the amount of this record: $";
    cin>>records[counter].amount;
    if(records[counter].type == "Expense")
        global_total_expense += records[counter].amount;
    if (global_total_expense > budget && budget !=0)
        cout << "You are over budget!!!\n";
    cout<<"-----------------------------"<<endl;
    if (records[counter].type == "Expense"){
        cout << "1. Food\t2. Game\t3. Transportion\t 4.Others"<<endl;
        cout << "Please indicate your choice (1-4): ";
        cin >> choice;
        switch (choice) {
            case 1:
                records[counter].cat = "Food";
                break;
            case 2:
                records[counter].cat = "Game";
                break;
            case 3:
                records[counter].cat = "Transportation";
                break;
            case 4:
                records[counter].cat = "Others";
                break;
            default:{
                cout<<"Invalid input, please re-enter the record"<<endl;
                data_entry(records);
            }
        }}
    else{
        cout<<"1. Salary 2. Gift"<<endl;
        cout<<"Please indicate your choice (1/2): ";
        cin >> choice;
        if(choice == 1)
            records[counter].cat = "Salary";
        else if(choice == 2)
            records[counter].cat = "Gift";
        else{
            cout<<"Invalid input, please re-enter the record"<<endl;
            data_entry(records);
        }
    }
    // above allows user to input the category of the record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"Please enter the date of this record: "<<endl;
    cout<<"Year: ";
    cin>>records[counter].year;
    cout<<"Month: ";
    cin>>records[counter].month;
    cout<<"Day: ";
    cin>>records[counter].day;
    // above allows user to input the day of the record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"1. Cash\t2. Bank\t3. Credit card"<<endl;
    cout<<"Please indicate your choice (1 or 2 or 3): ";
    cin>> choice;
    switch (choice) {
        case 1:
            records[counter].acc ="Cash";
            break;
        case 2:
            records[counter].acc ="Bank";
            break;
        case 3:
            records[counter].acc ="Credit Card";
            break;
        default:{
            cout<<"Invalid input, please re-enter the record"<<endl;
            data_entry(records);
        }
    }
    // above allows user to choose the account of the record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"Successfully added!"<<endl;
    cout<<"-----------------------------"<<endl;
    counter += 1;
}

// function: displays the existing records
// input: entry records[]: array of structure entry, which is being edited
void data_display(entry records[]){
    cout << "-----------------------------" << endl;
    cout << left << setw(7) << "Number" << setw(17) << "Date(YYYY-MM-DD)" << setw(10) << "Amount" << setw(8) << "Type" << setw(15) << "Category" << setw(10) << "Account" << endl;
    for(int i=0; i <= 20 ;i++){
        if(records[i].type != "Expense" and records[i].type != "Income"){
            continue;
        }
        cout << setfill(' ');
        cout << left << setw(7) << i+1 << setw(4) << records[i].year << "-" << setw(2) << records[i].month << "-" << setw(9) << records[i].day << setw(10) << records[i].amount << setw(8) << records[i].type << setw(15) << records[i].cat << setw(10) << records[i].acc << endl;
        cout<<"-----------------------------"<<endl;
    }
}

// function: allows user to edit existing records
// input: entry records[]: array of structure entry, which is being edited
void data_edit(entry records[]){
    data_display(records);
    int choice, counter;
    cout<<"Record to be updated: ";
    cin >> counter;
    counter -= 1;
    if(records[counter].type == "Expense")
        global_total_expense -= records[counter].amount;
    cout<<"-----------------------------"<<endl;
    cout<<"You are updating a record"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"1. Expense\t2. Income"<<endl;
    cout<<"Please indicate your choice (1 or 2): ";
    cin >> choice ;
    if (choice == 1){
        records[counter].type = "Expense" ;
    }
    else if (choice == 2){
        records[counter].type = "Income" ;
    }
    else{
        cout<<"Invalid input, please re-enter the record"<<endl;
        data_entry(records);
    }
    // above allows user to choose the type of that record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"Please enter the amount of this record: $";
    cin>>records[counter].amount;
    if(records[counter].type == "Expense")
        global_total_expense += records[counter].amount;
    if (global_total_expense > budget && budget!=0)
        cout << "You are over budget!!!\n";
    cout<<"-----------------------------"<<endl;
    if (records[counter].type == "Expense"){
        cout << "1. Food\t2. Game\t3. Transportion\t 4.Others"<<endl;
        cout << "Please indicate your choice (1-4): ";
        cin >> choice;
        switch (choice) {
            case 1:
                records[counter].cat = "Food";
                break;
            case 2:
                records[counter].cat = "Game";
                break;
            case 3:
                records[counter].cat = "Transportation";
                break;
            case 4:
                records[counter].cat = "Others";
                break;
            default:{
                cout<<"Invalid input, please re-enter the record"<<endl;
                data_entry(records);
            }
        }}
    else{
        cout<<"1. Salary 2. Gift"<<endl;
        cout<<"Please indicate your choice (1/2): ";
        cin >> choice;
        if(choice == 1)
            records[counter].cat = "Salary";
        else if(choice == 2)
            records[counter].cat = "Gift";
        else{
            cout<<"Invalid input, please re-enter the record"<<endl;
            data_entry(records);
        }
    }
    // above allows user to input the category of the record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"Please enter the date of this record: "<<endl;
    cout<<"Year: ";
    cin>>records[counter].year;
    cout<<"Month: ";
    cin>>records[counter].month;
    cout<<"Day: ";
    cin>>records[counter].day;
    // above allows user to input the day of the record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"1. Cash\t2. Bank\t3. Credit card"<<endl;
    cout<<"Please indicate your choice (1-3): ";
    cin>> choice;
    switch (choice) {
        case 1:
            records[counter].acc ="Cash";
            break;
        case 2:
            records[counter].acc ="Bank";
            break;
        case 3:
            records[counter].acc ="Credit Card";
            break;
        default:{
            cout<<"Invalid input, please re-enter the record"<<endl;
            data_entry(records);
        }
    }
    // above allows user to choose the account of the record and stores it into records[]
    cout<<"-----------------------------"<<endl;
    cout<<"Successfully Edited!"<<endl;
    cout<<"-----------------------------"<<endl;
}

// function: allows user to edit existing records
// input: entry records[]: array of structure entry, which is being edited
void data_delete(entry records[]){
    int code;
    char choice;
    data_display(records);
    cout << "Please choose a reocrd to delete: ";
    cin >> code;
    cout << "You are deleting record, are you sure about that?(Y/N)\n";
    cin >> choice;
    if(choice =='Y'){
        for(int i = code-1; i < 19; i++){
            records[i].acc = records[i+1].acc;
            records[i].day = records[i+1].day;
            records[i].month = records[i+1].month;
            records[i].year = records[i+1].year;
            records[i].amount = records[i+1].amount;
            records[i].cat = records[i+1].cat;
            records[i].type = records[i+1].type;
        }
    }
     data_display(records);
}

void specific_display(int i,entry records[]){
    cout << setfill(' ');
    cout << left << setw(7) << i+1 << setw(4) << records[i].year << "-" << setw(2) << records[i].month << "-" << setw(9) << records[i].day << setw(10) << records[i].amount << setw(8) << records[i].type << setw(15) << records[i].cat << setw(10) << records[i].acc << endl;
    cout<<"-----------------------------"<<endl;
}

// function: filter and displays the existing records
// input: entry records[]: array of structure entry, which is being edited
void data_filter(entry records[]){
    int choice;
    cout << "You may choose one type of data for filtering:\n" <<
    "1. Expense/Income\n" <<
    "2. Date\n" <<
    "3. Category\n" <<
    "4. Account\n" <<
    "Please enter your choice: (1/2/3/4) ";
    cin >> choice;
    switch (choice) {
        case 1: {
            int choice;
            cout <<"Which type of record do you want to show? (1.Expense/2.Income)\n";
            cin >> choice;
            for (int i = 0; i <= 20; i++) {
                if (choice == 1){
                    if (records[i].type == "Expense")
                        specific_display(i, records);
                }
                if (choice == 2){
                    if (records[i].type == "Income")
                        specific_display(i, records);
                }
            }
            break;
        }
        case 2:{
            int year,month,day;
            cout << "Please enter a date and the record on or before this date will be shown: (YYYY-MM-DD)\n ";
            cin >> year >> month >> day;
            for (int i = 0; i <= 20; i++) {
                if (records[i].acc != "Bank" and records[i].acc != "Cash" and records[i].acc !="Credit Card"){
                    continue;
                }
                if (records[i].year < year){
                    specific_display(i, records);
                }
                else if (records[i].year == year and records[i].month < month){
                    specific_display(i, records);
                }
                else if (records[i].year == year and records[i].month == month and records[i].day <= day ){
                    specific_display(i, records);
                }
            }
            break;
        }
        case 3:{
            int type;
            cout <<"Which category of record do you want to show? (1. Food\t2. Game\t3. Transportion\t4. Others)\n";
            cin >> type;
            switch (type){
                case 1:{
                    for (int i = 0; i <= 20; i++) {
                        if (records[i].cat == "Food"){
                            specific_display(i, records);
                        }}
                    break;
                }
                case 2:{
                    for (int i = 0; i <= 20; i++) {
                        if (records[i].cat == "Game"){
                            specific_display(i, records);
                        }}
                    break;
                }
                case 3:{
                    for (int i = 0; i <= 20; i++) {
                        if (records[i].cat == "Transportation"){
                            specific_display(i, records);
                        }}
                    break;
                }
                case 4:{
                    for (int i = 0; i <= 20; i++) {
                        if (records[i].cat == "Others"){
                            specific_display(i, records);
                        }}
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 4:{
            int cat;
            cout <<"Which account do you want to show? (1. Cash\t2. Bank\t3. Credit card)\n";
            cin >> cat;
            switch (cat){
                case 1:{
                    for (int i = 0; i <= 20; i++) {
                        if (records[i].acc == "Cash"){
                            specific_display(i, records);
                        }}
                    break;
                }
                case 2:{
                    for (int i = 0; i <= 20; i++) {
                        if (records[i].acc == "Bank"){
                            specific_display(i, records);
                        }}
                    break;
                }
                case 3:{
                    for (int i = 0; i <= 20; i++) {
                        if (records[i].acc == "Credit Card"){
                            specific_display(i, records);
                        }}
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void statistical_information(entry records[]){
    int total_expense = 0, total_income = 0;
    double food_count = 0, game_count = 0, transport_count = 0, other_count = 0;
    for(int i = 0;i < 20; i++){
        if(records[i].type == "Expense"){
            total_expense += records[i].amount;
            if (records[i].cat == "Food")
                food_count += records[i].amount;
            else if (records[i].cat == "Game")
                game_count += records[i].amount;
            else if (records[i].cat == "Transportation")
                transport_count += records[i].amount;
            else if (records[i].cat == "Others")
                other_count += records[i].amount;
        }
        else if(records[i].type == "Income" ){
            total_income += records[i].amount;
        }
        else
            continue;
    }
    cout << "Total expense: " << total_expense << endl;
    cout << "Total income: " << total_income << endl;
    cout << "Balance: " << total_income - total_expense << endl;
    cout<<"-----------------------------"<<endl;
    cout << "Precentage of each expense category:\n";
    cout << fixed <<setprecision(2);
    cout << "Food: " << food_count/total_expense * 100 << "%\n";
    cout << "Game: " << game_count/total_expense * 100 << "%\n";
    cout << "Transportation: " << transport_count/total_expense * 100 << "%\n";
    cout << "Others: " << other_count/total_expense * 100 << "%\n";
    cout<<"-----------------------------"<<endl;
    cout << "Budget remaining: $" << budget - total_expense << endl;
}

int budget_setting(){
    if (budget == 0){
        cout<<"-----------------------------"<<endl;
        cout<<"Please input your budget: $";
        cin>>budget;
        cout<<"-----------------------------"<<endl;
        cout<<"New budget is set!"<<endl;
        cout<<"-----------------------------"<<endl;
    }
    else{
        int choice;
        cout << "Current budget: $" << budget << endl;
        cout << "Enter '1' to reset budget, '0' to exit: ";
        cin >> choice;
        if (choice == 1){
            cout<<"Please input your budget: $";
            cin>>budget;
        }
        else{
            return budget;
        }
    }
    return budget;
}

int main(){
    int choice,inttemp;
    entry records[20]; // maximum of 20 entries is allowed
    while (true){
        choice=menu();
        if (choice==1){
            data_entry(records);
        }
        else if (choice==2){
            cout<<"1. Edit\t2. Delete"<<endl;
            cout<<"Please indicate your choice (1 or 2): ";
            cin>>inttemp;
            if(inttemp==1){
                data_edit(records);
            }
            else if(inttemp==2){
                data_delete(records);
            }
        }
       
        else if (choice==3){
            cout<<"1. Filter\t2. Show all"<<endl;
            cout<<"Please indicate your choice (1 or 2): ";
            cin>>inttemp;
            if (inttemp==1){
                data_filter(records);
            }
            else if (inttemp==2){
                data_display(records);
            }
        }
        else if (choice == 4){
            statistical_information(records);
        }
        else if( choice == 5){
            budget = budget_setting();
        }
        else if (choice == 6){
            cout << "End of progam, thanks for using.\n";
            return 0;
        }
    }
}





