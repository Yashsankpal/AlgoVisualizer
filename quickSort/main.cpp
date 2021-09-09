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
  queue<lst> ls;
  lst tq;

  //Create
  Box(int value){
    Data data;
    for(int i=0;i<value;i++){
      data.posx = i;
      data.height = 1 + rand()%(400);
      column.push_back(data);
    }
  }

  //Swap 
  void bswap(int left,int right){
    swap(column[left].height,column[right].height);
  }

  void qu(int low ,int high){
    tq.low = low;
    tq.high = high;
    ls.push(tq);
  }

  lst front(){
    tq = ls.front();
    ls.pop();
    return tq;
  }

  void bpush(int low,int high){
    tq.low = low;
    tq.high = high;
    ls.push(tq); 
  }
};




int main(){

  //Inputs
  int n=500;
  Box b(n);
  // bool sort = false;

  int low,high,pivot,i,j,part;
  low=high=pivot=0;
  
  b.qu(0,n-1);



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

    if(!b.ls.empty()){
      
      lst tq = b.front();
      
      low = tq.low;
      high = tq.high;
      pivot = b.column[high].height; // pivot 
      i = low; // Index of smaller element and indicates the right position of pivot found so far
    
      for (j = low; j < high; j++) 
      { 
          // If current element is smaller than the pivot 
          if (b.column[j].height < pivot) 
          { 
              b.bswap(i,j); 
              i++; // increment index of smaller element 
          } 
      }

      b.bswap(i, high); 
      part = i;
      if(low < high){
        b.qu(low,part-1);
        b.qu(part+1,high);
      }
    }


    //PRINT
    for(auto x:b.column){
      rectangle.setFillColor(Color(250,100+x.posx,200));
      rectangle.setPosition(x.posx,600);
      rectangle.setSize(Vector2f(2,x.height));
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

