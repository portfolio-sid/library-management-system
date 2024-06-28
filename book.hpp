#include <iostream>


using namespace std;
int search_title(FILE *fp, string title);
int search_author(FILE *fp, string author);
int search_cat(FILE *fp, string category);

typedef struct{
    int year;
    string number;
}bookid;

typedef enum{
    available, issued, removed
}status;


struct{
    bookid bid;
    status s;
    string cat;
    string title; 
    string author;
    double price;
}book;


void insert(FILE *fp){
        fseek(fp,0,2);
        cout << "Enter year: ";
        cin >> book.bid.year;
        cout << "Enter book number: ";
        cin >> book.bid.number;
        getchar();
        cout << "Enter name of the author: ";
        getline(cin, book.author);
        cout << "Enter title of the book: ";
        getline(cin, book.title);
        cout << "Enter price of the book: ";
        cin >> book.price;
        getchar();
        cout << "Enter the category: ";
        getline(cin, book.cat);
        book.s=available;
        cout << "Book entry successful" << endl;
        fwrite(&book, sizeof(book), 1, fp);
}

void change_status(FILE *fp){
        rewind(fp);
        int new_status;
        string title;
        getchar();
        cout << "Enter the title of the book: ";
        getline(cin, title); 
        if(search_title(fp, title)){
                cout << "available-0,issued-1,removed-2: " ;
                cin >> new_status;
                if(new_status==0){
                        book.s = available;
                        cout << "Status changed" << endl;
                }
                else if(new_status==1){
                        book.s = issued;
                        cout << "Status changed" << endl;
                }
                else if(new_status==2){
                        book.s = removed;
                        cout << "Status changed" << endl;
                }
                else
                        cout << "Not valid." << endl;
        }

        fseek(fp, -sizeof(book), 1);
        fwrite(&book, sizeof(book), 1, fp);

}       


void display(FILE *fp){
        rewind(fp);
        string title;
        int count=1;
        getchar();
        cout << "Enter the title of the book: ";
        getline(cin, title);
        while(!feof(fp)){                       //while of the condition so that keeps on reading till end is reached
                if(search_title(fp, title)){
                        cout << "--------------------------------------" << endl;
                        cout << "Bookid: " << book.bid.year << book.bid.number << endl;
                        cout << "Title of the book: " << book.title << endl;
                        cout << "Author: " << book.author << endl;
                        cout << "Status: ";
                        if(book.s==issued)
                                cout << "Issued" << endl;
                        else if(book.s==available)
                                cout << "Available" << endl;
                        else
                                cout << "Removed" << endl;
                        cout << "Category: " << book.cat << endl;
                        cout << "Price: " << book.price << endl;
                        cout << "--------------------------------------" << endl;
                        count++;
                }
        }
        if(count==1)
                cout << "No book by this title." << endl;

}



void list_category(FILE *fp){
        rewind(fp);
        int count=1;
        string category;
        getchar();
        cout << "Enter the category: ";
        getline(cin, category);
        while(!feof(fp)){                    
                if(search_cat(fp, category)){
                        cout << "--------------------------------------" << endl;
                        cout << "Count: " << count << endl;
                        cout << "Bookid: " << book.bid.year << book.bid.number << endl;
                        cout << "Title of the book: " << book.title << endl;
                        cout << "Author: " << book.author << endl;
                        cout << "Price: " << book.price << endl;
                        cout << "Status: ";
                        if(book.s==issued)
                                cout << "Issued" << endl;
                        else if(book.s==available)
                                cout << "Available" << endl;
                        else
                                cout << "Removed" << endl;
                        cout << "--------------------------------------" << endl;
                        count++;
                }
        
        }
        if(count==1)
                cout << "No books in this category." << endl;
        rewind(fp);

}

void list_author(FILE *fp){
        rewind(fp);
        int count=1;
        string author;
        getchar();
        cout << "Enter name of the author: ";
        getline(cin, author);
        while(!feof(fp)){                      
                if(search_author(fp, author )){
                        cout << "--------------------------------------" << endl;
                        cout << "Count: " << count << endl;
                        cout << "Bookid: " << book.bid.year << book.bid.number << endl;
                        cout << "Title of the book: " << book.title << endl;
                        cout << "Status: ";
                        if(book.s==issued)
                                cout << "Issued" << endl;
                        else if(book.s==available)
                                cout << "Available" << endl;
                        else
                                cout << "Removed" << endl;
                        cout << "Category: " << book.cat << endl;
                        cout << "Price: " << book.price << endl;
                        cout << "--------------------------------------" << endl;
                        count++;
                }
        }
        if(count==1)
                cout << "No books by this author." << endl;
        rewind(fp);
}

int search_title(FILE *fp, string title){
        unsigned flag = 0;
        while(fread(&book, sizeof(book), 1, fp)==1){         //so that it reads one item which is a struct here
                if(title==book.title){
                        flag=1;
                        break;
                }
        }
        
        return flag;
}


int search_author(FILE *fp, string author){
        unsigned flag = 0;
        while(fread(&book, sizeof(book), 1, fp)==1){
                if(author==book.author){
                        flag=1;
                        break;
                }
        }
        
        return flag;
}


int search_cat(FILE *fp, string category){
        unsigned flag = 0;
        while(fread(&book, sizeof(book), 1, fp)==1){
                if(category==book.cat){
                        flag=1;
                        break;
                }
        }
        
        return flag;
}


