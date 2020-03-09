import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 375
    height: 812
    id: root

    signal appIsActive()
    signal appIsInactive()

    onAppIsActive: {
        console.log("QML: is now active")
    }
    onAppIsInactive: {
        console.log("QML: is now inactive")
    }
}
