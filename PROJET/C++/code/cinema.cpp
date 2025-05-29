#include <iostream>
#include <string>

using namespace std;

// Classe pour représenter une réservation
class Reservation {
public:
    string userName;
    string movieTitle;
    string hallName;
    string date;
    string seatNumber;
    string cardNumber;

    Reservation(string userName, string movieTitle, string hallName, string date, string seatNumber, string cardNumber)
        : userName(userName), movieTitle(movieTitle), hallName(hallName), date(date), seatNumber(seatNumber), cardNumber(cardNumber) {}
};

// Classe pour un nœud dans la liste chaînée
class Node {
public:
    Reservation* reservation;
    Node* next;

    Node(Reservation* reservation) : reservation(reservation), next(nullptr) {}
};

// Classe pour gérer la liste chaînée de réservations
class ReservationList {
private:
    Node* head;

public:
    ReservationList() : head(nullptr) {}

    void addReservation(string userName, string movieTitle, string hallName, string date, string seatNumber, string cardNumber) {
        Reservation* newReservation = new Reservation(userName, movieTitle, hallName, date, seatNumber, cardNumber);
        Node* newNode = new Node(newReservation);
        newNode->next = head;
        head = newNode; // Ajoute à la tête de la liste
    }

    void displayReservations() {
        Node* temp = head;
        cout << "Réservations:\n";
        while (temp) {
            cout << "Nom: " << temp->reservation->userName 
                 << ", Film: " << temp->reservation->movieTitle 
                 << ", Salle: " << temp->reservation->hallName 
                 << ", Date: " << temp->reservation->date 
                 << ", Siège: " << temp->reservation->seatNumber 
                 << ", Carte: " << temp->reservation->cardNumber << "\n";
            temp = temp->next;
        }
    }

    ~ReservationList() {
        Node* temp = head;
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete->reservation;
            delete toDelete;
        }
    }
};

// Fonction principale
int main() {
    ReservationList reservationList;

    string userName, movieTitle, hallName, date, seatNumber, cardNumber;

    cout << "Entrez votre nom: ";
    getline(cin, userName);
    
    cout << "Entrez le nom du film: ";
    getline(cin, movieTitle);
    
    cout << "Entrez le nom de la salle: ";
    getline(cin, hallName);
    
    cout << "Entrez la date (JJ/MM/AAAA): ";
    getline(cin, date);
    
    cout << "Entrez le numéro de siège: ";
    getline(cin, seatNumber);
    
    cout << "Entrez le numéro de carte bancaire: ";
    getline(cin, cardNumber);

    // Ajouter la réservation à la liste
    reservationList.addReservation(userName, movieTitle, hallName, date, seatNumber, cardNumber);

    // Afficher toutes les réservations
    reservationList.displayReservations();

    return 0;
}
