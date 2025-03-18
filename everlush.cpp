#include <iostream> 
#include <limits>  

using namespace std;  
struct BanquetHall
 
{
  
    string name = " EVER LUSH BANQUET ";  
    int capacity = 500;  
    int currentGuests = 0;  
    string bookingDate = "";    
    int waitersNeeded = 0;  
    string paymentMethod = "20000 (2 installments)"; 
	 
};  

void displayHallDetails(const BanquetHall& hall) 

{  
    string password;  
    cout << " ENTER PASSWORD TO VIEW ALL DETAILS ABOUT BANQUET : ";  
    cin >> password;  
    if (password != "2626") 
	
	{  
	
	cout<<" INCORRECT PASSWORD ... " << endl ;
        return;  
    }  
    cout << " HALL: " << hall.name << endl;  
    cout << " CAPACITY: " << hall.capacity << endl;
    cout << " BOOKED GUESTS : " << hall.currentGuests << endl;   
    cout << " BOOKING DATE : " << hall.bookingDate  << endl;
    cout << " WAITERS REQUIREMENT : " << hall.waitersNeeded  << endl;
    cout << " PAYMENT : " << hall.paymentMethod << endl; 
    cout<< endl;
    
}  

bool isValidInput() {  
    if (cin.fail()) {  
        cin.clear();    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    
        return false;  
    }  
    return true;  
}  

int main() {  
    BanquetHall hall;  
    int choice, guests, waiters;  
    string date;  

    do {  
    
        cout << "1. BOOK HALL " << endl;
        cout << "2. CANCEL BOOKING " << endl;
        cout << "3. VIEW DETAILS" << endl; 
        cout << "4. EXIT " << endl; 
        cout<< endl;
        
        cout << "   ENTER CHOICE : " <<endl;
		 cin >> choice;
        
        cout<< endl ; 
		
		 
        if (!isValidInput())
		
		 {  
            cout << " INVALID INPUT TRY AGAIN ... " << endl ;  
            continue;  
        }  

        switch (choice) {  
            case 1:  
                cout << " ENTER NUMBER OF GUESTS : ";  
                cin >> guests;  
                if (!isValidInput() || guests <= 0) {  
                    cout << " INVALID NUMBER OF GUEST " << endl;  
                    break;  
                }  
                if (hall.currentGuests + guests > hall.capacity) {  
                    cout << "Not enough capacity.\n";  
                    break;  
                }  
                cout << "Enter booking date (YYYY-MM-DD): ";  
                cin >> date;  
                cout << "Enter number of waiters (Max 20): ";  
                cin >> waiters;  
                if (!isValidInput() || waiters > 20) {  
                    cout << "Invalid number of waiters.\n";  
                    break;  
                }  
                hall.currentGuests += guests;  
                hall.bookingDate = date;  
                hall.waitersNeeded = waiters;  
                cout<< endl ;
                
                cout << " YOUR BOOKING IS CONFIRMED FOR " << date << endl ; 
				cout<< endl ; 
                break;  

				cout<< endl ;

            case 2:  
                cout << " ENTER NUMBER OF GUEST TO CANCEL  : ";  
                cin >> guests;  
                if (!isValidInput() || guests <= 0 || guests > hall.currentGuests) {  
                    cout<< endl ;
					cout << "INVALID CANCELATION AMOUNT " << endl ;  
                    
                    break;  
                }  
                hall.currentGuests -= guests;  
                if (hall.currentGuests == 0) {  
                    hall.bookingDate = "";  
                    hall.waitersNeeded = 0;  
                }  
                cout << " BOOKING CANCELED " <<endl ;  
                break;  

            case 3:  
                displayHallDetails(hall);  
                break;  

            case 4:   
            
                cout << " EXITING SYSTEM ..... " << endl ;  
                break;  

            default:  
            
                cout << " INVALID CHOICE PLEASE TRY AGAIN " <<endl ;  
        } 
		
		 
    } while (choice != 4);  

    return 0;  
    
}