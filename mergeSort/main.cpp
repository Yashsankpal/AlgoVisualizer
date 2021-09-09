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
  vector<Data> column;
  stack<lst> st;
  int mid;
    Box(int value){
      Data data;
      for(int i=0;i<value;i++){
        data.posx = i;
        data.height = 1 + rand()%(500);
        column.push_back(data);
      }
    }
    void bpush(int low,int high){
      lst ls;
        ls.low = low;
        ls.high = high;
        st.push(ls);
    }

    void init(int low,int high){
      if(low<high){
        bpush(low,high);
        mid = (low+high)/2;
        init(low,mid);
        init(mid+1,high);
      }
    }

    lst bfront(){
      lst i = st.top();
      st.pop();
      return i;
    }
};


int main(){

  //Inputs
  int n=900;
  Box b(n);

  int type=0,low,high,mid;
  lst tq;
  int arr1[1000],arr2[1000];
  // bool isSpacePressed=true;

  b.init(0,n-1);

  //Window
  RenderWindow appWindow(VideoMode(1000,1000),"merge Sort");
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

    if(!b.st.empty()){

      tq = b.bfront();
      low = tq.low;
      high = tq.high;
      mid = (low+high)/2;

      int n1,n2;
  
      n1 = mid-low+1;
      n2 = high-mid;


      for(int i = 0;i<n1;i++) arr1[i]=b.column[low+i].height;
      for(int i = 0;i<n2;i++) arr2[i]=b.column[mid+1+i].height;

      int l,i,r;
      l=r=0;
      i=low;
      while(l<n1 && r<n2){
        if(arr1[l] <= arr2[r]){
          b.column[i].height = arr1[l];
          l++; 
        }else{
          b.column[i].height = arr2[r];
          r++;
        }
        i++;
      }

      while( l < n1){
        b.column[i].height = arr1[l];
        l++;
        i++;
      }
      while( r < n2){
        b.column[i].height = arr2[r];
        r++;
        i++;
      }
    }

    //PRINT
    for(auto x:b.column){
      rectangle.setFillColor(Color(255,100+x.posx,200));
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

