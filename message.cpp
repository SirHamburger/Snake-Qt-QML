#include "message.h"



Message::Message(QObject *parent) : QObject(parent)
{

}


//void Message::setAuthor(const QString &a) {
//    if (a != m_author) {
//        m_author = a;
//        for(int i= 0; i < 50; i++)
//        emit send(i,i);
//        emit authorChanged();
//    }
//}

void Message::startGame()
{


    x=0;
    y=0;
    tInt = 170;


    lastkey='D';
    emit reset();


    if(difficulty==0)
    {

    }
    if(difficulty==1)
    {
        if(tInt==170)
            tInt = 130;

    }
    if(difficulty==2)
    {
        if(tInt==170)
            tInt = 110;

    }
    if(difficulty==3)
    {
        if(tInt==170)
            tInt = 70;

    }
    emit newSpeed(tInt);

    if (varTimer != nullptr)
        varTimer->stop();
    if(started)
    {
        for(int i =0 ; i < feld->getSizeX(); i ++)
        {
            for(int j = 0; j < feld->getSizeY(); j ++)
            {
                if(feld->getFeld()[i][j].getHasPoop())
                    removeKoordinates(i,j);
            }
        }
            while(!feld->getSnake().getSnake().empty())
        {
            removeKoordinates(feld->getSnake().getSnake().front().getXKoordinate(),feld->getSnake().getSnake().front().getYKoordinate());
            feld->getSnake().getSnake().pop();
        }
        removeKoordinates(feld->getFood().getXKoordinate(), feld->getFood().getYKoordinate());
    }
    started=true;

    feld = new Spielfeld();
    feld->generateFood();
    sendFood(feld->getFood().getXKoordinate(),feld->getFood().getYKoordinate());
    varTimer = new QTimer(this);
    connect(varTimer, SIGNAL(timeout()), this, SLOT(timer()));
    varTimer->start(tInt);




    block=false;




}

void Message::removeKoordinates(int x, int y)
{
    emit remove(x*scale,y*scale);
}

void Message::sendFood(int x, int y)
{
    emit food(x*scale,y*scale);
}

void Message::timer()
{
    if(!block){
        block = true;

        if(x < 0|| x >= Spielfeld::getSizeX())
        {
            varTimer->stop();
            return;
        }
        if(y < 0 || y >= Spielfeld::getSizeY())
        {    varTimer->stop();
            return;
        }
        int px = x;
        int py = y;


        feld->getFeld()[feld->getSnake().getSnake().front().getXKoordinate()][feld->getSnake().getSnake().front().getYKoordinate()].setHasSnake(false);

        if(difficulty==3)
        {
            if(!feld->getFeld()[feld->getSnake().getSnake().front().getXKoordinate()][feld->getSnake().getSnake().front().getYKoordinate()].getHasPoop())
                removeKoordinates(feld->getSnake().getSnake().front().getXKoordinate(),feld->getSnake().getSnake().front().getYKoordinate());

        }
        else
            removeKoordinates(feld->getSnake().getSnake().front().getXKoordinate(),feld->getSnake().getSnake().front().getYKoordinate());

        switch(lastkey)
        {
        case 'W':
            y--;
            break;
        case 'A':
            x--;

            break;
        case 'S':

            y++;
            break;
        case 'D':

            x++;

            break;
        }
        if(x < 0|| x >=Spielfeld::getSizeX())
        {
            varTimer->stop();
            return;
        }
        if(y < 0 || y >= Spielfeld::getSizeY())
        {    varTimer->stop();
            return;
        }

        if(feld->getFeld()[x][y].getHasSnake() || feld->getFeld()[x][y].getHasPoop())
            varTimer->stop();


        sendKoordinates(x,y);



        if(!feld->getFeld()[x][y].getHasFood())
        {
            feld->getSnake().deleteLastPosition();
            feld->getSnake().addNewPosition(x,y);
        }
        else
        {
            feld->getFeld()[feld->getFood().getXKoordinate()][feld->getFood().getYKoordinate()].setHasFood(false);

            if(difficulty==3)
                feld->getFeld()[feld->getFood().getXKoordinate()][feld->getFood().getYKoordinate()].setHasPoop(true);

            feld->getSnake().addNewPosition(x,y);
            sendKoordinates(px,py);
            //  removeKoordinates(feld->getFood().getXKoordinate(),feld->getFood().getYKoordinate());


            feld->generateFood();
            sendFood(feld->getFood().getXKoordinate(),feld->getFood().getYKoordinate());

            if(difficulty==0)
            {



                tInt=100;
            }
            if(difficulty==1)
            {

                tInt=tInt-tInt/20;
                if (tInt< 75)
                    tInt=75;
            }
            if(difficulty==2)
            {

                tInt = tInt - tInt/10;
                if (tInt<50)
                    tInt = 50;
            }
            if(difficulty==3)
            {

                tInt = tInt - tInt/10;
                if (tInt<50)
                    tInt = 50;
            }
            varTimer->setInterval(tInt);
            emit punkteChanged();
            emit newSpeed(tInt);
        }

        feld->getFeld()[x][y].setHasSnake(true);


        block = false;
    }
}

void Message::buttonHandler()
{
    startGame();
}

void Message::keyboardHandler(QChar key)
{
    int temp = key.toLatin1();
    lastkey= (char)temp;
}

void Message::setDifficulty(int diff)
{
    this->difficulty = diff;
}

void Message::start(int scale)
{

    this->scale = scale;
}

void Message::getSize(int sizeX, int sizeY)
{
    feld->setSizeX(sizeX);
    feld->setSizeY(sizeY);
}
//QString Message::author() const {
//    return m_author;
//}
void Message::sendKoordinates(int x, int y)
{
    emit send(x*scale,y*scale);
}


