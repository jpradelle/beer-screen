#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#pragma once

class IController
{
public:
    IController();
    ~IController();
    virtual void update() = 0;
    virtual bool isUp() = 0;
    virtual bool isDown() = 0;
    virtual bool isLeft() = 0;
    virtual bool isRight() = 0;
    virtual bool isButton1() = 0;
    virtual bool isButton2() = 0;
    virtual bool isQuit() = 0;

private:

};

#endif