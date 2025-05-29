            #include <iostream>
#include <string>
using namespace std;
struct reservation{
    string name;
    string eventName;
    string date;
    double price;
    string logo;
    reservation* next;
    // constructeur
    reservation( string cname , string ename , string d , double p, string l) : name(cname) , eventName(ename) , date(d) , price(p) , logo(l) , next(nullptr){}

};
class ReservationTicket{
    private:
      reservation* head;
    public:
      ReservationTicket() : head( nullptr) {}
      void addReservation(string name , string eventName , string date , double price, string logo){
        reservation* newreservation = new reservation(name , eventName , date , price , logo);
        if(!head) {
            head = newreservation;
        } 
        else{
            reservation* temp = head ;
            while( temp -> next){
                temp = temp -> next;
            }
            temp -> next = newreservation;
        }
      } 
      ~ReservationTicket(){
        reservation* current =head;
        while( current){
           reservation* next = current -> next;
           delete current;
           current = next;
        }
      }
      void displayreservation(){
        reservation* temp = head ;
        while ( temp ){
            cout << "clien : " << temp -> name ;
            cout << " evenement : " << temp -> eventName;
            cout << " date : " << temp -> date;
            cout << " prix : " << temp ->price;
            cout << " logo : " << temp -> logo;
            temp = temp -> next;
        }
      }
};
int main(){
    ReservationTicket ticket;
    ticket.addReservation( "ANDRE" , "concert religieux" , "24 mai 2025" , 5000 , " logo_concert.ping");
    ticket.addReservation( "DURAN" , "competion course voiture" , " 3 juin 2025" , 10000 , " logo_competion.ping");
    ticket.addReservation( "LANDRY" , " voyage " , "30 mai 2025" , 10000 , " logo_agence.ping");
    cout << " ticket de reservation : "<< endl;
    ticket.displayreservation();
    return 0;
}

