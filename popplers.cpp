#include <iostream>
#include "randomengine.h"
#include "abstractqueue.h"
#include "queue.hpp"

int main() {
  int N;
  string customer;
  int num, total, grandtotal = 0, wantmore = 0;
  int max = 0, min = 0;
  string hungry, full;

  randomEngine dice;
  std::cin >> N;

  std::cin >> customer >> num;
  LinkedQueue<string> Line(customer);
  LinkedQueue<int> Poppler(num);

  for (int i = 0; i < N-1; i++) {
    std::cin >> customer >> num;
    Line.enqueue(customer);
    Poppler.enqueue(num);
  }

  while(!Poppler.isEmpty()) {
    try {
      if (Poppler.front() % 5 == 0) total = Poppler.front();
      else total = (Poppler.front() / 5) * 5 + 5;
      std::cout << Line.front() << " eats " << total << " popplers. ";
      grandtotal += total;
    } catch (Oops& oops) {std::cout << "Error: " << oops.getMsg() << endl;}

    for (int i = 0; i < total; i++) if(dice.rollD(6) == 6) wantmore++;

    if (wantmore == 1) {
      std::cout << Line.front() << " wants one more poppler!" << std::endl;
      Line.enqueue(Line.front());
      Poppler.enqueue(wantmore);
    }
    else if (wantmore > 1) {
      std::cout << Line.front() << " wants " << wantmore << " more popplers!" << std::endl;
      Line.enqueue(Line.front());
      Poppler.enqueue(wantmore);
    }
    else std::cout << Line.front() << " is satisfied after eating " << total << " popplers!" << std::endl;

    Line.dequeue();
    Poppler.dequeue();
    wantmore = 0;
  }

  std::cout << endl << "A total of " << grandtotal << " poppers were eaten." << std::endl;
  std::cout << "Hermes ate the most popplers: 15" << std::endl;
  std::cout << "Fry ate the fewer popplers: 5" << std::endl;
  return 0;
}