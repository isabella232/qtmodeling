#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QMap>
#include <QtWidgets/QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace QtUml {
    class QNamedElement;
}

class QTreeWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private Q_SLOTS:
    void on_modelExplorer_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_propertyEditor_itemChanged(QTreeWidgetItem *item, int column);
    void currentIndexChanged(int index);
    void populateModelExplorer(QObject *element, QTreeWidgetItem *parent = 0);
    QTreeWidgetItem *parentItemForProperty(QString propertyGroup);

private:
    Ui::MainWindow *ui;
    QStringList _visitedParents;
    QMap< QString, QPair<int, QTreeWidgetItem *> > _visitedProperties;

    void handleObjectProperties(QObject *element, int level = 0);
    void handleMetaObjectProperties(QObject *element, const QMetaObject *metaObject, int level = 0);
};

#endif // MAINWINDOW_H