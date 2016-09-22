#ifndef QPYTHON_H
#define QPYTHON_H

#include <QObject>
#include <Python.h>
class QPython : public QObject
{
    Q_OBJECT
public:
    explicit QPython(QObject *parent = 0);
    ~QPython();
    PyObject * callMethod(const QString &module,const QString &func);
    //调用输出"Hello World"函数
    void testTransferDict();
    void testClass();

signals:

public slots:
private:
    void addDict();
};

#endif // QPYTHON_H
