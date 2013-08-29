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
#include "umllinkenddestructiondata_p.h"

#include "private/umlinputpin_p.h"

/*!
    \class UmlLinkEndDestructionData

    \inmodule QtUml

    \brief A link end destruction data is not an action. It is an element that identifies links. It identifies one end of a link to be destroyed by destroy link action.
 */

UmlLinkEndDestructionData::UmlLinkEndDestructionData() :
    _destroyAt(0),
    _isDestroyDuplicates(false)
{
}

// OWNED ATTRIBUTES

/*!
    Specifies the position of an existing link to be destroyed in ordered nonunique association ends. The type of the pin is UnlimitedNatural, but the value cannot be zero or unlimited.
 */
UmlInputPin *UmlLinkEndDestructionData::destroyAt() const
{
    // This is a read-write association end

    return _destroyAt;
}

void UmlLinkEndDestructionData::setDestroyAt(UmlInputPin *destroyAt)
{
    // This is a read-write association end

    if (_destroyAt != destroyAt) {
        _destroyAt = destroyAt;
    }
}

/*!
    Specifies whether to destroy duplicates of the value in nonunique association ends.
 */
bool UmlLinkEndDestructionData::isDestroyDuplicates() const
{
    // This is a read-write property

    return _isDestroyDuplicates;
}

void UmlLinkEndDestructionData::setDestroyDuplicates(bool isDestroyDuplicates)
{
    // This is a read-write property

    if (_isDestroyDuplicates != isDestroyDuplicates) {
        _isDestroyDuplicates = isDestroyDuplicates;
    }
}
