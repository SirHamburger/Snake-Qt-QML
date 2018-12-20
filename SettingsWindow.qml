import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
//import QtQuick.Dialogs 1.0
import Qt.labs.settings 1.0
import QtQuick.Dialogs 1.3




ApplicationWindow {
    id: settings
    visible: true
    width: 400
    height: 500
    title: qsTr("Settings")
    color: "grey"


    Column
    {
        id: column
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        spacing: 5
        MyButton
        {
            anchors.horizontalCenter: parent.horizontalCenter

            btnText: "Snake Color";
            onClick: {
                colorCaller = 0;
                colorDialog.visible=true;

            }
        }

        MyButton
        {
            anchors.horizontalCenter: parent.horizontalCenter

            btnText: "Food Color";
            onClick: {
                colorCaller = 1;
                colorDialog.visible=true;

            }
        }

        MyButton
        {
            anchors.horizontalCenter: parent.horizontalCenter

            btnText: "Background Color";
            onClick: {
                colorCaller = 2;
                colorDialog.visible=true;

            }
        }
        MyButton
        {
            anchors.horizontalCenter: parent.horizontalCenter

            btnText: "Drawback Color";
            onClick: {
                colorCaller = 3;
                colorDialog.visible=true;

            }
        }


        ColorDialog
        {
            id: colorDialog
            visible: false
            title: "Please choose a color"

            onAccepted:
            {
                if(colorCaller == 0)
                    colorSettings.snakeColor= colorDialog.color;
                if(colorCaller==1)
                    colorSettings.foodColor = colorDialog.color;
                if(colorCaller==2)
                {
                    colorSettings.backgroundColor = colorDialog.color;
                    //messageDialog.visible=true;
                    //   updateAmount()
                }
                if(colorCaller==3)
                {
                    colorSettings.drawbackColor= colorDialog.color;
                }

                colorCaller=100;
            }
            onRejected:
            {
                console.log("Canceled")
            }
        }



        RowLayout
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle
            {
                 radius: 	5
                width: 100
                height: 50
                color: "black"
                Text
                {

                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    text: "Anzahl Spalten:"
                    width: 100
                    height: 50
                    color: "white"
                }
            }

            Rectangle
            {
                 radius: 	5
                width: 100
                height: 50
                color: "black"
                TextInput
                {

                    id: amountColumns
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    text: gameSettings.columns
                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                    width: 100
                    height: 50
                    color: "white"
                    onTextEdited:
                    {
                           gameSettings.columns= amountColumns.text;
                    }
                }
            }
           /* MyButton
            {
                btnText: "Spalten speichern"
                onClick:
                {
                    gameSettings.columns= amountColumns.text;
                    //gameSettings.updateAmount()
                    // cells.reload();
                    //    updateAmount()

                }
            }*/
        }

        RowLayout
        {


            Rectangle
            {
                 radius: 	5
                width: 100
                height: 50
                color: "black"
                Text
                {

                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    text: "Anzahl Zeilen:"
                    width: 100
                    height: 50
                    color: "white"
                }
            }

            anchors.horizontalCenter: parent.horizontalCenter
            Rectangle
            {
                width: 100
                height: 50
                color: "black"
                  radius: 	5

                TextInput
                {
                    id: amountRows
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    text: gameSettings.rows

                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                    width: 100
                    height: 50
                    color: "white"
                    onTextEdited:
                    {
                           gameSettings.rows= amountRows.text;
                    }
                }
            }
           /* MyButton
            {
                btnText: "Zeilen speichern"
                onClick:
                {


                    gameSettings.rows= amountRows.text;
                    //updateAmount()
                    // cells.reload();

                }
            }*/
        }




        MessageDialog {
            id: messageDialog
            visible: false
            title: "May I have your attention please"
            text: "Änderungen werden nach dem Neustart aktiv"
            onAccepted: {
                //console.log("And of course you could only agree.")
                //Qt.quit()

            }

        }
    }
    MyButton
    {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter;
        btnText: "Anwenden"
        onClick:
        {


            //gameSettings.rows= amountRows.text;
            updateAmount()
            // cells.reload();

        }
    }
}
