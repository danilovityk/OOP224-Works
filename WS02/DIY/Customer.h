#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    
       
    void read(char* str, int len);
   
    // to be completed


void EmptyRecord(Customers& customer);  // Sets Customer data members to an empty state


void EmptyRecord(CustomersRecord& custRec);   // Sets CustomersRecord data members to an empty state


bool read(Customers& rec);


void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
              

void display(const Customers& c_rec);

void display(const CustomersRecord& t_rec);
}

#endif 
