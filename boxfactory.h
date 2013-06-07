#ifndef BOXFACTORY_H
#define BOXFACTORY_H
#include <QDebug>
#include "box.h"
#include <iostream>
#include <qDebug>
#include <memory>
class BoxFactory
{
public:
    BoxFactory();
    std::shared_ptr<Box> getBox(int size=0, QString type="", long int off=0, int e=0);
};

#endif // BOXFACTORY_H
