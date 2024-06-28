#include <iostream>
#include "book.hpp"
#include "authentication.hpp"

using namespace std;


int main(){
    int choice=1;
    FILE *fp;
    fp=fopen("catalogue","rb+");
    if(fp==NULL)
    {
        fp=fopen("catalogue","wb+");
        if(fp==NULL){
                cout << "Error in opening file";
                exit(1);
        }
    }

    FILE *fp1;
    fp1=fopen("loginsystem","rb+");
    if(fp1==NULL)
    {
        fp1=fopen("loginsystem","wb+");
        if(fp1==NULL){
                cout << "Error in opening file";
                exit(1);
        }
    }



    while(choice!=8)
    {   
        cout << "Press 1 to Login or Signup" << endl;
        cout << "Press 2 to Add new book" << endl;
        cout << "Press 3 to change book status" << endl;
        cout << "Press 4 to Display book information" << endl;
        cout << "Press 5 to List books by category" << endl;
        cout << "Press 6 to List books by an author" << endl;
        cout << "Press 7 to logout" << endl;
        cout << "Press 8 to Exit" << endl;
        cout << "These are available options. Choose what you want to do : " ;
        cin >> choice; 
        //system("cls"); 
        switch(choice)
        {
            case 1:

                auth(fp1);
                if(check==1)
                    cout << "Logged in" << endl;
                break;

            case 2:

                if(check==1)   
                    insert(fp);
                else
                    cout << "Login or Signup first" << endl;
                break;

            case 3:

                if(check==1)   
                    change_status(fp);
                else
                    cout << "Login or Signup first" << endl;
                break;

            case 4:

                display(fp);
                break;

            case 5:
                
                list_category(fp);
                break;

            case 6:

                list_author(fp);
                break;
            
            case 7:
                check=0;
                cout << "Logged out" << endl;
                break;

            case 8:

                fclose(fp);
                fclose(fp1);
                break;

            default:
                    
                cout << "Invalid choice" << endl;
        
        }

    }
    cout << "Exit" << endl;


    return 0;
}

