#ifndef BOXFACTORY_H
#define BOXFACTORY_H
#include "box.h"
#include "sampleentry.h"
#include <iostream>
#include <qDebug>
#include <memory>
#include "analyzer.h"

class Analyzer;

class BoxFactory
{
private:
    Analyzer* analyzer;
public:
    BoxFactory(Analyzer* an);
    std::shared_ptr<Box> getBox(int size=0, QString type="", long int off=0, int e=0);
};

#endif // BOXFACTORY_H
