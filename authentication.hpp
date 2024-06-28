#include <iostream>

using namespace std;

int login(FILE *fp1);
int  signup(FILE *fp1);
int search_details(FILE *fp1, string id, string key);

int check= 0, choice1;
string id, key;
struct{
    string loginid;
    string password;
}detail;


int auth(FILE *fp1){
    cout << "Press 1 to Login\n";
    cout << "Press 2 to Signup\n";
    cin >> choice1;
    getchar();
    switch(choice1){
            case 1:
                    check= login(fp1);
                    break;
            case 2:
                    check= signup(fp1);
                    break;
            default: printf("Enter a valid choice\n");

        }   
    return check;
}

int login(FILE *fp1){
    rewind(fp1);    
    unsigned flag= 0;
    cout << "Enter id: ";
    getline(cin, id);
    cout << "Enter password: ";
    getline(cin, key);
    if(search_details(fp1, id, key))
        flag=1;
    return flag;
}
int signup(FILE *fp1){
    fseek(fp1,0,2);
    cout << "Enter id: ";
    getline(cin, id);
    cout << "Enter password: ";
    getline(cin, key);
    detail.loginid = id;
    detail.password = key;
    fwrite(&detail, sizeof(detail), 1, fp1);
    return 1;
}

int search_details(FILE *fp1, string id, string key){
        unsigned flag = 0;
        while(fread(&detail, sizeof(detail), 1, fp1)==1){
                if((id==detail.loginid) && (key==detail.password)){
                        flag=1;
                        break;
                }
        }
        
        if(flag==0)
                cout << "Invalid credentials" << endl;
        
        return flag;
}