#include <SFML/Graphics.hpp>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;

struct Data{
  int height;
  int posx;
};

struct lst{
  int low;
  int high;
};

class Box{
  public:
  int part=0;
  vector<Data> column;

  //Create
  Box(int value){
    Data data;
    for(int i=0;i<value;i++){
      data.posx = i;
      data.height = 1 + rand()%(500);
      column.push_back(data);
    }
  }

  //Swap 
  void swap(int left,int right){
    swap(column[left].height,column[right].height);
  }

};




int main(){

  //Inputs
  int n=400;
  Box b(n);
  // bool sort = false;

  int low,high,pivot,i,j;
  low=high=pivot=0;
  
  queue<lst> qu;
  lst ls;

  ls.low = 0;
  ls.high = n-1;
  qu.push(ls);



  //Window
  RenderWindow appWindow(VideoMode(800,600),"quick Sort");
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

    if(!qu.empty()){
      
      lst tq = qu.front();
      qu.pop();
      
      pivot = b.column[tq.high].height; // pivot 
      i = (tq.low - 1); // Index of smaller element and indicates the right position of pivot found so far
    
      for (j = tq.low; j < tq.high; j++) 
      { 
          // If current element is smaller than the pivot 
          if (b.column[j].height < pivot) 
          { 
              i++; // increment index of smaller element 
              b.swap(i,j); 
          } 
      }

      b.swap(i + 1, tq.high); 

      lst ts;
      if(i != tq.low){
        ts.low = tq.low;
        ts.high = i;
        qu.push(ts);
      }
      if(i+1 != tq.high){
        ts.low = i+2;
        ts.high = tq.high;
        qu.push(ts);
      }

    }


    //PRINT
    for(auto x:b.column){
      rectangle.setFillColor(Color(250,100,200));
      rectangle.setPosition(x.posx,600);
      rectangle.setSize(Vector2f(1,x.height));
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

