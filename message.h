#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <spielfeld.h>
#include <QTimer>
#include <exception>





class Message : public QObject
{
    Q_OBJECT
   //Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
public:
    explicit Message(QObject *parent = nullptr);
    void sendKoordinates(int x, int y);
   // QString author() const ;
   // void setAuthor(const QString &a);
    void startGame();
    void removeKoordinates(int x, int y);
    void sendFood(int x, int y);


signals:
 //void authorChanged();
 void send(int x, int y);
 void remove(int x, int y);
 void timeout();
 void punkteChanged();
 void reset();
 void newSpeed(int speed);
 void food(int x, int y);

public slots:
    void timer();
    void buttonHandler();
    void keyboardHandler(QChar key);
    void setDifficulty(int diff);
    void start(int scale);
    void getSize(int sizeX, int sizeY);
private:
   //QString m_author;
    int x=0;
    int y=0;
    int tInt = 170;
    char lastkey='D';
    Spielfeld *feld=nullptr;
    QTimer *varTimer = nullptr;
    bool started=false;
    int difficulty;
    bool block=false;
    int scale;

};

#endif // MESSAGE_H
