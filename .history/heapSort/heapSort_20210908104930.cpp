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

  int n=800;
  // bool srt=true;


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

  while(appWindow.isOpen()){

    while(appWindow.pollEvent(appEvent)){
      if(appEvent.type == Event::Closed) appWindow.close();
    }











    for(auto i:b.column){
      rectangle.setFillColor(Color(235,149,13));
      rectangle.setPosition(i.posx,600);
      rectangle.setSize(Vector2f(2,i.height));
      rectangle.setRotation(180);
      appWindow.draw(rectangle);
    }


    appWindow.display();

    
    appWindow.clear(Color::Black);
    appWindow.draw(fondo);
  }

  return 0;
}

