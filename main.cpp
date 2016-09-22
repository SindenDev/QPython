#include "qpython.h"
int main()
{

    QPython pytest;
   if(nullptr != pytest.callMethod("testList", "HelloWorld"))
   {
       pytest.testTransferDict();
       pytest.testClass();
   }
   return 0;
}



