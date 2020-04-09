#include <fstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

class NoteInterface {
  private:
  public:
  string noteString;
  int userChoice;
  void* note_interface(void) {
	  while (userChoice != 2) {
      LABEL : 
      cout << "MENU" << endl;
      Sleep(2000);
      cout << "1. Add a New Note" << endl;
      cout << "2. Exit Application" << endl;
      cout << "Select an option> " << endl;
      cin >> userChoice;

      if (userChoice == 1) {
        cout << "########## ADD A NEW NOTE ##########" << endl;
        cout << "Write your note> ";
        cin >> noteString;
        cout << "Saving..." << endl;
        addNote(noteString);
        Sleep(2000);
        system("cls");
      }
      else if (userChoice == 2) {
        Sleep(1000);
        cout << "Exiting..." << endl;
        Sleep(2000);
        exit(1);
      }
      else {
        cout << "#### PLEASE SELECT A VALID OPTION ####" << endl;
      }
    }
  } 
  void* addNote(string note) {
    fstream file;
    file.open("notes.dat", ios::binary | ios::app | ios::in);
    file << "Note> " << note;
    cout << "Note Saved!";
    file.close();
  }
  ~NoteInterface() {
    cout << "########## THANKS FOR USING ##########" << endl;
  }
  protected:
};

int main() {
  system("cls");
  NoteInterface noteInterface;
  noteInterface.note_interface();
  return 0;
}
