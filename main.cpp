#include <bits/stdc++.h>
using namespace std;
//create struct for books
struct Book{
    int id , quantity ,borrowed ;
    string name;
    Book (int Id , int Quantity , string Name)
    {
        id = Id;
        quantity = Quantity;
        name = Name;
        borrowed = 0;
    }
    void print()
    {
        cout << "id = " << id << " name = " << name << " total quantity = " << quantity << " total borrowed = "<< borrowed<<'\n';
    }
};
//create struct for users
struct User{
    int Id ;
    string Name;
    vector <string> borrowed_books;
    User(int id , string name)
    {
        Id = id;
        Name = std::move(name);
        borrowed_books = {};
    }
};

//create vector to contain all books
vector <Book> books;

//create vector to contain all users
vector <User> users;

//compare functions to sort vector of books by name , id
bool compare_books_id(const Book& b1,const Book& b2)
{
    return (b1.id < b2.id);
}
bool compare_books_name(const Book& b1,const Book& b2){
    return (b1.name < b2.name);
}

//functions to check if book , user exist
bool exist_user( string & name)
{
    for (auto & user : users)
    {
        if(user.Name == name)
            return true;
    }
    return false;
}
bool exist_book( string & name)
{
    for (auto & book : books)
    {
        if(book.name == name)
            return true;
    }
    return false;
}
//my functions
void add_book()
{
    cout << "Enter book info : 'id' & 'name' & 'total quantity' \n ";
    int id , total_quantity;
    string name;
    bool found = false;
    cin >> id >> name >> total_quantity;
    Book book = Book(id , total_quantity , name);
    for (auto & book : books)
    {
        if(book.name == name && book.id == id)
        {
            book.quantity += total_quantity;
            found = true;
            break;
        }
    }
    if(!found)
    {
        books.push_back(book);
    }
}
void search_book_by_prefix(){
    cout << "enter the prefix \n";
    string prefix;
    cin >> prefix;
    bool found = false;
    for (auto & book : books)
    {
        bool differ = true;
        for (int j = 0 ; j < prefix.size() ; ++j)
        {
            if(prefix[j] != book.name[j]){
                differ = false;
                break;
            }
        }
        if(differ)
        {
            found = true;
            cout<<book.name<<'\n';
        }
    }
    if(!found)
        cout<<"there is no book contain this prefix \n";

}
void print_who_borrowed_book_by_name()
{
    cout << "Enter book name \n";
    string bookname;
    cin >> bookname;
    bool borrowed = false;
    for (auto & user : users) {
        for (int j = 0; j < user.borrowed_books.size() ; ++j)
        {
            if(user.borrowed_books[j] == bookname){
                cout << user.Name << endl;
                borrowed = true;
                break;
            }
        }
    }
    if(!borrowed)
        cout << "The book is not borrowed yet \n";
}
void print_library_by_id()
{
    sort(books.begin() , books.end() ,  compare_books_id);
    for (auto & book : books)
    {
        book.print();
    }
}
void print_library_by_name(){
    sort(books.begin() , books.end() ,  compare_books_name);
    for (auto & book : books)
    {
        book.print();
    }
}
void add_user()
{
    cout << "Enter user name & national id \n";
    string username;
    int id;
    cin >> username >> id;
    User user = User(id,username);
    users.push_back(user);
}
void borrow_book()
{
    cout << "Enter username and book name \n";
    string username,bookname;
    cin >> username >> bookname;
    if(exist_book(bookname) && exist_user(username))
    {
        for (auto & book : books)
        {
            if(book.name==bookname)
            {
                if(!book.quantity)
                {
                    cout<<"the available quantity is not sufficient \n";
                    return;
                }
                book.quantity-=1;
                book.borrowed+=1;
            }
        }
        for (auto & user : users) {
            if(user.Name == username)
            {
                user.borrowed_books.push_back(bookname);
            }
        }
    }
    else
    {
        cout<<"Invalid user name or book name \n";
    }
}
void print_users()
{
    for(auto & user : users){
        cout << "user " << user.Name <<" id " << user.Id << " borrowed books name :" ;
        for (auto & borrowed_book : user.borrowed_books)
        {
            cout << borrowed_book << " ";
        }
        cout<<'\n' ;
    }
}
void return_book()
{
    cout << "Enter username & book name \n";
    string username,bookname;
    cin >> username >> bookname;
    if(exist_book(bookname) && exist_user(username)) {
        for (auto &book: books)
        {
            if (book.name == bookname)
            {
                book.quantity += 1;
                book.borrowed -= 1;
            }
        }
        for (auto &user: users)
        {
            auto it = user.borrowed_books.begin();
            for (int j = 0; j < user.borrowed_books.size(); ++j)
            {
                if (user.borrowed_books[j] == bookname)
                {
                    user.borrowed_books.erase(it);
                }
                it++;
            }
        }
    }
}
int main()
{
    while (true)
    {
        cout << "1) Add a book \n" ;
        cout << "2) Search books by prefix \n";
        cout << "3) print who borrowed book by name \n";
        cout << "4) print library by id \n";
        cout << "5) print library by name \n";
        cout << "6) add user \n";
        cout << "7) user borrow book \n";
        cout << "8) user return book \n";
        cout << "9) print users \n" ;
        cout << "10 Exit \n";
        cout << "\n";
        cout <<  "Enter you menu choice [ 1 -10 ] \n";
        int n;
        cin >> n;
        if ( n == 1 )
        {
            add_book();
            cout<<"-----------------------\n";
        }
        else if ( n == 2 )
        {
            search_book_by_prefix();
            cout<<"-----------------------\n";
        }
        else if ( n == 3 )
        {
            print_who_borrowed_book_by_name();
            cout<<"-----------------------\n";
        }
        else if ( n == 4 )
        {
            print_library_by_id();
            cout<<"-----------------------\n";
        }
        else if ( n == 5 )
        {
            print_library_by_name();
            cout<<"-----------------------\n";
        }
        else if ( n == 6 )
        {
            add_user();
            cout<<"-----------------------\n";
        }
        else if ( n == 7 )
        {
            borrow_book();
            cout<<"-----------------------\n";
        }
        else if ( n == 8 )
        {
            return_book();
            cout<<"-----------------------\n";
        }
        else if ( n == 9 )
        {
            print_users();
            cout<<"-----------------------\n";
        }
        else
        {
            break;
        }
    }
}