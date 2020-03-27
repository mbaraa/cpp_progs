#include<iostream>
using namespace std;
class Movie{
public:
    string title , rating;
    double ticket;
    string mainCast , director;

    //constructor declaration:
    Movie(double ticket , string rating , string title){ //constructor header
        //"this" keyword is used to access 
        //a global variable within the class
        this -> ticket = ticket;
        this -> rating = rating;
        //same as the classic global calling
        Movie::title = title;
    }

    Movie(string dir){
        //or there is no need to call the global variable if it's
        //name isn't repeated
        director = dir;
    }
    //constructors overloading
    Movie(){
        this -> ticket = 1.2;
        this -> rating = "R";
        Movie::title = "The Silence of the Lamps";   
    }

    void listDetails(){
        cout << "Title: " << title << "\nRating: " << rating 
            << "\nMain Cast: " << mainCast << "\nDirector: " 
            << director << "\nTicket Price: " << ticket << endl; 
    }

};
int main(){
    /*
    nothing here
    just the class example
    
    */
    return 0;
}
