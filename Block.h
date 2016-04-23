#ifndef BLOCK
#define BLOCK

class Block{
private:
  int base;
  int limit;
public:
  virtual int getId();
  virtual bool isOccupied();
  void setBase(int b);
  int getBase();
  void setLimit(int l);
  int getLimit();
};

#endif
