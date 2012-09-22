[%- PROCESS 'macros.tpl' -%]
/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** [% GET '$QT_BEGIN_LICENSE:LGPL$' %]
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** [% GET '$QT_END_LICENSE$' %]
**
****************************************************************************/

#include "q${className.lower}.h"
//#include "q${className.lower}_p.h"

QT_BEGIN_NAMESPACE_UML_${currentPackage.replace('::', '_').upper}

/*!
    \class Q${className}

    \inmodule QtUml

    \brief [%- classData.ownedComment.body %]
 */

Q${className}::Q${className}(QObject *parent)
    : QObject(parent)
{
}

Q${className}::~Q${className}()
{
}
[% GENERATEACCESSORS(0, 0) -%]
[% GENERATEACCESSORS(1, 0) -%]
[% GENERATEOPERATIONS(0) -%]

#include "moc_q${className.lower}.cpp"

QT_END_NAMESPACE_UML_${currentPackage.replace('::', '_').upper}
