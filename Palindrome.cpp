#include <iostream>
using namespace std;
#include <cstring>

int main() {

  char filter[81];
  int viable;

  cout << "Type no more than 80 characters! No Spaces!\n";
  cin.getline(filter,80);

  // setting a number for a new filtered screen; count if character is a Alphabet (not a space too)
  for (int i = 0; i < strlen(filter); i++) {
    if (isalpha(filter[i]) && !isspace(filter[i])) {
      viable++;
    }
  }

  // convert Alphabets to lowercase; made using a diferent source
  int i = 0;
  while(filter[i])
  {
      if(filter[i] == std::toupper(filter[i]) && std::isalpha(filter[i]) == 1024)
      filter[i]+= 32;
      ++i;
  }

  // Setting new char arrays (1 for normal; 1 reversed) and a for for loops
  char input[viable];
  char newinput[viable];
  int a = viable-1;

  // going through orginal and transerring only if it a alphabet (no space)
  for (int i = 0; i < strlen(filter); i++) {
    if (isalpha(filter[i]) && !isspace(filter[i])) {
      input[a]=filter[i];
      a--;
    }
  }

  // resetting a to use it for newinput (backwards); the a and i are at opposite ends
  a = viable-1;
  for (int i = 0; i < strlen(input); i++) {
    newinput[a]=input[i];
    a--;
  }

  // comparing input to newinput; if not equal then not a palindrome & break; if it comes to last character then its a palindrome (equal check is before this so)
  cout << "\n";
  for (int i = 0; i < strlen(input); i++) {
    if (!(input[i] == newinput[i])) {
      cout << "Not a palindrome";
      break;
    }
    if (i == strlen(input)-1) {
      cout << "Palindrome";
    }
  }

}

/*
Sources :
https://www.codegrepper.com/code-examples/cpp/convert+char+array+to+lowercase+c%2B%2B : I used this to convert to lowercase alphabets
*/
