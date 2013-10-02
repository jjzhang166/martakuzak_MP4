#ifndef BOXFACTORY_H
#define BOXFACTORY_H
#include "box.h"
#include "sampleentry.h"
#include "sampletablebox.h"
#include <iostream>
#include <qDebug>
#include <memory>
#include "analyzer.h"

class Analyzer;

class BoxFactory
{
private:
    /*!
     * \brief analyzer
     */
    Analyzer* analyzer;
public:
    /*!
     * \brief BoxFactory
     * \param an analyzer that enables reading extra parameters of the box.
     */
    BoxFactory(Analyzer* an);
    /*!
     * \brief getBox creates Box according to the given parameters and adds extra parameters depending on type of the box.
     * \param size
     * \param type
     * \param off
     * \param e
     * \return Box created according to the given and extra parametrs
     */
    std::shared_ptr<Box> getBox(int size=0, QString type="", long int off=0, int e=0);
};

#endif // BOXFACTORY_H
