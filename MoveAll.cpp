
#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE
  std::vector<Book>::iterator it;//an iterator
  for(it = source.begin(); it != source.end();){
    const auto &book = *it;//i made a reference instead of a copy since it is "expensive"
    bool dummy = false;
    for(const auto &key : book.getKeywords()){
      if(key == keyword){
        dummy = true;
        }
      }
      if(dummy){//if true, turns the object it is "pointing" to to a rvalue then pushes.
        dest.push_back(std::move(*it));
          it = source.erase(it);
          books_moved++;
      }
      else{//if false, pre-increment it by 1 because it goes back to the last element
        ++it;
      }
    }
  


  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}