#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book(): title_(""), author_(""), ISBN_(0), icon_(nullptr), price_(0.0), blurb_(""){}

    Book::~Book()
    {
        if(icon_ != nullptr){//if icon has any bitvalue pointed, delete it and set it to nullptr.
            delete[] icon_;
            icon_ = nullptr;
        }
    }

    Book::Book(const Book& rhs):title_(rhs.title_), author_(rhs.author_), ISBN_(rhs.ISBN_), price_(rhs.price_),blurb_(rhs.blurb_)//copy constructor
    {
        if(rhs.icon_ != nullptr){
            icon_ = new int[80];
            std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
        }
        else{
            icon_ = nullptr;
        }
        keywords_ = rhs.keywords_;
    }   

Book &Book::operator=(const Book &rhs) // deep copy
{
    if (this != &rhs) 
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        blurb_ = rhs.blurb_;

        if (icon_ != nullptr)
        {
            delete[] icon_;
        }

        if (rhs.icon_ != nullptr)
        {
            icon_ = new int[80];
            std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
        }
        else
        {
            icon_ = nullptr;
        }
        keywords_ = rhs.keywords_;
    }
    return *this;
}

    Book::Book(Book&& rhs)//move constructor
    {   //here, I am basically turning the lvalues into rvalues.
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        icon_ = std::move(rhs.icon_);
        rhs.icon_ = nullptr;
        price_ = std::move(rhs.price_);
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
    }

    Book& Book::operator=(Book&& rhs)//swapping the rvalues to this.
    {
        if(this != &rhs){
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = std::move(rhs.ISBN_);
            icon_ = std::move(rhs.icon_);
            rhs.icon_ = nullptr;
            price_ = std::move(rhs.price_);
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
        }
        return *this;
    }

    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }   

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        if(icon_ != nullptr){
            delete[] icon_;
            icon_ = nullptr;    
        }
        icon_ = new int[80];
        std::copy(icon, icon + 80, icon_);
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price; 
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    void Book::print() const
    {
        std::string keyword = "";
        for(int i = 0; i < keywords_.size(); i++){
            keyword += keywords_[i]; 
            if(i < keywords_.size() - 1){//reason for this is because you don't want to have another comma if there is no other keyword.
                keyword += ", ";
            }
        }
        std::cout << "Title: " << getTitle() << std::endl << "Author: " << 
        getAuthor() << std::endl << "ISBN: " << getISBN() << std::endl
        << "Icon: ";
        for(int i = 0; i < 80; i++){
            std::cout << icon_[i] << " ";
        }
        std::cout <<"\nPrice: $" << std::fixed << std::setprecision(2) << getPrice() << std::endl
        << "Keywords: " << keyword << std::endl << "Blurb: " << getBlurb() << "\n\n";
    }