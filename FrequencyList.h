#include "NodeList.h"

class FrequencyList_node{
public:
  FrequencyList_node *next;
  FrequencyList_node *prev;
  int frequency;
  NodeList_node *head;
  NodeList_node *tail;
  FrequencyList_node(){
    head=NULL;
    tail=NULL;
  }
};

//#include "NodeList.h"

class FrequencyList{

public:FrequencyList_node* head;

public:
        FrequencyList(){
          head=NULL;
        }
        void Add_FrequencyList(int key);
        void Insert_FrequencyList(int key,int frequency,FrequencyList_node*,FrequencyList_node* );
      //  void Insert_NodeList();
        void Delete_FrequencyList();
      //  void Delete_NodeList();
        void RemoveFrom_FrequencyList(int key,int frequency );
    //    friend class FrequencyList_node;
  //      friend class LFU;
//        friend class NodeList_node;
}frequencylist;
