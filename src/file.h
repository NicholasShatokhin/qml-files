
#ifndef QML_FILES_FILE_H
#define QML_FILES_FILE_H

#include <qqml.h>
#include <QtCore/qobject.h>
#include <QtQml/5.2.0/QtQml/private/qtqmlglobal_p.h>


class wQFilePrivate;
class Q_QML_PRIVATE_EXPORT wQFile : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(wQFile)
    Q_INTERFACES(QQmlParserStatus)
    
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    
    Q_PROPERTY(bool    exists        READ exists)
    Q_PROPERTY(QString symLinkTarget READ symLinkTarget)
    Q_PROPERTY(qint64  size          READ size)
    
public:
    wQFile(QObject *parent=0);
    
protected:
    void classBegin();
    void componentComplete();
    
public slots:
    // bool    copy(const QString & newName);
    bool    exists() const;
    // bool    link(const QString & linkName);
    // bool    open(FILE * fh, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle);
    // bool    open(int fd, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle);
    // bool    remove();
    // bool    rename(const QString & newName);
    void    setFileName(const QString & name);
    QString symLinkTarget() const;
    
    QString fileName() const;
    // bool    open(OpenMode mode);
    // Permissions permissions() const;
    // bool    resize(qint64 sz);
    // bool    setPermissions(Permissions permissions);
    qint64  size() const;
    
    // FileError   error() const
    // bool    flush()
    // int handle() const
    // uchar * map(qint64 offset, qint64 size, MemoryMapFlags flags = NoOptions)
    // bool    unmap(uchar * address)
    // void    unsetError()
    
    // bool    atEnd() const
    // void    close()
    // bool    isSequential() const
    // qint64  pos() const
    // bool    seek(qint64 pos)

    // qint64  bytesAvailable() const
    // qint64  bytesToWrite() const
    // bool    canReadLine() const
    // QString errorString() const
    // bool    getChar(char * c)
    // bool    isOpen() const
    // bool    isReadable() const
    // bool    isTextModeEnabled() const
    // bool    isWritable() const
    // OpenMode    openMode() const
    // qint64  peek(char * data, qint64 maxSize)
    // QByteArray  peek(qint64 maxSize)
    // bool    putChar(char c)
    // qint64  read(char * data, qint64 maxSize)
    // QByteArray  read(qint64 maxSize)
    // QByteArray  readAll()
    // qint64  readLine(char * data, qint64 maxSize)
    // QByteArray  readLine(qint64 maxSize = 0)
    // bool    reset()
    // bool    seek(qint64 pos)
    // void    setTextModeEnabled(bool enabled)
    // void    ungetChar(char c)
    // bool    waitForBytesWritten(int msecs)
    // bool    waitForReadyRead(int msecs)
    // qint64  write(const char * data, qint64 maxSize)
    // qint64  write(const char * data)
    // qint64  write(const QByteArray & byteArray)
    
signals:
    // void    aboutToClose()
    // void    bytesWritten(qint64 bytes)
    // void    readChannelFinished()
    // void    readyRead()
};


#endif
