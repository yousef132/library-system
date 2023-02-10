# library-system

## 1.0 Overview

It's a hospital system for only one user (admin) , he can do the following :

- [Adding a book to the system](2.1-Adding-a-book-to-the-system) 

- [Searching for a book by it's prefix]() .

- [Printing who borrowed book]() .

- [Printing the library by id]() .

- [Printing the library by name]() .

- [Adding user]().

- [User borrow a book]() .

- [User return a book]() .

- [Prining users]() .


## 2.0 Functions used in the project

### 2.1 Adding a book to the system

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



### 2.1 Searching for a book by it's prefix

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






















































































