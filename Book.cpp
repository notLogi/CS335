#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book(){}

    Book::~Book()
    {
        delete icon_;
    }

    Book::Book(const Book& rhs)
    {
        this->author_ = rhs.title_;
        this->author_ = rhs.author_;
        this->ISBN_ = rhs.ISBN_;
        this->icon_ = rhs.icon_;
        this->price_ = rhs.price_;
        this->keywords_ = rhs.keywords_;
        this->blurb_ = rhs.blurb_;
    }

    Book& Book::operator=(const Book& rhs)
    {
        if(this == &rhs){
            return *this;
        }
            this->title_ = rhs.title_;
            this->author_ = rhs.author_;
            this->ISBN_ = rhs.ISBN_;
            this->icon_ = rhs.icon_;
            this->price_ = rhs.price_;
            this->keywords_ = rhs.keywords_;
            this->blurb_ = rhs.blurb_;
            return *this;
    }

    Book::Book(Book&& rhs)
    {
        this->title_ = std::move(rhs.title_);
        this->author_ = std::move(rhs.author_);
        this->ISBN_ = std::move(rhs.ISBN_);
        this->icon_ = std::move(rhs.icon_);
        this->price_ = std::move(rhs.price_);
        this->keywords_ = std::move(rhs.keywords_);
        this->blurb_ = std::move(rhs.blurb_);
    }

    Book& Book::operator=(Book&& rhs)
    {
        if(this == &rhs){
            return *this;
        }
        this->title_ = std::move(rhs.title_);
        this->author_ = std::move(rhs.author_);
        this->ISBN_ = std::move(rhs.ISBN_);
        this->icon_ = std::move(rhs.icon_);
        this->price_ = std::move(rhs.price_);
        this->keywords_ = std::move(rhs.keywords_);
        this->blurb_ = std::move(rhs.blurb_);
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
        icon_ = icon;
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
        bool test = false;
        std::string keyword = "";
        for(int i = 0; i < getKeywords().size(); i++){
            keyword += getKeywords()[i]; 
            while(!test){
                keyword += ", ";
                if(i == getKeywords().size()){
                    test = true;
                }
            }  
        }
        std::cout << "Title: " << getTitle() << std::endl << "Author: " << 
        getAuthor() << std::endl << "ISBN: " << getISBN() << std::endl
        << "Icon: " << getIcon() << std::endl << "Price: " << getPrice() << std::endl
        << "Keywords: " << keyword << std::endl << "Blurb: " << getBlurb() << "\n\n";
    }
