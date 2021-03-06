#pragma once

#include <QObject>
#include <QProcess>
#include <QString>
#include <QVariant>
#include <QVariantList>

#include "util/cpp/PropertyHelper.h"

class Pacman : public QObject {
    Q_OBJECT

public:
    explicit Pacman(QObject* parent = nullptr);

    std::vector<QString> readConfigFile();

    QProcess* pRepos;
    QProcess* pNextUpdateList;
    QProcess* pRepoSummary;
    QProcess* pNextUpdateSize;
    QProcess* pLastUpgradeTime;
    QProcess* pMyAurHelper;
    QProcess* pQueryFileDB;

    Q_INVOKABLE void execPackages();
    Q_INVOKABLE void execNextUpdateList();
    Q_INVOKABLE void execRepoSummary();
    Q_INVOKABLE void execNextUpdateSize();
    Q_INVOKABLE void execMyAurHelper();
    Q_INVOKABLE void execLastUpgradeTime();
    Q_INVOKABLE void execQueryFileDB(QString file);

    void returnPackages();
    void returnNextUpdateList();
    void returnRepoSummary();
    void returnNextUpdateSize();
    void returnLastUpgradeTime();
    void returnMyAurHelper();
    void returnQueryFileDB();

public slots:

signals:
    void modelReady(QVariantList model);
    void singleModelReady(QVariant singleModel);
    void lastUpdateTimeReady(QVariant lastUpdateTime);
    void myAurHelperReady(QVariant myAurHelper);

private:
};
