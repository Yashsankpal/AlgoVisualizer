#include <SFML/Graphics.hpp>
#include<iostream>
#include<bits/stdc++.h>
using namespace sf;
using namespace std;

struct Data{
  int height;
  int posx;
};

class Box{
  public:
  vector<Data> column;
  queue<int> st;
    Box(int value){
      Data data;
      for(int i=0;i<value;i++){
        data.posx = i;
        data.height = 1 + rand()%(500);
        column.push_back(data);
      }
    }
    void bswap(int left,int right){
      swap(column[left].height,column[right].height);
    }
    void init(int n){
      for(int i = n / 2 - 1; i >= 0; i--) st.push(i);
    }
    int bfront(){
      int i = st.front();
      st.pop();
      return i;
    }
    void bRequeue(int n){
      for(int i = n; i >= 0; i--) st.push(i);
    }
};


int main(){

  //Inputs
  int n=400;
  Box b(n);

  int type=0, i=0,largest,l,r,length=n-1;
  largest=l=r=0;

  // bool isSpacePressed=true;

  b.init(n);
  i = b.bfront();

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
                b.bswap(i,largest);
                i = largest;
            }
            else{
              if(b.st.empty()){
                type =1;

              }else{
                i = b.bfront();
              }
            }
          
      }

      
      if(type){
        b.bswap(0,length);
        b.bRequeue(n-1);
        length--;
        type = 0;
      }

    //PRINT
    for(auto x:b.column){
      rectangle.setFillColor(Color(255,i,200));
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

