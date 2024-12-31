/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 *   @brief Custom QGCCorePlugin Implementation
 *   @author Gus Grubba <gus@auterion.com>
 */

#include <iostream>
#include <QtQml>
#include <QQmlEngine>
#include <QDateTime>
#include "QGCSettings.h"
#include "MAVLinkLogManager.h"
#include "CustomPlugin.h"

#include "MultiVehicleManager.h"
#include "QGCApplication.h"
#include "SettingsManager.h"
#include "AppMessages.h"
#include "QmlComponentInfo.h"
#include "QGCPalette.h"
#include "QDetectedObject.h"

QGC_LOGGING_CATEGORY(CustomLog, "CustomLog")

CustomPlugin::CustomPlugin(QGCApplication* app, QGCToolbox* toolbox)
    : QGCCorePlugin(app, toolbox)
{
    std::cout << "CustomPlugin::CustomPlugin" << std::endl;
}

bool CustomPlugin::mavlinkMessage(Vehicle* vehicle, LinkInterface* link, mavlink_message_t message)
{
    Q_UNUSED(vehicle);
    Q_UNUSED(link);
    switch (message.msgid) {
    case MAVLINK_MSG_ID_DEBUG_VECT:
        _handleDebugVect(message);
        break;
    }
    return true;
}

void CustomPlugin::_handleDebugVect(const mavlink_message_t& message)
{
    mavlink_debug_vect_t debugVect;
    mavlink_msg_debug_vect_decode(&message, &debugVect);
    // std::cout << "DEBUG VECT: " << debugVect.name << " " << debugVect.time_usec << " " << debugVect.x << " " << debugVect.y << " " << debugVect.z << std::endl;
    QGeoCoordinate coord(debugVect.x, debugVect.y, 300);
    customMapItems()->append(new QDetectedObject(coord, debugVect.name, QUrl("DetectedObjectIndicator.qml")));
}

CustomPlugin::~CustomPlugin()
{
}