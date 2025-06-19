#include <iostream>

using namespace std;

int main(){


    double pwater = 10.00;
    double psoda = 30.00;
    double phamburger= 100.00;
    double pfries = 59.5;

    int Water;
    int Soda;
    int Hamburger;
    int Fries;


    double tax = 0;
    double taxsoda;
    double taxfries;
    double taxhamburger;


    


    cout << "Enter the quantity of each product you have ordered: " << endl;
    cout << "Water: ";
    cin >> Water;
    
    cout << "Soda: ";
    cin >> Soda;
    
    cout << "Fries: " ;
    cin >> Fries;
    
    cout << "Hamburger: " ;
    cin >> Hamburger;


    
     


 
    

    if(Water!=0){ // normal fiyatları. 

        pwater = Water * pwater;


    }
    else{

        pwater=0;
    }




    if(Soda!=0){

        psoda =  Soda * psoda;

        taxsoda = psoda/2;
    }
    else{

        psoda = 0;
        taxsoda = 0;
    }



    if(Fries!=0){

        pfries= Fries * pfries ;
        taxfries = pfries/10;

    }

    else{


        pfries = 0;
        taxfries=0;
    }




    if(Hamburger != 0){
        int cheese;
        cout << "Add cheese to your hamburger(s)? (1 for yes, 0 for no): ";
        cin >> cheese;
        if (cheese == 1){
            phamburger = Hamburger * (phamburger + 11);
            taxhamburger=(phamburger)/10;
        }

        else{

            phamburger = Hamburger * phamburger;
            taxhamburger=phamburger/10;
        }

        
    }



    else{

        phamburger = 0;
        taxhamburger=0;
    }


    tax = taxsoda + taxfries + taxhamburger;


    double subtotal;
    double service_charge;
    double total_price;
    subtotal = psoda + pfries + phamburger + pwater;



    cout << "Are you a student? (1 for yes, 0 for no): " << endl;
    int student;
    cin >> student;


    if (student==1){



        double discounted  = (subtotal + tax - (subtotal + tax)/4);
        double student_discount = (subtotal + tax)/4;
        cout << "Student discount applied!" << endl;

        
        // burdaydı normalde

        if(discounted < 175){

            total_price = discounted + discounted/10;
            service_charge=discounted/10;

        }

        else if(175 <= discounted && discounted < 375){

            total_price= discounted + discounted*8/100;
            service_charge=discounted*8/100;



        }

        else if(discounted >=375) {

            total_price = discounted + discounted*6/100;
            service_charge=discounted*6/100; 



        }

    
    }

    else if(student==0){

        cout << "    " << endl;

        if(subtotal + tax < 175){


            total_price = (subtotal + tax) + (subtotal + tax)/10;
            service_charge=(subtotal + tax)/10;

        }

        else if(175 <= subtotal + tax && subtotal + tax < 375){

            total_price= (subtotal + tax) + (subtotal + tax)*8/100;
            service_charge=(subtotal + tax)*8/100;



        }

        else if(subtotal + tax >=375) {

            total_price = (subtotal + tax) + (subtotal + tax)*6/100;
            service_charge=(subtotal + tax)*6/100;


        }



    


        

    }






     // burdaydı



    cout <<  "===================================" << endl;
    cout <<  "         Restaurant Invoice        " << endl;
    cout <<  "===================================" << endl;



    if(Water==0 && Soda==0 && Hamburger==0 && Fries==0 ){
        cout << "The customer has not made a purchase or placed an order!";


    }


    else {




    if(Water!=0){
        cout << "Water " << "(" << Water << "): " << pwater << " TL" << endl;

    }


    if(Soda!=0){
        cout << "Soda " << "(" << Soda << "): " << psoda << " TL" << endl;


    }

    
    if(Fries!=0){
        cout << "Fries " << "(" << Fries << "): " << pfries << " TL" << endl;


    }



    if(Hamburger!=0){
        cout << "Hamburgers " << "(" << Hamburger << "): " << phamburger << " TL" << endl;


    }



    cout << "Subtotal: " << subtotal << " TL" << endl << endl;
    cout << "VAT: " << tax << " TL" << endl;
    if(student==1){
        cout << "Student discount: " << "-" << (subtotal + tax)/4 << " TL" << endl;


    }
    cout << "Service fee: " << service_charge << " TL" << endl;
    cout << "Total price: " << total_price << " TL" << endl;



    }

   



    






    // subtotal falan, genel olaarak if e bağlamadan yaz.



/*


Water (1): 10 TL
Soda (1): 30 TL
Fries (1): 59.5 TL
Hamburgers (1): 111 TL
Subtotal: 210.5 TL
VAT: 32.05 TL
Service fee: 19.404 TL
Total price: 261.954 TL
*/


    


     








    }




   


   
