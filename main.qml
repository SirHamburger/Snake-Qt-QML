import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0
import Qt.labs.settings 1.0
import QtQuick.Dialogs 1.1

import "componentCreation.js" as MyScript


ApplicationWindow  {

    property int mColumns: 100
    property int mRows: 50
    property int punkte: 0
    property int gesch: 0
    property color defaultSnakeColor: "white";
    property int colorCaller: -1;
    property color defaultFoodColor: "red"
    property color backgroundColor: "DarkBlue";


    property color nocolor:;
    property int difficulty: 0

    property int recangleSize: 8;


    id: window
    visible: true
    //width: 8*mColumns+150
    //height: 8*mRows
    minimumHeight: 400;
    minimumWidth: 300;
    property alias window: window
    title: qsTr("Snake")
    color: "grey"
    function updateAmount(){
        window.mColumns = gameSettings.columns;
        window.mRows = gameSettings.rows;
        backgroundColor = colorSettings.backgroundColor
    }


    Item
    {
        id: keyhandler
        focus: true
        Keys.onPressed: {
            switch (event.key) {
            case Qt.Key_W :
                msg.keyboardHandler('W');
                break;
            case Qt.Key_S:
                msg.keyboardHandler('S');

                break;
            case Qt.Key_A :
                msg.keyboardHandler('A');
                break;
            case Qt.Key_D :
                msg.keyboardHandler('D');
                break;
             case Qt.Key_Up:
                     msg.keyboardHandler('W');
                 break;
             case  Qt.Key_Down:
                 msg.keyboardHandler('S');
                 break;

             case Qt.Key_Left:
                  msg.keyboardHandler('A');
                 break;

             case  Qt.Key_Right:
                      msg.keyboardHandler('D');
                 break;
            }
        }
    }

    Settings {
            property alias x: window.x
            property alias y: window.y
            property alias width: window.width
            property alias height: window.height
        }


    Settings {
        id: colorSettings

        property color snakeColor;
        property color backgroundColor;

         property color foodColor;
        property bool colorSet;



    }
    Settings {
        id: gameSettings

        property int difficulty;


        property int columns: 100;
        property int rows: 50


    }

    Component.onCompleted: {
        updateAmount();
        if(gameSettings.difficulty ==0)
            first.checked=true;
        if(gameSettings.difficulty==1)
            second.checked=true;
        if(gameSettings.difficulty ==2)
            third.checked=true;
        if(gameSettings.difficulty ==3)
            fourth.checked=true;
        if(colorSettings.colorSet==false)
            colorSettings.backgroundColor="DarkBlue"
        backgroundColor = colorSettings.backgroundColor

        //calcRectangeSize();



    }
    Grid {
        id: cells

        width:parent.width-150;
        height: parent.height;
        columns: mColumns
        rows: mRows
        Repeater {
            model: mColumns*mRows
            Rectangle {
                color: backgroundColor
                border.color: "Black"
                //width: parent.width / parent.columns
                //height: parent.height / parent.rows

               width: recangleSize
               height: recangleSize
            }
        }

        onPositioningComplete:
        {
            calcRectangeSize();
        }


    }

    Connections
    {
        target: msg


        onSend:
        {
            cells.childAt(x,y).color= colorSettings.snakeColor;
        }
        onFood:
        {
            cells.childAt(x,y).color= colorSettings.foodColor
        }

        onRemove:
        {
            cells.childAt(x,y).color=backgroundColor
        }

        onPunkteChanged: {
            punkte+=1;
        }
        onReset:
        {
            punkte=0;
            msg.setDifficulty(difficulty);
        }
        onNewSpeed:
        {
            gesch = speed;
        }

    }





    Column
    {
        id: column
        x: parent.width-150+15
        y: 7
        width: 135
        height: 785
        spacing: 2
        MyButton
         {
             btnText: "Start/Reset";
             onClick: {

                 if(colorSettings.colorSet === false )
                 {
                     colorSettings.snakeColor = defaultSnakeColor;
                  colorSettings.foodColor = defaultFoodColor;
                 colorSettings.colorSet=true;
                 }

               //  mColumns = gameSettings.columns;
               //  mRows = gameSettings.rows;

                msg.getSize(mColumns,mRows);
                 msg.start(cells.childAt(0,0).width);

                 msg.buttonHandler();

             }
         }

        MyButton
         {
             btnText:  "Punkte: " + punkte;

         }
        MyButton
        {
            btnText: "Geschwindigkeit " + gesch;
        }


        GroupBox {

            focus: true
            Keys.onPressed: {
                switch (event.key) {
                case Qt.Key_W || Qt.Key_Up:
                    msg.keyboardHandler('W');
                    break;
                case Qt.Key_S || Qt.Key_Down:
                    msg.keyboardHandler('S');
                    break;
                case Qt.Key_A || Qt.Key_Left:
                    msg.keyboardHandler('A');
                    break;
                case Qt.Key_D || Qt.Key_Right:
                    msg.keyboardHandler('D');
                    break;
                }
            }
            id: groupBox
            title: "Difficulty"

            ColumnLayout {
                //ExclusiveGroup { id: tabPositionGroup }
                RadioButton {
                    id: first
                    text: "Easy"
                    checked: true
                    onCheckedChanged: {
                        if(first.checked )
                        {difficulty=0;
                            gameSettings.difficulty = difficulty;
                            second.checked=false;
                            third.checked=false;
                            fourth.checked=false;
                        }
                    }

                }
                RadioButton {
                    id:second
                    onCheckedChanged: {
                        if(second.checked )
                        {difficulty=1;
                            gameSettings.difficulty = difficulty;
                            first.checked=false;
                            third.checked=false;
                            fourth.checked=false;
                        }
                    }
                    text: "Medium"
                }
                RadioButton {
                    id:third
                    onCheckedChanged: {
                        if(third.checked )
                        {difficulty=2;
                            gameSettings.difficulty = difficulty;
                            second.checked=false;
                            first.checked=false;
                            fourth.checked=false;
                        }
                    }
                    text: "Hard"
                }
                RadioButton {
                    id:fourth
                    onCheckedChanged: {
                        if(fourth.checked )
                        {difficulty=3;
                            gameSettings.difficulty = difficulty;
                             third.checked=false;
                            second.checked=false;
                            first.checked=false;
                        }
                    }
                    text: "Dark Souls"
                }
            }
        }



    }



    MyButton
             {
                 anchors.bottom: parent.bottom
                 anchors.bottomMargin: 5;
                  x: parent.width-150+15
                 btnText: "Settings";
                 onClick: {
                     MyScript.createSpriteObjects();

                 }
             }

onWidthChanged:
    {

        calcRectangeSize();
   }
    onHeightChanged:
    {

        calcRectangeSize();
    }
    function calcRectangeSize()
    {
        if(cells.width / cells.columns< cells.height / cells.rows)
            recangleSize= cells.width / cells.columns;
        else
            recangleSize = cells.height / cells.rows;

        if(recangleSize == 0 || recangleSize == -1)
            recangleSize=8;
    }

}

