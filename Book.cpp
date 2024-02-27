#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book(): title_(""), author_(""), ISBN_(0), icon_(nullptr), price_(0.0), blurb_(""){}

    Book::~Book()
    {
        if(this->icon_ != nullptr){
            delete[] this->icon_;
            this->icon_ = nullptr;
        }
    }

    Book::Book(const Book& rhs)
    {
        this->author_ = rhs.title_;
        this->author_ = rhs.author_;
        this->ISBN_ = rhs.ISBN_;
        if(icon_ == nullptr){
            this->icon_ = new int[80];
        }
        else{
            for(int i = 0; i < 80; i++){
                this->icon_[i] = rhs.icon_[i];
            }
        }
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
            if(this->icon_ == nullptr){
                this->icon_ = new int[80];
            }
            for(int i = 0; i < 80; i++){
                this->icon_[i] = rhs.icon_[i];
            }
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
        rhs.icon_ = nullptr;
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
        delete[] icon_;
        this->icon_ = std::move(rhs.icon_);
        rhs.icon_ = nullptr;
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
        std::cout << "Title: " << title_ << std::endl << "Author: " << 
        author_ << std::endl << "ISBN: " << ISBN_ << std::endl
        << "Icon: ";
        for(int i = 0; i < 80; i++){
            std::cout <<icon_[i] << " ";
        }
        std::cout << std::endl << "Price: $" << std::fixed << std::setprecision(2) << price_ << std::endl
        << "Keywords: " << keyword << std::endl << "Blurb: " << blurb_ << "\n\n";
    }
