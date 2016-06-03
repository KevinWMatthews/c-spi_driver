#ifndef __Test_SpiSlave_H
#define __Test_SpiSlave_H

class Test_SpiSlave
{
  public:
    explicit Test_SpiSlave();
    virtual ~Test_SpiSlave();

  private:
    Test_SpiSlave(const Test_SpiSlave&);
    Test_SpiSlave& operator=(const Test_SpiSlave&);
};

#endif
