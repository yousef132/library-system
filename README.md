# library-system

## 1.0 Overview

It's a hospital system for only one user (admin) , he can do the following :

- [Adding a book to the system](#Adding-a-book-to-the-system) .

- [Searching for a book by it's prefix](#Searching-for-a-book-by-its-prefix) .

- [Printing who borrowed book](#Printing-who-borrowed-book) .

- [Printing the library by id](#Printing-the-library-by-id) .

- [Printing the library by name](#Printing-the-library-by-name) .

- [Adding user](#Adding-user) .

- [User borrow a book](#User-borrow-a-book) .

- [User return a book](#User-return-a-book) .

- [Prining users](#Prining-users) .


## 2.0 Functions used in the project

### Adding a book to the system

  - Code :

```cpp

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

```

---------

### Searching for a book by it's prefix

  - Code :

```cpp

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

```

-------------------------


### Printing who borrowed book

  - Code :

```cpp

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

```

-------------

### Printing the library by id


- Code :

```cpp  

void print_library_by_id()
{
    sort(books.begin() , books.end() ,  compare_books_id);
    for (auto & book : books)
    {
        book.print();
    }
}


```

- NOTE : I used compare function to sort books by id .

   - Code : 

```cpp

//compare functions to sort vector of books by name , id
bool compare_books_id(const Book& b1,const Book& b2)
{
    return (b1.id < b2.id);
}

```

--------------------------------

### Printing the library by name


- Code :

```cpp  

void print_library_by_name(){

    sort(books.begin() , books.end() ,  compare_books_name);
    for (auto & book : books)
    {
        book.print();
    }
}


```

- NOTE : I used compare function to sort books by name .

   - Code : 

```cpp

//compare functions to sort vector of books by name , id
bool compare_books_name(const Book& b1,const Book& b2){
    return (b1.name < b2.name);
}

```

--------------

###  Adding user

- Code :

```cpp

void add_user()
{
    cout << "Enter user name & national id \n";
    string username;
    int id;
    cin >> username >> id;
    User user = User(id,username);
    users.push_back(user);
}

```

------------------------

### User borrow a book

- Code :


```cpp
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

```

-----------------

### User return a book

- Code :


```cpp

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

```

----------------------

### Printing users

- Code :

```cpp

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


```


 



















































































