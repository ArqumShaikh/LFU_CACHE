#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#include "LFU.h"

void LFU::Insert_LFU(int key){
  if(NodeList_map[key]!=NULL){
    LookUp(key);
    return;
  }
  frequencylist.Add_FrequencyList(key);
}

void LFU::Delete_LFU(){
  if(frequencylist.head==NULL){
  cout<<"List is Empty\n";
  return;
  }
  frequencylist.Delete_FrequencyList();
}

void LFU::LookUp(int key){
  if(NodeList_map[key]==NULL){
    //cout<<"Key is not present\n";
    frequencylist.Add_FrequencyList(key);
    return;
  }
  //int frequency = NodeList_map[key]->frequency + 1;
  FrequencyList_node * Previous = NodeList_map[key]->prev;
  FrequencyList_node * Next = NodeList_map[key]->prev->next;
  int frequency=Previous->frequency;
  frequencylist.RemoveFrom_FrequencyList(key,frequency);
    if(Previous->head==NULL)
    {
      FrequencyList_node * temp = Previous->prev;
      free(Previous);
      FrequencyList_map[frequency]=NULL;
      Previous=temp;
    }
  frequencylist.Insert_FrequencyList(key,frequency+1,Previous,Next);
return ;
}

void LFU::PrintLFU(){
  FrequencyList_node *fptr= frequencylist.head;
    while(fptr!=NULL){
      cout<<"Count "<<fptr->frequency<<":";
      NodeList_node *nptr =fptr->head;
        while(nptr!=NULL){
          cout<<nptr->key<<" ";
          nptr=nptr->next;
        }
        cout<<"\n";
        fptr=fptr->next;
    }
  return ;
}

void FrequencyList::Add_FrequencyList(int key){
  FrequencyList_node *fptr=lfu.FrequencyList_map[1];
    if(fptr==NULL){
      fptr = new FrequencyList_node ;
      fptr->frequency=1;
      fptr->next=frequencylist.head;
      fptr->prev=NULL;
      frequencylist.head=fptr;
    }
    lfu.FrequencyList_map[1]=fptr;
  //  NodeList_node * nptr=lfu.NodeList_map[key];
    NodeList_node* nptr = new NodeList_node;
    nptr->key=key;
    nptr->next=NULL;
    nptr->prev=fptr;
    nptr->prevnode=fptr->tail;
    lfu.NodeList_map[key]=nptr;
      if(fptr->head==NULL){
        fptr->head=fptr->tail=nptr;
        return;
      }
      fptr->tail->next= nptr;
      fptr->tail=nptr;
return;
}

void FrequencyList::Delete_FrequencyList(){
    FrequencyList_node *fptr=frequencylist.head;
    int frequency=fptr->frequency;
    lfu.NodeList_map[fptr->head->key]=NULL;
    NodeList_node *temp = fptr->head;
    fptr->head->prevnode=NULL;
    fptr->head=fptr->head->next;
    free(temp);
      if(fptr->head==NULL){
      //  free(fptr);
        lfu.FrequencyList_map[frequency]=NULL;
        frequencylist.head=frequencylist.head->next;
        free(fptr);
      }
return ;
}

void FrequencyList::RemoveFrom_FrequencyList(int key,int frequency){
  FrequencyList_node *fptr=lfu.FrequencyList_map[frequency];
  NodeList_node * nptr=lfu.NodeList_map[key];
    if(nptr==fptr->head){
      fptr->head=nptr->next;
    //  free(nptr);
    //  return;
    }
    if(nptr->next!=NULL)
    nptr->next->prevnode=nptr->prevnode;
    if(nptr->prevnode!=NULL)
    nptr->prevnode->next=nptr->next;
    free(nptr);
  //  lfu.NodeList_map[key]=NULL;
}

void FrequencyList::Insert_FrequencyList(int key,int frequency,FrequencyList_node *Previous,FrequencyList_node *Next){
  FrequencyList_node *fptr = lfu.FrequencyList_map[frequency];
    if(fptr==NULL){
      lfu.FrequencyList_map[frequency]=fptr= new FrequencyList_node;
      fptr->frequency=frequency;
      fptr->next=Next;
      fptr->prev=Previous;
      fptr->head=fptr->tail=NULL;
    }
      if(Previous==NULL){
        frequencylist.head=fptr;
      }
      if(Next!=NULL){
        Next->prev=fptr;
        }
      if(Previous!=NULL){
        Previous->next=fptr;
        }


    NodeList_node *nptr = new NodeList_node;
    lfu.NodeList_map[key]=nptr;
    nptr->key=key;
    nptr->prev=fptr;
    nptr->next=NULL;
    nptr->prevnode=fptr->tail;
          if(fptr->tail!=NULL){
          fptr->tail->next=nptr;
          }
    fptr->tail=nptr;
          if(fptr->head==NULL){
            fptr->head=nptr;
          }
return ;
}

int main()
{
  int num_op,op;
  printf("Enter the number of operations to be performed \n");
  cin>>num_op;
    while(num_op--){
  printf("\nThe operations are - \n1.AddValue Value : Insert Value into the Cache. \n2.LookUpValue Value : Check if Value is there and increment Frequency.\n3.EvictFromCache  : Remove least Frequent Element. \n4.PrintLFU : Print the Elements in LFU. Format = Frequency: List of Elements.\nEnter the serial number corresponding to the operation \n");
  cin>>op;
    if(op==1){
      int value;
      cout<<"Enter the value to be inserted"<<endl;
      cin>>value;
      lfu.Insert_LFU(value);
    }
    else if(op==2){
      int value;
      cout<<"Enter the value to be looked up"<<endl;
      cin>>value;
      lfu.LookUp(value);
    }
    else if(op==3){
      lfu.Delete_LFU();
    }
    else if(op==4){
      lfu.PrintLFU();
    }
    else{
      cout<<"Invalid Operation Number\n";
    }
 }
return 0;
}
