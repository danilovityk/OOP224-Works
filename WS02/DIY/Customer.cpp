#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    
    // complete
   

void EmptyRecord(Customers customer)  // Sets Customer data members to an empty state
{
    customer.likes_count = 0;
    customer.share_videos = 0;
    customer.replies_count = 0;
    customer.retweets_count = 0;
    customer.user_name[0] = '\0';
    
}

void EmptyRecord(CustomersRecord custRec)   // Sets CustomersRecord data members to an empty state
{
    
 //   EmptyRecord(*custRec.ptr_rec);
    
    custRec.noOfRecords = 0;
    
}



bool read(Customers& rec){
    bool garbage = false;
    
    cout << " Enter User name: ";
    
    cin.get(rec.user_name, 21);
    
    if (strlen(rec.user_name) != 0)
        garbage = true;
    
    
    if (garbage)
    {
        cout << " Enter likes_count: ";
        cin >> rec.likes_count;
        
        cout << " Enter retweets_count: ";
        cin >> rec.retweets_count;
        
        cout << " Enter replies_count: ";
        cin >> rec.replies_count;
        
        cout << "Enter share videos (y/n): ";
        cin.get (rec.share_videos);
        
        
    }
    
    cout << rec.user_name << endl;
    
    return garbage;
}

void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
{
    
    
}

  }

