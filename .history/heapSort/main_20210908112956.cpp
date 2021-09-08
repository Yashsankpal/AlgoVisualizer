#include <SFML/Graphics.hpp>
#include<iostream>
#include<bits/stdc++.h>
using namespace sf;

struct Data{
  int height;
  int posx;
};

class Box{
  public:
  std::vector<Data> column;
    Box(int value){
      Data data;
      for(int i=0;i<value;i++){
        data.posx = i;
        data.height = 1 + rand()%(400);
        column.push_back(data);
      }
    }
};


int main(){
  Box b(800);

  int n=800 , type=0, i=499,largest,l,r;
  largest=l=r=0;
  



  RenderWindow appWindow(VideoMode(800,600),"Bubble Sort");
  Event appEvent;
  Texture fondot;
  fondot.loadFromFile("fondo1.png");
  Sprite fondo(fondot);

  RectangleShape rectangle(Vector2f(2,178));
  rectangle.setFillColor(Color(235,149,13));

  appWindow.clear(Color::Black);
  appWindow.draw(fondo);

  srand(time(NULL));

  //LOOP
  while(appWindow.isOpen()){
    // CLOSING LOOP
    while(appWindow.pollEvent(appEvent)){
      if(appEvent.type == Event::Closed) appWindow.close();
    }

    //A single loop
    switch(type){
      //Max heap
      case 0:
      {
        if(2*i+1 > 800 && 2*i+2 > 800 && i>0){
          i--;
        }
        else{
          largest = i; // Initialize largest as root
          l = 2 * i + 1; // left = 2*i + 1
          r = 2 * i + 2; // right = 2*i + 2
      
          // If left child is larger than root
          if (l < n && b.column[l].height > b.column[largest].height)
              largest = l;
      
          // If right child is larger than largest so far
          if (r < n && b.column[r].height > b.column[largest].height)
              largest = r;
      
          // If largest is not root
          if (largest != i) {
              b.column[i].height=b.column[i].height + b.column[largest].height;
              b.column[largest].height=b.column[i].height - b.column[largest].height;
              b.column[i].height=b.column[i].height - b.column[largest].height;

              i = largest;
          }
        }
        break;
      }
      //Swap heap
      case 1:
      {
        break;
      }
    }

    //PRINT
    for(auto i:b.column){
      rectangle.setFillColor(Color(235,149,13));
      rectangle.setPosition(i.posx,600);
      rectangle.setSize(Vector2f(2,i.height));
      rectangle.setRotation(180);
      appWindow.draw(rectangle);
    }

    //DISPLAY
    appWindow.display();

    //CLEAR
    appWindow.clear(Color::Black);
    appWindow.draw(fondo);
  }

  return 0;
}

