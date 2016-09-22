#include "qpython.h"
#include <iostream>
using namespace std;

QPython::QPython(QObject *parent) : QObject(parent)
{
    Py_Initialize();              //使用python之前，要调用Py_Initialize();这个函数进行初始化
}

QPython::~QPython()
{
    Py_Finalize();                //调用Py_Finalize,这个和Py_Initialize相对应的.
}

PyObject* QPython::callMethod(const QString &module,const QString &func)
{
    PyObject * pModule = nullptr;    //声明变量
    PyObject * pFunc = nullptr;      //声明变量
    pModule =PyImport_ImportModule(qPrintable(module));              //这里是要调用的Python文件名
    if(pModule == nullptr) return pModule;

    pFunc= PyObject_GetAttrString(pModule, qPrintable(func));   //这里是要调用的函数名
    if(pFunc == nullptr) return pFunc;

    return PyEval_CallObject(pFunc, NULL);                         //调用函数,NULL表示参数为空
}

void QPython::testTransferDict()
{
    addDict();
    PyObject * pModule = NULL;
    PyObject * pFunc = NULL;
    pModule =PyImport_ImportModule("testList");      //testList:Python文件名
    pFunc= PyObject_GetAttrString(pModule, "TestDict"); //Add:Python文件中的函数名

    PyObject *pArgs = PyTuple_New(1);
    PyObject *pDict = PyDict_New();   //创建字典类型变量
    PyDict_SetItemString(pDict, "Name", Py_BuildValue("s", "WangYao")); //往字典类型变量中填充数据
    PyDict_SetItemString(pDict, "Age", Py_BuildValue("i", 25));         //往字典类型变量中填充数据
    PyTuple_SetItem(pArgs, 0, pDict);//0---序号  将字典类型变量添加到参数元组中

    PyObject *pReturn = NULL;
    pReturn = PyEval_CallObject(pFunc, pArgs);      //调用函数

    int size = PyDict_Size(pReturn);
    cout << "Dict size: " << size << endl;
    PyObject *pNewAge = PyDict_GetItemString(pReturn, "Age");
    int newAge;
    PyArg_Parse(pNewAge, "i", &newAge);
    cout << "True Age: " << newAge << endl;
}

void QPython::testClass()
{
    PyObject * pModule = NULL;
    PyObject * pFunc = NULL;
    pModule =PyImport_ImportModule("testList");      //testList:Python文件名
    pFunc= PyObject_GetAttrString(pModule, "TestDict"); //Add:Python文件中的函数名

    PyObject *pClassPerson = PyObject_GetAttrString(pModule, "Person");

    PyObject *pInstancePerson = PyInstance_New(pClassPerson, NULL, NULL);
    PyObject_CallMethod(pInstancePerson, "greet", "s", "Hello Kitty");
}

void QPython::addDict()
{
    PyObject * pModule = NULL;
    PyObject * pFunc = NULL;
    pModule =PyImport_ImportModule("testList");      //testList:Python文件名
    pFunc= PyObject_GetAttrString(pModule, "add");  //Add:Python文件中的函数名

    PyObject *pArgs = PyTuple_New(2);               //函数调用的参数传递均是以元组的形式打包的,2表示参数个数
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 5));//0---序号  i表示创建int型变量
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", 7));//1---序号

    PyObject *pReturn = NULL;
    pReturn = PyEval_CallObject(pFunc, pArgs);      //调用函数

    int result;
    PyArg_Parse(pReturn, "i", &result);    //i表示转换成int型变量
    cout << "5+7 = " << result << endl;
}
