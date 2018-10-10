#include "FrequencyList.h"
class LFU{
public:unordered_map<int,FrequencyList_node*> FrequencyList_map;
       unordered_map<int,NodeList_node*> NodeList_map;

public:
  void Insert_LFU(int key);
  void Delete_LFU();
  void LookUp(int key);
  void PrintLFU();
}lfu;
