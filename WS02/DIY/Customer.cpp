/*
        Name: Danylo Vityk
        Email: dvityk@myseneca.ca
        Sudent ID: 176326213
        Date: Jan 31, 2023


 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


*/

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
   

void EmptyRecord(Customers& customer)  // Sets Customer data members to an empty state
{
    customer.likes_count = 0;
    customer.share_videos = 0;
    customer.replies_count = 0;
    customer.retweets_count = 0;
    strCpy(customer.user_name,  "");
    
}

void EmptyRecord(CustomersRecord& custRec) // Sets CustomersRecord data members to an empty state
{
    if (custRec.ptr_rec != NULL)
        custRec.ptr_rec = NULL;
    
    custRec.noOfRecords = 0;
}





bool read(Customers& rec){
    bool garbage = false;
    
    cout << " Enter User name: ";
    
    cin.getline(rec.user_name, 21);
    
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
        
        cin.ignore(10000, '\n');
        
        cout << "Enter share videos (y/n): ";
        cin.get (rec.share_videos);
        
        cin.ignore(10000, '\n');
        
    }
    
    
    return garbage;
}

void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
{
    t_rec.noOfRecords++;
    
    Customers *tempCust = new Customers[t_rec.noOfRecords];
    
    // copying old array into a buffer
    for (int i = 0; i < t_rec.noOfRecords - 1; i++){
        tempCust[i] = t_rec.ptr_rec[i];
    }
    
    // adding the new element to the buffer array
    tempCust[t_rec.noOfRecords - 1] = c_rec;
    
    // deallocation of the old array of customers.
    if(!t_rec.ptr_rec) delete[] t_rec.ptr_rec;
    
    // memory alloc for the new array
    t_rec.ptr_rec = new Customers[t_rec.noOfRecords];
    
    t_rec.ptr_rec = tempCust;
    
}

void display(const Customers& c_rec)
{
    cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count << ", " << c_rec.share_videos << endl;
}

void display(const CustomersRecord& t_rec)
{
    if (t_rec.ptr_rec != NULL)
    {
        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            cout << (i + 1) << ". ";
            display(t_rec.ptr_rec[i]);
            cout << endl;
        }
    }
}

  }

