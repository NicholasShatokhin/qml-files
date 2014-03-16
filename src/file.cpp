
#include "file.h"


wQFile::wQFile(QObject *parent) { Q_UNUSED(parent); WQ_INIT_PRIV(QFile); }

void wQFile::classBegin() { }

void wQFile::componentComplete() { }


///
// Public Functions


// bool    wQFile::copy(const QString & newName)

bool    wQFile::exists() const
{ WQ_PRIV(const QFile); return o->exists(); };

// bool    wQFile::link(const QString & linkName)

// bool    wQFile::open(FILE * fh, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    wQFile::open(int fd, OpenMode mode, FileHandleFlags handleFlags = DontCloseHandle)

// bool    wQFile::remove()

// bool    wQFile::rename(const QString & newName)

void    wQFile::setFileName(const QString & name)
{ WQ_PRIV(QFile); return o->setFileName(name); };

QString wQFile::symLinkTarget() const
{ WQ_PRIV(const QFile); return o->symLinkTarget(); };


///
// Reimplemented Public Functions


QString wQFile::fileName() const
{ WQ_PRIV(const QFile); return o->fileName(); };

bool    wQFile::open(OpenMode mode)
{ WQ_PRIV(QFile); return o->open((QIODevice::OpenMode)mode); };

// Permissions wQFile::permissions() const

// bool    wQFile::resize(qint64 sz)

// bool    wQFile::setPermissions(Permissions permissions)

qint64  wQFile::size() const
{ WQ_PRIV(const QFile); return o->size(); };


///
// public functions inherited from QFileDevice


// FileError   wQFile::error() const

// bool    wQFile::flush()

// int wQFile::handle() const

// uchar * wQFile::map(qint64 offset, qint64 size, MemoryMapFlags flags = NoOptions)

// bool    wQFile::unmap(uchar * address)

// void    wQFile::unsetError()


///
// reimplemented public functions inherited from QFileDevice


// bool    wQFile::atEnd() const

void    wQFile::close()
{ WQ_PRIV(QFile); return o->close(); };

// bool    wQFile::isSequential() const

// qint64  wQFile::pos() const

// bool    wQFile::seek(qint64 pos)


///
// public functions inherited from QIODevice


// qint64  wQFile::bytesAvailable() const

// qint64  wQFile::bytesToWrite() const

// bool    wQFile::canReadLine() const

// QString wQFile::errorString() const

// bool    wQFile::getChar(char * c)

bool    wQFile::isOpen() const
{ WQ_PRIV(const QFile); return o->isOpen(); };

// bool    wQFile::isReadable() const

// bool    wQFile::isTextModeEnabled() const

// bool    wQFile::isWritable() const

// OpenMode    wQFile::openMode() const

// qint64  wQFile::peek(char * data, qint64 maxSize)

#define LATIN1_CHARS \
" !\"#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

QString  wQFile::peek(qint64 maxSize)
{ WQ_PRIV(QFile);
  return QString::fromLatin1(o->peek(maxSize).toPercentEncoding(LATIN1_CHARS)); };

// bool    wQFile::putChar(char c)

// qint64  wQFile::read(char * data, qint64 maxSize)

QString  wQFile::read(qint64 maxSize)
{ WQ_PRIV(QFile);
  return QString::fromLatin1(o->read(maxSize).toPercentEncoding(LATIN1_CHARS)); };

QString  wQFile::readAll()
{ WQ_PRIV(QFile);
  return QString::fromLatin1(o->readAll().toPercentEncoding(LATIN1_CHARS)); };

// qint64  wQFile::readLine(char * data, qint64 maxSize)

// QByteArray  wQFile::readLine(qint64 maxSize = 0)

bool    wQFile::reset()
{ WQ_PRIV(QFile); return o->reset(); };

// bool    wQFile::seek(qint64 pos)

// void    wQFile::setTextModeEnabled(bool enabled)

// void    wQFile::ungetChar(char c)

// bool    wQFile::waitForBytesWritten(int msecs)

// bool    wQFile::waitForReadyRead(int msecs)

qint64  wQFile::write(const QString & string)
{ WQ_PRIV(QFile);
  return o->write(QByteArray::fromPercentEncoding(string.toLatin1())); };
