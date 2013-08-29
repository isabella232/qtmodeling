/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "umlimage_p.h"

/*!
    \class UmlImage

    \inmodule QtUml

    \brief Physical definition of a graphical image.
 */

UmlImage::UmlImage()
{
}

// OWNED ATTRIBUTES

/*!
    This contains the serialization of the image according to the format. The value could represent a bitmap, image such as a GIF file, or drawing 'instructions' using a standard such as Scalable Vector Graphic (SVG) (which is XML based).
 */
QString UmlImage::content() const
{
    // This is a read-write property

    return _content;
}

void UmlImage::setContent(QString content)
{
    // This is a read-write property

    if (_content != content) {
        _content = content;
    }
}

/*!
    This indicates the format of the content - which is how the string content should be interpreted. The following values are reserved: SVG, GIF, PNG, JPG, WMF, EMF, BMP. In addition the prefix 'MIME: ' is also reserved. This option can be used as an alternative to express the reserved values above, for example "SVG" could instead be expressed as "MIME: image/svg+xml".
 */
QString UmlImage::format() const
{
    // This is a read-write property

    return _format;
}

void UmlImage::setFormat(QString format)
{
    // This is a read-write property

    if (_format != format) {
        _format = format;
    }
}

/*!
    This contains a location that can be used by a tool to locate the image as an alternative to embedding it in the stereotype.
 */
QString UmlImage::location() const
{
    // This is a read-write property

    return _location;
}

void UmlImage::setLocation(QString location)
{
    // This is a read-write property

    if (_location != location) {
        _location = location;
    }
}
