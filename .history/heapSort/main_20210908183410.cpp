#include <SFML/Graphics.hpp>
#include<iostream>
#include<bits/stdc++.h>
using namespace sf;

struct Data{
  int height;
  int posx;
  int x;
  int y;
  int z;
};

class Box{
  public:
  std::vector<Data> column;
    Box(int value){
      Data data;
      for(int i=0;i<value;i++){
        data.posx = i;
        data.height = 1 + rand()%(500);
        data.x = i+ rand()%(255);
        data.y = i+ rand()%(255);
        data.z = i+ rand()%(255);
        column.push_back(data);
      }
    }
    void swap(int left,int right){
      std::swap(column[left].height,column[right].height);
    }
};


int main(){

  //Inputs
  int n=400;
  Box b(n);

  int type=0, i=0,largest,l,r,length=99;
  largest=l=r=0;

  // bool isSpacePressed=true;

  std::queue<int> st;
  for(int i = n / 2 - 1; i >= 0; i--) st.push(i);
  i = st.front();
  st.pop();

  //Window
  RenderWindow appWindow(VideoMode(800,600),"heap Sort");
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
      if(!type){

            largest = i; // Initialize largest as root
            l = 2 * i + 1; // left = 2*i + 1
            r = 2 * i + 2; // right = 2*i + 2
        
            // If left child is larger than root
            if (l < length && b.column[l].height >= b.column[largest].height)
                largest = l;
        
            // If right child is larger than largest so far
            if (r < length && b.column[r].height >= b.column[largest].height)
                largest = r;
        
            // If largest is not root
            if (largest != i) {
                b.swap(i,largest);
                i = largest;
            }
            else{
              if(st.empty()){
                type =1;

              }else{
                i = st.front();
                st.pop();
              }
            }
          
      }

      
      if(type){
        b.swap(0,length);
        for(int i = n - 1; i >= 0; i--) st.push(i);
        length--;
        type = 0;
      }

    //PRINT
    for(auto x:b.column){
      rectangle.setFillColor(Color(x.x,x.y,x.z));
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

