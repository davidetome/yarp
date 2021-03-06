/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

import QtQuick 2.0
import QtQuick.Controls 1.1


MenuBar {

    property bool rightClickVisible: false;

    signal quit()
    signal about()
    signal freeze(bool checked)
    signal setOriginalSize()
    signal setOriginalAspectRatio()
    signal synchDisplayPeriod(bool checked)
    signal synchDisplaySize(bool checked)
    signal changeRefreshInterval()
    signal saveSingleImage(bool checked)
    signal saveSetImages(bool checked)
    signal pickColor(bool checked)
    signal rightClickEnable(bool checked)

    function enableSynch(check){
        if(check === true){
            synchItem.checked = true
        }else{
            synchItem.checked = false
        }
    }

    function externallyCheckRightClick(check){
        rightClickVisible = check;
        rightClickItem.checked = check;
    }

    function enableAutosize(check){
        if(check === true){
            autosizeItem.checked = true
        }else{
            autosizeItem.checked = false
        }
    }

    // NB: This is not the best solution but the fastest one.
    /*!
      \brief Changes the "saveSingle" menu checked state
      \param checked Bollean: Whether or not the menu item has to be checked
      */
    function saveSingleChecked(checked){
        saveSingle.checked = checked;
    }
    /*!
      \brief Changes the "saveSet" menu checked state
      \param checked Bollean: Whether or not the menu item has to be checked
      */
    function saveSetChecked(checked){
        saveSet.checked = checked;
    }

    Menu {

        title: "File"

        MenuItem { id: saveSingle
                   text: "Save single image..."
                   checkable: true
                   onTriggered: {
                       saveSingleImage(saveSingle.checked)
                       saveSet.checked = false
                       saveSetImages(saveSet.checked)
                   }}
        MenuItem {  id: saveSet
                    text: "Save a set of images..."
                    checkable: true
                    onTriggered: {
                        saveSetImages(saveSet.checked)
                        saveSingle.checked = false
                        saveSingleImage(saveSingle.checked)
                    }}
        MenuSeparator{}
        MenuItem { text: "Quit"
            onTriggered: {
                quit()
            }}
    }

    Menu {
        title: "Image"
        MenuItem { text: "Original Size"
                   onTriggered: {
                       setOriginalSize()
                   }}
        MenuItem { text: "Original aspect ratio"
                    onTriggered: {
                        setOriginalAspectRatio()
                    }}
        MenuSeparator{}
        MenuItem { id: freezeItem
                   text: "Freeze"
                   checkable: true
                   onTriggered: {
                       freeze(freezeItem.checked)
                   }}
        MenuSeparator{}
        MenuItem { id: synchItem
                   text: "Synch display"
                   checkable: true
                   onTriggered: {
                       synchDisplayPeriod(synchItem.checked)
                   }}
        MenuSeparator{}
        MenuItem { id: autosizeItem
                   text: "Auto resize"
                   checkable: true
                   onTriggered: {
                       synchDisplaySize(autosizeItem.checked)
                   }}
        MenuSeparator{}
        MenuItem { id: colorPickerItem
                   text: "Display pixel value"
                   checkable: true
                   onTriggered: {
                       pickColor(colorPickerItem.checked);
                   }}
        MenuSeparator{}
        MenuItem { id: rightClickItem
                   text: "Intercept right click"
                   visible: rightClickVisible
                   checkable: true
                   onTriggered: {
                       rightClickEnable(rightClickItem.checked);
                   }}
        MenuSeparator{
                   visible: rightClickVisible
        }
        MenuItem { text: "Change refresh interval"
                    onTriggered: {
                        changeRefreshInterval()
                    }}
    }
    Menu {
        title: "Help"
        MenuItem { text: "About..."
            onTriggered: {
                about()
                   }
        }
    }

}
