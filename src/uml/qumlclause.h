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
#ifndef QUMLCLAUSE_H
#define QUMLCLAUSE_H

#include <QtUml/QtUmlGlobal>

#include <QtUml/QUmlElement>


QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlExecutableNode;
class QUmlOutputPin;

class Q_UML_EXPORT QUmlClause : public QUmlElement
{
public:
    explicit QUmlClause(bool createQObject = true);
    virtual ~QUmlClause();

    QModelingObject *clone() const;

    // Owned attributes
    const QSet<QUmlExecutableNode *> body() const;
    void addBody(QUmlExecutableNode *body);
    void removeBody(QUmlExecutableNode *body);
    const QList<QUmlOutputPin *> bodyOutput() const;
    void addBodyOutput(QUmlOutputPin *bodyOutput);
    void removeBodyOutput(QUmlOutputPin *bodyOutput);
    QUmlOutputPin *decider() const;
    void setDecider(QUmlOutputPin *decider);
    const QSet<QUmlClause *> predecessorClause() const;
    void addPredecessorClause(QUmlClause *predecessorClause);
    void removePredecessorClause(QUmlClause *predecessorClause);
    const QSet<QUmlClause *> successorClause() const;
    void addSuccessorClause(QUmlClause *successorClause);
    void removeSuccessorClause(QUmlClause *successorClause);
    const QSet<QUmlExecutableNode *> test() const;
    void addTest(QUmlExecutableNode *test);
    void removeTest(QUmlExecutableNode *test);

protected:
    QSet<QUmlExecutableNode *> _body;
    QList<QUmlOutputPin *> _bodyOutput;
    QUmlOutputPin *_decider;
    QSet<QUmlClause *> _predecessorClause;
    QSet<QUmlClause *> _successorClause;
    QSet<QUmlExecutableNode *> _test;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE(QUmlClause) *)

QT_END_HEADER

#endif // QUMLCLAUSE_H

