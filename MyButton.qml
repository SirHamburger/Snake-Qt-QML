import QtQuick 2.0



    Rectangle
    {


        id: rootItm;
        property string btnText: "fill me";
        signal click();
        width: 100
        height: 50
        color: "black"

      radius: 	5

        clip: true;
        Text
        {

            color: "white"
            text: btnText
            anchors.centerIn: parent
        }

        MouseArea
        {
            anchors.fill: parent
            onReleased:
            {
                rootItm.click();
            }
        }
    }

