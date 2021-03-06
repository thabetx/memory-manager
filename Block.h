#ifndef BLOCK
#define BLOCK

class Block{
protected:
  int base;
  int limit;
public:
  Block(int base=0,int limit=0);
  virtual int getId();
  virtual bool isOccupied();
  void setBase(int base);
  int getBase();
  void setLimit(int limit);
  int getLimit();
};

#endif
