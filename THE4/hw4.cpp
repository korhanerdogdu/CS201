#include <iostream>
#include <string>
#include <iomanip>     // for setw  
#include <vector>
using namespace std;      // Matrix A (3 x 2)  burda 3  satır 3 sütun demek.


// her bir işlem için fonksiyon kullanılabilir. Eğer koşulu sağlıyorsa fonksiyonun içine vektörü koy gibi...



void Print(const vector<vector<int> > & mat){ // referans koymasan da olur, vektörü değiştiremiyon çünkü. Ama performans için kullan.
	for (int j=0; j < mat.size(); j++){   // mat.size() bize içerdeki vektörlerin sayısını eleman sayısı olarak verir.
		for (int k=0; k < mat[0].size(); k++){   
			cout << mat[j][k] << " ";
		}
		cout << endl;
	}
}

// vektör tek boyutlu olunca 1. parametre; vector <int> v(3) yani 3 eleman sayısı, 2 boyutlu olunca 1. parametre satır, 2. parametre sütun sayısı oluyor diye anladım.

int main(){ 
    string giris;
    int numOfRow, numOfCol, num;  
    int numOfRow2, numOfCol2, num2;  // 3 tane iç içe vektör olamalı, ilk 2 vektör işleme alınacaklar, sonuncu ise sonuç vektörü. Sonuç vektörü boş olmalı.
    vector<vector<int> > mat; // satır sayısını ve sütun sayısının ne ne olacağını bilmediğimiz için parantez içinde bir şey yazmadık. vector <int> v(3) gibi. Şu an bu vektör boş. Sonra satır ve sütun sayısını belirleyeceğiz.
    vector<vector<int> > mat2;  // 3 tane temp kullanılabilir.
    vector<vector<int> > result;

    do{

        cout << "Pick a choice from the list:" << endl;
        cout << "1- Addition Operation" << endl;
        cout << "2- Multiplication Operation" << endl;
        cout << "3- Power Operation" << endl;
        cout << "4- Transpose Operation" << endl;
        cout << "5 - Exit" << endl;
        cin >> giris;
        cout << "Choice: " << giris << endl;

        if(giris == "1"){
            cout << "Please enter the dimensions of the first matrix: ";
            cin >> numOfRow >> numOfCol;
            cout << "Please enter the dimensions of the second matrix: ";
            cin >> numOfRow2 >> numOfCol2;

            if(numOfRow == numOfRow2 && numOfCol==numOfCol2){

                cout << "The two matrices have the same dimensions. Addition can be performed." << endl << endl;
                cout << "Please enter the numbers for the first matrix." << endl;

                for(int i=0; i<numOfRow; i++){ //********* çok önemli
		            cout << "Enter the numbers for row # " << i + 1 << endl;
		            vector<int> temp;
		            for(int j=0; j<numOfCol; j++){
			            cin >> num;
			            temp.push_back(num);

		            }
		            mat.push_back(temp);
	            }

                cout << "The first matrix is: " << endl;
                Print(mat);
                cout << endl << endl;

                cout << "Please enter the numbers for the second matrix." << endl;

                for(int i=0; i<numOfRow2; i++){ //********* çok önemli
		            cout << "Enter the numbers for row # " << i + 1 << endl;
		            vector<int> temp2;
		            for(int j=0; j<numOfCol2; j++){
			            cin >> num2;
			            temp2.push_back(num2); //temp2 vektörünü her döngü öncesinde sıfırlamanıza gerek yoktur. Yeni bir döngü başladığında otomatik olarak yeni bir temp2 vektörü oluşturulacaktır.

		            }
		            mat2.push_back(temp2);  // sıfırlamak isteseydim temp2.clear(); derdim.
	            }

                cout << "The second matrix is: " << endl;
                Print(mat2);
                cout << endl << endl;


                vector<vector<int> > result(mat.size(), vector<int>(mat[0].size())); // result ın kaç satır ve sütundan oluşacağını belirliyor.
                // vektörü tanımladım.

                for (int i = 0; i < numOfRow; i++) { 
                    for (int j = 0; j < numOfCol; j++) {
                        result[i][j] = mat[i][j] + mat2[i][j];
                    }
                }
                cout << "Result of the Sum Operation:" << endl;


                

                for (int i = 0; i < result.size(); i++) {
                    for (int j = 0; j < result[i].size(); j++) {
                        cout << result[i][j] << " ";
                    }
                    cout << endl;
                }


            }

            else{

                cout << "The two matrices do not have the same dimensions. Addition cannot be performed." << endl;
            }

        }

// If the matrices are compatible for multiplication then the resulting matrix will have the same number of rows as the first matrix and the same number of columns as the second matrix.

        else if(giris == "2"){
            cout << "Please enter the dimensions of the first matrix: ";
            cin >> numOfRow >> numOfCol;
            cout << "Please enter the dimensions of the second matrix: ";
            cin >> numOfRow2 >> numOfCol2;
            if(numOfCol == numOfRow2 ){
                cout << "The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed." << endl;
                cout << "Please enter the numbers for the first matrix." << endl;

                for(int i=0; i<numOfRow; i++){ //********* çok önemli
		            cout << "Enter the numbers for row # " << i + 1 << endl;
		            vector<int> temp;
		            for(int j=0; j<numOfCol; j++){
			            cin >> num;
			            temp.push_back(num);

		            }
		            mat.push_back(temp);
	            }

                cout << "The first matrix is: " << endl;
                Print(mat);
                cout << endl << endl;

                cout << "Please enter the numbers for the second matrix." << endl;

                for(int i=0; i<numOfRow2; i++){ //********* çok önemli
		            cout << "Enter the numbers for row # " << i + 1 << endl;
		            vector<int> temp2;
		            for(int j=0; j<numOfCol2; j++){
			            cin >> num2;
			            temp2.push_back(num2);

		            }
		            mat2.push_back(temp2);
	            }

                cout << "The second matrix is: " << endl;
                Print(mat2);
                cout << endl << endl;
                vector<vector<int> > result(mat.size(), vector<int>(mat2[0].size())); // 1. matrisin satır sayısına, 2.matrisin sütun sayısına eşit olsun.




                // you take each row of the first matrix and multiply each column of the second matrix going by each element.



                for (int i = 0; i < mat.size(); i++) {
                    for (int j = 0; j < mat2[0].size(); j++) {
                        for (int k = 0; k < mat[0].size(); k++) {
                            result[i][j] += mat[i][k] * mat2[k][j];
                        }
                    }
                }

                cout << "Result of the Multiplication Operation:" << endl;


                for (int i = 0; i < result.size(); i++) {
                    for (int j = 0; j < result[0].size(); j++) {
                        cout << result[i][j] << " ";
                    }
                    cout << endl;
                }



            }


            else {
                cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix. Multiplication cannot be performed." << endl;
            }


        }


        else if(giris == "3"){
            cout << "Please enter the dimensions of the matrix: ";
            cin >> numOfRow >> numOfCol;
            
            if(numOfRow == numOfCol){

                cout << "The matrix has the same number of rows as columns. Power can be performed." << endl << endl;
                cout << "Please enter the numbers for the matrix." << endl;

                for(int i=0; i<numOfRow; i++){ //********* çok önemli
		            cout << "Enter the numbers for row # " << i + 1 << endl;
		            vector<int> temp;
		            for(int j=0; j<numOfCol; j++){
			            cin >> num;
			            temp.push_back(num);

		            }
		            mat.push_back(temp);
	            }

                cout << "The matrix is: " << endl;
                Print(mat);
                cout << endl << endl;

                vector<vector<int> > result(mat.size(), vector<int>(mat[0].size()));

                cout << "Please enter the power: ";
                int power;
                cin >> power;

                for (int i = 0; i < numOfRow; i++) { 
                    for (int j = 0; j < numOfCol; j++) {
                        result[i][j] = (mat[i][j] * mat[i][j])*2; 
                    }
                }

                if(power > 2){
                    for(int l=0;l< power-2;l++){
                        for (int i = 0; i < numOfRow; i++) { 
                            for (int j = 0; j < numOfCol; j++) {
                                result[i][j] = (result[i][j] * mat[i][j])*2; 
                            }
                        }

                    }
                }

 
                


                cout << "Result of the Power Operation:" << endl;

                for (int i = 0; i < result.size(); i++) {
                    for (int j = 0; j < result[0].size(); j++) {
                        cout << result[i][j] << " ";
                    }
                    cout << endl;
                }


            }


            else {

                cout << "The matrix does not have the same number of rows as columns. Power cannot be performed." << endl << endl;
            }





        }

        else if(giris == "4"){
            cout << "Please enter the dimensions of the matrix: ";
            cin >> numOfRow >> numOfCol;
            cout << "Please enter the numbers for the matrix." << endl;



            for(int i=0; i<numOfRow; i++){ //********* çok önemli
		        cout << "Enter the numbers for row # " << i + 1 << endl;
		        vector<int> temp;
		        for(int j=0; j<numOfCol; j++){
			        cin >> num;
			        temp.push_back(num);

		        }
		        mat.push_back(temp);
            }


            cout << "The matrix is: " << endl;
            Print(mat);
            cout << endl << endl;
            vector<vector<int> > result(mat[0].size(), vector<int>(mat.size())); 



            for (int i = 0; i < numOfCol; i++) { 
                for (int j = 0; j < numOfRow; j++) {
                    result[i][j] = (mat[j][i]); 
                }
            }


            cout << "Result of the Transpose Operation:" << endl;



            for (int i = 0; i < result.size(); i++) {
                for (int j = 0; j < result[i].size(); j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }










        }


        

 

    }while(giris!="5");








}






/*


vector<vector<int> > result(mat.size(), vector<int>(mat[0].size()));



vector<int>(mat[0].size()) ifadesi yerine  sadece mat[0].size() yazsak hata verir mi? ---> EVET;




mat[0].size() ifadesi yalnızca bir tamsayı döndürür, bu nedenle vector<int> oluşturmak için yeterli değildir. 
Eğer sadece mat[0].size() kullanırsanız, ayrıntılar belirtilmeyen bir hata alırsınız.



kodun düzgün çalışması için vector<int>(mat[0].size()) ifadesi kullanılmalıdır.
Bu ifade, mat matrisinin ilk satırındaki sütun sayısı kadar elemanı olan bir vector<int> oluşturur ve result vektörünün her bir satırının boyutunu belirlemek için kullanılır.



Yani bir iç içe vektörün boyutlarını tanımlarken ilk parametre tamsayı, ikinci parametre vektör cinsinden olmalıdır. (satır,sütun)


*/